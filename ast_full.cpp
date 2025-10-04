#include "ast_full.h"
#include <iostream>
#include <iomanip>
#include <sstream>

void printIndent(int indent) {
    for (int i = 0; i < indent; i++) {
        std::cout << "  ";
    }
}

// Type implementations
bool Type::equals(const Type* other) const {
    if (!other) return false;
    return kind == other->kind && 
           is_const == other->is_const && 
           is_volatile == other->is_volatile &&
           is_unsigned == other->is_unsigned;
}

std::string Type::toString() const {
    std::string result;
    
    if (is_const) result += "const ";
    if (is_volatile) result += "volatile ";
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

int Type::getSize() const {
    switch (kind) {
        case VOID_TYPE: return 0;
        case CHAR_TYPE: return 1;
        case SHORT_TYPE: return 2;
        case INT_TYPE: return 4;
        case LONG_TYPE: return 8;
        case FLOAT_TYPE: return 4;
        case DOUBLE_TYPE: return 8;
        case POINTER_TYPE: return 8; // 64-bit pointers
        default: return 0;
    }
}

int Type::getAlignment() const {
    return getSize();
}

void Type::print(int indent) const {
    printIndent(indent);
    std::cout << "Type: " << toString() << std::endl;
}

void Type::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// PointerType implementations
bool PointerType::equals(const Type* other) const {
    if (!Type::equals(other)) return false;
    auto ptr_other = dynamic_cast<const PointerType*>(other);
    return ptr_other && pointee_type->equals(ptr_other->pointee_type.get());
}

std::string PointerType::toString() const {
    return pointee_type->toString() + "*";
}

int PointerType::getSize() const {
    return 8; // 64-bit pointers
}

// ArrayType implementations
bool ArrayType::equals(const Type* other) const {
    if (!Type::equals(other)) return false;
    auto arr_other = dynamic_cast<const ArrayType*>(other);
    return arr_other && 
           element_type->equals(arr_other->element_type.get()) &&
           size == arr_other->size;
}

std::string ArrayType::toString() const {
    return element_type->toString() + "[" + std::to_string(size) + "]";
}

int ArrayType::getSize() const {
    return element_type->getSize() * size;
}

// FunctionType implementations
bool FunctionType::equals(const Type* other) const {
    if (!Type::equals(other)) return false;
    auto func_other = dynamic_cast<const FunctionType*>(other);
    if (!func_other || !return_type->equals(func_other->return_type.get()) ||
        parameter_types.size() != func_other->parameter_types.size()) {
        return false;
    }
    
    for (size_t i = 0; i < parameter_types.size(); i++) {
        if (!parameter_types[i]->equals(func_other->parameter_types[i].get())) {
            return false;
        }
    }
    
    return true;
}

std::string FunctionType::toString() const {
    std::string result = return_type->toString() + "(";
    for (size_t i = 0; i < parameter_types.size(); i++) {
        if (i > 0) result += ", ";
        result += parameter_types[i]->toString();
    }
    if (is_variadic) {
        if (!parameter_types.empty()) result += ", ";
        result += "...";
    }
    result += ")";
    return result;
}

// StructType implementations
bool StructType::equals(const Type* other) const {
    if (!Type::equals(other)) return false;
    auto struct_other = dynamic_cast<const StructType*>(other);
    return struct_other && name == struct_other->name;
}

std::string StructType::toString() const {
    return "struct " + name;
}

int StructType::getSize() const {
    if (!is_complete) return 0;
    
    int total_size = 0;
    int max_alignment = 1;
    
    for (const auto& member : members) {
        int member_size = member.second->getSize();
        int member_alignment = member.second->getAlignment();
        
        max_alignment = std::max(max_alignment, member_alignment);
        
        // Align current offset
        if (total_size % member_alignment != 0) {
            total_size += member_alignment - (total_size % member_alignment);
        }
        
        total_size += member_size;
    }
    
    // Align final size to largest member alignment
    if (total_size % max_alignment != 0) {
        total_size += max_alignment - (total_size % max_alignment);
    }
    
    return total_size;
}

int StructType::getMemberOffset(const std::string& member_name) const {
    int offset = 0;
    
    for (const auto& member : members) {
        if (member.first == member_name) {
            return offset;
        }
        
        int member_alignment = member.second->getAlignment();
        if (offset % member_alignment != 0) {
            offset += member_alignment - (offset % member_alignment);
        }
        
        offset += member.second->getSize();
    }
    
    return -1; // Member not found
}

// Expression implementations
void IntLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "IntLiteral: " << value << std::endl;
}

void IntLiteral::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void FloatLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "FloatLiteral: " << std::fixed << std::setprecision(2) << value << std::endl;
}

void FloatLiteral::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void StringLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "StringLiteral: \"" << value << "\"" << std::endl;
}

