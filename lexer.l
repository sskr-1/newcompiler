%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"
#include "parser.tab.h"

extern int yylineno;
void yyerror(const char* s);
%}

%option noyywrap
%option yylineno

/* Regular expressions for tokens */
DIGIT       [0-9]
LETTER      [a-zA-Z_]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT})*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
STRING      \"([^\"\\]|\\.)*\"
CHAR        \'([^\'\\]|\\.)\'

%%

/* Keywords */
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
"sizeof"        { return SIZEOF; }

/* Operators */
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
"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }
"*="            { return MULT_ASSIGN; }
"/="            { return DIV_ASSIGN; }

/* Delimiters */
"("             { return LPAREN; }
")"             { return RPAREN; }
"{"             { return LBRACE; }
"}"             { return RBRACE; }
"["             { return LBRACKET; }
"]"             { return RBRACKET; }
";"             { return SEMICOLON; }
","             { return COMMA; }
"."             { return DOT; }
"->"            { return ARROW; }

/* Literals */
{INTEGER}       { 
                  yylval.int_val = atoi(yytext); 
                  return INT_LITERAL; 
                }
{FLOAT}         { 
                  yylval.float_val = atof(yytext); 
                  return FLOAT_LITERAL; 
                }
{STRING}        { 
                  yylval.str_val = strdup(yytext); 
                  return STRING_LITERAL; 
                }
{CHAR}          { 
                  yylval.char_val = yytext[1]; 
                  return CHAR_LITERAL; 
                }

/* Identifiers */
{IDENTIFIER}    { 
                  yylval.str_val = strdup(yytext); 
                  return IDENTIFIER; 
                }

/* Whitespace */
[ \t]+          { /* ignore whitespace */ }
\n              { /* ignore newlines */ }

/* Comments */
"//".*          { /* ignore single-line comments */ }
"/*"([^*]|\*+[^*/])*\*+"/" { /* ignore multi-line comments */ }

/* Unknown characters */
.               { 
                  fprintf(stderr, "Unknown character: %s at line %d\n", yytext, yylineno);
                  return yytext[0]; 
                }

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}