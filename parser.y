%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <vector>
#include "ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

Program* root = nullptr;
%}

%union {
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
    std::vector<ExprPtr>* expr_list;
    std::vector<StmtPtr>* stmt_list;
    std::vector<DeclPtr>* decl_list;
}

/* Tokens */
%token <int_val> INT_LITERAL
%token <float_val> FLOAT_LITERAL
%token <str_val> STRING_LITERAL IDENTIFIER
%token <char_val> CHAR_LITERAL

/* Keywords */
%token INT FLOAT_TYPE CHAR_TYPE VOID
%token IF ELSE WHILE FOR RETURN BREAK CONTINUE
%token STRUCT SIZEOF

/* Operators */
%token PLUS MINUS MULT DIV MOD
%token ASSIGN EQ NE LT LE GT GE
%token AND OR NOT
%token INC DEC
%token PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN

/* Delimiters */
%token LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET
%token SEMICOLON COMMA DOT ARROW

/* Non-terminals */
%type <program> program
%type <decl_list> declaration_list
%type <decl> declaration function_declaration variable_declaration struct_declaration
%type <param_list> parameter_list parameter_list_opt
%type <param> parameter
%type <type> type_specifier
%type <block> compound_statement
%type <stmt_list> statement_list
%type <stmt> statement expression_statement selection_statement iteration_statement jump_statement
%type <expr> expression assignment_expression conditional_expression logical_or_expression
%type <expr> logical_and_expression equality_expression relational_expression
%type <expr> additive_expression multiplicative_expression unary_expression postfix_expression primary_expression
%type <expr_list> argument_expression_list argument_expression_list_opt
%type <un_op> unary_operator

