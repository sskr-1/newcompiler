%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

extern int yylineno;
void yyerror(const char* s);
%}

%option noyywrap
%option yylineno

DIGIT           [0-9]
LETTER          [a-zA-Z_]
IDENTIFIER      {LETTER}({LETTER}|{DIGIT})*
INTEGER         {DIGIT}+
FLOAT           {DIGIT}+\.{DIGIT}+
STRING          \"([^\"\\]|\\.)*\"
CHAR            \'([^\'\\]|\\.)\'

%%

"auto"          { return AUTO; }
"break"         { return BREAK; }
"case"          { return CASE; }
"char"          { return CHAR_TYPE; }
"const"         { return CONST; }
"continue"      { return CONTINUE; }
"default"       { return DEFAULT; }
"do"            { return DO; }
"double"        { return DOUBLE_TYPE; }
"else"          { return ELSE; }
"enum"          { return ENUM; }
"extern"        { return EXTERN; }
"float"         { return FLOAT_TYPE; }
"for"           { return FOR; }
"goto"          { return GOTO; }
"if"            { return IF; }
"inline"        { return INLINE; }
"int"           { return INT; }
"long"          { return LONG; }
"register"      { return REGISTER; }
"restrict"      { return RESTRICT; }
"return"        { return RETURN; }
"short"         { return SHORT; }
"signed"        { return SIGNED; }
"sizeof"        { return SIZEOF; }
"static"        { return STATIC; }
"struct"        { return STRUCT; }
"switch"        { return SWITCH; }
"typedef"       { return TYPEDEF; }
"union"         { return UNION; }
"unsigned"      { return UNSIGNED; }
"void"          { return VOID; }
"volatile"      { return VOLATILE; }
"while"         { return WHILE; }

"+"             { return PLUS; }
"-"             { return MINUS; }
"*"             { return MULT; }
"/"             { return DIV; }
"%"             { return MOD; }
"++"            { return INC; }
"--"            { return DEC; }
"="             { return ASSIGN; }
"+="            { return PLUS_ASSIGN; }
"-="            { return MINUS_ASSIGN; }
"*="            { return MULT_ASSIGN; }
"/="            { return DIV_ASSIGN; }
"%="            { return MOD_ASSIGN; }
"<<="           { return LSHIFT_ASSIGN; }
">>="           { return RSHIFT_ASSIGN; }
"&="            { return AND_ASSIGN; }
"|="            { return OR_ASSIGN; }
"^="            { return XOR_ASSIGN; }
"=="            { return EQ; }
"!="            { return NE; }
"<"             { return LT; }
"<="            { return LE; }
">"             { return GT; }
">="            { return GE; }
"&&"            { return AND; }
"||"            { return OR; }
"!"             { return NOT; }
"&"             { return BITWISE_AND; }
"|"             { return BITWISE_OR; }
"^"             { return BITWISE_XOR; }
"~"             { return BITWISE_NOT; }
"<<"            { return LSHIFT; }
">>"            { return RSHIFT; }
"?"             { return QUESTION; }
":"             { return COLON; }

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

{INTEGER}       { yylval.int_val = atoll(yytext); return INT_LITERAL; }
{FLOAT}         { yylval.double_val = atof(yytext); return DOUBLE_LITERAL; }
{STRING}        { yylval.str_val = strdup(yytext); return STRING_LITERAL; }
{CHAR}          { yylval.char_val = yytext[1]; return CHAR_LITERAL; }
{IDENTIFIER}    { yylval.str_val = strdup(yytext); return IDENTIFIER; }

[ \t\r]+        
\n              
"//".*$         
"/*"([^*]|\*+[^*/])*\*+"/"

.               { fprintf(stderr, "Unknown character: '%s' at line %d\n", yytext, yylineno); return yytext[0]; }

%%