void StringLiteral::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void CharLiteral::print(int indent) const {
    printIndent(indent);
    std::cout << "CharLiteral: '" << value << "'" << std::endl;
}

void CharLiteral::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void Identifier::print(int indent) const {
    printIndent(indent);
    std::cout << "Identifier: " << name << std::endl;
}

void Identifier::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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

bool BinaryOp::isAssignmentOp() const {
    return op >= ASSIGN && op <= XOR_ASSIGN;
}

bool BinaryOp::isComparisonOp() const {
    return op >= EQ && op <= GE;
}

bool BinaryOp::isArithmeticOp() const {
    return op >= ADD && op <= MOD;
}

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

void BinaryOp::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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
        case UnaryOp::SIZEOF_EXPR: return "sizeof";
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
    } else {
        printIndent(indent + 2);
        std::cout << "null" << std::endl;
    }
}

void UnaryOp::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Conditional operation implementation
void ConditionalOp::print(int indent) const {
    printIndent(indent);
    std::cout << "ConditionalOp: ? :" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Condition:" << std::endl;
    if (condition) condition->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "True:" << std::endl;
    if (true_expr) true_expr->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "False:" << std::endl;
    if (false_expr) false_expr->print(indent + 2);
}

void ConditionalOp::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Function call implementation
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
            if (arg) {
                arg->print(indent + 2);
            }
        }
    }
}

void FunctionCall::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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

void ArrayAccess::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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

void MemberAccess::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Cast expression implementation
void CastExpression::print(int indent) const {
    printIndent(indent);
    std::cout << "CastExpression:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Type:" << std::endl;
    if (cast_type) cast_type->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "Expression:" << std::endl;
    if (operand) operand->print(indent + 2);
}

void CastExpression::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Sizeof expression implementation
void SizeofExpression::print(int indent) const {
    printIndent(indent);
    std::cout << "SizeofExpression:" << std::endl;
    
    if (sizeof_type) {
        printIndent(indent + 1);
        std::cout << "Type:" << std::endl;
        sizeof_type->print(indent + 2);
    }
    
    if (sizeof_expr) {
        printIndent(indent + 1);
        std::cout << "Expression:" << std::endl;
        sizeof_expr->print(indent + 2);
    }
}

void SizeofExpression::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Statement implementations
void ExpressionStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ExpressionStatement:" << std::endl;
    if (expression) {
        expression->print(indent + 1);
    }
}

void ExpressionStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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

void Block::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

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

void IfStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

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

void WhileStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void DoWhileStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "DoWhileStatement:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Body:" << std::endl;
    if (body) {
        body->print(indent + 2);
    }
    
    printIndent(indent + 1);
    std::cout << "Condition:" << std::endl;
    if (condition) {
        condition->print(indent + 2);
    }
}

void DoWhileStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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
    if (body) {
        body->print(indent + 2);
    }
}

void ForStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void SwitchStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "SwitchStatement:" << std::endl;
    
    printIndent(indent + 1);
    std::cout << "Expression:" << std::endl;
    if (expression) expression->print(indent + 2);
    
    printIndent(indent + 1);
    std::cout << "Body:" << std::endl;
    if (body) body->print(indent + 2);
}

void SwitchStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void CaseStatement::print(int indent) const {
    printIndent(indent);
    if (value) {
        std::cout << "CaseStatement:" << std::endl;
        printIndent(indent + 1);
        std::cout << "Value:" << std::endl;
        value->print(indent + 2);
    } else {
        std::cout << "DefaultStatement:" << std::endl;
    }
    
    if (statement) {
        printIndent(indent + 1);
        std::cout << "Statement:" << std::endl;
        statement->print(indent + 2);
    }
}

void CaseStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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

void ReturnStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void BreakStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "BreakStatement" << std::endl;
}

void BreakStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void ContinueStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "ContinueStatement" << std::endl;
}

void ContinueStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void GotoStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "GotoStatement: " << label << std::endl;
}

void GotoStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void LabelStatement::print(int indent) const {
    printIndent(indent);
    std::cout << "LabelStatement: " << label << std::endl;
    
    if (statement) {
        statement->print(indent + 1);
    }
}

void LabelStatement::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Declaration implementations
void VariableDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "VariableDeclaration: ";
    
    if (is_extern) std::cout << "extern ";
    if (is_static) std::cout << "static ";
    if (is_register) std::cout << "register ";
    if (is_typedef) std::cout << "typedef ";
    
    if (decl_type) {
        std::cout << decl_type->toString();
    }
    std::cout << " " << name << std::endl;
    
    if (initializer) {
        printIndent(indent + 1);
        std::cout << "Initializer:" << std::endl;
        initializer->print(indent + 2);
    }
}