/* Operator precedence and associativity */
%right ASSIGN PLUS_ASSIGN MINUS_ASSIGN MULT_ASSIGN DIV_ASSIGN
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
    declaration_list {
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

declaration_list:
    declaration {
        $$ = new std::vector<Declaration*>();
        if ($1) $$->push_back($1);
    }
    | declaration_list declaration {
        $$ = $1;
        if ($2) $$->push_back($2);
    }
    ;

declaration:
    variable_declaration { $$ = $1; }
    | function_declaration { $$ = $1; }
    | struct_declaration { $$ = $1; }
    ;

variable_declaration:
    type_specifier IDENTIFIER SEMICOLON {
        $$ = new VariableDeclaration($2, $1);
        free($2);
    }
    | type_specifier IDENTIFIER ASSIGN assignment_expression SEMICOLON {
        $$ = new VariableDeclaration($2, $1, std::unique_ptr<Expression>($4));
        free($2);
    }
    | type_specifier IDENTIFIER LBRACKET INT_LITERAL RBRACKET SEMICOLON {
        auto var = new VariableDeclaration($2, $1);
        var->is_array = true;
        var->array_size = $4;
        $$ = var;
        free($2);
    }
    ;

function_declaration:
    type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement {
        auto func = new FunctionDeclaration($2, $1);
        if ($4) {
            func->parameters = *$4;
            delete $4;
        }
        func->body = std::unique_ptr<Block>($6);
        $$ = func;
        free($2);
    }
    | type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN SEMICOLON {
        auto func = new FunctionDeclaration($2, $1);
        if ($4) {
            func->parameters = *$4;
            delete $4;
        }
        $$ = func;
        free($2);
    }
    ;

parameter_list_opt:
    /* empty */ { $$ = nullptr; }
    | parameter_list { $$ = $1; }
    ;

parameter_list:
    parameter {
        $$ = new std::vector<Parameter>();
        if ($1) {
            $$->push_back(*$1);
            delete $1;
        }
    }
    | parameter_list COMMA parameter {
        $$ = $1;
        if ($3) {
            $$->push_back(*$3);
            delete $3;
        }
    }
    ;

parameter:
    type_specifier IDENTIFIER {
        $$ = new Parameter($2, $1);
        free($2);
    }
    | type_specifier IDENTIFIER LBRACKET RBRACKET {
        $$ = new Parameter($2, $1, true);
        free($2);
    }
    ;

struct_declaration:
    STRUCT IDENTIFIER LBRACE RBRACE SEMICOLON {
        auto struct_decl = new StructDeclaration($2);
        $$ = struct_decl;
        free($2);
    }
    ;

type_specifier:
    INT { $$ = Expression::INT_TYPE; }
    | FLOAT_TYPE { $$ = Expression::FLOAT_TYPE; }
    | CHAR_TYPE { $$ = Expression::CHAR_TYPE; }
    | VOID { $$ = Expression::VOID_TYPE; }
    ;

compound_statement:
    LBRACE statement_list RBRACE {
        auto block = new Block();
        if ($2) {
            for (auto& stmt : *$2) {
                block->statements.push_back(std::unique_ptr<Statement>(stmt));
            }
            delete $2;
        }
        $$ = block;
    }
    | LBRACE RBRACE {
        $$ = new Block();
    }
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
    expression_statement { $$ = $1; }
    | compound_statement { $$ = $1; }
    | selection_statement { $$ = $1; }
    | iteration_statement { $$ = $1; }
    | jump_statement { $$ = $1; }
    | variable_declaration { $$ = $1; }
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
    ;

iteration_statement:
    WHILE LPAREN expression RPAREN statement {
        $$ = new WhileStatement(std::unique_ptr<Expression>($3), std::unique_ptr<Statement>($5));
    }
    | FOR LPAREN expression_statement expression_statement expression RPAREN statement {
        $$ = new ForStatement(std::unique_ptr<Statement>($3), std::unique_ptr<Expression>($4->expression.release()), std::unique_ptr<Expression>($5), std::unique_ptr<Statement>($7));
        delete $4;
    }
    | FOR LPAREN expression_statement expression_statement RPAREN statement {
        $$ = new ForStatement(std::unique_ptr<Statement>($3), std::unique_ptr<Expression>($4->expression.release()), nullptr, std::unique_ptr<Statement>($6));
        delete $4;
    }
    ;

jump_statement:
    RETURN expression SEMICOLON {
        $$ = new ReturnStatement(std::unique_ptr<Expression>($2));
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
    | unary_expression ASSIGN assignment_expression {
        $$ = new BinaryOp(BinaryOp::ASSIGN, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | unary_expression PLUS_ASSIGN assignment_expression {
        $$ = new BinaryOp(BinaryOp::PLUS_ASSIGN, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | unary_expression MINUS_ASSIGN assignment_expression {
        $$ = new BinaryOp(BinaryOp::MINUS_ASSIGN, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | unary_expression MULT_ASSIGN assignment_expression {
        $$ = new BinaryOp(BinaryOp::MULT_ASSIGN, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | unary_expression DIV_ASSIGN assignment_expression {
        $$ = new BinaryOp(BinaryOp::DIV_ASSIGN, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

conditional_expression:
    logical_or_expression { $$ = $1; }
    ;

logical_or_expression:
    logical_and_expression { $$ = $1; }
    | logical_or_expression OR logical_and_expression {
        $$ = new BinaryOp(BinaryOp::OR, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    ;

logical_and_expression:
    equality_expression { $$ = $1; }
    | logical_and_expression AND equality_expression {
        $$ = new BinaryOp(BinaryOp::AND, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
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
    additive_expression { $$ = $1; }
    | relational_expression LT additive_expression {
        $$ = new BinaryOp(BinaryOp::LT, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | relational_expression GT additive_expression {
        $$ = new BinaryOp(BinaryOp::GT, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | relational_expression LE additive_expression {
        $$ = new BinaryOp(BinaryOp::LE, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | relational_expression GE additive_expression {
        $$ = new BinaryOp(BinaryOp::GE, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
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
    unary_expression { $$ = $1; }
    | multiplicative_expression MULT unary_expression {
        $$ = new BinaryOp(BinaryOp::MUL, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | multiplicative_expression DIV unary_expression {
        $$ = new BinaryOp(BinaryOp::DIV, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | multiplicative_expression MOD unary_expression {
        $$ = new BinaryOp(BinaryOp::MOD, std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
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
    | unary_operator unary_expression {
        $$ = new UnaryOp($1, std::unique_ptr<Expression>($2));
    }
    | SIZEOF unary_expression {
        // For simplicity, treat sizeof as unary operator
        $$ = new UnaryOp(UnaryOp::ADDRESS_OF, std::unique_ptr<Expression>($2)); // placeholder
    }
    ;

unary_operator:
    PLUS { $$ = UnaryOp::PLUS; }
    | MINUS { $$ = UnaryOp::MINUS; }
    | NOT { $$ = UnaryOp::NOT; }
    | MULT { $$ = UnaryOp::DEREF; }
    ;

postfix_expression:
    primary_expression { $$ = $1; }
    | postfix_expression LBRACKET expression RBRACKET {
        $$ = new ArrayAccess(std::unique_ptr<Expression>($1), std::unique_ptr<Expression>($3));
    }
    | postfix_expression LPAREN argument_expression_list_opt RPAREN {
        auto func_call = new FunctionCall(static_cast<Identifier*>($1)->name);
        if ($3) {
            for (auto& expr : *$3) {
                func_call->arguments.push_back(std::unique_ptr<Expression>(expr));
            }
            delete $3;
        }
        delete $1;
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
    | INT_LITERAL {
        $$ = new IntLiteral($1);
    }
    | FLOAT_LITERAL {
        $$ = new FloatLiteral($1);
    }
    | CHAR_LITERAL {
        $$ = new CharLiteral($1);
    }
    | STRING_LITERAL {
        $$ = new StringLiteral($1);
        free($1);
    }
    | LPAREN expression RPAREN {
        $$ = $2;
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