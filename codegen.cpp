#include "codegen.h"
#include <iostream>
#include <fstream>

std::unique_ptr<CodeGenerator> codeGen = nullptr;

CodeGenerator::CodeGenerator(const std::string& moduleName) 
    : hasErrors(false), currentFunction(nullptr) {
    context = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>(moduleName, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
    
    // Initialize LLVM targets
    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();
    llvm::InitializeNativeTargetAsmParser();
    
    // Declare built-in functions
    declareBuiltinFunctions();
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
    } else if (auto structDecl = dynamic_cast<StructDeclaration*>(decl)) {
        generateStructDeclaration(structDecl);
        return nullptr;
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
        if (param.is_array) {
            paramType = paramType->getPointerTo();
        }
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
    
    if (varDecl->is_array) {
        type = llvm::ArrayType::get(type, varDecl->array_size);
    }
    
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

llvm::StructType* CodeGenerator::generateStructDeclaration(StructDeclaration* structDecl) {
    std::vector<llvm::Type*> memberTypes;
    
    for (const auto& member : structDecl->members) {
        llvm::Type* memberType = getLLVMType(member->type);
        if (member->is_array) {
            memberType = llvm::ArrayType::get(memberType, member->array_size);
        }
        memberTypes.push_back(memberType);
    }
    
    llvm::StructType* structType = llvm::StructType::create(*context, memberTypes, structDecl->name);
    structTypes[structDecl->name] = structType;
    
    return structType;
}

llvm::Value* CodeGenerator::generateStatement(Statement* stmt) {
    if (auto block = dynamic_cast<Block*>(stmt)) {
        return generateBlock(block);
    } else if (auto ifStmt = dynamic_cast<IfStatement*>(stmt)) {
        return generateIfStatement(ifStmt);
    } else if (auto whileStmt = dynamic_cast<WhileStatement*>(stmt)) {
        return generateWhileStatement(whileStmt);
    } else if (auto forStmt = dynamic_cast<ForStatement*>(stmt)) {
        return generateForStatement(forStmt);
    } else if (auto retStmt = dynamic_cast<ReturnStatement*>(stmt)) {
        return generateReturnStatement(retStmt);
    } else if (auto breakStmt = dynamic_cast<BreakStatement*>(stmt)) {
        return generateBreakStatement(breakStmt);
    } else if (auto contStmt = dynamic_cast<ContinueStatement*>(stmt)) {
        return generateContinueStatement(contStmt);
    } else if (auto exprStmt = dynamic_cast<ExpressionStatement*>(stmt)) {
        return generateExpressionStatement(exprStmt);
    } else if (auto varDecl = dynamic_cast<VariableDeclaration*>(stmt)) {
        return generateVariableDeclaration(varDecl);
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

llvm::Value* CodeGenerator::generateIfStatement(IfStatement* ifStmt) {
    llvm::Value* condValue = generateExpression(ifStmt->condition.get());
    if (!condValue) return nullptr;
    
    // Convert condition to boolean
    condValue = builder->CreateICmpNE(condValue, 
                                     llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), 
                                     "ifcond");
    
    llvm::Function* function = builder->GetInsertBlock()->getParent();
    
    // Create blocks
    llvm::BasicBlock* thenBlock = llvm::BasicBlock::Create(*context, "then", function);
    llvm::BasicBlock* elseBlock = ifStmt->else_stmt ? 
                                 llvm::BasicBlock::Create(*context, "else") : nullptr;
    llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(*context, "ifcont");
    
    // Branch
    if (elseBlock) {
        builder->CreateCondBr(condValue, thenBlock, elseBlock);
    } else {
        builder->CreateCondBr(condValue, thenBlock, mergeBlock);
    }
    
    // Generate then block
    builder->SetInsertPoint(thenBlock);
    generateStatement(ifStmt->then_stmt.get());
    if (!builder->GetInsertBlock()->getTerminator()) {
        builder->CreateBr(mergeBlock);
    }
    
    // Generate else block if present
    if (elseBlock) {
        function->getBasicBlockList().push_back(elseBlock);
        builder->SetInsertPoint(elseBlock);
        generateStatement(ifStmt->else_stmt.get());
        if (!builder->GetInsertBlock()->getTerminator()) {
            builder->CreateBr(mergeBlock);
        }
    }
    
    // Continue with merge block
    function->getBasicBlockList().push_back(mergeBlock);
    builder->SetInsertPoint(mergeBlock);
    
    return nullptr;
}

llvm::Value* CodeGenerator::generateWhileStatement(WhileStatement* whileStmt) {
    llvm::Function* function = builder->GetInsertBlock()->getParent();
    
    llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(*context, "whilecond", function);
    llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(*context, "whilebody");
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(*context, "whileafter");
    
    // Jump to condition
    builder->CreateBr(condBlock);
    
    // Generate condition block
    builder->SetInsertPoint(condBlock);
    llvm::Value* condValue = generateExpression(whileStmt->condition.get());
    condValue = builder->CreateICmpNE(condValue, 
                                     llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), 
                                     "whilecond");
    builder->CreateCondBr(condValue, bodyBlock, afterBlock);
    
    // Generate body block
    function->getBasicBlockList().push_back(bodyBlock);
    builder->SetInsertPoint(bodyBlock);
    
    // Push loop context
    loopStack.push_back({afterBlock, condBlock});
    
    generateStatement(whileStmt->body.get());
    
    // Pop loop context
    loopStack.pop_back();
    
    if (!builder->GetInsertBlock()->getTerminator()) {
        builder->CreateBr(condBlock);
    }
    
    // Continue with after block
    function->getBasicBlockList().push_back(afterBlock);
    builder->SetInsertPoint(afterBlock);
    
    return nullptr;
}

llvm::Value* CodeGenerator::generateForStatement(ForStatement* forStmt) {
    llvm::Function* function = builder->GetInsertBlock()->getParent();
    
    // Generate initialization
    if (forStmt->init) {
        generateStatement(forStmt->init.get());
    }
    
    llvm::BasicBlock* condBlock = llvm::BasicBlock::Create(*context, "forcond", function);
    llvm::BasicBlock* bodyBlock = llvm::BasicBlock::Create(*context, "forbody");
    llvm::BasicBlock* updateBlock = llvm::BasicBlock::Create(*context, "forupdate");
    llvm::BasicBlock* afterBlock = llvm::BasicBlock::Create(*context, "forafter");
    
    // Jump to condition
    builder->CreateBr(condBlock);
    
    // Generate condition block
    builder->SetInsertPoint(condBlock);
    if (forStmt->condition) {
        llvm::Value* condValue = generateExpression(forStmt->condition.get());
        condValue = builder->CreateICmpNE(condValue, 
                                         llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), 
                                         "forcond");
        builder->CreateCondBr(condValue, bodyBlock, afterBlock);
    } else {
        builder->CreateBr(bodyBlock);
    }
    
    // Generate body block
    function->getBasicBlockList().push_back(bodyBlock);
    builder->SetInsertPoint(bodyBlock);
    
    // Push loop context
    loopStack.push_back({afterBlock, updateBlock});
    
    generateStatement(forStmt->body.get());
    
    // Pop loop context
    loopStack.pop_back();
    
    if (!builder->GetInsertBlock()->getTerminator()) {
        builder->CreateBr(updateBlock);
    }
    
    // Generate update block
    function->getBasicBlockList().push_back(updateBlock);
    builder->SetInsertPoint(updateBlock);
    if (forStmt->update) {
        generateExpression(forStmt->update.get());
    }
    builder->CreateBr(condBlock);
    
    // Continue with after block
    function->getBasicBlockList().push_back(afterBlock);
    builder->SetInsertPoint(afterBlock);
    
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

llvm::Value* CodeGenerator::generateBreakStatement(BreakStatement* breakStmt) {
    if (loopStack.empty()) {
        setError("Break statement outside of loop");
        return nullptr;
    }
    
    return builder->CreateBr(loopStack.back().breakBlock);
}

llvm::Value* CodeGenerator::generateContinueStatement(ContinueStatement* contStmt) {
    if (loopStack.empty()) {
        setError("Continue statement outside of loop");
        return nullptr;
    }
    
    return builder->CreateBr(loopStack.back().continueBlock);
}

llvm::Value* CodeGenerator::generateExpressionStatement(ExpressionStatement* exprStmt) {
    if (exprStmt->expression) {
        return generateExpression(exprStmt->expression.get());
    }
    return nullptr;
}

llvm::Value* CodeGenerator::generateExpression(Expression* expr) {
    if (auto binOp = dynamic_cast<BinaryOp*>(expr)) {
        return generateBinaryOp(binOp);
    } else if (auto unOp = dynamic_cast<UnaryOp*>(expr)) {
        return generateUnaryOp(unOp);
    } else if (auto funcCall = dynamic_cast<FunctionCall*>(expr)) {
        return generateFunctionCall(funcCall);
    } else if (auto arrayAccess = dynamic_cast<ArrayAccess*>(expr)) {
        return generateArrayAccess(arrayAccess);
    } else if (auto memberAccess = dynamic_cast<MemberAccess*>(expr)) {
        return generateMemberAccess(memberAccess);
    } else if (auto id = dynamic_cast<Identifier*>(expr)) {
        return generateIdentifier(id);
    } else if (auto intLit = dynamic_cast<IntLiteral*>(expr)) {
        return generateIntLiteral(intLit);
    } else if (auto floatLit = dynamic_cast<FloatLiteral*>(expr)) {
        return generateFloatLiteral(floatLit);
    } else if (auto strLit = dynamic_cast<StringLiteral*>(expr)) {
        return generateStringLiteral(strLit);
    } else if (auto charLit = dynamic_cast<CharLiteral*>(expr)) {
        return generateCharLiteral(charLit);
    }
    
    setError("Unknown expression type");
    return nullptr;
}

llvm::Value* CodeGenerator::generateBinaryOp(BinaryOp* binOp) {
    // Handle assignment operators
    if (binOp->op >= BinaryOp::ASSIGN && binOp->op <= BinaryOp::DIV_ASSIGN) {
        if (binOp->op == BinaryOp::ASSIGN) {
            return generateAssignment(binOp);
        } else {
            return generateCompoundAssignment(binOp);
        }
    }
    
    // Handle comparison operators
    if (binOp->op >= BinaryOp::EQ && binOp->op <= BinaryOp::GE) {
        return generateComparison(binOp);
    }
    
    // Handle logical operators
    if (binOp->op == BinaryOp::AND || binOp->op == BinaryOp::OR) {
        return generateLogicalOp(binOp);
    }
    
    // Handle arithmetic operators
    llvm::Value* left = generateExpression(binOp->left.get());
    llvm::Value* right = generateExpression(binOp->right.get());
    
    if (!left || !right) return nullptr;
    
    switch (binOp->op) {
        case BinaryOp::ADD:
            if (left->getType()->isFloatingPointTy() || right->getType()->isFloatingPointTy()) {
                return builder->CreateFAdd(left, right, "addtmp");
            } else {
                return builder->CreateAdd(left, right, "addtmp");
            }
        case BinaryOp::SUB:
            if (left->getType()->isFloatingPointTy() || right->getType()->isFloatingPointTy()) {
                return builder->CreateFSub(left, right, "subtmp");
            } else {
                return builder->CreateSub(left, right, "subtmp");
            }
        case BinaryOp::MUL:
            if (left->getType()->isFloatingPointTy() || right->getType()->isFloatingPointTy()) {
                return builder->CreateFMul(left, right, "multmp");
            } else {
                return builder->CreateMul(left, right, "multmp");
            }
        case BinaryOp::DIV:
            if (left->getType()->isFloatingPointTy() || right->getType()->isFloatingPointTy()) {
                return builder->CreateFDiv(left, right, "divtmp");
            } else {
                return builder->CreateSDiv(left, right, "divtmp");
            }
        case BinaryOp::MOD:
            return builder->CreateSRem(left, right, "modtmp");
        default:
            setError("Unknown binary operator");
            return nullptr;
    }
}

llvm::Value* CodeGenerator::generateComparison(BinaryOp* comparison) {
    llvm::Value* left = generateExpression(comparison->left.get());
    llvm::Value* right = generateExpression(comparison->right.get());
    
    if (!left || !right) return nullptr;
    
    if (left->getType()->isFloatingPointTy() || right->getType()->isFloatingPointTy()) {
        switch (comparison->op) {
            case BinaryOp::EQ: return builder->CreateFCmpOEQ(left, right, "eqtmp");
            case BinaryOp::NE: return builder->CreateFCmpONE(left, right, "netmp");
            case BinaryOp::LT: return builder->CreateFCmpOLT(left, right, "lttmp");
            case BinaryOp::LE: return builder->CreateFCmpOLE(left, right, "letmp");
            case BinaryOp::GT: return builder->CreateFCmpOGT(left, right, "gttmp");
            case BinaryOp::GE: return builder->CreateFCmpOGE(left, right, "getmp");
            default: break;
        }
    } else {
        switch (comparison->op) {
            case BinaryOp::EQ: return builder->CreateICmpEQ(left, right, "eqtmp");
            case BinaryOp::NE: return builder->CreateICmpNE(left, right, "netmp");
            case BinaryOp::LT: return builder->CreateICmpSLT(left, right, "lttmp");
            case BinaryOp::LE: return builder->CreateICmpSLE(left, right, "letmp");
            case BinaryOp::GT: return builder->CreateICmpSGT(left, right, "gttmp");
            case BinaryOp::GE: return builder->CreateICmpSGE(left, right, "getmp");
            default: break;
        }
    }
    
    setError("Unknown comparison operator");
    return nullptr;
}

llvm::Value* CodeGenerator::generateLogicalOp(BinaryOp* logicalOp) {
    llvm::Value* left = generateExpression(logicalOp->left.get());
    if (!left) return nullptr;
    
    // Convert to boolean
    left = builder->CreateICmpNE(left, llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), "leftbool");
    
    if (logicalOp->op == BinaryOp::AND) {
        // Short-circuit AND
        llvm::Function* function = builder->GetInsertBlock()->getParent();
        llvm::BasicBlock* rightBlock = llvm::BasicBlock::Create(*context, "and_right", function);
        llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(*context, "and_merge", function);
        
        builder->CreateCondBr(left, rightBlock, mergeBlock);
        
        builder->SetInsertPoint(rightBlock);
        llvm::Value* right = generateExpression(logicalOp->right.get());
        right = builder->CreateICmpNE(right, llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), "rightbool");
        builder->CreateBr(mergeBlock);
        rightBlock = builder->GetInsertBlock();
        
        builder->SetInsertPoint(mergeBlock);
        llvm::PHINode* phi = builder->CreatePHI(llvm::Type::getInt1Ty(*context), 2, "andresult");
        phi->addIncoming(llvm::ConstantInt::getFalse(*context), function->getBasicBlockList().end()[-2].getPrevNode());
        phi->addIncoming(right, rightBlock);
        
        return phi;
    } else if (logicalOp->op == BinaryOp::OR) {
        // Short-circuit OR
        llvm::Function* function = builder->GetInsertBlock()->getParent();
        llvm::BasicBlock* rightBlock = llvm::BasicBlock::Create(*context, "or_right", function);
        llvm::BasicBlock* mergeBlock = llvm::BasicBlock::Create(*context, "or_merge", function);
        
        builder->CreateCondBr(left, mergeBlock, rightBlock);
        
        builder->SetInsertPoint(rightBlock);
        llvm::Value* right = generateExpression(logicalOp->right.get());
        right = builder->CreateICmpNE(right, llvm::ConstantInt::get(*context, llvm::APInt(32, 0)), "rightbool");
        builder->CreateBr(mergeBlock);
        rightBlock = builder->GetInsertBlock();
        
        builder->SetInsertPoint(mergeBlock);
        llvm::PHINode* phi = builder->CreatePHI(llvm::Type::getInt1Ty(*context), 2, "orresult");
        phi->addIncoming(llvm::ConstantInt::getTrue(*context), function->getBasicBlockList().end()[-2].getPrevNode());
        phi->addIncoming(right, rightBlock);
        
        return phi;
    }
    
    setError("Unknown logical operator");
    return nullptr;
}