void VariableDeclaration::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void FunctionDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "FunctionDeclaration: ";
    
    if (is_inline) std::cout << "inline ";
    if (is_static) std::cout << "static ";
    if (is_extern) std::cout << "extern ";
    
    if (decl_type) {
        std::cout << decl_type->toString();
    }
    std::cout << " " << name << "(";
    
    for (size_t i = 0; i < parameters.size(); i++) {
        if (i > 0) std::cout << ", ";
        std::cout << parameters[i].type->toString() << " " << parameters[i].name;
    }
    
    if (is_variadic) {
        if (!parameters.empty()) std::cout << ", ";
        std::cout << "...";
    }
    
    std::cout << ")" << std::endl;
    
    if (body) {
        printIndent(indent + 1);
        std::cout << "Body:" << std::endl;
        body->print(indent + 2);
    }
}

void FunctionDeclaration::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void StructDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << (is_union ? "UnionDeclaration: " : "StructDeclaration: ") << name << std::endl;
    
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

void StructDeclaration::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void EnumDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "EnumDeclaration: " << name << std::endl;
    
    if (!enumerators.empty()) {
        printIndent(indent + 1);
        std::cout << "Enumerators:" << std::endl;
        for (const auto& enumerator : enumerators) {
            printIndent(indent + 2);
            std::cout << enumerator.name;
            if (enumerator.value) {
                std::cout << " = ";
                enumerator.value->print(0);
            }
            std::cout << " (" << enumerator.computed_value << ")" << std::endl;
        }
    }
}

void EnumDeclaration::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

void TypedefDeclaration::print(int indent) const {
    printIndent(indent);
    std::cout << "TypedefDeclaration: typedef " << decl_type->toString() << " " << name << std::endl;
}

void TypedefDeclaration::accept(ASTVisitor* visitor) {
    visitor->visit(this);
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

void Program::accept(ASTVisitor* visitor) {
    visitor->visit(this);
}

// Symbol table implementations
Symbol* Scope::lookup(const std::string& name) {
    auto it = symbols.find(name);
    if (it != symbols.end()) {
        return it->second.get();
    }
    
    if (parent) {
        return parent->lookup(name);
    }
    
    return nullptr;
}

Symbol* Scope::lookupLocal(const std::string& name) {
    auto it = symbols.find(name);
    return (it != symbols.end()) ? it->second.get() : nullptr;
}

void Scope::define(std::unique_ptr<Symbol> symbol) {
    symbols[symbol->name] = std::move(symbol);
}

bool Scope::isDefined(const std::string& name) {
    return symbols.find(name) != symbols.end();
}

SymbolTable::SymbolTable() {
    global_scope = std::make_unique<Scope>();
    current_scope = global_scope.get();
    defineBuiltins();
}

void SymbolTable::enterScope() {
    auto new_scope = std::make_unique<Scope>();
    new_scope->parent = current_scope;
    current_scope = new_scope.release();
}

void SymbolTable::exitScope() {
    if (current_scope && current_scope->parent) {
        Scope* old_scope = current_scope;
        current_scope = current_scope->parent;
        delete old_scope;
    }
}

Symbol* SymbolTable::lookup(const std::string& name) {
    return current_scope ? current_scope->lookup(name) : nullptr;
}

void SymbolTable::define(std::unique_ptr<Symbol> symbol) {
    if (current_scope) {
        current_scope->define(std::move(symbol));
    }
}

void SymbolTable::defineBuiltins() {
    // Define built-in functions like printf, scanf, malloc, free, etc.
    auto printf_type = std::make_unique<FunctionType>(std::make_unique<Type>(Type::INT_TYPE));
    printf_type->parameter_types.push_back(std::make_unique<PointerType>(std::make_unique<Type>(Type::CHAR_TYPE)));
    printf_type->is_variadic = true;
    
    auto printf_symbol = std::make_unique<Symbol>("printf", Symbol::FUNCTION, std::move(printf_type));
    define(std::move(printf_symbol));
    
    // Add more built-ins as needed
}

std::string typeToString(Type::Kind type) {
    switch (type) {
        case Type::VOID_TYPE: return "void";
        case Type::CHAR_TYPE: return "char";
        case Type::SHORT_TYPE: return "short";
        case Type::INT_TYPE: return "int";
        case Type::LONG_TYPE: return "long";
        case Type::FLOAT_TYPE: return "float";
        case Type::DOUBLE_TYPE: return "double";
        case Type::POINTER_TYPE: return "pointer";
        case Type::ARRAY_TYPE: return "array";
        case Type::FUNCTION_TYPE: return "function";
        case Type::STRUCT_TYPE: return "struct";
        case Type::UNION_TYPE: return "union";
        case Type::ENUM_TYPE: return "enum";
        default: return "unknown";
    }
}