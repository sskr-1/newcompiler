#include <iostream>
#include "ast.h"
#include "codegen_simple.h"

int main() {
    std::cout << "Testing AST and CodeGen components...\n";
    
    // Create a simple AST manually
    auto program = std::make_unique<Program>();
    
    // Create a simple function: int main() { return 42; }
    auto mainFunc = std::make_unique<FunctionDeclaration>("main", Expression::INT_TYPE);
    
    // Create function body
    auto body = std::make_unique<Block>();
    auto returnStmt = std::make_unique<ReturnStatement>(
        std::make_unique<IntLiteral>(42)
    );
    body->statements.push_back(std::move(returnStmt));
    mainFunc->body = std::move(body);
    
    program->declarations.push_back(std::move(mainFunc));
    
    std::cout << "Created AST for: int main() { return 42; }\n";
    
    // Print AST
    std::cout << "\n=== AST ===\n";
    program->print();
    
    // Test code generation
    std::cout << "\n=== Code Generation ===\n";
    codeGen = std::make_unique<CodeGenerator>("test_module");
    
    if (codeGen->generateCode(program.get())) {
        std::cout << "Code generation successful!\n";
        std::cout << "\n=== LLVM IR ===\n";
        codeGen->printModule();
    } else {
        std::cout << "Code generation failed: " << codeGen->getLastError() << "\n";
        return 1;
    }
    
    std::cout << "\nTest completed successfully!\n";
    return 0;
}