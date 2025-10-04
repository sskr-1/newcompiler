#include "ast.h"
#include <iostream>
#include <iomanip>

void printIndent(int indent) {
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }
}

// Helper functions
std::string typeToString(Expression::Type type) {
    switch (type) {
        case Expression::INT_TYPE: return "int";
        case Expression::FLOAT_TYPE: return "float";
        case Expression::CHAR_TYPE: return "char";
        case Expression::VOID_TYPE: return "void";
        case Expression::POINTER_TYPE: return "pointer";
        case Expression::ARRAY_TYPE: return "array";
        default: return "unknown";
    }
}

std::string binOpToString(BinaryOp::Operator op) {
    switch (op) {
        case BinaryOp::ADD: return "+";
        case BinaryOp::SUB: return "-";
        case BinaryOp::MUL: return "*";
        case BinaryOp::DIV: return "/";
        case BinaryOp::MOD: return "%";
        case BinaryOp::EQ: return "==";
        case BinaryOp::NE: return "!=";
        case BinaryOp::LT: return "<";
        case BinaryOp::LE: return "<=";
        case BinaryOp::GT: return ">";
        case BinaryOp::GE: return ">=";
        case BinaryOp::AND: return "&&";
        case BinaryOp::OR: return "||";
        case BinaryOp::ASSIGN: return "=";
        case BinaryOp::PLUS_ASSIGN: return "+=";
        case BinaryOp::MINUS_ASSIGN: return "-=";
        case BinaryOp::MULT_ASSIGN: return "*=";
        case BinaryOp::DIV_ASSIGN: return "/=";
        default: return "unknown";
    }
}

std::string unOpToString(UnaryOp::Operator op) {
    switch (op) {
        case UnaryOp::PLUS: return "+";
        case UnaryOp::MINUS: return "-";
        case UnaryOp::NOT: return "!";
        case UnaryOp::PRE_INC: return "++";
        case UnaryOp::PRE_DEC: return "--";
        case UnaryOp::POST_INC: return "++";
        case UnaryOp::POST_DEC: return "--";
        case UnaryOp::DEREF: return "*";
        case UnaryOp::ADDRESS_OF: return "&";
        default: return "unknown";
    }
}

// Literal implementations
void IntLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "IntLiteral: " << value << std::endl;
}

void FloatLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "FloatLiteral: " << std::fixed << std::setprecision(2) << value << std::endl;
}

void StringLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "StringLiteral: \"" << value << "\"" << std::endl;
}

void CharLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "CharLiteral: '" << value << "'" << std::endl;
}

void Identifier::print(int indent) const {
    printIndent(indent);
    std::cout << "Identifier: " << name << std::endl;
}

// Binary operation implementation
void BinaryOp::print(int indent) const {
    printIndent(indent);
    std::cout << "BinaryOp: " << binOpToString(op) << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Left:" << std::endl;
    if (left) {
        left->print(indent + 2);
    } else {
        printIndent(indent + 2);
        std::cout << "null" << std::endl;
    }
    
    printIndent(indent + 1);
    std::cout << "Right:" << std::endl;
    if (right) {
        right->print(indent + 2);
    } else {
        printIndent(indent + 2);
        std::cout << "null" << std::endl;
    }
}

// Unary operation implementation
void UnaryOp::print(int indent) const {
    printIndent(indent);
    std::cout << "UnaryOp: " << unOpToString(op) << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Operand:" << std::endl;
    if (operand) {
        operand->print(indent + 2);
    } else {
        printIndent(indent + 2);
        std::cout << "null" << std::endl;
    }
}

// Function call implementation
void FunctionCall::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionCall: " << name << std::endl;
    
    if (!arguments.empty()) {
        printIndent(indent + 1);
        std::cout << "Arguments:" << std::endl;
        for (const auto& arg : arguments) {
            if (arg) {
                arg->print(indent + 2);
            }
        }
    }
}

