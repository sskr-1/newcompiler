#!/bin/bash

echo "=== Compiler Test Suite ==="
echo

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Test counters
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# Function to run a test
run_test() {
    local test_name=$1
    local test_file=$2
    local expected_result=$3
    
    echo -n "Testing $test_name... "
    TOTAL_TESTS=$((TOTAL_TESTS + 1))
    
    # Test lexer only
    if [ -f "./test_lexer" ]; then
        echo -n "[LEXER] "
        if cat "$test_file" | ./test_lexer > /dev/null 2>&1; then
            echo -n "✓ "
        else
            echo -n "✗ "
        fi
    fi
    
    # Test parser (if available)
    if [ -f "./compiler" ]; then
        echo -n "[PARSER] "
        if ./compiler -ast "$test_file" > /dev/null 2>&1; then
            echo -n "✓ "
            PASSED_TESTS=$((PASSED_TESTS + 1))
        else
            echo -n "✗ "
            FAILED_TESTS=$((FAILED_TESTS + 1))
        fi
    else
        echo -n "[PARSER] N/A "
    fi
    
    echo
}

# Create test directory if it doesn't exist
mkdir -p test_cases

echo "1. Testing Lexer Components"
echo "=========================="

# Test basic lexer
echo "Testing basic lexer functionality..."
if [ -f "./test_lexer" ]; then
    echo "int main() { return 42; }" | ./test_lexer
    echo
else
    echo "Basic lexer test not available"
    echo
fi

echo "2. Testing Parser Components"
echo "============================"

# Test parser generation
if make test-parser > /dev/null 2>&1; then
    echo -e "${GREEN}✓ Parser generation successful${NC}"
else
    echo -e "${RED}✗ Parser generation failed${NC}"
fi

echo

echo "3. Testing AST Components"
echo "========================="

# Test AST compilation
if make test-ast > /dev/null 2>&1; then
    echo -e "${GREEN}✓ AST compilation successful${NC}"
else
    echo -e "${RED}✗ AST compilation failed${NC}"
fi

echo

echo "4. Running Test Cases"
echo "===================="

# Run individual test cases
run_test "Simple Function" "test_cases/test1_simple.c" "success"
run_test "Variables" "test_cases/test2_variables.c" "success"
run_test "Control Flow" "test_cases/test3_control_flow.c" "success"
run_test "Loops" "test_cases/test4_loops.c" "success"
run_test "Arrays" "test_cases/test5_arrays.c" "success"
run_test "Pointers" "test_cases/test6_pointers.c" "success"
run_test "Structs" "test_cases/test7_structs.c" "success"
run_test "Complex Program" "test_cases/test8_complex.c" "success"

echo
echo "5. Test Summary"
echo "==============="
echo "Total tests: $TOTAL_TESTS"
echo -e "Passed: ${GREEN}$PASSED_TESTS${NC}"
echo -e "Failed: ${RED}$FAILED_TESTS${NC}"

if [ $FAILED_TESTS -eq 0 ]; then
    echo -e "${GREEN}All tests passed!${NC}"
    exit 0
else
    echo -e "${RED}Some tests failed.${NC}"
    exit 1
fi