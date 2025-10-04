#ifndef AST_FULL_H
#define AST_FULL_H

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <unordered_map>

// Forward declarations
class ASTNode;
class Expression;
class Statement;
class Declaration;
class Type;

// Smart pointer types
using ASTNodePtr = std::unique_ptr<ASTNode>;
using ExprPtr = std::unique_ptr<Expression>;
using StmtPtr = std::unique_ptr<Statement>;
using DeclPtr = std::unique_ptr<Declaration>;
using TypePtr = std::unique_ptr<Type>;

// Base AST Node
class ASTNode {
public:
    int line = 0;
    int column = 0;
    
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
    virtual void accept(class ASTVisitor* visitor) = 0;
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
    bool is_volatile = false;
    bool is_unsigned = false;
    
    Type(Kind k) : kind(k) {}
    virtual bool equals(const Type* other) const;
    virtual std::string toString() const;
    virtual int getSize() const;
    virtual int getAlignment() const;
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

class PointerType : public Type {
public:
    TypePtr pointee_type;
    
    PointerType(TypePtr pointee) : Type(POINTER_TYPE), pointee_type(std::move(pointee)) {}
    bool equals(const Type* other) const override;
    std::string toString() const override;
    int getSize() const override;
};

class ArrayType : public Type {
public:
    TypePtr element_type;
    int size;
    bool is_variable_length = false;
    
    ArrayType(TypePtr element, int sz) : Type(ARRAY_TYPE), element_type(std::move(element)), size(sz) {}
    bool equals(const Type* other) const override;
    std::string toString() const override;
    int getSize() const override;
};

class FunctionType : public Type {
public:
    TypePtr return_type;
    std::vector<TypePtr> parameter_types;
    bool is_variadic = false;
    
    FunctionType(TypePtr ret_type) : Type(FUNCTION_TYPE), return_type(std::move(ret_type)) {}
    bool equals(const Type* other) const override;
    std::string toString() const override;
};

class StructType : public Type {
public:
    std::string name;
    std::vector<std::pair<std::string, TypePtr>> members;
    bool is_complete = false;
    
    StructType(const std::string& n) : Type(STRUCT_TYPE), name(n) {}
    bool equals(const Type* other) const override;
    std::string toString() const override;
    int getSize() const override;
    int getMemberOffset(const std::string& member_name) const;
};

// Expression base class
class Expression : public ASTNode {
public:
    TypePtr type;
    bool is_lvalue = false;
    bool is_constant = false;
    
    virtual bool isConstant() const { return is_constant; }
    virtual long long getConstantValue() const { return 0; }
};

// Literal expressions
class IntLiteral : public Expression {
public:
    long long value;
    
    IntLiteral(long long val) : value(val) {
        type = std::make_unique<Type>(Type::INT_TYPE);
        is_constant = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
    bool isConstant() const override { return true; }
    long long getConstantValue() const override { return value; }
};

class FloatLiteral : public Expression {
public:
    double value;
    
    FloatLiteral(double val) : value(val) {
        type = std::make_unique<Type>(Type::DOUBLE_TYPE);
        is_constant = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
    bool isConstant() const override { return true; }
};

class StringLiteral : public Expression {
public:
    std::string value;
    
