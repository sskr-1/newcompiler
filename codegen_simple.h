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
    
    // Current function being generated
    llvm::Function* currentFunction;
    
    // Error handling
    bool hasErrors;
    std::string lastError;
    
public:
    CodeGenerator(const std::string& moduleName);
    ~CodeGenerator() = default;
    
    // Main generation methods
    bool generateCode(Program* program);
    void printModule();
    
    // Error handling
    bool hasError() const { return hasErrors; }
    std::string getLastError() const { return lastError; }
    
private:
    // Type conversion methods
    llvm::Type* getLLVMType(Expression::Type type);
    
    // Declaration generation
    llvm::Value* generateDeclaration(Declaration* decl);
    llvm::Function* generateFunctionDeclaration(FunctionDeclaration* funcDecl);
    llvm::AllocaInst* generateVariableDeclaration(VariableDeclaration* varDecl);
    
    // Statement generation
    llvm::Value* generateStatement(Statement* stmt);
    llvm::Value* generateBlock(Block* block);
    llvm::Value* generateExpressionStatement(ExpressionStatement* exprStmt);
    llvm::Value* generateReturnStatement(ReturnStatement* retStmt);
    
    // Expression generation
    llvm::Value* generateExpression(Expression* expr);
    llvm::Value* generateBinaryOp(BinaryOp* binOp);
    llvm::Value* generateIdentifier(Identifier* id);
    llvm::Value* generateIntLiteral(IntLiteral* intLit);
    
    // Helper methods
    llvm::AllocaInst* createEntryBlockAlloca(llvm::Function* function, 
                                           const std::string& varName, 
                                           llvm::Type* type);
    
    // Utility methods
    void setError(const std::string& error);
};

// Global code generator instance
extern std::unique_ptr<CodeGenerator> codeGen;

#endif // CODEGEN_H