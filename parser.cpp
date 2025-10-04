/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

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

#line 86 "parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LITERAL = 3,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 5,             /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 6,                 /* IDENTIFIER  */
  YYSYMBOL_CHAR_LITERAL = 7,               /* CHAR_LITERAL  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_FLOAT_TYPE = 9,                 /* FLOAT_TYPE  */
  YYSYMBOL_CHAR_TYPE = 10,                 /* CHAR_TYPE  */
  YYSYMBOL_VOID = 11,                      /* VOID  */
  YYSYMBOL_IF = 12,                        /* IF  */
  YYSYMBOL_ELSE = 13,                      /* ELSE  */
  YYSYMBOL_WHILE = 14,                     /* WHILE  */
  YYSYMBOL_FOR = 15,                       /* FOR  */
  YYSYMBOL_RETURN = 16,                    /* RETURN  */
  YYSYMBOL_BREAK = 17,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 18,                  /* CONTINUE  */
  YYSYMBOL_STRUCT = 19,                    /* STRUCT  */
  YYSYMBOL_SIZEOF = 20,                    /* SIZEOF  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_MINUS = 22,                     /* MINUS  */
  YYSYMBOL_MULT = 23,                      /* MULT  */
  YYSYMBOL_DIV = 24,                       /* DIV  */
  YYSYMBOL_MOD = 25,                       /* MOD  */
  YYSYMBOL_ASSIGN = 26,                    /* ASSIGN  */
  YYSYMBOL_EQ = 27,                        /* EQ  */
  YYSYMBOL_NE = 28,                        /* NE  */
  YYSYMBOL_LT = 29,                        /* LT  */
  YYSYMBOL_LE = 30,                        /* LE  */
  YYSYMBOL_GT = 31,                        /* GT  */
  YYSYMBOL_GE = 32,                        /* GE  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_INC = 36,                       /* INC  */
  YYSYMBOL_DEC = 37,                       /* DEC  */
  YYSYMBOL_PLUS_ASSIGN = 38,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 39,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 40,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 41,                /* DIV_ASSIGN  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 43,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 44,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 45,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 46,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 47,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 48,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 49,                     /* COMMA  */
  YYSYMBOL_DOT = 50,                       /* DOT  */
  YYSYMBOL_ARROW = 51,                     /* ARROW  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_declaration_list = 54,          /* declaration_list  */
  YYSYMBOL_declaration = 55,               /* declaration  */
  YYSYMBOL_variable_declaration = 56,      /* variable_declaration  */
  YYSYMBOL_function_declaration = 57,      /* function_declaration  */
  YYSYMBOL_parameter_list_opt = 58,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 59,            /* parameter_list  */
  YYSYMBOL_parameter = 60,                 /* parameter  */
  YYSYMBOL_struct_declaration = 61,        /* struct_declaration  */
  YYSYMBOL_type_specifier = 62,            /* type_specifier  */
  YYSYMBOL_compound_statement = 63,        /* compound_statement  */
  YYSYMBOL_statement_list = 64,            /* statement_list  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_expression_statement = 66,      /* expression_statement  */
  YYSYMBOL_selection_statement = 67,       /* selection_statement  */
  YYSYMBOL_iteration_statement = 68,       /* iteration_statement  */
  YYSYMBOL_jump_statement = 69,            /* jump_statement  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_assignment_expression = 71,     /* assignment_expression  */
  YYSYMBOL_conditional_expression = 72,    /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 73,     /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 74,    /* logical_and_expression  */
  YYSYMBOL_equality_expression = 75,       /* equality_expression  */
  YYSYMBOL_relational_expression = 76,     /* relational_expression  */
  YYSYMBOL_additive_expression = 77,       /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 78, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 79,          /* unary_expression  */
  YYSYMBOL_unary_operator = 80,            /* unary_operator  */
  YYSYMBOL_postfix_expression = 81,        /* postfix_expression  */
  YYSYMBOL_primary_expression = 82,        /* primary_expression  */
  YYSYMBOL_argument_expression_list_opt = 83, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 84   /* argument_expression_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   322

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  97
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,   102,   106,   113,   114,   115,   119,   123,
     127,   137,   147,   159,   160,   164,   171,   181,   185,   192,
     200,   201,   202,   203,   207,   217,   223,   227,   234,   235,
     236,   237,   238,   239,   243,   246,   252,   255,   261,   264,
     268,   275,   278,   281,   284,   290,   294,   295,   298,   301,
     304,   307,   313,   317,   318,   324,   325,   331,   332,   335,
     341,   342,   345,   348,   351,   357,   358,   361,   367,   368,
     371,   374,   380,   381,   384,   387,   390,   397,   398,   399,
     400,   404,   405,   408,   419,   423,   427,   430,   436,   440,
     443,   446,   449,   453,   459,   460,   464,   468
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "INT_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "IDENTIFIER", "CHAR_LITERAL", "INT",
  "FLOAT_TYPE", "CHAR_TYPE", "VOID", "IF", "ELSE", "WHILE", "FOR",
  "RETURN", "BREAK", "CONTINUE", "STRUCT", "SIZEOF", "PLUS", "MINUS",
  "MULT", "DIV", "MOD", "ASSIGN", "EQ", "NE", "LT", "LE", "GT", "GE",
  "AND", "OR", "NOT", "INC", "DEC", "PLUS_ASSIGN", "MINUS_ASSIGN",
  "MULT_ASSIGN", "DIV_ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT", "ARROW", "$accept",
  "program", "declaration_list", "declaration", "variable_declaration",
  "function_declaration", "parameter_list_opt", "parameter_list",
  "parameter", "struct_declaration", "type_specifier",
  "compound_statement", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "conditional_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "argument_expression_list_opt", "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-142)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,  -142,  -142,  -142,  -142,     0,    17,    85,  -142,  -142,
    -142,  -142,    14,    -7,  -142,  -142,   -23,    -4,   280,   131,
      45,  -142,    15,  -142,  -142,  -142,  -142,  -142,   280,  -142,
    -142,  -142,  -142,   280,   280,   280,    29,  -142,    16,    50,
      18,   154,    40,    10,    13,   280,   101,  -142,    48,    49,
    -142,    91,    55,  -142,  -142,  -142,  -142,    60,  -142,  -142,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,  -142,  -142,
    -142,   280,   280,   105,   107,   -26,   131,    61,    66,  -142,
      50,  -142,    18,   154,   154,    40,    40,    40,    40,    10,
      10,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,  -142,
      72,    83,    97,  -142,  -142,   113,  -142,  -142,  -142,    98,
    -142,  -142,   280,  -142,   104,   111,   112,     7,   108,   124,
    -142,  -142,  -142,   153,  -142,   159,  -142,  -142,  -142,  -142,
    -142,   130,  -142,  -142,   280,   280,   205,  -142,   143,  -142,
    -142,   -22,  -142,  -142,  -142,   117,   149,   205,  -142,    64,
      64,   271,   180,  -142,    64,   155,    64,  -142,    64,  -142,
    -142
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    20,    21,    22,    23,     0,     0,     2,     3,     5,
       6,     7,     0,     0,     1,     4,     0,     0,     0,    13,
       0,     8,     0,    89,    90,    92,    88,    91,     0,    77,
      78,    80,    79,     0,     0,     0,     0,    46,    52,    53,
      55,    57,    60,    65,    68,     0,    72,    81,     0,    14,
      15,     0,     0,    19,    76,    73,    74,     0,    45,     9,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    75,    86,
      87,    94,     0,     0,     0,     0,     0,    17,     0,    93,
      54,    68,    56,    58,    59,    61,    63,    62,    64,    66,
      67,    69,    70,    71,    47,    48,    49,    50,    51,    96,
       0,    95,     0,    84,    85,     0,    12,    11,    16,     0,
      10,    83,     0,    82,     0,     0,     0,     0,     0,     0,
      25,    35,    33,     0,    29,     0,    26,    28,    30,    31,
      32,     0,    18,    97,     0,     0,     0,    42,     0,    43,
      44,     0,    24,    27,    34,     0,     0,     0,    41,     0,
       0,     0,    36,    38,     0,     0,     0,    40,     0,    37,
      39
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -142,  -142,  -142,   190,     8,  -142,  -142,  -142,   114,  -142,
       2,   120,  -142,  -128,  -141,  -142,  -142,  -142,   -35,   -17,
    -142,  -142,   139,   141,     3,   123,    21,   201,  -142,  -142,
    -142,  -142,  -142
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,   132,    10,    48,    49,    50,    11,
     133,   134,   135,   136,   137,   138,   139,   140,   141,    58,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,   110,   111
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      57,    36,    12,    18,    18,   157,    13,   153,     9,    12,
      23,    24,    25,    26,    27,     9,   161,    14,   115,    19,
      16,    51,   116,    20,    20,    21,    21,    28,    29,    30,
      31,   162,   163,    70,    71,    72,   167,    17,   169,    73,
     170,    22,    32,    33,    34,    62,    63,   112,    52,    35,
      60,    74,    75,    76,    77,   147,   104,   105,   106,   107,
     108,    68,    69,    53,   109,    93,    94,    23,    24,    25,
      26,    27,     1,     2,     3,     4,   124,    59,   125,   126,
     127,   128,   129,    61,    28,    29,    30,    31,    51,    99,
     100,    85,   148,     1,     2,     3,     4,    87,    86,    32,
      33,    34,    88,    89,     5,   143,    35,   119,   115,   155,
     156,   113,   131,   114,   120,   121,    23,    24,    25,    26,
      27,     1,     2,     3,     4,   124,   165,   125,   126,   127,
     128,   129,   122,    28,    29,    30,    31,    79,    80,     1,
       2,     3,     4,    81,   123,   142,   144,    82,    32,    33,
      34,    83,    84,   145,   146,    35,   149,   115,   130,   151,
     159,   131,    23,    24,    25,    26,    27,     1,     2,     3,
       4,   124,   150,   125,   126,   127,   128,   129,   154,    28,
      29,    30,    31,    64,    65,    66,    67,    95,    96,    97,
      98,   158,   160,   166,    32,    33,    34,    15,   168,    90,
     118,    35,    92,   115,   152,   117,     0,   131,    23,    24,
      25,    26,    27,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    28,    29,    30,    31,    54,
       0,     0,     0,     0,    55,    56,     0,     0,     0,     0,
      32,    33,    34,     0,     0,     0,    78,    35,     0,     0,
       0,     0,     0,   131,     0,     0,     0,     0,     0,     0,
       0,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,   101,   102,   103,    23,    24,    25,    26,    27,     0,
       0,     0,     0,    23,    24,    25,    26,    27,     0,     0,
       0,    28,    29,    30,    31,     0,     0,     0,     0,     0,
      28,    29,    30,    31,     0,     0,    32,    33,    34,     0,
       0,     0,     0,    35,   164,    32,    33,    34,     0,     0,
       0,     0,    35
};

static const yytype_int16 yycheck[] =
{
      35,    18,     0,    26,    26,   146,     6,   135,     0,     7,
       3,     4,     5,     6,     7,     7,   157,     0,    44,    42,
       6,    19,    48,    46,    46,    48,    48,    20,    21,    22,
      23,   159,   160,    23,    24,    25,   164,    44,   166,    26,
     168,    45,    35,    36,    37,    27,    28,    82,     3,    42,
      34,    38,    39,    40,    41,    48,    73,    74,    75,    76,
      77,    21,    22,    48,    81,    62,    63,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    48,    14,    15,
      16,    17,    18,    33,    20,    21,    22,    23,    86,    68,
      69,    43,   127,     8,     9,    10,    11,     6,    49,    35,
      36,    37,    47,    43,    19,   122,    42,    46,    44,   144,
     145,     6,    48,     6,    48,    43,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,   161,    14,    15,    16,
      17,    18,    49,    20,    21,    22,    23,    36,    37,     8,
       9,    10,    11,    42,    47,    47,    42,    46,    35,    36,
      37,    50,    51,    42,    42,    42,    48,    44,    45,     6,
      43,    48,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    48,    14,    15,    16,    17,    18,    48,    20,
      21,    22,    23,    29,    30,    31,    32,    64,    65,    66,
      67,    48,    43,    13,    35,    36,    37,     7,    43,    60,
      86,    42,    61,    44,    45,    85,    -1,    48,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    28,
      -1,    -1,    -1,    -1,    33,    34,    -1,    -1,    -1,    -1,
      35,    36,    37,    -1,    -1,    -1,    45,    42,    -1,    -1,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,    -1,    -1,
      -1,    20,    21,    22,    23,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    35,    36,    37,    -1,
      -1,    -1,    -1,    42,    43,    35,    36,    37,    -1,    -1,
      -1,    -1,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     8,     9,    10,    11,    19,    53,    54,    55,    56,
      57,    61,    62,     6,     0,    55,     6,    44,    26,    42,
      46,    48,    45,     3,     4,     5,     6,     7,    20,    21,
      22,    23,    35,    36,    37,    42,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    58,    59,
      60,    62,     3,    48,    79,    79,    79,    70,    71,    48,
      34,    33,    27,    28,    29,    30,    31,    32,    21,    22,
      23,    24,    25,    26,    38,    39,    40,    41,    79,    36,
      37,    42,    46,    50,    51,    43,    49,     6,    47,    43,
      74,    79,    75,    76,    76,    77,    77,    77,    77,    78,
      78,    79,    79,    79,    71,    71,    71,    71,    71,    71,
      83,    84,    70,     6,     6,    44,    48,    63,    60,    46,
      48,    43,    49,    47,    12,    14,    15,    16,    17,    18,
      45,    48,    56,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    47,    71,    42,    42,    42,    48,    70,    48,
      48,     6,    45,    65,    48,    70,    70,    66,    48,    43,
      43,    66,    65,    65,    43,    70,    13,    65,    43,    65,
      65
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    55,    56,    56,
      56,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      62,    62,    62,    62,    63,    63,    64,    64,    65,    65,
      65,    65,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    69,    69,    70,    71,    71,    71,    71,
      71,    71,    72,    73,    73,    74,    74,    75,    75,    75,
      76,    76,    76,    76,    76,    77,    77,    77,    78,    78,
      78,    78,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    81,    81,    81,    81,    81,    81,    81,    82,    82,
      82,    82,    82,    82,    83,    83,    84,    84
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     3,     5,
       6,     6,     6,     0,     1,     1,     3,     2,     4,     5,
       1,     1,     1,     1,     3,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     5,     7,     5,     7,
       6,     3,     2,     2,     2,     1,     1,     3,     3,     3,
       3,     3,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     4,     4,     3,     3,     2,     2,     1,     1,
       1,     1,     1,     3,     0,     1,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: declaration_list  */
