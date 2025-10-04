#include "codegen.h"
#include <iostream>
#include <fstream>

std::unique_ptr<CodeGenerator> codeGen = nullptr;

CodeGenerator::CodeGenerator(const std::string& moduleName) 
    : hasErrors(false), currentFunction(nullptr) {
    context = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>(moduleName, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
}

bool CodeGenerator::generateCode(Program* program) {
    if (!program) {
        setError("Null program");
        return false;
    }
    
    for (auto& decl : program->declarations) {
        if (!generateDeclaration(decl.get())) {
            return false;
        }
    }
    
    std::string error;
    llvm::raw_string_ostream errorStream(error);
    if (llvm::verifyModule(*module, &errorStream)) {
        setError("Module verification failed: " + error);
        return false;
    }
    
    return !hasErrors;
}

llvm::Value* CodeGenerator::generateDeclaration(Declaration* decl) {
    if (auto funcDecl = dynamic_cast<FunctionDeclaration*>(decl)) {
        return generateFunctionDeclaration(funcDecl);
    } else if (auto varDecl = dynamic_cast<VariableDeclaration*>(decl)) {
        return generateVariableDeclaration(varDecl);
    }
    
    setError("Unknown declaration type");
    return nullptr;
}

llvm::Function* CodeGenerator::generateFunctionDeclaration(FunctionDeclaration* funcDecl) {
    llvm::Function* function = module->getFunction(funcDecl->name);
    if (function) {
        setError("Function " + funcDecl->name + " already declared");
        return nullptr;
    }
    
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : funcDecl->parameters) {
        llvm::Type* paramType = getLLVMType(param.type.get());
        paramTypes.push_back(paramType);
    }
    
    llvm::Type* returnType = getLLVMType(funcDecl->decl_type.get());
    llvm::FunctionType* funcType = llvm::FunctionType::get(returnType, paramTypes, false);
    
    function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, 
                                    funcDecl->name, module.get());
    
    unsigned idx = 0;
    for (auto& arg : function->args()) {
        if (idx < funcDecl->parameters.size()) {
            arg.setName(funcDecl->parameters[idx].name);
        }
        idx++;
    }
    
    functions[funcDecl->name] = function;
    
    if (funcDecl->body) {
        llvm::BasicBlock* entryBlock = llvm::BasicBlock::Create(*context, "entry", function);
        builder->SetInsertPoint(entryBlock);
        
        currentFunction = function;
        namedValues.clear();
        
        idx = 0;
        for (auto& arg : function->args()) {
            llvm::AllocaInst* alloca = createEntryBlockAlloca(function, 
                                                            std::string(arg.getName()), 
                                                            arg.getType());
            builder->CreateStore(&arg, alloca);
            namedValues[std::string(arg.getName())] = alloca;
            idx++;
        }
        
        generateBlock(funcDecl->body.get());
        
        if (returnType->isVoidTy() && !builder->GetInsertBlock()->getTerminator()) {
            builder->CreateRetVoid();
        }
        
        currentFunction = nullptr;
    }
    
    return function;
}

llvm::AllocaInst* CodeGenerator::generateVariableDeclaration(VariableDeclaration* varDecl) {
    llvm::Type* type = getLLVMType(varDecl->decl_type.get());
    
    if (currentFunction) {
        llvm::AllocaInst* alloca = createEntryBlockAlloca(currentFunction, varDecl->name, type);
        namedValues[varDecl->name] = alloca;
        
        if (varDecl->initializer) {
            llvm::Value* initValue = generateExpression(varDecl->initializer.get());
            if (initValue) {
                builder->CreateStore(initValue, alloca);
            }
        }
        
        return alloca;
    } else {
        llvm::GlobalVariable* globalVar = new llvm::GlobalVariable(
            *module, type, false, llvm::GlobalValue::CommonLinkage,
            llvm::Constant::getNullValue(type), varDecl->name);
        
        if (varDecl->initializer && varDecl->initializer->isConstant()) {
            // Handle constant initializers for globals
            if (auto intLit = dynamic_cast<IntLiteral*>(varDecl->initializer.get())) {
                globalVar->setInitializer(llvm::ConstantInt::get(type, intLit->value));
            }
        }
        
        return nullptr;
    }
}

llvm::Value* CodeGenerator::generateStatement(Statement* stmt) {
    if (auto block = dynamic_cast<Block*>(stmt)) {
        return generateBlock(block);
    } else if (auto exprStmt = dynamic_cast<ExpressionStatement*>(stmt)) {
        return generateExpressionStatement(exprStmt);
    } else if (auto varDecl = dynamic_cast<VariableDeclaration*>(stmt)) {
        return generateVariableDeclaration(varDecl);
    } else if (auto retStmt = dynamic_cast<ReturnStatement*>(stmt)) {
        return generateReturnStatement(retStmt);
    } else if (auto ifStmt = dynamic_cast<IfStatement*>(stmt)) {
        return generateIfStatement(ifStmt);
    } else if (auto whileStmt = dynamic_cast<WhileStatement*>(stmt)) {
        return generateWhileStatement(whileStmt);
    }
    
    setError("Unknown statement type");
    return nullptr;
}

