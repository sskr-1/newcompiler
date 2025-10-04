#include <iostream>
#include <fstream>
#include <string>
#include "ast.h"

// Forward declarations from flex/bison
extern FILE* yyin;
extern int yyparse();
extern Program* root;

void printUsage(const char* programName) {
    std::cout << "Usage: " << programName << " [options] <input_file>\n";
    std::cout << "Options:\n";
    std::cout << "  -ast            Print AST\n";
    std::cout << "  -h, --help      Show help\n";
}

int main(int argc, char* argv[]) {
    std::string inputFile;
    bool printAST = false;
    
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];
        
        if (arg == "-h" || arg == "--help") {
            printUsage(argv[0]);
            return 0;
        } else if (arg == "-ast") {
            printAST = true;
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
    }
    
    return 0;
}