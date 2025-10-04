%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

Program* root = nullptr;
%}

%union {
    long long int_val;
    double float_val;
    double double_val;
    char char_val;
    char* str_val;
    
    void* node;
    void* expr;
    void* stmt;
    void* decl;
    void* program;
    void* block;
    void* type_node;
    
    int bin_op;
    int un_op;
    int type_kind;
}

/* Tokens */
%token <int_val> INT_LITERAL
%token <float_val> FLOAT_LITERAL
%token <double_val> DOUBLE_LITERAL
%token <str_val> STRING_LITERAL IDENTIFIER
%token <char_val> CHAR_LITERAL

/* Keywords */
%token AUTO BREAK CASE CHAR_TYPE CONST CONTINUE DEFAULT DO DOUBLE_TYPE
%token ELSE ENUM EXTERN FLOAT_TYPE FOR GOTO IF INLINE INT LONG
%token REGISTER RESTRICT RETURN SHORT SIGNED SIZEOF STATIC STRUCT
%token SWITCH TYPEDEF UNION UNSIGNED VOID VOLATILE WHILE

/* Operators */
%token PLUS MINUS MULT DIV MOD INC DEC
%token ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%token LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN
%token EQ NE LT LE GT GE
%token AND OR NOT
%token BITWISE_AND BITWISE_OR BITWISE_XOR BITWISE_NOT LSHIFT RSHIFT
%token QUESTION COLON

/* Delimiters */
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT ARROW

/* Non-terminals */
%type <program> program
%type <decl> declaration function_definition
%type <type_node> type_specifier
%type <block> compound_statement
%type <stmt> statement expression_statement selection_statement
%type <stmt> iteration_statement jump_statement
%type <expr> expression assignment_expression conditional_expression
%type <expr> logical_or_expression logical_and_expression equality_expression
%type <expr> relational_expression additive_expression multiplicative_expression
%type <expr> unary_expression postfix_expression primary_expression constant
%type <un_op> unary_operator
%type <bin_op> assignment_operator

/* Operator precedence */
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left MULT DIV MOD
%right NOT INC DEC
%left DOT ARROW LBRACKET LPAREN

%%

program:
    declaration {
        root = new Program();
        if ($1) {
            root->declarations.push_back(std::unique_ptr<Declaration>((Declaration*)$1));
        }
        $$ = root;
    }
    | program declaration {
        if ($2) {
            root->declarations.push_back(std::unique_ptr<Declaration>((Declaration*)$2));
        }
        $$ = root;
    }
    ;

declaration:
    function_definition { $$ = $1; }
    | type_specifier IDENTIFIER SEMICOLON {
        auto var_decl = new VariableDeclaration($2, std::unique_ptr<Type>((Type*)$1));
        $$ = var_decl;
        free($2);
    }
    | type_specifier IDENTIFIER ASSIGN assignment_expression SEMICOLON {
        auto var_decl = new VariableDeclaration($2, std::unique_ptr<Type>((Type*)$1), 
                                               std::unique_ptr<Expression>((Expression*)$4));
        $$ = var_decl;
        free($2);
    }
    ;

function_definition:
    type_specifier IDENTIFIER LPAREN RPAREN compound_statement {
        auto func_decl = new FunctionDeclaration($2, std::unique_ptr<Type>((Type*)$1));
        func_decl->body = std::unique_ptr<Block>((Block*)$5);
        $$ = func_decl;
        free($2);
    }
    ;

type_specifier:
    VOID { $$ = new Type(Type::VOID_TYPE); }
    | CHAR_TYPE { $$ = new Type(Type::CHAR_TYPE); }
    | INT { $$ = new Type(Type::INT_TYPE); }
    | FLOAT_TYPE { $$ = new Type(Type::FLOAT_TYPE); }
    | DOUBLE_TYPE { $$ = new Type(Type::DOUBLE_TYPE); }
    ;

compound_statement:
    LBRACE RBRACE {
        $$ = new Block();
    }
    | LBRACE statement RBRACE {
        auto block = new Block();
        if ($2) {
            block->statements.push_back(std::unique_ptr<Statement>((Statement*)$2));
        }
        $$ = block;
    }
    ;

statement:
    expression_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    ;

expression_statement:
    expression SEMICOLON {
        $$ = new ExpressionStatement(std::unique_ptr<Expression>((Expression*)$1));
    }
    | SEMICOLON {
        $$ = new ExpressionStatement(nullptr);
    }
    ;

selection_statement:
    IF LPAREN expression RPAREN statement {
        $$ = new IfStatement(std::unique_ptr<Expression>((Expression*)$3), 
                            std::unique_ptr<Statement>((Statement*)$5));
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        $$ = new IfStatement(std::unique_ptr<Expression>((Expression*)$3), 
                            std::unique_ptr<Statement>((Statement*)$5), 
                            std::unique_ptr<Statement>((Statement*)$7));
    }
    ;

iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        $$ = new WhileStatement(std::unique_ptr<Expression>((Expression*)$3), 
                               std::unique_ptr<Statement>((Statement*)$5));
    }
    ;

jump_statement:
    RETURN expression SEMICOLON {
        $$ = new ReturnStatement(std::unique_ptr<Expression>((Expression*)$2));
    }
    | RETURN SEMICOLON {
        $$ = new ReturnStatement();
    }
    | BREAK SEMICOLON {
        $$ = new BreakStatement();
    }
    | CONTINUE SEMICOLON {
        $$ = new ContinueStatement();
    }
    ;

expression:
    assignment_expression { $$ = $1; }
    ;

assignment_expression:
    conditional_expression { $$ = $1; }
    | unary_expression assignment_operator assignment_expression {
        $$ = new BinaryOp((BinaryOp::Operator)$2, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

assignment_operator:
    ASSIGN { $$ = BinaryOp::ASSIGN; }
    | PLUS_ASSIGN { $$ = BinaryOp::PLUS_ASSIGN; }
    | MINUS_ASSIGN { $$ = BinaryOp::MINUS_ASSIGN; }
    | MULT_ASSIGN { $$ = BinaryOp::MULT_ASSIGN; }
    | DIV_ASSIGN { $$ = BinaryOp::DIV_ASSIGN; }
    ;

conditional_expression:
    logical_or_expression { $$ = $1; }
    ;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression {
        $$ = new BinaryOp(BinaryOp::OR, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

logical_and_expression:
    equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression {
        $$ = new BinaryOp(BinaryOp::AND, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        $$ = new BinaryOp(BinaryOp::EQ, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | equality_expression NE relational_expression {
        $$ = new BinaryOp(BinaryOp::NE, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

relational_expression:
    additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        $$ = new BinaryOp(BinaryOp::LT, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | relational_expression GT additive_expression {
        $$ = new BinaryOp(BinaryOp::GT, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | relational_expression LE additive_expression {
        $$ = new BinaryOp(BinaryOp::LE, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | relational_expression GE additive_expression {
        $$ = new BinaryOp(BinaryOp::GE, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

additive_expression:
    multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression {
        $$ = new BinaryOp(BinaryOp::ADD, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | additive_expression MINUS multiplicative_expression {
        $$ = new BinaryOp(BinaryOp::SUB, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

multiplicative_expression:
    unary_expression { $$ = $1; }
    | multiplicative_expression MULT unary_expression {
        $$ = new BinaryOp(BinaryOp::MUL, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | multiplicative_expression DIV unary_expression {
        $$ = new BinaryOp(BinaryOp::DIV, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    | multiplicative_expression MOD unary_expression {
        $$ = new BinaryOp(BinaryOp::MOD, 
                         std::unique_ptr<Expression>((Expression*)$1), 
                         std::unique_ptr<Expression>((Expression*)$3));
    }
    ;

unary_expression:
    postfix_expression { $$ = $1; }
    | INC unary_expression {
        $$ = new UnaryOp(UnaryOp::PRE_INC, std::unique_ptr<Expression>((Expression*)$2));
    }
    | DEC unary_expression {
        $$ = new UnaryOp(UnaryOp::PRE_DEC, std::unique_ptr<Expression>((Expression*)$2));
    }
    | unary_operator unary_expression {
        $$ = new UnaryOp((UnaryOp::Operator)$1, std::unique_ptr<Expression>((Expression*)$2));
    }
    ;

unary_operator:
    BITWISE_AND { $$ = UnaryOp::ADDRESS_OF; }
    | MULT { $$ = UnaryOp::DEREF; }
    | PLUS { $$ = UnaryOp::PLUS; }
    | MINUS { $$ = UnaryOp::MINUS; }
    | BITWISE_NOT { $$ = UnaryOp::BITWISE_NOT; }
    | NOT { $$ = UnaryOp::NOT; }
    ;

postfix_expression:
    primary_expression { $$ = $1; }
    | postfix_expression INC {
        $$ = new UnaryOp(UnaryOp::POST_INC, std::unique_ptr<Expression>((Expression*)$1));
    }
    | postfix_expression DEC {
        $$ = new UnaryOp(UnaryOp::POST_DEC, std::unique_ptr<Expression>((Expression*)$1));
    }
    ;

primary_expression:
    IDENTIFIER {
        $$ = new Identifier($1);
        free($1);
    }
    | constant { $$ = $1; }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    ;

constant:
    INT_LITERAL {
        $$ = new IntLiteral($1);
    }
    | FLOAT_LITERAL {
        $$ = new FloatLiteral($1);
    }
    | DOUBLE_LITERAL {
        $$ = new FloatLiteral($1);
    }
    | CHAR_LITERAL {
        $$ = new CharLiteral($1);
    }
    | STRING_LITERAL {
        $$ = new StringLiteral($1);
        free($1);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
}