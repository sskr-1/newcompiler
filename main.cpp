#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include "ast.h"
#include "codegen.h"

// Forward declarations from flex/bison
extern FILE* yyin;
extern int yyparse();
extern Program* root;
extern int yylineno;

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [options] <input_file>\n";
    std::cout << "Options:\n";
    std::cout << "  -o <output>     Specify output file\n";
    std::cout << "  -S              Generate assembly output\n";
    std::cout << "  -c              Generate object file (default)\n";
    std::cout << "  -emit-llvm      Generate LLVM IR\n";
    std::cout << "  -O0             No optimization (default)\n";
    std::cout << "  -O1             Basic optimization\n";
    std::cout << "  -O2             More optimization\n";
    std::cout << "  -ast            Print AST and exit\n";
    std::cout << "  -jit            Execute with JIT\n";
    std::cout << "  -h, --help      Show this help message\n";
}

int main(int argc, char* argv[]) {
    std::string inputFile;
    std::string outputFile;
    bool generateAssembly = false;
    bool generateObject = true;
    bool emitLLVM = false;
    bool printAST = false;
    bool useJIT = false;
    int optimizationLevel = 0;
    
    // Parse command line arguments
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "-o" && i + 1 < argc) {
            outputFile = argv[++i];
        } else if (arg == "-S") {
            generateAssembly = true;
            generateObject = false;
        } else if (arg == "-c") {
            generateObject = true;
            generateAssembly = false;
        } else if (arg == "-emit-llvm") {
            emitLLVM = true;
            generateObject = false;
            generateAssembly = false;
        } else if (arg == "-O0") {
            optimizationLevel = 0;
        } else if (arg == "-O1") {
            optimizationLevel = 1;
        } else if (arg == "-O2") {
            optimizationLevel = 2;
        } else if (arg == "-ast") {
            printAST = true;
        } else if (arg == "-jit") {
            useJIT = true;
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
        if (!useJIT && !emitLLVM && !generateAssembly && !generateObject) {
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
    
    // Apply optimizations
    if (optimizationLevel > 0) {
        std::cout << "Applying optimizations (level " << optimizationLevel << ")...\n";
        codeGen->optimizeModule();
    }
    
    // Handle different output modes
    if (useJIT) {
        std::cout << "Executing with JIT...\n";
        if (!codeGen->executeJIT()) {
            std::cerr << "JIT execution failed\n";
            return 1;
        }
    } else if (emitLLVM) {
        if (outputFile.empty()) {
            // Print to stdout
            codeGen->printModule();
        } else {
            // Write to file
            std::ofstream outFile(outputFile);
            if (!outFile) {
                std::cerr << "Error: Cannot create output file " << outputFile << "\n";
                return 1;
            }
            // Redirect LLVM output to file
            // This would need proper implementation
            codeGen->printModule();
        }
    } else if (generateAssembly) {
        if (outputFile.empty()) {
            outputFile = inputFile.substr(0, inputFile.find_last_of('.')) + ".s";
        }
        std::cout << "Generating assembly to " << outputFile << "...\n";
        if (!codeGen->writeAssembly(outputFile)) {
            std::cerr << "Assembly generation failed\n";
            return 1;
        }
    } else if (generateObject) {
        if (outputFile.empty()) {
            outputFile = inputFile.substr(0, inputFile.find_last_of('.')) + ".o";
        }
        std::cout << "Generating object file to " << outputFile << "...\n";
        if (!codeGen->writeObjectFile(outputFile)) {
            std::cerr << "Object file generation failed\n";
            return 1;
        }
    }
    
    std::cout << "Compilation completed successfully!\n";
    return 0;
}