    StringLiteral(const std::string& val) : value(val) {
        auto char_type = std::make_unique<Type>(Type::CHAR_TYPE);
        type = std::make_unique<ArrayType>(std::move(char_type), val.length() + 1);
        is_constant = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

class CharLiteral : public Expression {
public:
    char value;
    
    CharLiteral(char val) : value(val) {
        type = std::make_unique<Type>(Type::CHAR_TYPE);
        is_constant = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
    bool isConstant() const override { return true; }
    long long getConstantValue() const override { return value; }
};

// Identifier expression
class Identifier : public Expression {
public:
    std::string name;
    class Symbol* symbol = nullptr; // Resolved symbol
    
    Identifier(const std::string& n) : name(n) {
        is_lvalue = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Binary operations
class BinaryOp : public Expression {
public:
    enum Operator {
        // Arithmetic
        ADD, SUB, MUL, DIV, MOD,
        // Comparison
        EQ, NE, LT, LE, GT, GE,
        // Logical
        AND, OR,
        // Bitwise
        BITWISE_AND, BITWISE_OR, BITWISE_XOR, LSHIFT, RSHIFT,
        // Assignment
        ASSIGN, PLUS_ASSIGN, MINUS_ASSIGN, MULT_ASSIGN, DIV_ASSIGN, MOD_ASSIGN,
        LSHIFT_ASSIGN, RSHIFT_ASSIGN, AND_ASSIGN, OR_ASSIGN, XOR_ASSIGN,
        // Other
        COMMA
    };
    
    Operator op;
    ExprPtr left;
    ExprPtr right;
    
    BinaryOp(Operator o, ExprPtr l, ExprPtr r) 
        : op(o), left(std::move(l)), right(std::move(r)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
    bool isAssignmentOp() const;
    bool isComparisonOp() const;
    bool isArithmeticOp() const;
};

// Unary operations
class UnaryOp : public Expression {
public:
    enum Operator {
        PLUS, MINUS, NOT, BITWISE_NOT,
        PRE_INC, PRE_DEC, POST_INC, POST_DEC,
        DEREF, ADDRESS_OF, SIZEOF_EXPR
    };
    
    Operator op;
    ExprPtr operand;
    
    UnaryOp(Operator o, ExprPtr expr) : op(o), operand(std::move(expr)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Conditional (ternary) operator
class ConditionalOp : public Expression {
public:
    ExprPtr condition;
    ExprPtr true_expr;
    ExprPtr false_expr;
    
    ConditionalOp(ExprPtr cond, ExprPtr true_e, ExprPtr false_e)
        : condition(std::move(cond)), true_expr(std::move(true_e)), false_expr(std::move(false_e)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Function call
class FunctionCall : public Expression {
public:
    ExprPtr function;
    std::vector<ExprPtr> arguments;
    
    FunctionCall(ExprPtr func) : function(std::move(func)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Array access
class ArrayAccess : public Expression {
public:
    ExprPtr array;
    ExprPtr index;
    
    ArrayAccess(ExprPtr arr, ExprPtr idx) 
        : array(std::move(arr)), index(std::move(idx)) {
        is_lvalue = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Member access
class MemberAccess : public Expression {
public:
    ExprPtr object;
    std::string member;
    bool is_pointer; // true for ->, false for .
    
    MemberAccess(ExprPtr obj, const std::string& mem, bool ptr) 
        : object(std::move(obj)), member(mem), is_pointer(ptr) {
        is_lvalue = true;
    }
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Cast expression
class CastExpression : public Expression {
public:
    TypePtr cast_type;
    ExprPtr operand;
    
    CastExpression(TypePtr cast_to, ExprPtr expr)
        : cast_type(std::move(cast_to)), operand(std::move(expr)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Sizeof expression
class SizeofExpression : public Expression {
public:
    TypePtr sizeof_type;
    ExprPtr sizeof_expr;
    
    SizeofExpression(TypePtr type_arg) : sizeof_type(std::move(type_arg)) {
        this->type = std::make_unique<Type>(Type::INT_TYPE);
        is_constant = true;
    }
    
    SizeofExpression(ExprPtr expr_arg) : sizeof_expr(std::move(expr_arg)) {
        this->type = std::make_unique<Type>(Type::INT_TYPE);
        is_constant = true;
    }
    
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
    bool isConstant() const override { return true; }
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
    void accept(class ASTVisitor* visitor) override;
};

// Block statement
class Block : public Statement {
public:
    std::vector<StmtPtr> statements;
    class Scope* scope = nullptr;
    
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
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
    void accept(class ASTVisitor* visitor) override;
};

// While statement
class WhileStatement : public Statement {
public:
    ExprPtr condition;
    StmtPtr body;
    
    WhileStatement(ExprPtr cond, StmtPtr b) 
        : condition(std::move(cond)), body(std::move(b)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Do-while statement
class DoWhileStatement : public Statement {
public:
    StmtPtr body;
    ExprPtr condition;
    
    DoWhileStatement(StmtPtr b, ExprPtr cond)
        : body(std::move(b)), condition(std::move(cond)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
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
    void accept(class ASTVisitor* visitor) override;
};

// Switch statement
class SwitchStatement : public Statement {
public:
    ExprPtr expression;
    StmtPtr body;
    
    SwitchStatement(ExprPtr expr, StmtPtr b)
        : expression(std::move(expr)), body(std::move(b)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Case statement
class CaseStatement : public Statement {
public:
    ExprPtr value; // null for default case
    StmtPtr statement;
    
    CaseStatement(ExprPtr val, StmtPtr stmt)
        : value(std::move(val)), statement(std::move(stmt)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Jump statements
class ReturnStatement : public Statement {
public:
    ExprPtr value; // can be null for void return
    
    ReturnStatement(ExprPtr val = nullptr) : value(std::move(val)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

class BreakStatement : public Statement {
public:
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

class ContinueStatement : public Statement {
public:
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

class GotoStatement : public Statement {
public:
    std::string label;
    
    GotoStatement(const std::string& lbl) : label(lbl) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

class LabelStatement : public Statement {
public:
    std::string label;
    StmtPtr statement;
    
    LabelStatement(const std::string& lbl, StmtPtr stmt)
        : label(lbl), statement(std::move(stmt)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
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
    ExprPtr initializer; // can be null
    bool is_extern = false;
    bool is_static = false;
    bool is_register = false;
    bool is_typedef = false;
    
    VariableDeclaration(const std::string& n, TypePtr t, ExprPtr init = nullptr)
        : Declaration(n, std::move(t)), initializer(std::move(init)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
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
    std::unique_ptr<Block> body; // can be null for forward declarations
    bool is_inline = false;
    bool is_static = false;
    bool is_extern = false;
    bool is_variadic = false;
    
    FunctionDeclaration(const std::string& n, TypePtr ret_type)
        : Declaration(n, std::move(ret_type)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Struct/Union declaration
class StructDeclaration : public Declaration {
public:
    std::vector<std::unique_ptr<VariableDeclaration>> members;
    bool is_union = false;
    bool is_complete = false;
    
    StructDeclaration(const std::string& n, bool union_type = false) 
        : Declaration(n, std::make_unique<StructType>(n)), is_union(union_type) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Enum declaration
class EnumDeclaration : public Declaration {
public:
    struct Enumerator {
        std::string name;
        ExprPtr value; // can be null for auto-increment
        long long computed_value = 0;
    };
    
    std::vector<Enumerator> enumerators;
    
    EnumDeclaration(const std::string& n) 
        : Declaration(n, std::make_unique<Type>(Type::ENUM_TYPE)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Typedef declaration
class TypedefDeclaration : public Declaration {
public:
    TypedefDeclaration(const std::string& n, TypePtr t)
        : Declaration(n, std::move(t)) {}
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Program (root of AST)
class Program : public ASTNode {
public:
    std::vector<DeclPtr> declarations;
    
    void print(int indent = 0) const override;
    void accept(class ASTVisitor* visitor) override;
};

// Symbol table and scope management
class Symbol {
public:
    enum Kind {
        VARIABLE,
        FUNCTION,
        TYPE,
        ENUM_CONSTANT,
        LABEL
    };
    
    std::string name;
    Kind kind;
    TypePtr type;
    Declaration* declaration = nullptr;
    bool is_defined = false;
    
    Symbol(const std::string& n, Kind k, TypePtr t)
        : name(n), kind(k), type(std::move(t)) {}
};

class Scope {
public:
    Scope* parent = nullptr;
    std::unordered_map<std::string, std::unique_ptr<Symbol>> symbols;
    
    Symbol* lookup(const std::string& name);
    Symbol* lookupLocal(const std::string& name);
    void define(std::unique_ptr<Symbol> symbol);
    bool isDefined(const std::string& name);
};

class SymbolTable {
public:
    std::unique_ptr<Scope> global_scope;
    Scope* current_scope = nullptr;
    
    SymbolTable();
    void enterScope();
    void exitScope();
    Symbol* lookup(const std::string& name);
    void define(std::unique_ptr<Symbol> symbol);
    void defineBuiltins();
};

// Visitor pattern for AST traversal
class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    
    // Types
    virtual void visit(Type* node) = 0;
    
    // Expressions
    virtual void visit(IntLiteral* node) = 0;
    virtual void visit(FloatLiteral* node) = 0;
    virtual void visit(StringLiteral* node) = 0;
    virtual void visit(CharLiteral* node) = 0;
    virtual void visit(Identifier* node) = 0;
    virtual void visit(BinaryOp* node) = 0;
    virtual void visit(UnaryOp* node) = 0;
    virtual void visit(ConditionalOp* node) = 0;
    virtual void visit(FunctionCall* node) = 0;
    virtual void visit(ArrayAccess* node) = 0;
    virtual void visit(MemberAccess* node) = 0;
    virtual void visit(CastExpression* node) = 0;
    virtual void visit(SizeofExpression* node) = 0;
    
    // Statements
    virtual void visit(ExpressionStatement* node) = 0;
    virtual void visit(Block* node) = 0;
    virtual void visit(IfStatement* node) = 0;
    virtual void visit(WhileStatement* node) = 0;
    virtual void visit(DoWhileStatement* node) = 0;
    virtual void visit(ForStatement* node) = 0;
    virtual void visit(SwitchStatement* node) = 0;
    virtual void visit(CaseStatement* node) = 0;
    virtual void visit(ReturnStatement* node) = 0;
    virtual void visit(BreakStatement* node) = 0;
    virtual void visit(ContinueStatement* node) = 0;
    virtual void visit(GotoStatement* node) = 0;
    virtual void visit(LabelStatement* node) = 0;
    
    // Declarations
    virtual void visit(VariableDeclaration* node) = 0;
    virtual void visit(FunctionDeclaration* node) = 0;
    virtual void visit(StructDeclaration* node) = 0;
    virtual void visit(EnumDeclaration* node) = 0;
    virtual void visit(TypedefDeclaration* node) = 0;
    virtual void visit(Program* node) = 0;
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
std::string typeToString(Type::Kind type);
std::string binOpToString(BinaryOp::Operator op);
std::string unOpToString(UnaryOp::Operator op);
void printIndent(int indent);

#endif // AST_FULL_H