llvm::Value* CodeGenerator::generateAssignment(BinaryOp* assignment) {
    llvm::Value* rvalue = generateExpression(assignment->right.get());
    if (!rvalue) return nullptr;
    
    llvm::Value* lvalueAddr = getLValueAddress(assignment->left.get());
    if (!lvalueAddr) return nullptr;
    
    builder->CreateStore(rvalue, lvalueAddr);
    return rvalue;
}

llvm::Value* CodeGenerator::generateCompoundAssignment(BinaryOp* assignment) {
    llvm::Value* lvalueAddr = getLValueAddress(assignment->left.get());
    if (!lvalueAddr) return nullptr;
    
    llvm::Value* lvalue = createLoad(lvalueAddr);
    llvm::Value* rvalue = generateExpression(assignment->right.get());
    if (!lvalue || !rvalue) return nullptr;
    
    llvm::Value* result = nullptr;
    
    switch (assignment->op) {
        case BinaryOp::PLUS_ASSIGN:
            result = builder->CreateAdd(lvalue, rvalue, "plusassign");
            break;
        case BinaryOp::MINUS_ASSIGN:
            result = builder->CreateSub(lvalue, rvalue, "minusassign");
            break;
        case BinaryOp::MULT_ASSIGN:
            result = builder->CreateMul(lvalue, rvalue, "multassign");
            break;
        case BinaryOp::DIV_ASSIGN:
            result = builder->CreateSDiv(lvalue, rvalue, "divassign");
            break;
        default:
            setError("Unknown compound assignment operator");
            return nullptr;
    }
    
    builder->CreateStore(result, lvalueAddr);
    return result;
}