#line 89 "parser.y"
                     {
        root = new Program();
        if ((yyvsp[0].decl_list)) {
            for (auto& decl : *(yyvsp[0].decl_list)) {
                root->declarations.push_back(std::unique_ptr<Declaration>(decl));
            }
            delete (yyvsp[0].decl_list);
        }
        (yyval.program) = root;
    }
#line 1322 "parser.cpp"
    break;

  case 3: /* declaration_list: declaration  */
#line 102 "parser.y"
                {
        (yyval.decl_list) = new std::vector<Declaration*>();
        if ((yyvsp[0].decl)) (yyval.decl_list)->push_back((yyvsp[0].decl));
    }
#line 1331 "parser.cpp"
    break;

  case 4: /* declaration_list: declaration_list declaration  */
#line 106 "parser.y"
                                   {
        (yyval.decl_list) = (yyvsp[-1].decl_list);
        if ((yyvsp[0].decl)) (yyval.decl_list)->push_back((yyvsp[0].decl));
    }
#line 1340 "parser.cpp"
    break;

  case 5: /* declaration: variable_declaration  */
#line 113 "parser.y"
                         { (yyval.decl) = (yyvsp[0].decl); }
#line 1346 "parser.cpp"
    break;

  case 6: /* declaration: function_declaration  */
