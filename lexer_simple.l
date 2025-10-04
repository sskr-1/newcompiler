%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.hpp"

extern int yylineno;
void yyerror(const char* s);
%}

%option noyywrap
%option yylineno

DIGIT       [0-9]
LETTER      [a-zA-Z_]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+

%%

"int"           { return INT; }
"float"         { return FLOAT_TYPE; }
"char"          { return CHAR_TYPE; }
"void"          { return VOID; }
"if"            { return IF; }
"else"          { return ELSE; }
"while"         { return WHILE; }
"for"           { return FOR; }
"return"        { return RETURN; }
"break"         { return BREAK; }
"continue"      { return CONTINUE; }
"struct"        { return STRUCT; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"="             { return ASSIGN; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"++"            { return INC; }
"--"            { return DEC; }

"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"."             { return DOT; }

{INTEGER}       { yylval.int_val = atoi(yytext); return INT_LITERAL; }
{FLOAT}         { yylval.float_val = atof(yytext); return FLOAT_LITERAL; }
{IDENTIFIER}    { yylval.str_val = strdup(yytext); return IDENTIFIER; }

[ \t]+          { /* ignore whitespace */ }
\n              { /* ignore newlines */ }
"//".*          { /* ignore single-line comments */ }

.               { return yytext[0]; }

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}