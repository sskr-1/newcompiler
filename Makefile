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
SOURCES = main.cpp ast.cpp codegen.cpp lexer.cpp parser.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = compiler

# Generated files
LEXER_SRC = lexer.cpp
PARSER_SRC = parser.cpp
PARSER_HDR = parser.tab.h

.PHONY: all clean test install

all: $(TARGET)

# Generate lexer from flex file
$(LEXER_SRC): lexer_simple.l
	$(FLEX) -o $@ $<

# Generate parser from bison file
$(PARSER_SRC) $(PARSER_HDR): parser.y
	$(BISON) -d -o $(PARSER_SRC) $<

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -c $< -o $@

# Special compilation for generated files (disable some warnings)
lexer.o: $(LEXER_SRC)
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -Wno-unused-function -Wno-sign-compare -c $< -o $@

parser.o: $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) $(LLVM_CXXFLAGS) -Wno-unused-function -c $< -o $@

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) $(LDFLAGS) $(LLVM_LDFLAGS) -o $@

# Test with a simple program
test: $(TARGET)
	@echo "Creating test program..."
	@echo 'int main() { return 42; }' > test.c
	@echo "Testing compiler..."
	./$(TARGET) -ast test.c
	@echo "Test completed."

# Install dependencies (Ubuntu/Debian)
install-deps:
	sudo apt-get update
	sudo apt-get install -y flex bison llvm-dev clang build-essential

# Clean build files
clean:
	rm -f $(OBJECTS) $(TARGET) $(LEXER_SRC) $(PARSER_SRC) $(PARSER_HDR)
	rm -f test.c test.o test.s
	rm -f *.output *.tab.c *.tab.h

# Debug build
debug: CXXFLAGS += -DDEBUG -g3
debug: $(TARGET)

# Release build
release: CXXFLAGS = -std=c++14 -O3 -DNDEBUG
release: $(TARGET)

# Show compiler info
info:
	@echo "Compiler: $(CXX)"
	@echo "LLVM Config: $(LLVM_CONFIG)"
	@echo "LLVM Version: $(shell $(LLVM_CONFIG) --version)"
	@echo "LLVM CXX Flags: $(LLVM_CXXFLAGS)"
	@echo "LLVM LD Flags: $(LLVM_LDFLAGS)"