#line 114 "parser.y"
                           { (yyval.decl) = (yyvsp[0].decl); }
#line 1352 "parser.cpp"
    break;

  case 7: /* declaration: struct_declaration  */
#line 115 "parser.y"
                         { (yyval.decl) = (yyvsp[0].decl); }
#line 1358 "parser.cpp"
    break;

  case 8: /* variable_declaration: type_specifier IDENTIFIER SEMICOLON  */
#line 119 "parser.y"
                                        {
        (yyval.decl) = new VariableDeclaration((yyvsp[-1].str_val), (yyvsp[-2].type));
        free((yyvsp[-1].str_val));
    }
#line 1367 "parser.cpp"
    break;

  case 9: /* variable_declaration: type_specifier IDENTIFIER ASSIGN assignment_expression SEMICOLON  */
#line 123 "parser.y"
                                                                       {
        (yyval.decl) = new VariableDeclaration((yyvsp[-3].str_val), (yyvsp[-4].type), std::unique_ptr<Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].str_val));
    }
#line 1376 "parser.cpp"
    break;

  case 10: /* variable_declaration: type_specifier IDENTIFIER LBRACKET INT_LITERAL RBRACKET SEMICOLON  */
#line 127 "parser.y"
                                                                        {
        auto var = new VariableDeclaration((yyvsp[-4].str_val), (yyvsp[-5].type));
        var->is_array = true;
        var->array_size = (yyvsp[-2].int_val);
        (yyval.decl) = var;
        free((yyvsp[-4].str_val));
    }
