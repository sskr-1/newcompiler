# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -O0

# Flex and Bison
FLEX = flex
BISON = bison

# Object files
OBJECTS = main.o ast.o lexer.yy.o parser.tab.o
TARGET = compiler

# Generated files
LEXER_SRC = lexer.yy.cc
PARSER_SRC = parser.tab.cc
PARSER_HDR = parser.tab.h

.PHONY: all clean test test-lexer test-parser test-ast test-components

all: $(TARGET)

# Generate lexer from flex file
$(LEXER_SRC): lexer.l
	$(FLEX) --outfile=$@ $<

# Generate parser from bison file
$(PARSER_SRC) $(PARSER_HDR): parser_simple.y
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
test-ast: ast.h ast.cpp
	@echo "Testing AST compilation..."
	$(CXX) $(CXXFLAGS) -c ast.cpp -o ast.o
	@echo "✓ AST compiled successfully"

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.cc
	$(CXX) $(CXXFLAGS) -Wno-unused-function -Wno-sign-compare -c $< -o $@

# Special compilation for generated files
lexer.yy.o: $(LEXER_SRC) $(PARSER_HDR)
	$(CXX) $(CXXFLAGS) -Wno-unused-function -Wno-sign-compare -Wno-register -c $< -o $@

parser.tab.o: $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) -Wno-unused-function -c $< -o $@

# Link the final executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@

# Test all components
test-components: test-lexer test-parser test-ast
	@echo "✓ All components tested successfully"

# Test with sample program
test: $(TARGET)
	@echo "Creating test program..."
	@echo 'int main() { return 42; }' > test.c
	@echo "Testing compiler..."
	./$(TARGET) -ast test.c
	@echo "Test completed."

# Clean build files
clean:
	rm -f *.o $(TARGET) $(LEXER_SRC) $(PARSER_SRC) $(PARSER_HDR)
	rm -f test.c *.output

# Show what files we have
info:
	@echo "Essential files:"
	@ls -la *.l *.y *.h *.cpp Makefile 2>/dev/null || true