llvm::Value* CodeGenerator::generateUnaryOp(UnaryOp* unOp) {
    llvm::Value* operand = generateExpression(unOp->operand.get());
    if (!operand) return nullptr;
    
    switch (unOp->op) {
        case UnaryOp::PLUS:
            return operand;
        case UnaryOp::MINUS:
            if (operand->getType()->isFloatingPointTy()) {
                return builder->CreateFNeg(operand, "negtmp");
            } else {
                return builder->CreateNeg(operand, "negtmp");
            }
        case UnaryOp::NOT:
            return builder->CreateNot(operand, "nottmp");
        case UnaryOp::PRE_INC: {
            llvm::Value* addr = getLValueAddress(unOp->operand.get());
            if (!addr) return nullptr;
            llvm::Value* val = createLoad(addr);
            llvm::Value* inc = builder->CreateAdd(val, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)), "preinc");
            builder->CreateStore(inc, addr);
            return inc;
        }
        case UnaryOp::PRE_DEC: {
            llvm::Value* addr = getLValueAddress(unOp->operand.get());
            if (!addr) return nullptr;
            llvm::Value* val = createLoad(addr);
            llvm::Value* dec = builder->CreateSub(val, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)), "predec");
            builder->CreateStore(dec, addr);
            return dec;
        }
        case UnaryOp::POST_INC: {
            llvm::Value* addr = getLValueAddress(unOp->operand.get());
            if (!addr) return nullptr;
            llvm::Value* val = createLoad(addr);
            llvm::Value* inc = builder->CreateAdd(val, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)), "postinc");
            builder->CreateStore(inc, addr);
            return val; // Return original value
        }
        case UnaryOp::POST_DEC: {
            llvm::Value* addr = getLValueAddress(unOp->operand.get());
            if (!addr) return nullptr;
            llvm::Value* val = createLoad(addr);
            llvm::Value* dec = builder->CreateSub(val, llvm::ConstantInt::get(*context, llvm::APInt(32, 1)), "postdec");
            builder->CreateStore(dec, addr);
            return val; // Return original value
        }
        case UnaryOp::DEREF:
            return createLoad(operand, "deref");
        case UnaryOp::ADDRESS_OF:
            return getLValueAddress(unOp->operand.get());
        default:
            setError("Unknown unary operator");
            return nullptr;
    }
}