#line 1388 "parser.cpp"
    break;

  case 11: /* function_declaration: type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement  */
#line 137 "parser.y"
                                                                                  {
        auto func = new FunctionDeclaration((yyvsp[-4].str_val), (yyvsp[-5].type));
        if ((yyvsp[-2].param_list)) {
            func->parameters = *(yyvsp[-2].param_list);
            delete (yyvsp[-2].param_list);
        }
        func->body = std::unique_ptr<Block>((yyvsp[0].block));
        (yyval.decl) = func;
        free((yyvsp[-4].str_val));
    }
#line 1403 "parser.cpp"
    break;

  case 12: /* function_declaration: type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN SEMICOLON  */
#line 147 "parser.y"
                                                                           {
        auto func = new FunctionDeclaration((yyvsp[-4].str_val), (yyvsp[-5].type));
        if ((yyvsp[-2].param_list)) {
            func->parameters = *(yyvsp[-2].param_list);
            delete (yyvsp[-2].param_list);
        }
        (yyval.decl) = func;
        free((yyvsp[-4].str_val));
    }
#line 1417 "parser.cpp"
    break;

  case 13: /* parameter_list_opt: %empty  */
#line 159 "parser.y"
                { (yyval.param_list) = nullptr; }
#line 1423 "parser.cpp"
    break;

  case 14: /* parameter_list_opt: parameter_list  */
