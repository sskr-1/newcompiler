%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylineno;
%}

%option noyywrap
%option yylineno

DIGIT           [0-9]
LETTER          [a-zA-Z_]
IDENTIFIER      {LETTER}({LETTER}|{DIGIT})*
INTEGER         {DIGIT}+

%%

"int"           { printf("TOKEN: INT\n"); }
"return"        { printf("TOKEN: RETURN\n"); }
"+"             { printf("TOKEN: PLUS\n"); }
"-"             { printf("TOKEN: MINUS\n"); }
"="             { printf("TOKEN: ASSIGN\n"); }
"("             { printf("TOKEN: LPAREN\n"); }
")"             { printf("TOKEN: RPAREN\n"); }
"{"             { printf("TOKEN: LBRACE\n"); }
"}"             { printf("TOKEN: RBRACE\n"); }
";"             { printf("TOKEN: SEMICOLON\n"); }

{INTEGER}       { printf("TOKEN: INTEGER(%s)\n", yytext); }
{IDENTIFIER}    { printf("TOKEN: IDENTIFIER(%s)\n", yytext); }

[ \t\r]+        { /* ignore whitespace */ }
\n              { /* ignore newlines */ }

.               { printf("TOKEN: UNKNOWN(%s)\n", yytext); }

%%

int main() {
    printf("Testing lexer...\n");
    yylex();
    return 0;
}