%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast_full.h"
#include "parser.tab.h"

extern int yylineno;
void yyerror(const char* s);
%}

%option noyywrap
%option yylineno
%option c++
%option outfile="lexer.yy.cc"

/* Regular expressions for tokens */
DIGIT           [0-9]
LETTER          [a-zA-Z_]
IDENTIFIER      {LETTER}({LETTER}|{DIGIT})*
INTEGER         {DIGIT}+
HEX_INTEGER     0[xX][0-9a-fA-F]+
OCTAL_INTEGER   0[0-7]+
FLOAT           {DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?
FLOAT_F         {DIGIT}+\.{DIGIT}+([eE][+-]?{DIGIT}+)?[fF]
STRING          \"([^\"\\]|\\.)*\"
CHAR            \'([^\'\\]|\\.)\'
WHITESPACE      [ \t\r]
NEWLINE         \n

%%

/* Keywords */
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

/* Operators */
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
{HEX_INTEGER}   { 
                  yylval.int_val = (long long)strtoll(yytext, NULL, 16); 
                  return INT_LITERAL; 
                }
{OCTAL_INTEGER} { 
                  yylval.int_val = (long long)strtoll(yytext, NULL, 8); 
                  return INT_LITERAL; 
                }
{INTEGER}       { 
                  yylval.int_val = (long long)atoll(yytext); 
                  return INT_LITERAL; 
                }
{FLOAT_F}       { 
                  yylval.float_val = atof(yytext); 
                  return FLOAT_LITERAL; 
                }
{FLOAT}         { 
                  yylval.double_val = atof(yytext); 
                  return DOUBLE_LITERAL; 
                }
{STRING}        { 
                  yylval.str_val = strdup(yytext); 
                  return STRING_LITERAL; 
                }
{CHAR}          { 
                  /* Handle escape sequences */
                  if (yytext[1] == '\\') {
                      switch (yytext[2]) {
                          case 'n': yylval.char_val = '\n'; break;
                          case 't': yylval.char_val = '\t'; break;
                          case 'r': yylval.char_val = '\r'; break;
                          case 'b': yylval.char_val = '\b'; break;
                          case 'f': yylval.char_val = '\f'; break;
                          case 'a': yylval.char_val = '\a'; break;
                          case 'v': yylval.char_val = '\v'; break;
                          case '\\': yylval.char_val = '\\'; break;
                          case '\'': yylval.char_val = '\''; break;
                          case '\"': yylval.char_val = '\"'; break;
                          case '0': yylval.char_val = '\0'; break;
                          default: yylval.char_val = yytext[2]; break;
                      }
                  } else {
                      yylval.char_val = yytext[1];
                  }
                  return CHAR_LITERAL; 
                }

/* Identifiers */
{IDENTIFIER}    { 
                  yylval.str_val = strdup(yytext); 
                  return IDENTIFIER; 
                }

/* Whitespace and comments */
{WHITESPACE}+   { /* ignore whitespace */ }
{NEWLINE}       { /* ignore newlines but track line numbers */ }

"//".*$         { /* ignore single-line comments */ }
"/*"            { 
                  /* multi-line comment handling */
                  int c;
                  while ((c = yyinput()) != 0) {
                      if (c == '*') {
                          if ((c = yyinput()) == '/') break;
                          unput(c);
                      }
                  }
                }

/* Preprocessor directives (basic handling) */
^{WHITESPACE}*"#".*$ { /* ignore preprocessor directives for now */ }

/* Unknown characters */
.               { 
                  fprintf(stderr, "Unknown character: '%s' at line %d\n", yytext, yylineno);
                  return yytext[0]; 
                }

%%

void yyerror(const char* s) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, s);
}