llvm::Value* CodeGenerator::generateFunctionCall(FunctionCall* funcCall) {
    llvm::Function* function = functions[funcCall->name];
    if (!function) {
        function = module->getFunction(funcCall->name);
        if (!function) {
            setError("Unknown function: " + funcCall->name);
            return nullptr;
        }
    }
    
    if (function->arg_size() != funcCall->arguments.size()) {
        setError("Incorrect number of arguments for function: " + funcCall->name);
        return nullptr;
    }
    
    std::vector<llvm::Value*> args;
    for (const auto& arg : funcCall->arguments) {
        llvm::Value* argValue = generateExpression(arg.get());
        if (!argValue) return nullptr;
        args.push_back(argValue);
    }
    
    return builder->CreateCall(function, args, "calltmp");
}

llvm::Value* CodeGenerator::generateArrayAccess(ArrayAccess* arrayAccess) {
    llvm::Value* array = generateExpression(arrayAccess->array.get());
    llvm::Value* index = generateExpression(arrayAccess->index.get());
    
    if (!array || !index) return nullptr;
    
    // Create GEP instruction
    std::vector<llvm::Value*> indices = {
        llvm::ConstantInt::get(*context, llvm::APInt(32, 0)),
        index
    };
    
    llvm::Value* elementPtr = builder->CreateGEP(array->getType()->getPointerElementType(), array, indices, "arrayaccess");
    return createLoad(elementPtr);
}

