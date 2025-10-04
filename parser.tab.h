/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LITERAL = 258,             /* INT_LITERAL  */
    FLOAT_LITERAL = 259,           /* FLOAT_LITERAL  */
    DOUBLE_LITERAL = 260,          /* DOUBLE_LITERAL  */
    STRING_LITERAL = 261,          /* STRING_LITERAL  */
    IDENTIFIER = 262,              /* IDENTIFIER  */
    CHAR_LITERAL = 263,            /* CHAR_LITERAL  */
    AUTO = 264,                    /* AUTO  */
    BREAK = 265,                   /* BREAK  */
    CASE = 266,                    /* CASE  */
    CHAR_TYPE = 267,               /* CHAR_TYPE  */
    CONST = 268,                   /* CONST  */
    CONTINUE = 269,                /* CONTINUE  */
    DEFAULT = 270,                 /* DEFAULT  */
    DO = 271,                      /* DO  */
    DOUBLE_TYPE = 272,             /* DOUBLE_TYPE  */
    ELSE = 273,                    /* ELSE  */
    ENUM = 274,                    /* ENUM  */
    EXTERN = 275,                  /* EXTERN  */
    FLOAT_TYPE = 276,              /* FLOAT_TYPE  */
    FOR = 277,                     /* FOR  */
    GOTO = 278,                    /* GOTO  */
    IF = 279,                      /* IF  */
    INLINE = 280,                  /* INLINE  */
    INT = 281,                     /* INT  */
    LONG = 282,                    /* LONG  */
    REGISTER = 283,                /* REGISTER  */
    RESTRICT = 284,                /* RESTRICT  */
    RETURN = 285,                  /* RETURN  */
    SHORT = 286,                   /* SHORT  */
    SIGNED = 287,                  /* SIGNED  */
    SIZEOF = 288,                  /* SIZEOF  */
    STATIC = 289,                  /* STATIC  */
    STRUCT = 290,                  /* STRUCT  */
    SWITCH = 291,                  /* SWITCH  */
    TYPEDEF = 292,                 /* TYPEDEF  */
    UNION = 293,                   /* UNION  */
    UNSIGNED = 294,                /* UNSIGNED  */
    VOID = 295,                    /* VOID  */
    VOLATILE = 296,                /* VOLATILE  */
    WHILE = 297,                   /* WHILE  */
    PLUS = 298,                    /* PLUS  */
    MINUS = 299,                   /* MINUS  */
    MULT = 300,                    /* MULT  */
    DIV = 301,                     /* DIV  */
    MOD = 302,                     /* MOD  */
    INC = 303,                     /* INC  */
    DEC = 304,                     /* DEC  */
    ASSIGN = 305,                  /* ASSIGN  */
    PLUS_ASSIGN = 306,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 307,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 308,             /* MULT_ASSIGN  */
    DIV_ASSIGN = 309,              /* DIV_ASSIGN  */
    MOD_ASSIGN = 310,              /* MOD_ASSIGN  */
    LSHIFT_ASSIGN = 311,           /* LSHIFT_ASSIGN  */
    RSHIFT_ASSIGN = 312,           /* RSHIFT_ASSIGN  */
    AND_ASSIGN = 313,              /* AND_ASSIGN  */
    OR_ASSIGN = 314,               /* OR_ASSIGN  */
    XOR_ASSIGN = 315,              /* XOR_ASSIGN  */
    EQ = 316,                      /* EQ  */
    NE = 317,                      /* NE  */
    LT = 318,                      /* LT  */
    LE = 319,                      /* LE  */
    GT = 320,                      /* GT  */
    GE = 321,                      /* GE  */
    AND = 322,                     /* AND  */
    OR = 323,                      /* OR  */
    NOT = 324,                     /* NOT  */
    BITWISE_AND = 325,             /* BITWISE_AND  */
    BITWISE_OR = 326,              /* BITWISE_OR  */
    BITWISE_XOR = 327,             /* BITWISE_XOR  */
    BITWISE_NOT = 328,             /* BITWISE_NOT  */
    LSHIFT = 329,                  /* LSHIFT  */
    RSHIFT = 330,                  /* RSHIFT  */
    QUESTION = 331,                /* QUESTION  */
    COLON = 332,                   /* COLON  */
    LPAREN = 333,                  /* LPAREN  */
    RPAREN = 334,                  /* RPAREN  */
    LBRACE = 335,                  /* LBRACE  */
    RBRACE = 336,                  /* RBRACE  */
    LBRACKET = 337,                /* LBRACKET  */
    RBRACKET = 338,                /* RBRACKET  */
    SEMICOLON = 339,               /* SEMICOLON  */
    COMMA = 340,                   /* COMMA  */
    DOT = 341,                     /* DOT  */
    ARROW = 342                    /* ARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "parser_simple.y"

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

#line 171 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
