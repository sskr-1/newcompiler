#include <iostream>
#include <fstream>
#include <string>
#include "ast.h"
#include "codegen.h"

// Forward declarations from flex/bison
extern FILE* yyin;
extern int yyparse();
extern Program* root;

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [options] <input_file>\n";
    std::cout << "Options:\n";
    std::cout << "  -ast            Print AST\n";
    std::cout << "  -emit-llvm      Generate LLVM IR (.ll file)\n";
    std::cout << "  -o <dir>        Output directory (default: output/)\n";
    std::cout << "  -h, --help      Show help\n";
}

int main(int argc, char* argv[]) {
    std::string inputFile;
    std::string outputDir = "output";
    bool printAST = false;
    bool emitLLVM = false;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "-ast") {
            printAST = true;
        } else if (arg == "-emit-llvm") {
            emitLLVM = true;
        } else if (arg == "-o" && i + 1 < argc) {
            outputDir = argv[++i];
        } else if (arg[0] != '-') {
            inputFile = arg;
        }
    }
    
    if (inputFile.empty()) {
        std::cerr << "Error: No input file specified\n";
        return 1;
    }
    
    FILE* file = fopen(inputFile.c_str(), "r");
    if (!file) {
        std::cerr << "Error: Cannot open file " << inputFile << "\n";
        return 1;
    }
    
    yyin = file;
    
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
    
    if (printAST) {
        std::cout << "\n=== Abstract Syntax Tree ===\n";
        root->print();
        std::cout << "\n";
    }
    
    if (emitLLVM) {
        std::cout << "Generating LLVM IR...\n";
        codeGen = std::make_unique<CodeGenerator>("main_module");
        
        if (codeGen->generateCode(root)) {
            std::cout << "Code generation successful!\n";
            
            // Create output filename
            std::string baseName = inputFile.substr(inputFile.find_last_of("/") + 1);
            baseName = baseName.substr(0, baseName.find_last_of("."));
            std::string outputFile = outputDir + "/" + baseName + ".ll";
            
            // Create output directory if it doesn't exist
            std::string mkdirCmd = "mkdir -p " + outputDir;
            system(mkdirCmd.c_str());
            
            if (codeGen->writeToFile(outputFile)) {
                std::cout << "LLVM IR written to: " << outputFile << "\n";
            } else {
                std::cerr << "Failed to write LLVM IR file\n";
                return 1;
            }
            
            std::cout << "\n=== LLVM IR ===\n";
            codeGen->printModule();
        } else {
            std::cerr << "Code generation failed: " << codeGen->getLastError() << "\n";
            return 1;
        }
    }
    
    return 0;
}