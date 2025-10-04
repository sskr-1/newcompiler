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

// Smart pointer types
using ASTNodePtr = std::unique_ptr<ASTNode>;
using ExprPtr = std::unique_ptr<Expression>;
using StmtPtr = std::unique_ptr<Statement>;
using DeclPtr = std::unique_ptr<Declaration>;

// Base AST Node
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

// Expression base class
class Expression : public ASTNode {
public:
    enum Type {
        INT_TYPE,
        FLOAT_TYPE,
        CHAR_TYPE,
        VOID_TYPE,
        POINTER_TYPE,
        ARRAY_TYPE
    };
    
    Type type = INT_TYPE;
};

// Literal expressions
class IntLiteral : public Expression {
public:
    int value;
    
    IntLiteral(int val) : value(val) { type = INT_TYPE; }
    void print(int indent = 0) const override;
};

class FloatLiteral : public Expression {
public:
    double value;
    
    FloatLiteral(double val) : value(val) { type = FLOAT_TYPE; }
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
    
    CharLiteral(char val) : value(val) { type = CHAR_TYPE; }
    void print(int indent = 0) const override;
};

// Identifier expression
class Identifier : public Expression {
public:
    std::string name;
    
    Identifier(const std::string& n) : name(n) {}
    void print(int indent = 0) const override;
};

// Binary operations
class BinaryOp : public Expression {
public:
    enum Operator {
        ADD, SUB, MUL, DIV, MOD,
        EQ, NE, LT, LE, GT, GE,
        AND, OR,
        ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN, MULT_ASSIGN, DIV_ASSIGN
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
        PLUS, MINUS, NOT, PRE_INC, PRE_DEC, POST_INC, POST_DEC,
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
    std::string name;
    std::vector<ExprPtr> arguments;
    
    FunctionCall(const std::string& n) : name(n) {}
    void print(int indent = 0) const override;
};

// Array access
class ArrayAccess : public Expression {
public:
    ExprPtr array;
    ExprPtr index;
    
    ArrayAccess(ExprPtr arr, ExprPtr idx) 
        : array(std::move(arr)), index(std::move(idx)) {}
    void print(int indent = 0) const override;
};

// Member access
class MemberAccess : public Expression {
public:
    ExprPtr object;
    std::string member;
    bool is_pointer; // true for ->, false for .
    
    MemberAccess(ExprPtr obj, const std::string& mem, bool ptr) 
        : object(std::move(obj)), member(mem), is_pointer(ptr) {}
    void print(int indent = 0) const override;
};

// Statement base class
class Statement : public ASTNode {
public:
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
    StmtPtr else_stmt; // can be null
    
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
    StmtPtr init;     // can be null
    ExprPtr condition; // can be null
    ExprPtr update;   // can be null
    StmtPtr body;
    
    ForStatement(StmtPtr i, ExprPtr c, ExprPtr u, StmtPtr b)
        : init(std::move(i)), condition(std::move(c)), update(std::move(u)), body(std::move(b)) {}
    void print(int indent = 0) const override;
};

// Return statement
class ReturnStatement : public Statement {
public:
    ExprPtr value; // can be null for void return
    
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
    Expression::Type type;
    
    Declaration(const std::string& n, Expression::Type t) : name(n), type(t) {}
};

// Variable declaration
class VariableDeclaration : public Declaration {
public:
    ExprPtr initializer; // can be null
    bool is_array;
    int array_size;
    
    VariableDeclaration(const std::string& n, Expression::Type t, ExprPtr init = nullptr)
        : Declaration(n, t), initializer(std::move(init)), is_array(false), array_size(0) {}
    void print(int indent = 0) const override;
};

// Parameter for function declarations
struct Parameter {
    std::string name;
    Expression::Type type;
    bool is_array;
    
    Parameter(const std::string& n, Expression::Type t, bool arr = false)
        : name(n), type(t), is_array(arr) {}
};

// Function declaration
class FunctionDeclaration : public Declaration {
public:
    std::vector<Parameter> parameters;
    std::unique_ptr<Block> body; // can be null for forward declarations
    
    FunctionDeclaration(const std::string& n, Expression::Type ret_type)
        : Declaration(n, ret_type) {}
    void print(int indent = 0) const override;
};

// Struct declaration
class StructDeclaration : public Declaration {
public:
    std::vector<std::unique_ptr<VariableDeclaration>> members;
    
    StructDeclaration(const std::string& n) : Declaration(n, Expression::VOID_TYPE) {}
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
    int int_val;
    double float_val;
    char char_val;
    char* str_val;
    ASTNode* node;
    Expression* expr;
    Statement* stmt;
    Declaration* decl;
    Program* program;
    Block* block;
    std::vector<Parameter>* param_list;
    Parameter* param;
    Expression::Type type;
    BinaryOp::Operator bin_op;
    UnaryOp::Operator un_op;
};

#define YYSTYPE_IS_DECLARED 1

// Helper functions
std::string typeToString(Expression::Type type);
std::string binOpToString(BinaryOp::Operator op);
std::string unOpToString(UnaryOp::Operator op);

#endif // AST_H