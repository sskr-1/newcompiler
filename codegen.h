#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Value.h>
#include <llvm/IR/Type.h>
#include <llvm/IR/Function.h>
#include <llvm/IR/BasicBlock.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include <llvm/ExecutionEngine/MCJIT.h>
#include <llvm/Support/TargetSelect.h>
#include <llvm/Target/TargetMachine.h>
#include <llvm/Support/FileSystem.h>
#include <llvm/Support/Host.h>
#include <llvm/Support/TargetRegistry.h>
#include <llvm/Target/TargetOptions.h>
#include <llvm/IR/LegacyPassManager.h>
#include <llvm/Transforms/InstCombine/InstCombine.h>
#include <llvm/Transforms/Scalar.h>
#include <llvm/Transforms/Scalar/GVN.h>
#include <llvm/Transforms/Utils.h>
#include <map>
#include <string>
#include <memory>

class CodeGenerator {
private:
    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;
    
    // Symbol tables
    std::map<std::string, llvm::AllocaInst*> namedValues;
    std::map<std::string, llvm::Function*> functions;
    std::map<std::string, llvm::StructType*> structTypes;
    
    // Current function being generated
    llvm::Function* currentFunction;
    
    // Loop context for break/continue
    struct LoopContext {
        llvm::BasicBlock* breakBlock;
        llvm::BasicBlock* continueBlock;
    };
    std::vector<LoopContext> loopStack;
    
    // Error handling
    bool hasErrors;
    std::string lastError;
    
public:
    CodeGenerator(const std::string& moduleName);
    ~CodeGenerator() = default;
    
    // Main generation methods
    bool generateCode(Program* program);
    void printModule();
    bool writeObjectFile(const std::string& filename);
    bool writeAssembly(const std::string& filename);
    
    // JIT execution
    bool executeJIT();
    
    // Optimization
    void optimizeModule();
    
    // Error handling
    bool hasError() const { return hasErrors; }
    std::string getLastError() const { return lastError; }
    
private:
    // Type conversion methods
    llvm::Type* getLLVMType(Expression::Type type);
    llvm::Type* getPointerType(Expression::Type type);
    llvm::Type* getArrayType(Expression::Type type, int size);
    
    // Declaration generation
    llvm::Value* generateDeclaration(Declaration* decl);
    llvm::Function* generateFunctionDeclaration(FunctionDeclaration* funcDecl);
    llvm::AllocaInst* generateVariableDeclaration(VariableDeclaration* varDecl);
    llvm::StructType* generateStructDeclaration(StructDeclaration* structDecl);
    
    // Statement generation
    llvm::Value* generateStatement(Statement* stmt);
    llvm::Value* generateBlock(Block* block);
    llvm::Value* generateIfStatement(IfStatement* ifStmt);
    llvm::Value* generateWhileStatement(WhileStatement* whileStmt);
    llvm::Value* generateForStatement(ForStatement* forStmt);
    llvm::Value* generateReturnStatement(ReturnStatement* retStmt);
    llvm::Value* generateBreakStatement(BreakStatement* breakStmt);
    llvm::Value* generateContinueStatement(ContinueStatement* contStmt);
    llvm::Value* generateExpressionStatement(ExpressionStatement* exprStmt);
    
    // Expression generation
    llvm::Value* generateExpression(Expression* expr);
    llvm::Value* generateBinaryOp(BinaryOp* binOp);
    llvm::Value* generateUnaryOp(UnaryOp* unOp);
    llvm::Value* generateFunctionCall(FunctionCall* funcCall);
    llvm::Value* generateArrayAccess(ArrayAccess* arrayAccess);
    llvm::Value* generateMemberAccess(MemberAccess* memberAccess);
    llvm::Value* generateIdentifier(Identifier* id);
    llvm::Value* generateIntLiteral(IntLiteral* intLit);
    llvm::Value* generateFloatLiteral(FloatLiteral* floatLit);
    llvm::Value* generateStringLiteral(StringLiteral* strLit);
    llvm::Value* generateCharLiteral(CharLiteral* charLit);
    
    // Helper methods
    llvm::AllocaInst* createEntryBlockAlloca(llvm::Function* function, 
                                           const std::string& varName, 
                                           llvm::Type* type);
    llvm::Value* createLoad(llvm::Value* ptr, const std::string& name = "");
    llvm::Value* createStore(llvm::Value* val, llvm::Value* ptr);
    
    // Assignment helpers
    llvm::Value* generateAssignment(BinaryOp* assignment);
    llvm::Value* generateCompoundAssignment(BinaryOp* assignment);
    
    // Comparison and logical operations
    llvm::Value* generateComparison(BinaryOp* comparison);
    llvm::Value* generateLogicalOp(BinaryOp* logicalOp);
    
    // Built-in functions
    void declareBuiltinFunctions();
    llvm::Function* declarePrintfFunction();
    llvm::Function* declareScanfFunction();
    llvm::Function* declareMallocFunction();
    llvm::Function* declareFreeFunction();
    
    // Utility methods
    void setError(const std::string& error);
    bool isLValue(Expression* expr);
    llvm::Value* getLValueAddress(Expression* expr);
    
    // Debug information (optional)
    void addDebugInfo(llvm::Value* value, const std::string& name);
};

// Global code generator instance
extern std::unique_ptr<CodeGenerator> codeGen;

// Helper functions for AST printing (implementation of virtual methods)
void printIndent(int indent);

#endif // CODEGEN_H