llvm::Value* CodeGenerator::generateMemberAccess(MemberAccess* memberAccess) {
    // This would require struct type information and member indices
    // For now, return a placeholder
    setError("Member access not fully implemented");
    return nullptr;
}

llvm::Value* CodeGenerator::generateIdentifier(Identifier* id) {
    llvm::AllocaInst* alloca = namedValues[id->name];
    if (!alloca) {
        // Check for global variables
        llvm::GlobalVariable* globalVar = module->getNamedGlobal(id->name);
        if (globalVar) {
            return createLoad(globalVar, id->name);
        }
        setError("Unknown variable: " + id->name);
        return nullptr;
    }
    
    return createLoad(alloca, id->name);
}

llvm::Value* CodeGenerator::generateIntLiteral(IntLiteral* intLit) {
    return llvm::ConstantInt::get(*context, llvm::APInt(32, intLit->value));
}

llvm::Value* CodeGenerator::generateFloatLiteral(FloatLiteral* floatLit) {
    return llvm::ConstantFP::get(*context, llvm::APFloat(floatLit->value));
}

llvm::Value* CodeGenerator::generateStringLiteral(StringLiteral* strLit) {
    return builder->CreateGlobalStringPtr(strLit->value, "str");
}

llvm::Value* CodeGenerator::generateCharLiteral(CharLiteral* charLit) {
    return llvm::ConstantInt::get(*context, llvm::APInt(8, charLit->value));
}

