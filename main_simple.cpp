#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "ast.h"
#include "codegen_simple.h"

// Forward declarations from flex/bison
extern FILE* yyin;
extern int yyparse();
extern Program* root;
extern int yylineno;

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [options] <input_file>\n";
    std::cout << "Options:\n";
    std::cout << "  -ast            Print AST and exit\n";
    std::cout << "  -emit-llvm      Generate LLVM IR\n";
    std::cout << "  -h, --help      Show this help message\n";
}

int main(int argc, char* argv[]) {
    std::string inputFile;
    bool printAST = false;
    bool emitLLVM = false;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "-emit-llvm") {
            emitLLVM = true;
        } else if (arg == "-ast") {
            printAST = true;
        } else if (arg[0] != '-') {
            if (inputFile.empty()) {
                inputFile = arg;
            } else {
                std::cerr << "Error: Multiple input files specified\n";
                return 1;
            }
        } else {
            std::cerr << "Error: Unknown option " << arg << "\n";
            printUsage(argv[0]);
            return 1;
        }
    }
    
    if (inputFile.empty()) {
        std::cerr << "Error: No input file specified\n";
        printUsage(argv[0]);
        return 1;
    }
    
    // Open input file
    FILE* file = fopen(inputFile.c_str(), "r");
    if (!file) {
        std::cerr << "Error: Cannot open file " << inputFile << "\n";
        return 1;
    }
    
    yyin = file;
    
    // Parse the input
    std::cout << "Parsing " << inputFile << "...\n";
    int parseResult = yyparse();
    fclose(file);
    
    if (parseResult != 0) {
        std::cerr << "Parse failed\n";
        return 1;
    }
    
    if (!root) {
        std::cerr << "Error: No AST generated\n";
        return 1;
    }
    
    std::cout << "Parse successful!\n";
    
    // Print AST if requested
    if (printAST) {
        std::cout << "\n=== Abstract Syntax Tree ===\n";
        root->print();
        std::cout << "\n";
        if (!emitLLVM) {
            return 0;
        }
    }
    
    // Initialize code generator
    codeGen = std::make_unique<CodeGenerator>("main_module");
    
    // Generate LLVM IR
    std::cout << "Generating LLVM IR...\n";
    if (!codeGen->generateCode(root)) {
        std::cerr << "Code generation failed: " << codeGen->getLastError() << "\n";
        return 1;
    }
    
    std::cout << "Code generation successful!\n";
    
    // Handle different output modes
    if (emitLLVM) {
        codeGen->printModule();
    }
    
    std::cout << "Compilation completed successfully!\n";
    return 0;
}