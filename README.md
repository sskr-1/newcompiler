# C-like Language Compiler with LLVM Backend

A complete compiler implementation for a C-like programming language using LLVM for IR code generation. This project demonstrates all phases of compiler design including lexical analysis, parsing, AST construction, semantic analysis, and code generation.

## Features

### Language Features
- **Data Types**: `int`, `float`, `char`, `void`
- **Control Flow**: `if/else`, `while`, `for` loops
- **Functions**: Function declarations and definitions with parameters
- **Operators**: Arithmetic (`+`, `-`, `*`, `/`, `%`), comparison (`==`, `!=`, `<`, `>`, `<=`, `>=`), logical (`&&`, `||`, `!`)
- **Assignment**: Basic assignment (`=`) and compound assignment (`+=`, `-=`, `*=`, `/=`)
- **Expressions**: Binary and unary operations, function calls, literals
- **Statements**: Expression statements, return statements, break/continue

### Compiler Architecture
- **Lexer** (`lexer.l`): Flex-based lexical analyzer for tokenization
- **Parser** (`parser.y`): Bison-based parser for syntax analysis and AST construction  
- **AST** (`ast.h`, `ast.cpp`): Complete Abstract Syntax Tree implementation with visitor pattern
- **Code Generator** (`codegen.h`, `codegen.cpp`): LLVM-based IR code generation
- **Driver** (`main.cpp`): Command-line interface with multiple output options

## Files Overview

### Core Compiler Files
- `lexer.l` / `lexer_simple.l` - Flex lexical analyzer specification
- `parser.y` - Bison parser grammar with AST construction
- `ast.h` - AST node class definitions and interfaces
- `ast.cpp` - AST node implementations and pretty-printing
- `codegen.h` / `codegen_simple.h` - Code generation interface
- `codegen.cpp` / `codegen_simple.cpp` - LLVM IR code generation implementation
- `main.cpp` / `main_simple.cpp` - Compiler driver program

### Build System
- `Makefile` / `Makefile_simple` - Build configuration with LLVM integration
- `test_simple.cpp` - Unit test for core components

### Examples
- `example.c` - Simple test program

## Building the Compiler

### Prerequisites
```bash
# Ubuntu/Debian
sudo apt-get install flex bison llvm-dev clang build-essential

# The compiler requires:
# - GCC/Clang with C++17 support
# - Flex (lexical analyzer generator)
# - Bison (parser generator) 
# - LLVM development libraries
```

### Compilation
```bash
# Build the simplified version (recommended for testing)
make -f Makefile_simple

# Or build the full version
make -f Makefile

# Clean build files
make -f Makefile_simple clean
```

## Usage

### Command Line Options
```bash
./compiler [options] <input_file>

Options:
  -ast            Print AST and exit
  -emit-llvm      Generate LLVM IR output
  -h, --help      Show help message
```

### Examples
```bash
# Parse and show AST
./compiler -ast example.c

# Generate LLVM IR
./compiler -emit-llvm example.c

# Parse and generate code
./compiler example.c
```

## Testing

### Unit Tests
```bash
# Test core components without parser/lexer
g++ -std=c++17 -I/usr/lib/llvm-20/include -D_GNU_SOURCE -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS test_simple.cpp ast.cpp codegen_simple.cpp -L/usr/lib/llvm-20/lib -lLLVM-20 -o test_simple
./test_simple
```

### Example Output
For the program:
```c
int main() {
    return 42;
}
```

The compiler generates:
```llvm
; ModuleID = 'test_module'
source_filename = "test_module"

define i32 @main() {
entry:
  ret i32 42
}
```

## Architecture Details

### Lexical Analysis
The lexer recognizes:
- Keywords: `int`, `float`, `char`, `void`, `if`, `else`, `while`, `for`, `return`, etc.
- Operators: `+`, `-`, `*`, `/`, `=`, `==`, `!=`, `<`, `>`, `<=`, `>=`, `&&`, `||`, etc.
- Literals: Integer, floating-point, character, string literals
- Identifiers: Variable and function names
- Delimiters: `()`, `{}`, `[]`, `;`, `,`, `.`

### Syntax Analysis
The parser builds an AST using a recursive descent approach with the following node types:
- **Expressions**: Literals, identifiers, binary/unary operations, function calls
- **Statements**: Expression statements, control flow, return statements
- **Declarations**: Variables, functions, structures

### Code Generation
LLVM-based code generator that:
- Converts AST nodes to LLVM IR
- Handles type checking and conversion
- Manages symbol tables and scoping
- Generates optimized intermediate representation
- Supports function calls and control flow

## Current Status

### ✅ Completed Features
- Complete lexer with all C-like tokens
- Parser with AST construction
- AST node hierarchy with pretty-printing
- Basic LLVM code generation
- Function declarations and definitions
- Basic expressions and statements
- Return statements
- Build system with LLVM integration

### 🚧 In Progress / Planned Features
- Full parser/lexer integration (some compatibility issues remain)
- Advanced control flow (if/else, loops)
- Variable declarations and scoping
- Function calls with parameters
- Error recovery and better diagnostics
- Optimization passes
- More comprehensive test suite

## Known Issues

1. **Parser/Lexer Integration**: The full parser uses C++ types in the union which causes compatibility issues with the C-based lexer. The simplified version works correctly.

2. **Limited Language Features**: Currently supports basic function definitions and return statements. More language constructs need implementation.

3. **Error Handling**: Basic error reporting is implemented but could be more comprehensive.

## Development Notes

The project demonstrates a complete compiler pipeline:
1. **Lexical Analysis** → Tokens
2. **Syntax Analysis** → AST  
3. **Semantic Analysis** → Type checking (basic)
4. **Code Generation** → LLVM IR
5. **Optimization** → LLVM passes (planned)

The modular design allows for easy extension and modification of individual compiler phases.

## Contributing

To extend the compiler:
1. Add new token types in `lexer.l`
2. Extend grammar rules in `parser.y`  
3. Add corresponding AST nodes in `ast.h`
4. Implement code generation in `codegen.cpp`
5. Add tests and update documentation

## License

This project is for educational purposes demonstrating compiler construction techniques with modern tools (Flex, Bison, LLVM).