#line 160 "parser.y"
                     { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1429 "parser.cpp"
    break;

  case 15: /* parameter_list: parameter  */
#line 164 "parser.y"
              {
        (yyval.param_list) = new std::vector<Parameter>();
        if ((yyvsp[0].param)) {
            (yyval.param_list)->push_back(*(yyvsp[0].param));
            delete (yyvsp[0].param);
        }
    }
#line 1441 "parser.cpp"
    break;

  case 16: /* parameter_list: parameter_list COMMA parameter  */
#line 171 "parser.y"
                                     {
        (yyval.param_list) = (yyvsp[-2].param_list);
        if ((yyvsp[0].param)) {
            (yyval.param_list)->push_back(*(yyvsp[0].param));
            delete (yyvsp[0].param);
        }
    }
#line 1453 "parser.cpp"
    break;

  case 17: /* parameter: type_specifier IDENTIFIER  */
#line 181 "parser.y"
                              {
        (yyval.param) = new Parameter((yyvsp[0].str_val), (yyvsp[-1].type));
        free((yyvsp[0].str_val));
    }
#line 1462 "parser.cpp"
    break;

  case 18: /* parameter: type_specifier IDENTIFIER LBRACKET RBRACKET  */
#line 185 "parser.y"
                                                  {
        (yyval.param) = new Parameter((yyvsp[-2].str_val), (yyvsp[-3].type), true);
        free((yyvsp[-2].str_val));
    }
#line 1471 "parser.cpp"
    break;

  case 19: /* struct_declaration: STRUCT IDENTIFIER LBRACE RBRACE SEMICOLON  */
#line 192 "parser.y"
                                              {
        auto struct_decl = new StructDeclaration((yyvsp[-3].str_val));
        (yyval.decl) = struct_decl;
        free((yyvsp[-3].str_val));
    }
#line 1481 "parser.cpp"
    break;

  case 20: /* type_specifier: INT  */
#line 200 "parser.y"
        { (yyval.type) = Expression::INT_TYPE; }
#line 1487 "parser.cpp"
    break;

  case 21: /* type_specifier: FLOAT_TYPE  */
#line 201 "parser.y"
                 { (yyval.type) = Expression::FLOAT_TYPE; }
#line 1493 "parser.cpp"
    break;

  case 22: /* type_specifier: CHAR_TYPE  */
#line 202 "parser.y"
                { (yyval.type) = Expression::CHAR_TYPE; }
#line 1499 "parser.cpp"
    break;

  case 23: /* type_specifier: VOID  */
#line 203 "parser.y"
           { (yyval.type) = Expression::VOID_TYPE; }
#line 1505 "parser.cpp"
    break;

  case 24: /* compound_statement: LBRACE statement_list RBRACE  */
#line 207 "parser.y"
                                 {
        auto block = new Block();
        if ((yyvsp[-1].stmt_list)) {
            for (auto& stmt : *(yyvsp[-1].stmt_list)) {
                block->statements.push_back(std::unique_ptr<Statement>(stmt));
            }
            delete (yyvsp[-1].stmt_list);
        }
        (yyval.block) = block;
    }
#line 1520 "parser.cpp"
    break;

  case 25: /* compound_statement: LBRACE RBRACE  */
#line 217 "parser.y"
                    {
        (yyval.block) = new Block();
    }
#line 1528 "parser.cpp"
    break;

  case 26: /* statement_list: statement  */
#line 223 "parser.y"
              {
        (yyval.stmt_list) = new std::vector<Statement*>();
        if ((yyvsp[0].stmt)) (yyval.stmt_list)->push_back((yyvsp[0].stmt));
    }
#line 1537 "parser.cpp"
    break;

  case 27: /* statement_list: statement_list statement  */
#line 227 "parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) (yyval.stmt_list)->push_back((yyvsp[0].stmt));
    }
