%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <memory>
#include "ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

Program* root = nullptr;
%}

%output "parser.tab.cc"
%defines "parser.tab.h"

%union {
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
%type <decl_list> translation_unit
%type <decl> external_declaration declaration
%type <decl> function_definition function_declaration
%type <decl> variable_declaration struct_declaration enum_declaration typedef_declaration
%type <param_list> parameter_list parameter_list_opt
%type <param> parameter_declaration
%type <type_node> type_specifier declaration_specifiers storage_class_specifier
%type <type_node> struct_or_union_specifier enum_specifier
%type <type_node> declarator direct_declarator pointer
%type <block> compound_statement
%type <stmt_list> statement_list statement_list_opt
%type <stmt> statement labeled_statement expression_statement selection_statement
%type <stmt> iteration_statement jump_statement
%type <expr> expression assignment_expression conditional_expression
%type <expr> logical_or_expression logical_and_expression inclusive_or_expression
%type <expr> exclusive_or_expression and_expression equality_expression
%type <expr> relational_expression shift_expression additive_expression
%type <expr> multiplicative_expression cast_expression unary_expression
%type <expr> postfix_expression primary_expression constant
%type <expr_list> argument_expression_list argument_expression_list_opt
%type <un_op> unary_operator
%type <bin_op> assignment_operator

/* Operator precedence and associativity */
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN
%right LSHIFT_ASSIGN RSHIFT_ASSIGN AND_ASSIGN OR_ASSIGN XOR_ASSIGN
%right QUESTION COLON
%left OR
%left AND
%left BITWISE_OR
%left BITWISE_XOR
%left BITWISE_AND
%left EQ NE
%left LT LE GT GE
%left LSHIFT RSHIFT
%left PLUS MINUS
%left MULT DIV MOD
%right NOT BITWISE_NOT INC DEC SIZEOF
%left DOT ARROW LBRACKET LPAREN

%%

program:
    translation_unit {
        root = new Program();
        if ($1) {
            for (auto& decl : *$1) {
                root->declarations.push_back(std::unique_ptr<Declaration>(decl));
            }
            delete $1;
        }
        $$ = root;
    }
    ;

translation_unit:
    external_declaration {
        $$ = new std::vector<Declaration*>();
        if ($1) $$->push_back($1);
    }
    | translation_unit external_declaration {
        $$ = $1;
        if ($2) $$->push_back($2);
    }
    ;

external_declaration:
    function_definition { $$ = $1; }
    | declaration { $$ = $1; }
    ;

function_definition:
    type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement {
        auto func_decl = new FunctionDeclaration($2, std::unique_ptr<Type>($1));
        if ($4) {
            func_decl->parameters = *$4;
            delete $4;
        }
        func_decl->body = std::unique_ptr<Block>($6);
        $$ = func_decl;
        free($2);
    }
    ;

function_declaration:
    type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN SEMICOLON {
        auto func_decl = new FunctionDeclaration($2, std::unique_ptr<Type>($1));
        if ($4) {
            func_decl->parameters = *$4;
            delete $4;
        }
        $$ = func_decl;
        free($2);
    }
    ;

declaration:
    type_specifier IDENTIFIER SEMICOLON {
        auto var_decl = new VariableDeclaration($2, std::unique_ptr<Type>($1));
        $$ = var_decl;
        free($2);
    }
    | type_specifier IDENTIFIER ASSIGN assignment_expression SEMICOLON {
        auto var_decl = new VariableDeclaration($2, std::unique_ptr<Type>($1), std::unique_ptr<Expression>($4));
        $$ = var_decl;
        free($2);
    }
    | type_specifier IDENTIFIER LBRACKET INT_LITERAL RBRACKET SEMICOLON {
        auto array_type = std::make_unique<ArrayType>(std::unique_ptr<Type>($1), $4);
        auto var_decl = new VariableDeclaration($2, std::move(array_type));
        $$ = var_decl;
        free($2);
    }
    | struct_declaration { $$ = $1; }
    | enum_declaration { $$ = $1; }
    | typedef_declaration { $$ = $1; }
    ;

type_specifier:
    VOID { $$ = new Type(Type::VOID_TYPE); }
    | CHAR_TYPE { $$ = new Type(Type::CHAR_TYPE); }
    | SHORT { $$ = new Type(Type::SHORT_TYPE); }
    | INT { $$ = new Type(Type::INT_TYPE); }
    | LONG { $$ = new Type(Type::LONG_TYPE); }
    | FLOAT_TYPE { $$ = new Type(Type::FLOAT_TYPE); }
    | DOUBLE_TYPE { $$ = new Type(Type::DOUBLE_TYPE); }
    | SIGNED { $$ = new Type(Type::INT_TYPE); }
    | UNSIGNED { 
        auto type = new Type(Type::INT_TYPE);
        type->is_unsigned = true;
        $$ = type;
    }
    | struct_or_union_specifier { $$ = $1; }
    | enum_specifier { $$ = $1; }
    | IDENTIFIER { 
        // TODO: Look up typedef name
        $$ = new Type(Type::INT_TYPE);
        free($1);
    }
    ;

struct_or_union_specifier:
    STRUCT IDENTIFIER LBRACE RBRACE {
        $$ = new StructType($2);
        free($2);
    }
    | UNION IDENTIFIER LBRACE RBRACE {
        auto struct_type = new StructType($2);
        struct_type->kind = Type::UNION_TYPE;
        $$ = struct_type;
        free($2);
    }
    | STRUCT IDENTIFIER {
        $$ = new StructType($2);
        free($2);
    }
    | UNION IDENTIFIER {
        auto struct_type = new StructType($2);
        struct_type->kind = Type::UNION_TYPE;
        $$ = struct_type;
        free($2);
    }
    ;

enum_specifier:
    ENUM IDENTIFIER LBRACE RBRACE {
        $$ = new Type(Type::ENUM_TYPE);
        free($2);
    }
    | ENUM IDENTIFIER {
        $$ = new Type(Type::ENUM_TYPE);
        free($2);
    }
    ;

parameter_list_opt:
    /* empty */ { $$ = nullptr; }
    | parameter_list { $$ = $1; }
    ;

parameter_list:
    parameter_declaration {
        $$ = new std::vector<Parameter>();
        if ($1) {
            $$->push_back(*$1);
            delete $1;
        }
    }
    | parameter_list COMMA parameter_declaration {
        $$ = $1;
        if ($3) {
            $$->push_back(*$3);
            delete $3;
        }
    }
    ;

parameter_declaration:
    type_specifier IDENTIFIER {
        $$ = new Parameter($2, std::unique_ptr<Type>($1));
        free($2);
    }
    | type_specifier IDENTIFIER LBRACKET RBRACKET {
        auto array_type = std::make_unique<ArrayType>(std::unique_ptr<Type>($1), 0);
        $$ = new Parameter($2, std::move(array_type));
        free($2);
    }
    | type_specifier {
        $$ = new Parameter("", std::unique_ptr<Type>($1));
    }
    ;

struct_declaration:
    STRUCT IDENTIFIER LBRACE RBRACE SEMICOLON {
        auto struct_decl = new StructDeclaration($2);
        $$ = struct_decl;
        free($2);
    }
    ;

enum_declaration:
    ENUM IDENTIFIER LBRACE RBRACE SEMICOLON {
        auto enum_decl = new EnumDeclaration($2);
        $$ = enum_decl;
        free($2);
    }
    ;

typedef_declaration:
    TYPEDEF type_specifier IDENTIFIER SEMICOLON {
        auto typedef_decl = new TypedefDeclaration($3, std::unique_ptr<Type>($2));
        $$ = typedef_decl;
        free($3);
    }
    ;

compound_statement:
    LBRACE statement_list_opt RBRACE {
        auto block = new Block();
        if ($2) {
            for (auto& stmt : *$2) {
                block->statements.push_back(std::unique_ptr<Statement>(stmt));
            }
            delete $2;
        }
        $$ = block;
    }
    ;

statement_list_opt:
    /* empty */ { $$ = nullptr; }
    | statement_list { $$ = $1; }
    ;

statement_list:
    statement {
        $$ = new std::vector<Statement*>();
        if ($1) $$->push_back($1);
    }
    | statement_list statement {
        $$ = $1;
        if ($2) $$->push_back($2);
    }
    ;

statement:
    labeled_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | expression_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    | declaration { $$ = $1; }
    ;

labeled_statement:
    IDENTIFIER COLON statement {
        $$ = new LabelStatement($1, std::unique_ptr<Statement>($3));
        free($1);
    }
    | CASE constant COLON statement {
        $$ = new CaseStatement(std::unique_ptr<Expression>($2), std::unique_ptr<Statement>($4));
    }
    | DEFAULT COLON statement {
        $$ = new CaseStatement(nullptr, std::unique_ptr<Statement>($3));
    }
    ;

expression_statement:
    expression SEMICOLON {
        $$ = new ExpressionStatement(std::unique_ptr<Expression>($1));
    }
    | SEMICOLON {
        $$ = new ExpressionStatement(nullptr);
    }
    ;

selection_statement:
    IF LPAREN expression RPAREN statement {
        $$ = new IfStatement(std::unique_ptr<Expression>($3), std::unique_ptr<Statement>($5));
    }
    | IF LPAREN expression RPAREN statement ELSE statement {
        $$ = new IfStatement(std::unique_ptr<Expression>($3), std::unique_ptr<Statement>($5), std::unique_ptr<Statement>($7));
    }
    | SWITCH LPAREN expression RPAREN statement {
        $$ = new SwitchStatement(std::unique_ptr<Expression>($3), std::unique_ptr<Statement>($5));
    }
    ;

iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        $$ = new WhileStatement(std::unique_ptr<Expression>($3), std::unique_ptr<Statement>($5));
    }
    | DO statement WHILE LPAREN expression RPAREN SEMICOLON {
        $$ = new DoWhileStatement(std::unique_ptr<Statement>($2), std::unique_ptr<Expression>($5));
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
        $$ = new ForStatement(std::unique_ptr<Statement>($3), 
                             std::unique_ptr<Expression>(static_cast<ExpressionStatement*>($4)->expression.release()),
                             std::unique_ptr<Expression>($5), 
                             std::unique_ptr<Statement>($7));
        delete $4;
    }
    | FOR LPAREN expression_statement expression_statement RPAREN statement {
        $$ = new ForStatement(std::unique_ptr<Statement>($3), 
                             std::unique_ptr<Expression>(static_cast<ExpressionStatement*>($4)->expression.release()),
                             nullptr, 
                             std::unique_ptr<Statement>($6));
        delete $4;
    }
    ;