// Array access implementation
void ArrayAccess::print(int indent) const {
    printIndent(indent);
    std::cout << "ArrayAccess:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Array:" << std::endl;
    if (array) {
        array->print(indent + 2);
    }
    
    printIndent(indent + 1);
    std::cout << "Index:" << std::endl;
    if (index) {
        index->print(indent + 2);
    }
}

// Member access implementation
void MemberAccess::print(int indent) const {
    printIndent(indent);
    std::cout << "MemberAccess: " << (is_pointer ? "->" : ".") << member << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Object:" << std::endl;
    if (object) {
        object->print(indent + 2);
    }
}

// Expression statement implementation
void ExpressionStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ExpressionStatement:" << std::endl;
    if (expression) {
        expression->print(indent + 1);
    }
}

// Block implementation
void Block::print(int indent) const {
    printIndent(indent);
    std::cout << "Block:" << std::endl;
    
    for (const auto& stmt : statements) {
        if (stmt) {
            stmt->print(indent + 1);
        }
    }
}

// If statement implementation
void IfStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "IfStatement:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Condition:" << std::endl;
    if (condition) {
        condition->print(indent + 2);
    }
    
    printIndent(indent + 1);
    std::cout << "Then:" << std::endl;
    if (then_stmt) {
        then_stmt->print(indent + 2);
    }
    
    if (else_stmt) {
        printIndent(indent + 1);
        std::cout << "Else:" << std::endl;
        else_stmt->print(indent + 2);
    }
}

// While statement implementation
void WhileStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "WhileStatement:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Condition:" << std::endl;
    if (condition) {
        condition->print(indent + 2);
    }
    
    printIndent(indent + 1);
    std::cout << "Body:" << std::endl;
    if (body) {
        body->print(indent + 2);
    }
}

// For statement implementation
void ForStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ForStatement:" << std::endl;
    
    if (init) {
        printIndent(indent + 1);
        std::cout << "Init:" << std::endl;
        init->print(indent + 2);
    }
    
    if (condition) {
        printIndent(indent + 1);
        std::cout << "Condition:" << std::endl;
        condition->print(indent + 2);
    }
    
    if (update) {
        printIndent(indent + 1);
        std::cout << "Update:" << std::endl;
        update->print(indent + 2);
    }
    
    printIndent(indent + 1);
    std::cout << "Body:" << std::endl;
    if (body) {
        body->print(indent + 2);
    }
}

// Return statement implementation
void ReturnStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ReturnStatement:" << std::endl;
    
    if (value) {
        printIndent(indent + 1);
        std::cout << "Value:" << std::endl;
        value->print(indent + 2);
    }
}

// Break statement implementation
void BreakStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "BreakStatement" << std::endl;
}

// Continue statement implementation
void ContinueStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ContinueStatement" << std::endl;
}

// Variable declaration implementation
void VariableDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "VariableDeclaration: " << typeToString(type) << " " << name;
    
    if (is_array) {
        std::cout << "[" << array_size << "]";
    }
    
    std::cout << std::endl;
    
    if (initializer) {
        printIndent(indent + 1);
        std::cout << "Initializer:" << std::endl;
        initializer->print(indent + 2);
    }
}

// Function declaration implementation
void FunctionDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionDeclaration: " << typeToString(type) << " " << name << "(";
    
    for (size_t i = 0; i < parameters.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << typeToString(parameters[i].type) << " " << parameters[i].name;
        if (parameters[i].is_array) {
            std::cout << "[]";
        }
    }
    
    std::cout << ")" << std::endl;
    
    if (body) {
        printIndent(indent + 1);
        std::cout << "Body:" << std::endl;
        body->print(indent + 2);
    }
}

// Struct declaration implementation
void StructDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "StructDeclaration: " << name << std::endl;
    
    if (!members.empty()) {
        printIndent(indent + 1);
        std::cout << "Members:" << std::endl;
        for (const auto& member : members) {
            if (member) {
                member->print(indent + 2);
            }
        }
    }
}

// Program implementation
void Program::print(int indent) const {
    printIndent(indent);
    std::cout << "Program:" << std::endl;
    
    for (const auto& decl : declarations) {
        if (decl) {
            decl->print(indent + 1);
        }
    }
}