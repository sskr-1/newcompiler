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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
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
    STRING_LITERAL = 260,          /* STRING_LITERAL  */
    IDENTIFIER = 261,              /* IDENTIFIER  */
    CHAR_LITERAL = 262,            /* CHAR_LITERAL  */
    INT = 263,                     /* INT  */
    FLOAT_TYPE = 264,              /* FLOAT_TYPE  */
    CHAR_TYPE = 265,               /* CHAR_TYPE  */
    VOID = 266,                    /* VOID  */
    IF = 267,                      /* IF  */
    ELSE = 268,                    /* ELSE  */
    WHILE = 269,                   /* WHILE  */
    FOR = 270,                     /* FOR  */
    RETURN = 271,                  /* RETURN  */
    BREAK = 272,                   /* BREAK  */
    CONTINUE = 273,                /* CONTINUE  */
    STRUCT = 274,                  /* STRUCT  */
    SIZEOF = 275,                  /* SIZEOF  */
    PLUS = 276,                    /* PLUS  */
    MINUS = 277,                   /* MINUS  */
    MULT = 278,                    /* MULT  */
    DIV = 279,                     /* DIV  */
    MOD = 280,                     /* MOD  */
    ASSIGN = 281,                  /* ASSIGN  */
    EQ = 282,                      /* EQ  */
    NE = 283,                      /* NE  */
    LT = 284,                      /* LT  */
    LE = 285,                      /* LE  */
    GT = 286,                      /* GT  */
    GE = 287,                      /* GE  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    NOT = 290,                     /* NOT  */
    INC = 291,                     /* INC  */
    DEC = 292,                     /* DEC  */
    PLUS_ASSIGN = 293,             /* PLUS_ASSIGN  */
    MINUS_ASSIGN = 294,            /* MINUS_ASSIGN  */
    MULT_ASSIGN = 295,             /* MULT_ASSIGN  */
    DIV_ASSIGN = 296,              /* DIV_ASSIGN  */
    LPAREN = 297,                  /* LPAREN  */
    RPAREN = 298,                  /* RPAREN  */
    LBRACE = 299,                  /* LBRACE  */
    RBRACE = 300,                  /* RBRACE  */
    LBRACKET = 301,                /* LBRACKET  */
    RBRACKET = 302,                /* RBRACKET  */
    SEMICOLON = 303,               /* SEMICOLON  */
    COMMA = 304,                   /* COMMA  */
    DOT = 305,                     /* DOT  */
    ARROW = 306                    /* ARROW  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 16 "parser.y"

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

#line 136 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