#line 1546 "parser.cpp"
    break;

  case 28: /* statement: expression_statement  */
#line 234 "parser.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1552 "parser.cpp"
    break;

  case 29: /* statement: compound_statement  */
#line 235 "parser.y"
                         { (yyval.stmt) = (yyvsp[0].block); }
#line 1558 "parser.cpp"
    break;

  case 30: /* statement: selection_statement  */
#line 236 "parser.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1564 "parser.cpp"
    break;

  case 31: /* statement: iteration_statement  */
#line 237 "parser.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1570 "parser.cpp"
    break;

  case 32: /* statement: jump_statement  */
#line 238 "parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1576 "parser.cpp"
    break;

  case 33: /* statement: variable_declaration  */
#line 239 "parser.y"
                           { (yyval.stmt) = (yyvsp[0].decl); }
#line 1582 "parser.cpp"
    break;

  case 34: /* expression_statement: expression SEMICOLON  */
#line 243 "parser.y"
                         {
        (yyval.stmt) = new ExpressionStatement(std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 1590 "parser.cpp"
    break;

  case 35: /* expression_statement: SEMICOLON  */
#line 246 "parser.y"
                {
        (yyval.stmt) = new ExpressionStatement(nullptr);
    }
#line 1598 "parser.cpp"
    break;

  case 36: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 252 "parser.y"
                                          {
        (yyval.stmt) = new IfStatement(std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1606 "parser.cpp"
    break;

  case 37: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 255 "parser.y"
                                                           {
        (yyval.stmt) = new IfStatement(std::unique_ptr<Expression>((yyvsp[-4].expr)), std::unique_ptr<Statement>((yyvsp[-2].stmt)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1614 "parser.cpp"
    break;

  case 38: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 261 "parser.y"
                                             {
        (yyval.stmt) = new WhileStatement(std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1622 "parser.cpp"
    break;

  case 39: /* iteration_statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 264 "parser.y"
                                                                                       {
        (yyval.stmt) = new ForStatement(std::unique_ptr<Statement>((yyvsp[-4].stmt)), std::unique_ptr<Expression>((yyvsp[-3].stmt)->expression.release()), std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
        delete (yyvsp[-3].stmt);
    }
#line 1631 "parser.cpp"
    break;

  case 40: /* iteration_statement: FOR LPAREN expression_statement expression_statement RPAREN statement  */
#line 268 "parser.y"
                                                                            {
        (yyval.stmt) = new ForStatement(std::unique_ptr<Statement>((yyvsp[-3].stmt)), std::unique_ptr<Expression>((yyvsp[-2].stmt)->expression.release()), nullptr, std::unique_ptr<Statement>((yyvsp[0].stmt)));
        delete (yyvsp[-2].stmt);
    }
#line 1640 "parser.cpp"
    break;

  case 41: /* jump_statement: RETURN expression SEMICOLON  */
#line 275 "parser.y"
                                {
        (yyval.stmt) = new ReturnStatement(std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 1648 "parser.cpp"
    break;

  case 42: /* jump_statement: RETURN SEMICOLON  */
#line 278 "parser.y"
                       {
        (yyval.stmt) = new ReturnStatement();
    }
#line 1656 "parser.cpp"
    break;

  case 43: /* jump_statement: BREAK SEMICOLON  */
#line 281 "parser.y"
                      {
        (yyval.stmt) = new BreakStatement();
    }
#line 1664 "parser.cpp"
    break;

  case 44: /* jump_statement: CONTINUE SEMICOLON  */
#line 284 "parser.y"
                         {
        (yyval.stmt) = new ContinueStatement();
    }
#line 1672 "parser.cpp"
    break;

  case 45: /* expression: assignment_expression  */
#line 290 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1678 "parser.cpp"
    break;

  case 46: /* assignment_expression: conditional_expression  */
#line 294 "parser.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1684 "parser.cpp"
    break;

  case 47: /* assignment_expression: unary_expression ASSIGN assignment_expression  */
#line 295 "parser.y"
                                                    {
        (yyval.expr) = new BinaryOp(BinaryOp::ASSIGN, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1692 "parser.cpp"
    break;

  case 48: /* assignment_expression: unary_expression PLUS_ASSIGN assignment_expression  */
#line 298 "parser.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::PLUS_ASSIGN, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1700 "parser.cpp"
    break;

  case 49: /* assignment_expression: unary_expression MINUS_ASSIGN assignment_expression  */
#line 301 "parser.y"
                                                          {
        (yyval.expr) = new BinaryOp(BinaryOp::MINUS_ASSIGN, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1708 "parser.cpp"
    break;

  case 50: /* assignment_expression: unary_expression MULT_ASSIGN assignment_expression  */
#line 304 "parser.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::MULT_ASSIGN, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1716 "parser.cpp"
    break;

  case 51: /* assignment_expression: unary_expression DIV_ASSIGN assignment_expression  */
#line 307 "parser.y"
                                                        {
        (yyval.expr) = new BinaryOp(BinaryOp::DIV_ASSIGN, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1724 "parser.cpp"
    break;

  case 52: /* conditional_expression: logical_or_expression  */
#line 313 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1730 "parser.cpp"
    break;

  case 53: /* logical_or_expression: logical_and_expression  */
#line 317 "parser.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1736 "parser.cpp"
    break;

  case 54: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 318 "parser.y"
                                                      {
        (yyval.expr) = new BinaryOp(BinaryOp::OR, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1744 "parser.cpp"
    break;

  case 55: /* logical_and_expression: equality_expression  */
#line 324 "parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1750 "parser.cpp"
    break;

  case 56: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 325 "parser.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::AND, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1758 "parser.cpp"
    break;

  case 57: /* equality_expression: relational_expression  */
#line 331 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1764 "parser.cpp"
    break;

  case 58: /* equality_expression: equality_expression EQ relational_expression  */
#line 332 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::EQ, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1772 "parser.cpp"
    break;

  case 59: /* equality_expression: equality_expression NE relational_expression  */
#line 335 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::NE, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1780 "parser.cpp"
    break;

  case 60: /* relational_expression: additive_expression  */
#line 341 "parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1786 "parser.cpp"
    break;

  case 61: /* relational_expression: relational_expression LT additive_expression  */
#line 342 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::LT, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1794 "parser.cpp"
    break;

  case 62: /* relational_expression: relational_expression GT additive_expression  */
#line 345 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::GT, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1802 "parser.cpp"
    break;

  case 63: /* relational_expression: relational_expression LE additive_expression  */
#line 348 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::LE, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1810 "parser.cpp"
    break;

  case 64: /* relational_expression: relational_expression GE additive_expression  */
#line 351 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::GE, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1818 "parser.cpp"
    break;

  case 65: /* additive_expression: multiplicative_expression  */
#line 357 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 1824 "parser.cpp"
    break;

  case 66: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 358 "parser.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::ADD, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1832 "parser.cpp"
    break;

  case 67: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 361 "parser.y"
                                                          {
        (yyval.expr) = new BinaryOp(BinaryOp::SUB, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1840 "parser.cpp"
    break;

  case 68: /* multiplicative_expression: unary_expression  */
#line 367 "parser.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 1846 "parser.cpp"
    break;

  case 69: /* multiplicative_expression: multiplicative_expression MULT unary_expression  */
#line 368 "parser.y"
                                                      {
        (yyval.expr) = new BinaryOp(BinaryOp::MUL, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1854 "parser.cpp"
    break;

  case 70: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 371 "parser.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::DIV, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1862 "parser.cpp"
    break;

  case 71: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 374 "parser.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::MOD, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1870 "parser.cpp"
    break;

  case 72: /* unary_expression: postfix_expression  */
#line 380 "parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 1876 "parser.cpp"
    break;

  case 73: /* unary_expression: INC unary_expression  */
#line 381 "parser.y"
                           {
        (yyval.expr) = new UnaryOp(UnaryOp::PRE_INC, std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1884 "parser.cpp"
    break;

  case 74: /* unary_expression: DEC unary_expression  */
#line 384 "parser.y"
                           {
        (yyval.expr) = new UnaryOp(UnaryOp::PRE_DEC, std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1892 "parser.cpp"
    break;

  case 75: /* unary_expression: unary_operator unary_expression  */
#line 387 "parser.y"
                                      {
        (yyval.expr) = new UnaryOp((yyvsp[-1].un_op), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 1900 "parser.cpp"
    break;

  case 76: /* unary_expression: SIZEOF unary_expression  */
#line 390 "parser.y"
                              {
        // For simplicity, treat sizeof as unary operator
        (yyval.expr) = new UnaryOp(UnaryOp::ADDRESS_OF, std::unique_ptr<Expression>((yyvsp[0].expr))); // placeholder
    }
#line 1909 "parser.cpp"
    break;

  case 77: /* unary_operator: PLUS  */
#line 397 "parser.y"
         { (yyval.un_op) = UnaryOp::PLUS; }
#line 1915 "parser.cpp"
    break;

  case 78: /* unary_operator: MINUS  */
#line 398 "parser.y"
            { (yyval.un_op) = UnaryOp::MINUS; }
#line 1921 "parser.cpp"
    break;

  case 79: /* unary_operator: NOT  */
#line 399 "parser.y"
          { (yyval.un_op) = UnaryOp::NOT; }
#line 1927 "parser.cpp"
    break;

  case 80: /* unary_operator: MULT  */
#line 400 "parser.y"
           { (yyval.un_op) = UnaryOp::DEREF; }
#line 1933 "parser.cpp"
    break;

  case 81: /* postfix_expression: primary_expression  */
#line 404 "parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 1939 "parser.cpp"
    break;

  case 82: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 405 "parser.y"
                                                      {
        (yyval.expr) = new ArrayAccess(std::unique_ptr<Expression>((yyvsp[-3].expr)), std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 1947 "parser.cpp"
    break;

  case 83: /* postfix_expression: postfix_expression LPAREN argument_expression_list_opt RPAREN  */
#line 408 "parser.y"
                                                                    {
        auto func_call = new FunctionCall(static_cast<Identifier*>((yyvsp[-3].expr))->name);
        if ((yyvsp[-1].expr_list)) {
            for (auto& expr : *(yyvsp[-1].expr_list)) {
                func_call->arguments.push_back(std::unique_ptr<Expression>(expr));
            }
            delete (yyvsp[-1].expr_list);
        }
        delete (yyvsp[-3].expr);
        (yyval.expr) = func_call;
    }
#line 1963 "parser.cpp"
    break;

  case 84: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 419 "parser.y"
                                        {
        (yyval.expr) = new MemberAccess(std::unique_ptr<Expression>((yyvsp[-2].expr)), (yyvsp[0].str_val), false);
        free((yyvsp[0].str_val));
    }
#line 1972 "parser.cpp"
    break;

  case 85: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 423 "parser.y"
                                          {
        (yyval.expr) = new MemberAccess(std::unique_ptr<Expression>((yyvsp[-2].expr)), (yyvsp[0].str_val), true);
        free((yyvsp[0].str_val));
    }
#line 1981 "parser.cpp"
    break;

  case 86: /* postfix_expression: postfix_expression INC  */
#line 427 "parser.y"
                             {
        (yyval.expr) = new UnaryOp(UnaryOp::POST_INC, std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 1989 "parser.cpp"
    break;

  case 87: /* postfix_expression: postfix_expression DEC  */
#line 430 "parser.y"
                             {
        (yyval.expr) = new UnaryOp(UnaryOp::POST_DEC, std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 1997 "parser.cpp"
    break;

  case 88: /* primary_expression: IDENTIFIER  */
#line 436 "parser.y"
               {
        (yyval.expr) = new Identifier((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 2006 "parser.cpp"
    break;

  case 89: /* primary_expression: INT_LITERAL  */
#line 440 "parser.y"
                  {
        (yyval.expr) = new IntLiteral((yyvsp[0].int_val));
    }
#line 2014 "parser.cpp"
    break;

  case 90: /* primary_expression: FLOAT_LITERAL  */
#line 443 "parser.y"
                    {
        (yyval.expr) = new FloatLiteral((yyvsp[0].float_val));
    }
#line 2022 "parser.cpp"
    break;

  case 91: /* primary_expression: CHAR_LITERAL  */
#line 446 "parser.y"
                   {
        (yyval.expr) = new CharLiteral((yyvsp[0].char_val));
    }
#line 2030 "parser.cpp"
    break;

  case 92: /* primary_expression: STRING_LITERAL  */
#line 449 "parser.y"
                     {
        (yyval.expr) = new StringLiteral((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 2039 "parser.cpp"
    break;

  case 93: /* primary_expression: LPAREN expression RPAREN  */
#line 453 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2047 "parser.cpp"
    break;

  case 94: /* argument_expression_list_opt: %empty  */
#line 459 "parser.y"
                { (yyval.expr_list) = nullptr; }
#line 2053 "parser.cpp"
    break;

  case 95: /* argument_expression_list_opt: argument_expression_list  */
#line 460 "parser.y"
                               { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 2059 "parser.cpp"
    break;

  case 96: /* argument_expression_list: assignment_expression  */
#line 464 "parser.y"
                          {
        (yyval.expr_list) = new std::vector<Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 2068 "parser.cpp"
    break;

  case 97: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 468 "parser.y"
                                                           {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 2077 "parser.cpp"
    break;


#line 2081 "parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 474 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
}
