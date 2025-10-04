#!/bin/bash

echo "=== Compiler Test Suite ==="
echo

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m' # No Color

echo "1. Testing Component Generation"
echo "==============================="

# Test parser generation
echo -n "Parser generation... "
if make test-parser > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
    exit 1
fi

# Test lexer generation
echo -n "Lexer generation... "
if make test-lexer > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
    exit 1
fi

# Test AST compilation
echo -n "AST compilation... "
if make test-ast > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
    exit 1
fi

echo

echo "2. Testing Full Compilation"
echo "==========================="

# Test full compiler build
echo -n "Full compiler build... "
if make > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
    exit 1
fi

echo

echo "3. Testing Sample Programs"
echo "=========================="

# Test simple program
echo -n "Simple function... "
if ./compiler -ast test_cases/test1_simple.c > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
fi

echo -n "Variables... "
if ./compiler -ast test_cases/test2_variables.c > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
fi

echo -n "Control flow... "
if ./compiler -ast test_cases/test3_control_flow.c > /dev/null 2>&1; then
    echo -e "${GREEN}✓${NC}"
else
    echo -e "${RED}✗${NC}"
fi

echo

echo -e "${GREEN}All tests completed!${NC}"