// Helper methods implementation
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

llvm::Value* CodeGenerator::createLoad(llvm::Value* ptr, const std::string& name) {
    return builder->CreateLoad(ptr->getType()->getPointerElementType(), ptr, name);
}

llvm::Value* CodeGenerator::createStore(llvm::Value* val, llvm::Value* ptr) {
    return builder->CreateStore(val, ptr);
}

llvm::Value* CodeGenerator::getLValueAddress(Expression* expr) {
    if (auto id = dynamic_cast<Identifier*>(expr)) {
        llvm::AllocaInst* alloca = namedValues[id->name];
        if (!alloca) {
            llvm::GlobalVariable* globalVar = module->getNamedGlobal(id->name);
            if (globalVar) {
                return globalVar;
            }
            setError("Unknown variable: " + id->name);
            return nullptr;
        }
        return alloca;
    }
    
    setError("Expression is not an lvalue");
    return nullptr;
}

void CodeGenerator::declareBuiltinFunctions() {
    declarePrintfFunction();
    declareScanfFunction();
    declareMallocFunction();
    declareFreeFunction();
}

llvm::Function* CodeGenerator::declarePrintfFunction() {
    std::vector<llvm::Type*> printfArgs;
    printfArgs.push_back(llvm::Type::getInt8PtrTy(*context));
    
    llvm::FunctionType* printfType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(*context), printfArgs, true);
    
    llvm::Function* printfFunc = llvm::Function::Create(
        printfType, llvm::Function::ExternalLinkage, "printf", module.get());
    
    functions["printf"] = printfFunc;
    return printfFunc;
}