llvm::Value* CodeGenerator::generateBlock(Block* block) {
    llvm::Value* lastValue = nullptr;
    
    for (const auto& stmt : block->statements) {
        lastValue = generateStatement(stmt.get());
        if (hasErrors) break;
    }
    
    return lastValue;
}

llvm::Value* CodeGenerator::generateExpressionStatement(ExpressionStatement* exprStmt) {
    if (exprStmt->expression) {
        return generateExpression(exprStmt->expression.get());
    }
    return nullptr;
}

llvm::Value* CodeGenerator::generateReturnStatement(ReturnStatement* retStmt) {
    if (retStmt->value) {
        llvm::Value* retValue = generateExpression(retStmt->value.get());
        return builder->CreateRet(retValue);
    } else {
        return builder->CreateRetVoid();
    }
}

llvm::Value* CodeGenerator::generateIfStatement(IfStatement* ifStmt) {
    llvm::Value* condValue = generateExpression(ifStmt->condition.get());
    if (!condValue) return nullptr;
    
    condValue = builder->CreateICmpNE(condValue, 
                                     llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), 
                                     "ifcond");
    
    llvm::Function* function = builder->GetInsertBlock()->getParent();
    
    llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(*context, "then", function);
    llvm::BasicBlock* elseBlock = ifStmt->else_stmt ? 
                                 llvm::BasicBlock::Create(*context, "else") : nullptr;
    llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(*context, "ifcont");
    
    if (elseBlock) {
        builder->CreateCondBr(condValue, thenBlock, elseBlock);
    } else {
        builder->CreateCondBr(condValue, thenBlock, mergeBlock);
    }
    
    builder->SetInsertPoint(thenBlock);
    generateStatement(ifStmt->then_stmt.get());
    if (!builder->GetInsertBlock()->getTerminator()) {
        builder->CreateBr(mergeBlock);
    }
    
    if (elseBlock) {
        function->getBasicBlockList().push_back(elseBlock);
        builder->SetInsertPoint(elseBlock);
        generateStatement(ifStmt->else_stmt.get());
        if (!builder->GetInsertBlock()->getTerminator()) {
            builder->CreateBr(mergeBlock);
        }
    }
    
    function->getBasicBlockList().push_back(mergeBlock);
    builder->SetInsertPoint(mergeBlock);
    
    return nullptr;
}

llvm::Value* CodeGenerator::generateWhileStatement(WhileStatement* whileStmt) {
    llvm::Function* function = builder->GetInsertBlock()->getParent();
    
    llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(*context, "whilecond", function);
    llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(*context, "whilebody");
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(*context, "whileafter");
    
    builder->CreateBr(condBlock);
    
    builder->SetInsertPoint(condBlock);
    llvm::Value* condValue = generateExpression(whileStmt->condition.get());
    condValue = builder->CreateICmpNE(condValue, 
                                     llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), 
                                     "whilecond");
    builder->CreateCondBr(condValue, bodyBlock, afterBlock);
    
    function->getBasicBlockList().push_back(bodyBlock);
    builder->SetInsertPoint(bodyBlock);
    
    generateStatement(whileStmt->body.get());
    
    if (!builder->GetInsertBlock()->getTerminator()) {
        builder->CreateBr(condBlock);
    }
    
    function->getBasicBlockList().push_back(afterBlock);
    builder->SetInsertPoint(afterBlock);
    
    return nullptr;
}

llvm::Value* CodeGenerator::generateExpression(Expression* expr) {
    if (auto binOp = dynamic_cast<BinaryOp*>(expr)) {
        return generateBinaryOp(binOp);
    } else if (auto unOp = dynamic_cast<UnaryOp*>(expr)) {
        return generateUnaryOp(unOp);
    } else if (auto funcCall = dynamic_cast<FunctionCall*>(expr)) {
        return generateFunctionCall(funcCall);
    } else if (auto id = dynamic_cast<Identifier*>(expr)) {
        return generateIdentifier(id);
    } else if (auto intLit = dynamic_cast<IntLiteral*>(expr)) {
        return generateIntLiteral(intLit);
    } else if (auto floatLit = dynamic_cast<FloatLiteral*>(expr)) {
        return generateFloatLiteral(floatLit);
    }
    
    setError("Unknown expression type");
    return nullptr;
}