jump_statement:
    GOTO IDENTIFIER SEMICOLON {
        $$ = new GotoStatement($2);
        free($2);
    }
    | CONTINUE SEMICOLON {
        $$ = new ContinueStatement();
    }
    | BREAK SEMICOLON {
        $$ = new BreakStatement();
    }
    | RETURN expression SEMICOLON {
        $$ = new ReturnStatement(std::unique_ptr<Expression>($2));
    }
    | RETURN SEMICOLON {
        $$ = new ReturnStatement();
    }
    ;

expression:
    assignment_expression { $$ = $1; }
    | expression COMMA assignment_expression {
        $$ = new BinaryOp(BinaryOp::COMMA, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

assignment_expression:
    conditional_expression { $$ = $1; }
    | unary_expression assignment_operator assignment_expression {
        $$ = new BinaryOp($2, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

assignment_operator:
    ASSIGN { $$ = BinaryOp::ASSIGN; }
    | MULT_ASSIGN { $$ = BinaryOp::MULT_ASSIGN; }
    | DIV_ASSIGN { $$ = BinaryOp::DIV_ASSIGN; }
    | MOD_ASSIGN { $$ = BinaryOp::MOD_ASSIGN; }
    | PLUS_ASSIGN { $$ = BinaryOp::PLUS_ASSIGN; }
    | MINUS_ASSIGN { $$ = BinaryOp::MINUS_ASSIGN; }
    | LSHIFT_ASSIGN { $$ = BinaryOp::LSHIFT_ASSIGN; }
    | RSHIFT_ASSIGN { $$ = BinaryOp::RSHIFT_ASSIGN; }
    | AND_ASSIGN { $$ = BinaryOp::AND_ASSIGN; }
    | XOR_ASSIGN { $$ = BinaryOp::XOR_ASSIGN; }
    | OR_ASSIGN { $$ = BinaryOp::OR_ASSIGN; }
    ;

conditional_expression:
    logical_or_expression { $$ = $1; }
    | logical_or_expression QUESTION expression COLON conditional_expression {
        $$ = new ConditionalOp(std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3), std::unique_ptr<Expression>($5));
    }
    ;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression {
        $$ = new BinaryOp(BinaryOp::OR, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

logical_and_expression:
    inclusive_or_expression { $$ = $1; }
    | logical_and_expression AND inclusive_or_expression {
        $$ = new BinaryOp(BinaryOp::AND, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

inclusive_or_expression:
    exclusive_or_expression { $$ = $1; }
    | inclusive_or_expression BITWISE_OR exclusive_or_expression {
        $$ = new BinaryOp(BinaryOp::BITWISE_OR, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

exclusive_or_expression:
    and_expression { $$ = $1; }
    | exclusive_or_expression BITWISE_XOR and_expression {
        $$ = new BinaryOp(BinaryOp::BITWISE_XOR, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

and_expression:
    equality_expression { $$ = $1; }
    | and_expression BITWISE_AND equality_expression {
        $$ = new BinaryOp(BinaryOp::BITWISE_AND, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

equality_expression:
    relational_expression { $$ = $1; }
    | equality_expression EQ relational_expression {
        $$ = new BinaryOp(BinaryOp::EQ, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | equality_expression NE relational_expression {
        $$ = new BinaryOp(BinaryOp::NE, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

relational_expression:
    shift_expression { $$ = $1; }
    | relational_expression LT shift_expression {
        $$ = new BinaryOp(BinaryOp::LT, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | relational_expression GT shift_expression {
        $$ = new BinaryOp(BinaryOp::GT, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | relational_expression LE shift_expression {
        $$ = new BinaryOp(BinaryOp::LE, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | relational_expression GE shift_expression {
        $$ = new BinaryOp(BinaryOp::GE, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

shift_expression:
    additive_expression { $$ = $1; }
    | shift_expression LSHIFT additive_expression {
        $$ = new BinaryOp(BinaryOp::LSHIFT, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | shift_expression RSHIFT additive_expression {
        $$ = new BinaryOp(BinaryOp::RSHIFT, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

additive_expression:
    multiplicative_expression { $$ = $1; }
    | additive_expression PLUS multiplicative_expression {
        $$ = new BinaryOp(BinaryOp::ADD, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | additive_expression MINUS multiplicative_expression {
        $$ = new BinaryOp(BinaryOp::SUB, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

multiplicative_expression:
    cast_expression { $$ = $1; }
    | multiplicative_expression MULT cast_expression {
        $$ = new BinaryOp(BinaryOp::MUL, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | multiplicative_expression DIV cast_expression {
        $$ = new BinaryOp(BinaryOp::DIV, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | multiplicative_expression MOD cast_expression {
        $$ = new BinaryOp(BinaryOp::MOD, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

cast_expression:
    unary_expression { $$ = $1; }
    | LPAREN type_specifier RPAREN cast_expression {
        $$ = new CastExpression(std::unique_ptr<Type>($2), std::unique_ptr<Expression>($4));
    }
    ;

unary_expression:
    postfix_expression { $$ = $1; }
    | INC unary_expression {
        $$ = new UnaryOp(UnaryOp::PRE_INC, std::unique_ptr<Expression>($2));
    }
    | DEC unary_expression {
        $$ = new UnaryOp(UnaryOp::PRE_DEC, std::unique_ptr<Expression>($2));
    }
    | unary_operator cast_expression {
        $$ = new UnaryOp($1, std::unique_ptr<Expression>($2));
    }
    | SIZEOF unary_expression {
        $$ = new SizeofExpression(std::unique_ptr<Expression>($2));
    }
    | SIZEOF LPAREN type_specifier RPAREN {
        $$ = new SizeofExpression(std::unique_ptr<Type>($3));
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
    | postfix_expression LBRACKET expression RBRACKET {
        $$ = new ArrayAccess(std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | postfix_expression LPAREN argument_expression_list_opt RPAREN {
        auto func_call = new FunctionCall(std::unique_ptr<Expression>($1));
        if ($3) {
            for (auto& expr : *$3) {
                func_call->arguments.push_back(std::unique_ptr<Expression>(expr));
            }
            delete $3;
        }
        $$ = func_call;
    }
    | postfix_expression DOT IDENTIFIER {
        $$ = new MemberAccess(std::unique_ptr<Expression>($1), $3, false);
        free($3);
    }
    | postfix_expression ARROW IDENTIFIER {
        $$ = new MemberAccess(std::unique_ptr<Expression>($1), $3, true);
        free($3);
    }
    | postfix_expression INC {
        $$ = new UnaryOp(UnaryOp::POST_INC, std::unique_ptr<Expression>($1));
    }
    | postfix_expression DEC {
        $$ = new UnaryOp(UnaryOp::POST_DEC, std::unique_ptr<Expression>($1));
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

argument_expression_list_opt:
    /* empty */ { $$ = nullptr; }
    | argument_expression_list { $$ = $1; }
    ;

argument_expression_list:
    assignment_expression {
        $$ = new std::vector<Expression*>();
        $$->push_back($1);
    }
    | argument_expression_list COMMA assignment_expression {
        $$ = $1;
        $$->push_back($3);
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
}