llvm::Function* CodeGenerator::declareScanfFunction() {
    std::vector<llvm::Type*> scanfArgs;
    scanfArgs.push_back(llvm::Type::getInt8PtrTy(*context));
    
    llvm::FunctionType* scanfType = llvm::FunctionType::get(
        llvm::Type::getInt32Ty(*context), scanfArgs, true);
    
    llvm::Function* scanfFunc = llvm::Function::Create(
        scanfType, llvm::Function::ExternalLinkage, "scanf", module.get());
    
    functions["scanf"] = scanfFunc;
    return scanfFunc;
}

llvm::Function* CodeGenerator::declareMallocFunction() {
    std::vector<llvm::Type*> mallocArgs;
    mallocArgs.push_back(llvm::Type::getInt64Ty(*context));
    
    llvm::FunctionType* mallocType = llvm::FunctionType::get(
        llvm::Type::getInt8PtrTy(*context), mallocArgs, false);
    
    llvm::Function* mallocFunc = llvm::Function::Create(
        mallocType, llvm::Function::ExternalLinkage, "malloc", module.get());
    
    functions["malloc"] = mallocFunc;
    return mallocFunc;
}

llvm::Function* CodeGenerator::declareFreeFunction() {
    std::vector<llvm::Type*> freeArgs;
    freeArgs.push_back(llvm::Type::getInt8PtrTy(*context));
    
    llvm::FunctionType* freeType = llvm::FunctionType::get(
        llvm::Type::getVoidTy(*context), freeArgs, false);
    
    llvm::Function* freeFunc = llvm::Function::Create(
        freeType, llvm::Function::ExternalLinkage, "free", module.get());
    
    functions["free"] = freeFunc;
    return freeFunc;
}

void CodeGenerator::setError(const std::string& error) {
    hasErrors = true;
    lastError = error;
    std::cerr << "CodeGen Error: " << error << std::endl;
}

void CodeGenerator::printModule() {
    module->print(llvm::outs(), nullptr);
}

bool CodeGenerator::writeObjectFile(const std::string& filename) {
    // Implementation for writing object file
    return true; // Placeholder
}

bool CodeGenerator::writeAssembly(const std::string& filename) {
    // Implementation for writing assembly
    return true; // Placeholder
}

void CodeGenerator::optimizeModule() {
    // Add optimization passes
    auto passManager = std::make_unique<llvm::legacy::FunctionPassManager>(module.get());
    
    // Add some basic optimizations
    passManager->add(llvm::createInstructionCombiningPass());
    passManager->add(llvm::createReassociatePass());
    passManager->add(llvm::createGVNPass());
    passManager->add(llvm::createCFGSimplificationPass());
    
    passManager->doInitialization();
    
    for (auto& function : *module) {
        passManager->run(function);
    }
}

bool CodeGenerator::executeJIT() {
    // JIT execution implementation
    return true; // Placeholder
}