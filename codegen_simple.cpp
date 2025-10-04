#include "codegen_simple.h"
#include <iostream>

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
    
    // Generate all declarations
    for (auto& decl : program->declarations) {
        if (!generateDeclaration(decl.get())) {
            return false;
        }
    }
    
    // Verify the module
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
    // Check if function already exists
    llvm::Function* function = module->getFunction(funcDecl->name);
    if (function) {
        setError("Function " + funcDecl->name + " already declared");
        return nullptr;
    }
    
    // Create parameter types
    std::vector<llvm::Type*> paramTypes;
    for (const auto& param : funcDecl->parameters) {
        llvm::Type* paramType = getLLVMType(param.type);
        paramTypes.push_back(paramType);
    }
    
    // Create function type
    llvm::Type* returnType = getLLVMType(funcDecl->type);
    llvm::FunctionType* funcType = llvm::FunctionType::get(returnType, paramTypes, false);
    
    // Create function
    function = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, 
                                    funcDecl->name, module.get());
    
    // Set parameter names
    unsigned idx = 0;
    for (auto& arg : function->args()) {
        arg.setName(funcDecl->parameters[idx++].name);
    }
    
    functions[funcDecl->name] = function;
    
    // Generate function body if present
    if (funcDecl->body) {
        llvm::BasicBlock* entryBlock = llvm::BasicBlock::Create(*context, "entry", function);
        builder->SetInsertPoint(entryBlock);
        
        currentFunction = function;
        
        // Create allocas for parameters
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
        
        // Generate function body
        generateBlock(funcDecl->body.get());
        
        // Add return if missing (for void functions)
        if (returnType->isVoidTy() && !builder->GetInsertBlock()->getTerminator()) {
            builder->CreateRetVoid();
        }
        
        currentFunction = nullptr;
    }
    
    return function;
}

llvm::AllocaInst* CodeGenerator::generateVariableDeclaration(VariableDeclaration* varDecl) {
    llvm::Type* type = getLLVMType(varDecl->type);
    
    llvm::AllocaInst* alloca;
    
    if (currentFunction) {
        // Local variable
        alloca = createEntryBlockAlloca(currentFunction, varDecl->name, type);
        namedValues[varDecl->name] = alloca;
    } else {
        // Global variable
        llvm::GlobalVariable* globalVar = new llvm::GlobalVariable(
            *module, type, false, llvm::GlobalValue::CommonLinkage,
            llvm::Constant::getNullValue(type), varDecl->name);
        namedValues[varDecl->name] = nullptr; // Global variables handled differently
        return nullptr;
    }
    
    // Handle initializer
    if (varDecl->initializer) {
        llvm::Value* initValue = generateExpression(varDecl->initializer.get());
        if (initValue) {
            builder->CreateStore(initValue, alloca);
        }
    }
    
    return alloca;
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

llvm::Value* CodeGenerator::generateExpression(Expression* expr) {
    if (auto binOp = dynamic_cast<BinaryOp*>(expr)) {
        return generateBinaryOp(binOp);
    } else if (auto id = dynamic_cast<Identifier*>(expr)) {
        return generateIdentifier(id);
    } else if (auto intLit = dynamic_cast<IntLiteral*>(expr)) {
        return generateIntLiteral(intLit);
    }
    
    setError("Unknown expression type");
    return nullptr;
}

llvm::Value* CodeGenerator::generateBinaryOp(BinaryOp* binOp) {
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
        default:
            setError("Unknown binary operator");
            return nullptr;
    }
}

llvm::Value* CodeGenerator::generateIdentifier(Identifier* id) {
    llvm::AllocaInst* alloca = namedValues[id->name];
    if (!alloca) {
        setError("Unknown variable: " + id->name);
        return nullptr;
    }
    
    return builder->CreateLoad(alloca->getAllocatedType(), alloca, id->name);
}

llvm::Value* CodeGenerator::generateIntLiteral(IntLiteral* intLit) {
    return llvm::ConstantInt::get(*context, llvm::APInt(32, intLit->value));
}

llvm::Type* CodeGenerator::getLLVMType(Expression::Type type) {
    switch (type) {
        case Expression::INT_TYPE:
            return llvm::Type::getInt32Ty(*context);
        case Expression::FLOAT_TYPE:
            return llvm::Type::getDoubleTy(*context);
        case Expression::CHAR_TYPE:
            return llvm::Type::getInt8Ty(*context);
        case Expression::VOID_TYPE:
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