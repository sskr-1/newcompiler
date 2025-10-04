#include "ast.h"
#include <iostream>
#include <iomanip>

void printIndent(int indent) {
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }
}

// Type implementations
std::string Type::toString() const {
    std::string result;
    
    if (is_const) result += "const ";
    if (is_unsigned) result += "unsigned ";
    
    switch (kind) {
        case VOID_TYPE: result += "void"; break;
        case CHAR_TYPE: result += "char"; break;
        case SHORT_TYPE: result += "short"; break;
        case INT_TYPE: result += "int"; break;
        case LONG_TYPE: result += "long"; break;
        case FLOAT_TYPE: result += "float"; break;
        case DOUBLE_TYPE: result += "double"; break;
        case POINTER_TYPE: result += "pointer"; break;
        case ARRAY_TYPE: result += "array"; break;
        case FUNCTION_TYPE: result += "function"; break;
        case STRUCT_TYPE: result += "struct"; break;
        case UNION_TYPE: result += "union"; break;
        case ENUM_TYPE: result += "enum"; break;
    }
    
    return result;
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

// Expression implementations
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
        case BinaryOp::BITWISE_AND: return "&";
        case BinaryOp::BITWISE_OR: return "|";
        case BinaryOp::BITWISE_XOR: return "^";
        case BinaryOp::LSHIFT: return "<<";
        case BinaryOp::RSHIFT: return ">>";
        case BinaryOp::ASSIGN: return "=";
        case BinaryOp::PLUS_ASSIGN: return "+=";
        case BinaryOp::MINUS_ASSIGN: return "-=";
        case BinaryOp::MULT_ASSIGN: return "*=";
        case BinaryOp::DIV_ASSIGN: return "/=";
        case BinaryOp::MOD_ASSIGN: return "%=";
        case BinaryOp::LSHIFT_ASSIGN: return "<<=";
        case BinaryOp::RSHIFT_ASSIGN: return ">>=";
        case BinaryOp::AND_ASSIGN: return "&=";
        case BinaryOp::OR_ASSIGN: return "|=";
        case BinaryOp::XOR_ASSIGN: return "^=";
        case BinaryOp::COMMA: return ",";
        default: return "unknown";
    }
}

void BinaryOp::print(int indent) const {
    printIndent(indent);
    std::cout << "BinaryOp: " << binOpToString(op) << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Left:" << std::endl;
    if (left) {
        left->print(indent + 2);
    }
    
    printIndent(indent + 1);
    std::cout << "Right:" << std::endl;
    if (right) {
        right->print(indent + 2);
    }
}

// Unary operation implementation
std::string unOpToString(UnaryOp::Operator op) {
    switch (op) {
        case UnaryOp::PLUS: return "+";
        case UnaryOp::MINUS: return "-";
        case UnaryOp::NOT: return "!";
        case UnaryOp::BITWISE_NOT: return "~";
        case UnaryOp::PRE_INC: return "++";
        case UnaryOp::PRE_DEC: return "--";
        case UnaryOp::POST_INC: return "++";
        case UnaryOp::POST_DEC: return "--";
        case UnaryOp::DEREF: return "*";
        case UnaryOp::ADDRESS_OF: return "&";
        default: return "unknown";
    }
}

void UnaryOp::print(int indent) const {
    printIndent(indent);
    std::cout << "UnaryOp: " << unOpToString(op) << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Operand:" << std::endl;
    if (operand) {
        operand->print(indent + 2);
    }
}

void FunctionCall::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionCall:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Function:" << std::endl;
    if (function) function->print(indent + 2);
    
    if (!arguments.empty()) {
        printIndent(indent + 1);
        std::cout << "Arguments:" << std::endl;
        for (const auto& arg : arguments) {
            if (arg) arg->print(indent + 2);
        }
    }
}

void ArrayAccess::print(int indent) const {
    printIndent(indent);
    std::cout << "ArrayAccess:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Array:" << std::endl;
    if (array) array->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "Index:" << std::endl;
    if (index) index->print(indent + 2);
}

void MemberAccess::print(int indent) const {
    printIndent(indent);
    std::cout << "MemberAccess: " << (is_pointer ? "->" : ".") << member << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Object:" << std::endl;
    if (object) object->print(indent + 2);
}

// Statement implementations
void ExpressionStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ExpressionStatement:" << std::endl;
    if (expression) {
        expression->print(indent + 1);
    }
}

void Block::print(int indent) const {
    printIndent(indent);
    std::cout << "Block:" << std::endl;
    
    for (const auto& stmt : statements) {
        if (stmt) {
            stmt->print(indent + 1);
        }
    }
}

void IfStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "IfStatement:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Condition:" << std::endl;
    if (condition) condition->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "Then:" << std::endl;
    if (then_stmt) then_stmt->print(indent + 2);
    
    if (else_stmt) {
        printIndent(indent + 1);
        std::cout << "Else:" << std::endl;
        else_stmt->print(indent + 2);
    }
}

void WhileStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "WhileStatement:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Condition:" << std::endl;
    if (condition) condition->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "Body:" << std::endl;
    if (body) body->print(indent + 2);
}

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
    if (body) body->print(indent + 2);
}

void ReturnStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ReturnStatement:" << std::endl;
    
    if (value) {
        printIndent(indent + 1);
        std::cout << "Value:" << std::endl;
        value->print(indent + 2);
    }
}

void BreakStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "BreakStatement" << std::endl;
}

void ContinueStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ContinueStatement" << std::endl;
}

// Declaration implementations
void VariableDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "VariableDeclaration: " << decl_type->toString() << " " << name << std::endl;
    
    if (initializer) {
        printIndent(indent + 1);
        std::cout << "Initializer:" << std::endl;
        initializer->print(indent + 2);
    }
}

void FunctionDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionDeclaration: " << decl_type->toString() << " " << name << "(";
    
    for (size_t i = 0; i < parameters.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << parameters[i].type->toString() << " " << parameters[i].name;
    }
    
    std::cout << ")" << std::endl;
    
    if (body) {
        printIndent(indent + 1);
        std::cout << "Body:" << std::endl;
        body->print(indent + 2);
    }
}

void Program::print(int indent) const {
    printIndent(indent);
    std::cout << "Program:" << std::endl;
    
    for (const auto& decl : declarations) {
        if (decl) {
            decl->print(indent + 1);
        }
    }
}