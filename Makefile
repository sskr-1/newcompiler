# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O0
LDFLAGS = 

# LLVM settings
LLVM_CONFIG = llvm-config-20
LLVM_CXXFLAGS = $(shell $(LLVM_CONFIG) --cxxflags)
LLVM_LDFLAGS = $(shell $(LLVM_CONFIG) --ldflags --libs core executionengine mcjit interpreter analysis native bitwriter)

# Flex and Bison
FLEX = flex
BISON = bison

# Source files
SOURCES = main.cpp ast_full.cpp codegen_full.cpp lexer.yy.cc parser.tab.cc
OBJECTS = $(SOURCES:.cpp=.o) $(SOURCES:.cc=.o)
TARGET = compiler

# Generated files
LEXER_SRC = lexer.yy.cc
PARSER_SRC = parser.tab.cc
PARSER_HDR = parser.tab.h

.PHONY: all clean test test-lexer test-parser test-ast test-codegen

all: $(TARGET)

# Generate lexer from flex file
$(LEXER_SRC): lexer.l
	$(FLEX) --outfile=$@ $<

# Generate parser from bison file
$(PARSER_SRC) $(PARSER_HDR): parser.y
	$(BISON) --output=$(PARSER_SRC) --defines=$(PARSER_HDR) $<

# Test lexer generation
test-lexer: $(LEXER_SRC)
	@echo "✓ Lexer generated successfully"
	@echo "Generated files:"
	@ls -la $(LEXER_SRC)

# Test parser generation
test-parser: $(PARSER_SRC) $(PARSER_HDR)
	@echo "✓ Parser generated successfully"
	@echo "Generated files:"
	@ls -la $(PARSER_SRC) $(PARSER_HDR)

# Test AST compilation
test-ast: ast_full.cpp ast_full.h
	@echo "Testing AST compilation..."
	$(CXX) $(CXXFLAGS) -c ast_full.cpp -o ast_full.o
	@echo "✓ AST compiled successfully"

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -Wno-unused-function -Wno-sign-compare -c $< -o $@

# Special compilation for generated files (disable some warnings)
lexer.yy.o: $(LEXER_SRC) $(PARSER_HDR)
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -Wno-unused-function -Wno-sign-compare -Wno-register -c $< -o $@

parser.tab.o: $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -Wno-unused-function -c $< -o $@

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LLVM_LDFLAGS) -o $@

# Test individual components
test-components: test-lexer test-parser test-ast
	@echo "✓ All components tested successfully"

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET) $(LEXER_SRC) $(PARSER_SRC) $(PARSER_HDR)
	rm -f test.c test.o test.s
	rm -f *.output

# Show compiler info
info:
	@echo "Compiler: $(CXX)"
	@echo "LLVM Config: $(LLVM_CONFIG)"
	@echo "LLVM Version: $(shell $(LLVM_CONFIG) --version)"
	@echo "LLVM CXX Flags: $(LLVM_CXXFLAGS)"
	@echo "LLVM LD Flags: $(LLVM_LDFLAGS)"