llvm::Value* CodeGenerator::generateBinaryOp(BinaryOp* binOp) {
    if (binOp->op == BinaryOp::ASSIGN) {
        llvm::Value* rvalue = generateExpression(binOp->right.get());
        if (!rvalue) return nullptr;
        
        if (auto id = dynamic_cast<Identifier*>(binOp->left.get())) {
            llvm::AllocaInst* alloca = namedValues[id->name];
            if (!alloca) {
                setError("Unknown variable: " + id->name);
                return nullptr;
            }
            builder->CreateStore(rvalue, alloca);
            return rvalue;
        }
        
        setError("Invalid assignment target");
        return nullptr;
    }
    
    llvm::Value* left = generateExpression(binOp->left.get());
    llvm::Value* right = generateExpression(binOp->right.get());
    
    if (!left || !right) return nullptr;
    
    switch (binOp->op) {
        case BinaryOp::ADD:
            return builder->CreateAdd(left, right, "addtmp");
        case BinaryOp::SUB:
            return builder->CreateSub(left, right, "subtmp");
        case BinaryOp::MUL:
            return builder->CreateMul(left, right, "multmp");
        case BinaryOp::DIV:
            return builder->CreateSDiv(left, right, "divtmp");
        case BinaryOp::MOD:
            return builder->CreateSRem(left, right, "modtmp");
        case BinaryOp::EQ:
            return builder->CreateICmpEQ(left, right, "eqtmp");
        case BinaryOp::NE:
            return builder->CreateICmpNE(left, right, "netmp");
        case BinaryOp::LT:
            return builder->CreateICmpSLT(left, right, "lttmp");
        case BinaryOp::LE:
            return builder->CreateICmpSLE(left, right, "letmp");
        case BinaryOp::GT:
            return builder->CreateICmpSGT(left, right, "gttmp");
        case BinaryOp::GE:
            return builder->CreateICmpSGE(left, right, "getmp");
        default:
            setError("Unknown binary operator");
            return nullptr;
    }
}

llvm::Value* CodeGenerator::generateUnaryOp(UnaryOp* unOp) {
    llvm::Value* operand = generateExpression(unOp->operand.get());
    if (!operand) return nullptr;
    
    switch (unOp->op) {
        case UnaryOp::PLUS:
            return operand;
        case UnaryOp::MINUS:
            return builder->CreateNeg(operand, "negtmp");
        case UnaryOp::NOT:
            return builder->CreateNot(operand, "nottmp");
        default:
            setError("Unknown unary operator");
            return nullptr;
    }
}

llvm::Value* CodeGenerator::generateFunctionCall(FunctionCall* funcCall) {
    if (auto id = dynamic_cast<Identifier*>(funcCall->function.get())) {
        llvm::Function* function = functions[id->name];
        if (!function) {
            function = module->getFunction(id->name);
            if (!function) {
                setError("Unknown function: " + id->name);
                return nullptr;
            }
        }
        
        std::vector<llvm::Value*> args;
        for (const auto& arg : funcCall->arguments) {
            llvm::Value* argValue = generateExpression(arg.get());
            if (!argValue) return nullptr;
            args.push_back(argValue);
        }
        
        return builder->CreateCall(function, args, "calltmp");
    }
    
    setError("Invalid function call");
    return nullptr;
}

llvm::Value* CodeGenerator::generateIdentifier(Identifier* id) {
    llvm::AllocaInst* alloca = namedValues[id->name];
    if (!alloca) {
        llvm::GlobalVariable* globalVar = module->getNamedGlobal(id->name);
        if (globalVar) {
            return builder->CreateLoad(globalVar->getValueType(), globalVar, id->name);
        }
        setError("Unknown variable: " + id->name);
        return nullptr;
    }
    
    return builder->CreateLoad(alloca->getAllocatedType(), alloca, id->name);
}

llvm::Value* CodeGenerator::generateIntLiteral(IntLiteral* intLit) {
    return llvm::ConstantInt::get(*context, llvm::APInt(32, intLit->value));
}

llvm::Value* CodeGenerator::generateFloatLiteral(FloatLiteral* floatLit) {
    return llvm::ConstantFP::get(*context, llvm::APFloat(floatLit->value));
}

llvm::Type* CodeGenerator::getLLVMType(Type* type) {
    if (!type) return llvm::Type::getInt32Ty(*context);
    
    switch (type->kind) {
        case Type::INT_TYPE:
            return llvm::Type::getInt32Ty(*context);
        case Type::FLOAT_TYPE:
            return llvm::Type::getFloatTy(*context);
        case Type::DOUBLE_TYPE:
            return llvm::Type::getDoubleTy(*context);
        case Type::CHAR_TYPE:
            return llvm::Type::getInt8Ty(*context);
        case Type::VOID_TYPE:
            return llvm::Type::getVoidTy(*context);
        default:
            return llvm::Type::getInt32Ty(*context);
    }
}

llvm::AllocaInst* CodeGenerator::createEntryBlockAlloca(llvm::Function* function, 
                                                       const std::string& varName, 
                                                       llvm::Type* type) {
    llvm::IRBuilder<> tmpBuilder(&function->getEntryBlock(), function->getEntryBlock().begin());
    return tmpBuilder.CreateAlloca(type, nullptr, varName);
}

void CodeGenerator::setError(const std::string& error) {
    hasErrors = true;
    lastError = error;
    std::cerr << "CodeGen Error: " << error << std::endl;
}

void CodeGenerator::printModule() {
    module->print(llvm::outs(), nullptr);
}

bool CodeGenerator::writeToFile(const std::string& filename) {
    std::error_code errorCode;
    llvm::raw_fd_ostream file(filename, errorCode);
    
    if (errorCode) {
        setError("Cannot open file: " + filename);
        return false;
    }
    
    module->print(file, nullptr);
    return true;
}