#include "ast.h"
#include <iostream>

void printIndent(int indent) {
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }
}

std::string Type::toString() const {
    switch (kind) {
        case VOID_TYPE: return "void";
        case CHAR_TYPE: return "char";
        case INT_TYPE: return "int";
        case FLOAT_TYPE: return "float";
        case DOUBLE_TYPE: return "double";
        default: return "unknown";
    }
}

void Type::print(int indent) const {
    printIndent(indent);
    std::cout << "Type: " << toString() << std::endl;
}

std::string PointerType::toString() const {
    return pointee_type->toString() + "*";
}

std::string ArrayType::toString() const {
    return element_type->toString() + "[" + std::to_string(size) + "]";
}

void IntLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "IntLiteral: " << value << std::endl;
}

void FloatLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "FloatLiteral: " << value << std::endl;
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

void BinaryOp::print(int indent) const {
    printIndent(indent);
    std::cout << "BinaryOp" << std::endl;
    if (left) left->print(indent + 1);
    if (right) right->print(indent + 1);
}

void UnaryOp::print(int indent) const {
    printIndent(indent);
    std::cout << "UnaryOp" << std::endl;
    if (operand) operand->print(indent + 1);
}

void FunctionCall::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionCall" << std::endl;
    if (function) function->print(indent + 1);
}

void ArrayAccess::print(int indent) const {
    printIndent(indent);
    std::cout << "ArrayAccess" << std::endl;
    if (array) array->print(indent + 1);
    if (index) index->print(indent + 1);
}

void MemberAccess::print(int indent) const {
    printIndent(indent);
    std::cout << "MemberAccess: " << member << std::endl;
    if (object) object->print(indent + 1);
}

void ExpressionStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ExpressionStatement" << std::endl;
    if (expression) expression->print(indent + 1);
}

void Block::print(int indent) const {
    printIndent(indent);
    std::cout << "Block" << std::endl;
    for (const auto& stmt : statements) {
        if (stmt) stmt->print(indent + 1);
    }
}

void IfStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "IfStatement" << std::endl;
    if (condition) condition->print(indent + 1);
    if (then_stmt) then_stmt->print(indent + 1);
    if (else_stmt) else_stmt->print(indent + 1);
}

void WhileStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "WhileStatement" << std::endl;
    if (condition) condition->print(indent + 1);
    if (body) body->print(indent + 1);
}

void ForStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ForStatement" << std::endl;
    if (init) init->print(indent + 1);
    if (condition) condition->print(indent + 1);
    if (update) update->print(indent + 1);
    if (body) body->print(indent + 1);
}

void ReturnStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ReturnStatement" << std::endl;
    if (value) value->print(indent + 1);
}

void BreakStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "BreakStatement" << std::endl;
}

void ContinueStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ContinueStatement" << std::endl;
}

void VariableDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "VariableDeclaration: " << decl_type->toString() << " " << name << std::endl;
    if (initializer) initializer->print(indent + 1);
}

void FunctionDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionDeclaration: " << decl_type->toString() << " " << name << std::endl;
    if (body) body->print(indent + 1);
}

void Program::print(int indent) const {
    printIndent(indent);
    std::cout << "Program" << std::endl;
    for (const auto& decl : declarations) {
        if (decl) decl->print(indent + 1);
    }
}