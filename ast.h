#ifndef AST_H
#define AST_H

#include <string>
#include <vector>
#include <memory>

// Forward declarations
class ASTNode;
class Expression;
class Statement;
class Declaration;
class Type;

// Smart pointer types
using ExprPtr = std::unique_ptr<Expression>;
using StmtPtr = std::unique_ptr<Statement>;
using DeclPtr = std::unique_ptr<Declaration>;
using TypePtr = std::unique_ptr<Type>;

// Base AST Node
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

// Type system
class Type : public ASTNode {
public:
    enum Kind {
        VOID_TYPE,
        CHAR_TYPE,
        SHORT_TYPE,
        INT_TYPE,
        LONG_TYPE,
        FLOAT_TYPE,
        DOUBLE_TYPE,
        POINTER_TYPE,
        ARRAY_TYPE,
        FUNCTION_TYPE,
        STRUCT_TYPE,
        UNION_TYPE,
        ENUM_TYPE
    };
    
    Kind kind;
    bool is_const = false;
    bool is_unsigned = false;
    
    Type(Kind k) : kind(k) {}
    virtual std::string toString() const;
    void print(int indent = 0) const override;
};

class PointerType : public Type {
public:
    TypePtr pointee_type;
    
    PointerType(TypePtr pointee) : Type(POINTER_TYPE), pointee_type(std::move(pointee)) {}
    std::string toString() const override;
};

class ArrayType : public Type {
public:
    TypePtr element_type;
    int size;
    
    ArrayType(TypePtr element, int sz) : Type(ARRAY_TYPE), element_type(std::move(element)), size(sz) {}
    std::string toString() const override;
};

// Expression base class
class Expression : public ASTNode {
public:
    TypePtr type;
    bool is_lvalue = false;
};

// Literal expressions
class IntLiteral : public Expression {
public:
    long long value;
    
    IntLiteral(long long val) : value(val) {}
    void print(int indent = 0) const override;
};

class FloatLiteral : public Expression {
public:
    double value;
    
    FloatLiteral(double val) : value(val) {}
    void print(int indent = 0) const override;
};

class StringLiteral : public Expression {
public:
    std::string value;
    
    StringLiteral(const std::string& val) : value(val) {}
    void print(int indent = 0) const override;
};

class CharLiteral : public Expression {
public:
    char value;
    
    CharLiteral(char val) : value(val) {}
    void print(int indent = 0) const override;
};

class Identifier : public Expression {
public:
    std::string name;
    
    Identifier(const std::string& n) : name(n) { is_lvalue = true; }
    void print(int indent = 0) const override;
};

// Binary operations
class BinaryOp : public Expression {
public:
    enum Operator {
        ADD, SUB, MUL, DIV, MOD,
        EQ, NE, LT, LE, GT, GE,
        AND, OR,
        BITWISE_AND, BITWISE_OR, BITWISE_XOR, LSHIFT, RSHIFT,
        ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN, MULT_ASSIGN, DIV_ASSIGN, MOD_ASSIGN,
        LSHIFT_ASSIGN, RSHIFT_ASSIGN, AND_ASSIGN, OR_ASSIGN, XOR_ASSIGN,
        COMMA
    };
    
    Operator op;
    ExprPtr left;
    ExprPtr right;
    
    BinaryOp(Operator o, ExprPtr l, ExprPtr r) 
        : op(o), left(std::move(l)), right(std::move(r)) {}
    void print(int indent = 0) const override;
};

// Unary operations
class UnaryOp : public Expression {
public:
    enum Operator {
        PLUS, MINUS, NOT, BITWISE_NOT,
        PRE_INC, PRE_DEC, POST_INC, POST_DEC,
        DEREF, ADDRESS_OF
    };
    
    Operator op;
    ExprPtr operand;
    
    UnaryOp(Operator o, ExprPtr expr) : op(o), operand(std::move(expr)) {}
    void print(int indent = 0) const override;
};

// Function call
class FunctionCall : public Expression {
public:
    ExprPtr function;
    std::vector<ExprPtr> arguments;
    
    FunctionCall(ExprPtr func) : function(std::move(func)) {}
    void print(int indent = 0) const override;
};

// Array access
class ArrayAccess : public Expression {
public:
    ExprPtr array;
    ExprPtr index;
    
    ArrayAccess(ExprPtr arr, ExprPtr idx) 
        : array(std::move(arr)), index(std::move(idx)) { is_lvalue = true; }
    void print(int indent = 0) const override;
};

// Member access
class MemberAccess : public Expression {
public:
    ExprPtr object;
    std::string member;
    bool is_pointer;
    
    MemberAccess(ExprPtr obj, const std::string& mem, bool ptr) 
        : object(std::move(obj)), member(mem), is_pointer(ptr) { is_lvalue = true; }
    void print(int indent = 0) const override;
};

// Statement base class
class Statement : public ASTNode {
};

// Expression statement
class ExpressionStatement : public Statement {
public:
    ExprPtr expression;
    
    ExpressionStatement(ExprPtr expr) : expression(std::move(expr)) {}
    void print(int indent = 0) const override;
};

// Block statement
class Block : public Statement {
public:
    std::vector<StmtPtr> statements;
    
    void print(int indent = 0) const override;
};

// If statement
class IfStatement : public Statement {
public:
    ExprPtr condition;
    StmtPtr then_stmt;
    StmtPtr else_stmt;
    
    IfStatement(ExprPtr cond, StmtPtr then_s, StmtPtr else_s = nullptr)
        : condition(std::move(cond)), then_stmt(std::move(then_s)), else_stmt(std::move(else_s)) {}
    void print(int indent = 0) const override;
};

// While statement
class WhileStatement : public Statement {
public:
    ExprPtr condition;
    StmtPtr body;
    
    WhileStatement(ExprPtr cond, StmtPtr b) 
        : condition(std::move(cond)), body(std::move(b)) {}
    void print(int indent = 0) const override;
};

// For statement
class ForStatement : public Statement {
public:
    StmtPtr init;
    ExprPtr condition;
    ExprPtr update;
    StmtPtr body;
    
    ForStatement(StmtPtr i, ExprPtr c, ExprPtr u, StmtPtr b)
        : init(std::move(i)), condition(std::move(c)), update(std::move(u)), body(std::move(b)) {}
    void print(int indent = 0) const override;
};

// Return statement
class ReturnStatement : public Statement {
public:
    ExprPtr value;
    
    ReturnStatement(ExprPtr val = nullptr) : value(std::move(val)) {}
    void print(int indent = 0) const override;
};

// Break/Continue statements
class BreakStatement : public Statement {
public:
    void print(int indent = 0) const override;
};

class ContinueStatement : public Statement {
public:
    void print(int indent = 0) const override;
};

// Declaration base class
class Declaration : public Statement {
public:
    std::string name;
    TypePtr decl_type;
    
    Declaration(const std::string& n, TypePtr t) : name(n), decl_type(std::move(t)) {}
};

// Variable declaration
class VariableDeclaration : public Declaration {
public:
    ExprPtr initializer;
    
    VariableDeclaration(const std::string& n, TypePtr t, ExprPtr init = nullptr)
        : Declaration(n, std::move(t)), initializer(std::move(init)) {}
    void print(int indent = 0) const override;
};

// Parameter for function declarations
struct Parameter {
    std::string name;
    TypePtr type;
    
    Parameter(const std::string& n, TypePtr t)
        : name(n), type(std::move(t)) {}
};

// Function declaration
class FunctionDeclaration : public Declaration {
public:
    std::vector<Parameter> parameters;
    std::unique_ptr<Block> body;
    
    FunctionDeclaration(const std::string& n, TypePtr ret_type)
        : Declaration(n, std::move(ret_type)) {}
    void print(int indent = 0) const override;
};

// Program (root of AST)
class Program : public ASTNode {
public:
    std::vector<DeclPtr> declarations;
    
    void print(int indent = 0) const override;
};

// Union type for parser
union YYSTYPE {
    long long int_val;
    double float_val;
    double double_val;
    char char_val;
    char* str_val;
    
    ASTNode* node;
    Expression* expr;
    Statement* stmt;
    Declaration* decl;
    Program* program;
    Block* block;
    Type* type_node;
    
    std::vector<Parameter>* param_list;
    Parameter* param;
    std::vector<ExprPtr>* expr_list;
    std::vector<StmtPtr>* stmt_list;
    std::vector<DeclPtr>* decl_list;
    
    BinaryOp::Operator bin_op;
    UnaryOp::Operator un_op;
    Type::Kind type_kind;
};

#define YYSTYPE_IS_DECLARED 1

// Helper functions
void printIndent(int indent);

#endif // AST_H