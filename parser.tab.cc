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
#line 1 "parser_simple.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ast.h"

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

Program* root = nullptr;

#line 84 "parser.tab.cc"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_INT_LITERAL = 3,                /* INT_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 4,              /* FLOAT_LITERAL  */
  YYSYMBOL_DOUBLE_LITERAL = 5,             /* DOUBLE_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 6,             /* STRING_LITERAL  */
  YYSYMBOL_IDENTIFIER = 7,                 /* IDENTIFIER  */
  YYSYMBOL_CHAR_LITERAL = 8,               /* CHAR_LITERAL  */
  YYSYMBOL_AUTO = 9,                       /* AUTO  */
  YYSYMBOL_BREAK = 10,                     /* BREAK  */
  YYSYMBOL_CASE = 11,                      /* CASE  */
  YYSYMBOL_CHAR_TYPE = 12,                 /* CHAR_TYPE  */
  YYSYMBOL_CONST = 13,                     /* CONST  */
  YYSYMBOL_CONTINUE = 14,                  /* CONTINUE  */
  YYSYMBOL_DEFAULT = 15,                   /* DEFAULT  */
  YYSYMBOL_DO = 16,                        /* DO  */
  YYSYMBOL_DOUBLE_TYPE = 17,               /* DOUBLE_TYPE  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_ENUM = 19,                      /* ENUM  */
  YYSYMBOL_EXTERN = 20,                    /* EXTERN  */
  YYSYMBOL_FLOAT_TYPE = 21,                /* FLOAT_TYPE  */
  YYSYMBOL_FOR = 22,                       /* FOR  */
  YYSYMBOL_GOTO = 23,                      /* GOTO  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_INLINE = 25,                    /* INLINE  */
  YYSYMBOL_INT = 26,                       /* INT  */
  YYSYMBOL_LONG = 27,                      /* LONG  */
  YYSYMBOL_REGISTER = 28,                  /* REGISTER  */
  YYSYMBOL_RESTRICT = 29,                  /* RESTRICT  */
  YYSYMBOL_RETURN = 30,                    /* RETURN  */
  YYSYMBOL_SHORT = 31,                     /* SHORT  */
  YYSYMBOL_SIGNED = 32,                    /* SIGNED  */
  YYSYMBOL_SIZEOF = 33,                    /* SIZEOF  */
  YYSYMBOL_STATIC = 34,                    /* STATIC  */
  YYSYMBOL_STRUCT = 35,                    /* STRUCT  */
  YYSYMBOL_SWITCH = 36,                    /* SWITCH  */
  YYSYMBOL_TYPEDEF = 37,                   /* TYPEDEF  */
  YYSYMBOL_UNION = 38,                     /* UNION  */
  YYSYMBOL_UNSIGNED = 39,                  /* UNSIGNED  */
  YYSYMBOL_VOID = 40,                      /* VOID  */
  YYSYMBOL_VOLATILE = 41,                  /* VOLATILE  */
  YYSYMBOL_WHILE = 42,                     /* WHILE  */
  YYSYMBOL_PLUS = 43,                      /* PLUS  */
  YYSYMBOL_MINUS = 44,                     /* MINUS  */
  YYSYMBOL_MULT = 45,                      /* MULT  */
  YYSYMBOL_DIV = 46,                       /* DIV  */
  YYSYMBOL_MOD = 47,                       /* MOD  */
  YYSYMBOL_INC = 48,                       /* INC  */
  YYSYMBOL_DEC = 49,                       /* DEC  */
  YYSYMBOL_ASSIGN = 50,                    /* ASSIGN  */
  YYSYMBOL_PLUS_ASSIGN = 51,               /* PLUS_ASSIGN  */
  YYSYMBOL_MINUS_ASSIGN = 52,              /* MINUS_ASSIGN  */
  YYSYMBOL_MULT_ASSIGN = 53,               /* MULT_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 54,                /* DIV_ASSIGN  */
  YYSYMBOL_MOD_ASSIGN = 55,                /* MOD_ASSIGN  */
  YYSYMBOL_LSHIFT_ASSIGN = 56,             /* LSHIFT_ASSIGN  */
  YYSYMBOL_RSHIFT_ASSIGN = 57,             /* RSHIFT_ASSIGN  */
  YYSYMBOL_AND_ASSIGN = 58,                /* AND_ASSIGN  */
  YYSYMBOL_OR_ASSIGN = 59,                 /* OR_ASSIGN  */
  YYSYMBOL_XOR_ASSIGN = 60,                /* XOR_ASSIGN  */
  YYSYMBOL_EQ = 61,                        /* EQ  */
  YYSYMBOL_NE = 62,                        /* NE  */
  YYSYMBOL_LT = 63,                        /* LT  */
  YYSYMBOL_LE = 64,                        /* LE  */
  YYSYMBOL_GT = 65,                        /* GT  */
  YYSYMBOL_GE = 66,                        /* GE  */
  YYSYMBOL_AND = 67,                       /* AND  */
  YYSYMBOL_OR = 68,                        /* OR  */
  YYSYMBOL_NOT = 69,                       /* NOT  */
  YYSYMBOL_BITWISE_AND = 70,               /* BITWISE_AND  */
  YYSYMBOL_BITWISE_OR = 71,                /* BITWISE_OR  */
  YYSYMBOL_BITWISE_XOR = 72,               /* BITWISE_XOR  */
  YYSYMBOL_BITWISE_NOT = 73,               /* BITWISE_NOT  */
  YYSYMBOL_LSHIFT = 74,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 75,                    /* RSHIFT  */
  YYSYMBOL_QUESTION = 76,                  /* QUESTION  */
  YYSYMBOL_COLON = 77,                     /* COLON  */
  YYSYMBOL_LPAREN = 78,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 79,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 80,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 81,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 82,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 83,                  /* RBRACKET  */
  YYSYMBOL_SEMICOLON = 84,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 85,                     /* COMMA  */
  YYSYMBOL_DOT = 86,                       /* DOT  */
  YYSYMBOL_ARROW = 87,                     /* ARROW  */
  YYSYMBOL_YYACCEPT = 88,                  /* $accept  */
  YYSYMBOL_program = 89,                   /* program  */
  YYSYMBOL_declaration = 90,               /* declaration  */
  YYSYMBOL_variable_declaration = 91,      /* variable_declaration  */
  YYSYMBOL_function_definition = 92,       /* function_definition  */
  YYSYMBOL_parameter_list = 93,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 94,     /* parameter_declaration  */
  YYSYMBOL_type_specifier = 95,            /* type_specifier  */
  YYSYMBOL_compound_statement = 96,        /* compound_statement  */
  YYSYMBOL_statement_list = 97,            /* statement_list  */
  YYSYMBOL_statement = 98,                 /* statement  */
  YYSYMBOL_expression_statement = 99,      /* expression_statement  */
  YYSYMBOL_selection_statement = 100,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 101,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 102,           /* jump_statement  */
  YYSYMBOL_expression = 103,               /* expression  */
  YYSYMBOL_assignment_expression = 104,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 105,      /* assignment_operator  */
  YYSYMBOL_conditional_expression = 106,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 107,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 108,   /* logical_and_expression  */
  YYSYMBOL_equality_expression = 109,      /* equality_expression  */
  YYSYMBOL_relational_expression = 110,    /* relational_expression  */
  YYSYMBOL_additive_expression = 111,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 112, /* multiplicative_expression  */
  YYSYMBOL_unary_expression = 113,         /* unary_expression  */
  YYSYMBOL_unary_operator = 114,           /* unary_operator  */
  YYSYMBOL_postfix_expression = 115,       /* postfix_expression  */
  YYSYMBOL_argument_expression_list = 116, /* argument_expression_list  */
  YYSYMBOL_primary_expression = 117,       /* primary_expression  */
  YYSYMBOL_constant = 118                  /* constant  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   406

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   342


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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    97,   106,   107,   111,   116,   122,   131,
     137,   147,   148,   152,   160,   161,   162,   163,   164,   168,
     171,   177,   184,   194,   195,   196,   197,   198,   199,   203,
     206,   212,   216,   224,   228,   235,   245,   248,   251,   254,
     260,   264,   265,   273,   274,   275,   276,   277,   281,   285,
     286,   294,   295,   303,   304,   309,   317,   318,   323,   328,
     333,   341,   342,   347,   355,   356,   361,   366,   374,   375,
     378,   381,   387,   388,   389,   390,   391,   392,   396,   397,
     401,   406,   410,   413,   419,   420,   424,   428,   429,   435,
     438,   441,   444,   447
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
  "FLOAT_LITERAL", "DOUBLE_LITERAL", "STRING_LITERAL", "IDENTIFIER",
  "CHAR_LITERAL", "AUTO", "BREAK", "CASE", "CHAR_TYPE", "CONST",
  "CONTINUE", "DEFAULT", "DO", "DOUBLE_TYPE", "ELSE", "ENUM", "EXTERN",
  "FLOAT_TYPE", "FOR", "GOTO", "IF", "INLINE", "INT", "LONG", "REGISTER",
  "RESTRICT", "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT",
  "SWITCH", "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE",
  "PLUS", "MINUS", "MULT", "DIV", "MOD", "INC", "DEC", "ASSIGN",
  "PLUS_ASSIGN", "MINUS_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "LSHIFT_ASSIGN", "RSHIFT_ASSIGN", "AND_ASSIGN", "OR_ASSIGN",
  "XOR_ASSIGN", "EQ", "NE", "LT", "LE", "GT", "GE", "AND", "OR", "NOT",
  "BITWISE_AND", "BITWISE_OR", "BITWISE_XOR", "BITWISE_NOT", "LSHIFT",
  "RSHIFT", "QUESTION", "COLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE",
  "LBRACKET", "RBRACKET", "SEMICOLON", "COMMA", "DOT", "ARROW", "$accept",
  "program", "declaration", "variable_declaration", "function_definition",
  "parameter_list", "parameter_declaration", "type_specifier",
  "compound_statement", "statement_list", "statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "logical_or_expression",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "multiplicative_expression", "unary_expression",
  "unary_operator", "postfix_expression", "argument_expression_list",
  "primary_expression", "constant", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-128)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     148,  -128,  -128,  -128,  -128,  -128,   128,  -128,  -128,  -128,
      -3,  -128,  -128,    10,   328,    12,    31,  -128,  -128,  -128,
    -128,  -128,  -128,  -128,  -128,  -128,  -128,   328,   328,  -128,
    -128,  -128,   328,   -42,  -128,   -23,   -14,   -55,    17,   -22,
     105,    45,   328,    -5,  -128,  -128,   -21,   -60,  -128,    55,
      22,  -128,  -128,    14,  -128,  -128,   328,   328,   328,   328,
     328,   328,   328,   328,   328,   328,   328,   328,   328,  -128,
    -128,  -128,  -128,  -128,   328,  -128,  -128,  -128,   249,   328,
       6,  -128,   -21,   148,  -128,     5,  -128,   -14,  -128,   -55,
      17,    17,   -22,   -22,   -22,   -22,   105,   105,  -128,  -128,
    -128,  -128,  -128,  -128,   -48,    26,    16,    29,    32,    46,
      63,    48,  -128,  -128,  -128,   115,  -128,   113,  -128,  -128,
    -128,  -128,  -128,    47,  -128,  -128,  -128,  -128,   328,  -128,
    -128,  -128,   242,   328,  -128,    54,   328,   -10,  -128,  -128,
    -128,  -128,   242,    50,  -128,    65,   296,   195,   195,   195,
      67,   124,  -128,  -128,   195,   195,  -128,  -128
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    15,    18,    17,    16,    14,     0,     2,     5,     4,
       0,     1,     3,     0,     0,     0,     0,     6,    89,    90,
      91,    93,    86,    92,    74,    75,    73,     0,     0,    77,
      72,    76,     0,     0,    41,    48,    49,    51,    53,    56,
      61,    64,     0,    68,    78,    87,     0,     0,    11,     0,
       0,    69,    70,     0,    40,     7,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
      44,    45,    46,    47,     0,    71,    82,    83,     0,     0,
       0,     9,     0,     0,    13,     0,    88,    50,    64,    52,
      54,    55,    57,    59,    58,    60,    62,    63,    65,    66,
      67,    42,    79,    84,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    30,    28,     0,    27,     0,    21,    23,
      24,    25,    26,     0,    10,    12,     8,    80,     0,    81,
      38,    39,     0,     0,    37,     0,     0,     0,    20,    22,
      29,    85,     0,     0,    36,     0,     0,     0,     0,     0,
       0,    31,    33,    35,     0,     0,    34,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -128,  -128,   142,    35,  -128,  -128,    76,     2,   -43,  -128,
     -91,  -127,  -128,  -128,  -128,   -32,   -13,  -128,  -128,  -128,
     111,   109,    44,   110,    99,   322,  -128,  -128,  -128,  -128,
    -128
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     6,     7,   114,     9,    47,    48,   115,   116,   117,
     118,   119,   120,   121,   122,   123,    54,    74,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,   104,    44,
      45
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      53,    33,    10,    81,    13,   142,    58,    59,    10,    18,
      19,    20,    21,    22,    23,   146,   106,    49,     1,    82,
     107,    64,    65,     2,     1,    83,   139,     3,   108,     2,
     109,   127,     4,     3,    50,     8,   110,   128,     4,   124,
      14,     8,    55,    76,    77,    56,     5,   105,   111,    24,
      25,    26,     5,    57,    27,    28,   151,   152,   153,    80,
      14,   101,    84,   156,   157,   103,    18,    19,    20,    21,
      22,    23,    16,    78,    17,    29,    30,    79,   135,    31,
      60,    61,    62,    63,    32,    49,    80,   112,    15,   126,
     113,    46,    16,    86,    17,    69,    70,    71,    72,    73,
     130,   143,    90,    91,   145,    85,    24,    25,    26,   129,
     132,    27,    28,   131,   150,   141,    18,    19,    20,    21,
      22,    23,   137,   106,   133,     1,   136,   107,    11,   147,
       2,   140,    29,    30,     3,   108,    31,   109,   144,     4,
       1,    32,   155,   110,   148,     2,   154,   134,    12,     3,
      66,    67,    68,     5,     4,   111,    24,    25,    26,   125,
       1,    27,    28,    96,    97,     2,    89,    87,     5,     3,
      92,    93,    94,    95,     4,     0,     0,     0,     0,     0,
       0,     0,    29,    30,     0,     0,    31,     0,     5,     0,
       0,    32,     0,    80,   138,     0,     0,   113,    18,    19,
      20,    21,    22,    23,     0,   106,     0,     1,     0,   107,
       0,     0,     2,     0,     0,     0,     3,   108,     0,   109,
       0,     4,     0,     0,     0,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     0,   111,    24,    25,
      26,     0,     0,    27,    28,    18,    19,    20,    21,    22,
      23,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,    29,    30,     0,     0,    31,     0,
       0,     0,     0,    32,     0,    80,     0,     0,     0,   113,
       0,     0,     0,     0,     0,    24,    25,    26,     0,     0,
      27,    28,    24,    25,    26,     0,     0,    27,    28,    18,
      19,    20,    21,    22,    23,     0,     0,     0,     0,     0,
       0,    29,    30,     0,     0,    31,     0,     0,    29,    30,
      32,     0,    31,     0,     0,     0,   113,    32,   102,     0,
       0,    18,    19,    20,    21,    22,    23,     0,     0,    24,
      25,    26,     0,     0,    27,    28,     0,     0,     0,    51,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    75,    29,    30,     0,     0,    31,
       0,    24,    25,    26,    32,   149,    27,    28,    88,    88,
      88,    88,    88,    88,    88,    88,    88,    88,    98,    99,
     100,     0,     0,     0,     0,     0,     0,    29,    30,     0,
       0,    31,     0,     0,     0,     0,    32
};

static const yytype_int16 yycheck[] =
{
      32,    14,     0,    46,     7,   132,    61,    62,     6,     3,
       4,     5,     6,     7,     8,   142,    10,    15,    12,    79,
      14,    43,    44,    17,    12,    85,   117,    21,    22,    17,
      24,    79,    26,    21,     3,     0,    30,    85,    26,    82,
      50,     6,    84,    48,    49,    68,    40,    79,    42,    43,
      44,    45,    40,    67,    48,    49,   147,   148,   149,    80,
      50,    74,     7,   154,   155,    78,     3,     4,     5,     6,
       7,     8,    82,    78,    84,    69,    70,    82,   110,    73,
      63,    64,    65,    66,    78,    83,    80,    81,    78,    84,
      84,    79,    82,    79,    84,    50,    51,    52,    53,    54,
      84,   133,    58,    59,   136,    83,    43,    44,    45,    83,
      78,    48,    49,    84,   146,   128,     3,     4,     5,     6,
       7,     8,     7,    10,    78,    12,    78,    14,     0,    79,
      17,    84,    69,    70,    21,    22,    73,    24,    84,    26,
      12,    78,    18,    30,    79,    17,    79,    84,     6,    21,
      45,    46,    47,    40,    26,    42,    43,    44,    45,    83,
      12,    48,    49,    64,    65,    17,    57,    56,    40,    21,
      60,    61,    62,    63,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    69,    70,    -1,    -1,    73,    -1,    40,    -1,
      -1,    78,    -1,    80,    81,    -1,    -1,    84,     3,     4,
       5,     6,     7,     8,    -1,    10,    -1,    12,    -1,    14,
      -1,    -1,    17,    -1,    -1,    -1,    21,    22,    -1,    24,
      -1,    26,    -1,    -1,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    -1,    42,    43,    44,
      45,    -1,    -1,    48,    49,     3,     4,     5,     6,     7,
       8,    -1,     3,     4,     5,     6,     7,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70,    -1,    -1,    73,    -1,
      -1,    -1,    -1,    78,    -1,    80,    -1,    -1,    -1,    84,
      -1,    -1,    -1,    -1,    -1,    43,    44,    45,    -1,    -1,
      48,    49,    43,    44,    45,    -1,    -1,    48,    49,     3,
       4,     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70,    -1,    -1,    73,    -1,    -1,    69,    70,
      78,    -1,    73,    -1,    -1,    -1,    84,    78,    79,    -1,
      -1,     3,     4,     5,     6,     7,     8,    -1,    -1,    43,
      44,    45,    -1,    -1,    48,    49,    -1,    -1,    -1,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    69,    70,    -1,    -1,    73,
      -1,    43,    44,    45,    78,    79,    48,    49,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,
      -1,    73,    -1,    -1,    -1,    -1,    78
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    12,    17,    21,    26,    40,    89,    90,    91,    92,
      95,     0,    90,     7,    50,    78,    82,    84,     3,     4,
       5,     6,     7,     8,    43,    44,    45,    48,    49,    69,
      70,    73,    78,   104,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   117,   118,    79,    93,    94,    95,
       3,   113,   113,   103,   104,    84,    68,    67,    61,    62,
      63,    64,    65,    66,    43,    44,    45,    46,    47,    50,
      51,    52,    53,    54,   105,   113,    48,    49,    78,    82,
      80,    96,    79,    85,     7,    83,    79,   108,   113,   109,
     110,   110,   111,   111,   111,   111,   112,   112,   113,   113,
     113,   104,    79,   104,   116,   103,    10,    14,    22,    24,
      30,    42,    81,    84,    91,    95,    96,    97,    98,    99,
     100,   101,   102,   103,    96,    94,    84,    79,    85,    83,
      84,    84,    78,    78,    84,   103,    78,     7,    81,    98,
      84,   104,    99,   103,    84,   103,    99,    79,    79,    79,
     103,    98,    98,    98,    79,    18,    98,    98
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    88,    89,    89,    90,    90,    91,    91,    91,    92,
      92,    93,    93,    94,    95,    95,    95,    95,    95,    96,
      96,    97,    97,    98,    98,    98,    98,    98,    98,    99,
      99,   100,   100,   101,   101,   101,   102,   102,   102,   102,
     103,   104,   104,   105,   105,   105,   105,   105,   106,   107,
     107,   108,   108,   109,   109,   109,   110,   110,   110,   110,
     110,   111,   111,   111,   112,   112,   112,   112,   113,   113,
     113,   113,   114,   114,   114,   114,   114,   114,   115,   115,
     115,   115,   115,   115,   116,   116,   117,   117,   117,   118,
     118,   118,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     5,     6,     5,
       6,     1,     3,     2,     1,     1,     1,     1,     1,     2,
       3,     1,     2,     1,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     5,     7,     6,     3,     2,     2,     2,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     4,     2,     2,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     1
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
  case 2: /* program: declaration  */
#line 90 "parser_simple.y"
                {
        root = new Program();
        if ((yyvsp[0].decl)) {
            root->declarations.push_back(std::unique_ptr<Declaration>((Declaration*)(yyvsp[0].decl)));
        }
        (yyval.program) = root;
    }
#line 1370 "parser.tab.cc"
    break;

  case 3: /* program: program declaration  */
#line 97 "parser_simple.y"
                          {
        if ((yyvsp[0].decl)) {
            root->declarations.push_back(std::unique_ptr<Declaration>((Declaration*)(yyvsp[0].decl)));
        }
        (yyval.program) = root;
    }
#line 1381 "parser.tab.cc"
    break;

  case 4: /* declaration: function_definition  */
#line 106 "parser_simple.y"
                        { (yyval.decl) = (yyvsp[0].decl); }
#line 1387 "parser.tab.cc"
    break;

  case 5: /* declaration: variable_declaration  */
#line 107 "parser_simple.y"
                           { (yyval.decl) = (yyvsp[0].decl); }
#line 1393 "parser.tab.cc"
    break;

  case 6: /* variable_declaration: type_specifier IDENTIFIER SEMICOLON  */
#line 111 "parser_simple.y"
                                        {
        auto var_decl = new VariableDeclaration((yyvsp[-1].str_val), std::unique_ptr<Type>((Type*)(yyvsp[-2].type_node)));
        (yyval.decl) = var_decl;
        free((yyvsp[-1].str_val));
    }
#line 1403 "parser.tab.cc"
    break;

  case 7: /* variable_declaration: type_specifier IDENTIFIER ASSIGN assignment_expression SEMICOLON  */
#line 116 "parser_simple.y"
                                                                       {
        auto var_decl = new VariableDeclaration((yyvsp[-3].str_val), std::unique_ptr<Type>((Type*)(yyvsp[-4].type_node)), 
                                               std::unique_ptr<Expression>((Expression*)(yyvsp[-1].expr)));
        (yyval.decl) = var_decl;
        free((yyvsp[-3].str_val));
    }
#line 1414 "parser.tab.cc"
    break;

  case 8: /* variable_declaration: type_specifier IDENTIFIER LBRACKET INT_LITERAL RBRACKET SEMICOLON  */
#line 122 "parser_simple.y"
                                                                        {
        auto array_type = std::make_unique<ArrayType>(std::unique_ptr<Type>((Type*)(yyvsp[-5].type_node)), (yyvsp[-2].int_val));
        auto var_decl = new VariableDeclaration((yyvsp[-4].str_val), std::move(array_type));
        (yyval.decl) = var_decl;
        free((yyvsp[-4].str_val));
    }
#line 1425 "parser.tab.cc"
    break;

  case 9: /* function_definition: type_specifier IDENTIFIER LPAREN RPAREN compound_statement  */
#line 131 "parser_simple.y"
                                                               {
        auto func_decl = new FunctionDeclaration((yyvsp[-3].str_val), std::unique_ptr<Type>((Type*)(yyvsp[-4].type_node)));
        func_decl->body = std::unique_ptr<Block>((Block*)(yyvsp[0].block));
        (yyval.decl) = func_decl;
        free((yyvsp[-3].str_val));
    }
#line 1436 "parser.tab.cc"
    break;

  case 10: /* function_definition: type_specifier IDENTIFIER LPAREN parameter_list RPAREN compound_statement  */
#line 137 "parser_simple.y"
                                                                                {
        auto func_decl = new FunctionDeclaration((yyvsp[-4].str_val), std::unique_ptr<Type>((Type*)(yyvsp[-5].type_node)));
        func_decl->body = std::unique_ptr<Block>((Block*)(yyvsp[0].block));
        // TODO: Add parameters from $4
        (yyval.decl) = func_decl;
        free((yyvsp[-4].str_val));
    }
#line 1448 "parser.tab.cc"
    break;

  case 11: /* parameter_list: parameter_declaration  */
#line 147 "parser_simple.y"
                          { (yyval.node) = (yyvsp[0].node); }
#line 1454 "parser.tab.cc"
    break;

  case 12: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 148 "parser_simple.y"
                                                 { (yyval.node) = (yyvsp[-2].node); }
#line 1460 "parser.tab.cc"
    break;

  case 13: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 152 "parser_simple.y"
                              {
        // For now, just return a placeholder
        (yyval.node) = nullptr;
        free((yyvsp[0].str_val));
    }
#line 1470 "parser.tab.cc"
    break;

  case 14: /* type_specifier: VOID  */
#line 160 "parser_simple.y"
         { (yyval.type_node) = new Type(Type::VOID_TYPE); }
#line 1476 "parser.tab.cc"
    break;

  case 15: /* type_specifier: CHAR_TYPE  */
#line 161 "parser_simple.y"
                { (yyval.type_node) = new Type(Type::CHAR_TYPE); }
#line 1482 "parser.tab.cc"
    break;

  case 16: /* type_specifier: INT  */
#line 162 "parser_simple.y"
          { (yyval.type_node) = new Type(Type::INT_TYPE); }
#line 1488 "parser.tab.cc"
    break;

  case 17: /* type_specifier: FLOAT_TYPE  */
#line 163 "parser_simple.y"
                 { (yyval.type_node) = new Type(Type::FLOAT_TYPE); }
#line 1494 "parser.tab.cc"
    break;

  case 18: /* type_specifier: DOUBLE_TYPE  */
#line 164 "parser_simple.y"
                  { (yyval.type_node) = new Type(Type::DOUBLE_TYPE); }
#line 1500 "parser.tab.cc"
    break;

  case 19: /* compound_statement: LBRACE RBRACE  */
#line 168 "parser_simple.y"
                  {
        (yyval.block) = new Block();
    }
#line 1508 "parser.tab.cc"
    break;

  case 20: /* compound_statement: LBRACE statement_list RBRACE  */
#line 171 "parser_simple.y"
                                   {
        (yyval.block) = (Block*)(yyvsp[-1].stmt);
    }
#line 1516 "parser.tab.cc"
    break;

  case 21: /* statement_list: statement  */
#line 177 "parser_simple.y"
              {
        auto block = new Block();
        if ((yyvsp[0].stmt)) {
            block->statements.push_back(std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
        }
        (yyval.stmt) = block;
    }
#line 1528 "parser.tab.cc"
    break;

  case 22: /* statement_list: statement_list statement  */
#line 184 "parser_simple.y"
                               {
        auto block = (Block*)(yyvsp[-1].stmt);
        if ((yyvsp[0].stmt)) {
            block->statements.push_back(std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
        }
        (yyval.stmt) = block;
    }
#line 1540 "parser.tab.cc"
    break;

  case 23: /* statement: expression_statement  */
#line 194 "parser_simple.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1546 "parser.tab.cc"
    break;

  case 24: /* statement: selection_statement  */
#line 195 "parser_simple.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1552 "parser.tab.cc"
    break;

  case 25: /* statement: iteration_statement  */
#line 196 "parser_simple.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1558 "parser.tab.cc"
    break;

  case 26: /* statement: jump_statement  */
#line 197 "parser_simple.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1564 "parser.tab.cc"
    break;

  case 27: /* statement: compound_statement  */
#line 198 "parser_simple.y"
                         { (yyval.stmt) = (yyvsp[0].block); }
#line 1570 "parser.tab.cc"
    break;

  case 28: /* statement: variable_declaration  */
#line 199 "parser_simple.y"
                           { (yyval.stmt) = (yyvsp[0].decl); }
#line 1576 "parser.tab.cc"
    break;

  case 29: /* expression_statement: expression SEMICOLON  */
#line 203 "parser_simple.y"
                         {
        (yyval.stmt) = new ExpressionStatement(std::unique_ptr<Expression>((Expression*)(yyvsp[-1].expr)));
    }
#line 1584 "parser.tab.cc"
    break;

  case 30: /* expression_statement: SEMICOLON  */
#line 206 "parser_simple.y"
                {
        (yyval.stmt) = new ExpressionStatement(nullptr);
    }
#line 1592 "parser.tab.cc"
    break;

  case 31: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 212 "parser_simple.y"
                                          {
        (yyval.stmt) = new IfStatement(std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                            std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
    }
#line 1601 "parser.tab.cc"
    break;

  case 32: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 216 "parser_simple.y"
                                                           {
        (yyval.stmt) = new IfStatement(std::unique_ptr<Expression>((Expression*)(yyvsp[-4].expr)), 
                            std::unique_ptr<Statement>((Statement*)(yyvsp[-2].stmt)), 
                            std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
    }
#line 1611 "parser.tab.cc"
    break;

  case 33: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 224 "parser_simple.y"
                                             {
        (yyval.stmt) = new WhileStatement(std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                               std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
    }
#line 1620 "parser.tab.cc"
    break;

  case 34: /* iteration_statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 228 "parser_simple.y"
                                                                                       {
        (yyval.stmt) = new ForStatement(std::unique_ptr<Statement>((Statement*)(yyvsp[-4].stmt)),
                             std::unique_ptr<Expression>(((ExpressionStatement*)(yyvsp[-3].stmt))->expression.release()),
                             std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)),
                             std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
        delete (ExpressionStatement*)(yyvsp[-3].stmt);
    }
#line 1632 "parser.tab.cc"
    break;

  case 35: /* iteration_statement: FOR LPAREN expression_statement expression_statement RPAREN statement  */
#line 235 "parser_simple.y"
                                                                            {
        (yyval.stmt) = new ForStatement(std::unique_ptr<Statement>((Statement*)(yyvsp[-3].stmt)),
                             std::unique_ptr<Expression>(((ExpressionStatement*)(yyvsp[-2].stmt))->expression.release()),
                             nullptr,
                             std::unique_ptr<Statement>((Statement*)(yyvsp[0].stmt)));
        delete (ExpressionStatement*)(yyvsp[-2].stmt);
    }
#line 1644 "parser.tab.cc"
    break;

  case 36: /* jump_statement: RETURN expression SEMICOLON  */
#line 245 "parser_simple.y"
                                {
        (yyval.stmt) = new ReturnStatement(std::unique_ptr<Expression>((Expression*)(yyvsp[-1].expr)));
    }
#line 1652 "parser.tab.cc"
    break;

  case 37: /* jump_statement: RETURN SEMICOLON  */
#line 248 "parser_simple.y"
                       {
        (yyval.stmt) = new ReturnStatement();
    }
#line 1660 "parser.tab.cc"
    break;

  case 38: /* jump_statement: BREAK SEMICOLON  */
#line 251 "parser_simple.y"
                      {
        (yyval.stmt) = new BreakStatement();
    }
#line 1668 "parser.tab.cc"
    break;

  case 39: /* jump_statement: CONTINUE SEMICOLON  */
#line 254 "parser_simple.y"
                         {
        (yyval.stmt) = new ContinueStatement();
    }
#line 1676 "parser.tab.cc"
    break;

  case 40: /* expression: assignment_expression  */
#line 260 "parser_simple.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1682 "parser.tab.cc"
    break;

  case 41: /* assignment_expression: conditional_expression  */
#line 264 "parser_simple.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1688 "parser.tab.cc"
    break;

  case 42: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 265 "parser_simple.y"
                                                                 {
        (yyval.expr) = new BinaryOp((BinaryOp::Operator)(yyvsp[-1].bin_op), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1698 "parser.tab.cc"
    break;

  case 43: /* assignment_operator: ASSIGN  */
#line 273 "parser_simple.y"
           { (yyval.bin_op) = BinaryOp::ASSIGN; }
#line 1704 "parser.tab.cc"
    break;

  case 44: /* assignment_operator: PLUS_ASSIGN  */
#line 274 "parser_simple.y"
                  { (yyval.bin_op) = BinaryOp::PLUS_ASSIGN; }
#line 1710 "parser.tab.cc"
    break;

  case 45: /* assignment_operator: MINUS_ASSIGN  */
#line 275 "parser_simple.y"
                   { (yyval.bin_op) = BinaryOp::MINUS_ASSIGN; }
#line 1716 "parser.tab.cc"
    break;

  case 46: /* assignment_operator: MULT_ASSIGN  */
#line 276 "parser_simple.y"
                  { (yyval.bin_op) = BinaryOp::MULT_ASSIGN; }
#line 1722 "parser.tab.cc"
    break;

  case 47: /* assignment_operator: DIV_ASSIGN  */
#line 277 "parser_simple.y"
                 { (yyval.bin_op) = BinaryOp::DIV_ASSIGN; }
#line 1728 "parser.tab.cc"
    break;

  case 48: /* conditional_expression: logical_or_expression  */
#line 281 "parser_simple.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1734 "parser.tab.cc"
    break;

  case 49: /* logical_or_expression: logical_and_expression  */
#line 285 "parser_simple.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 1740 "parser.tab.cc"
    break;

  case 50: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 286 "parser_simple.y"
                                                      {
        (yyval.expr) = new BinaryOp(BinaryOp::OR, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1750 "parser.tab.cc"
    break;

  case 51: /* logical_and_expression: equality_expression  */
#line 294 "parser_simple.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1756 "parser.tab.cc"
    break;

  case 52: /* logical_and_expression: logical_and_expression AND equality_expression  */
#line 295 "parser_simple.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::AND, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1766 "parser.tab.cc"
    break;

  case 53: /* equality_expression: relational_expression  */
#line 303 "parser_simple.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 1772 "parser.tab.cc"
    break;

  case 54: /* equality_expression: equality_expression EQ relational_expression  */
#line 304 "parser_simple.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::EQ, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1782 "parser.tab.cc"
    break;

  case 55: /* equality_expression: equality_expression NE relational_expression  */
#line 309 "parser_simple.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::NE, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1792 "parser.tab.cc"
    break;

  case 56: /* relational_expression: additive_expression  */
#line 317 "parser_simple.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 1798 "parser.tab.cc"
    break;

  case 57: /* relational_expression: relational_expression LT additive_expression  */
#line 318 "parser_simple.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::LT, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1808 "parser.tab.cc"
    break;

  case 58: /* relational_expression: relational_expression GT additive_expression  */
#line 323 "parser_simple.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::GT, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1818 "parser.tab.cc"
    break;

  case 59: /* relational_expression: relational_expression LE additive_expression  */
#line 328 "parser_simple.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::LE, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1828 "parser.tab.cc"
    break;

  case 60: /* relational_expression: relational_expression GE additive_expression  */
#line 333 "parser_simple.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::GE, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1838 "parser.tab.cc"
    break;

  case 61: /* additive_expression: multiplicative_expression  */
#line 341 "parser_simple.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 1844 "parser.tab.cc"
    break;

  case 62: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 342 "parser_simple.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::ADD, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1854 "parser.tab.cc"
    break;

  case 63: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 347 "parser_simple.y"
                                                          {
        (yyval.expr) = new BinaryOp(BinaryOp::SUB, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1864 "parser.tab.cc"
    break;

  case 64: /* multiplicative_expression: unary_expression  */
#line 355 "parser_simple.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 1870 "parser.tab.cc"
    break;

  case 65: /* multiplicative_expression: multiplicative_expression MULT unary_expression  */
#line 356 "parser_simple.y"
                                                      {
        (yyval.expr) = new BinaryOp(BinaryOp::MUL, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1880 "parser.tab.cc"
    break;

  case 66: /* multiplicative_expression: multiplicative_expression DIV unary_expression  */
#line 361 "parser_simple.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::DIV, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1890 "parser.tab.cc"
    break;

  case 67: /* multiplicative_expression: multiplicative_expression MOD unary_expression  */
#line 366 "parser_simple.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::MOD, 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)), 
                         std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1900 "parser.tab.cc"
    break;

  case 68: /* unary_expression: postfix_expression  */
#line 374 "parser_simple.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 1906 "parser.tab.cc"
    break;

  case 69: /* unary_expression: INC unary_expression  */
#line 375 "parser_simple.y"
                           {
        (yyval.expr) = new UnaryOp(UnaryOp::PRE_INC, std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1914 "parser.tab.cc"
    break;

  case 70: /* unary_expression: DEC unary_expression  */
#line 378 "parser_simple.y"
                           {
        (yyval.expr) = new UnaryOp(UnaryOp::PRE_DEC, std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1922 "parser.tab.cc"
    break;

  case 71: /* unary_expression: unary_operator unary_expression  */
#line 381 "parser_simple.y"
                                      {
        (yyval.expr) = new UnaryOp((UnaryOp::Operator)(yyvsp[-1].un_op), std::unique_ptr<Expression>((Expression*)(yyvsp[0].expr)));
    }
#line 1930 "parser.tab.cc"
    break;

  case 72: /* unary_operator: BITWISE_AND  */
#line 387 "parser_simple.y"
                { (yyval.un_op) = UnaryOp::ADDRESS_OF; }
#line 1936 "parser.tab.cc"
    break;

  case 73: /* unary_operator: MULT  */
#line 388 "parser_simple.y"
           { (yyval.un_op) = UnaryOp::DEREF; }
#line 1942 "parser.tab.cc"
    break;

  case 74: /* unary_operator: PLUS  */
#line 389 "parser_simple.y"
           { (yyval.un_op) = UnaryOp::PLUS; }
#line 1948 "parser.tab.cc"
    break;

  case 75: /* unary_operator: MINUS  */
#line 390 "parser_simple.y"
            { (yyval.un_op) = UnaryOp::MINUS; }
#line 1954 "parser.tab.cc"
    break;

  case 76: /* unary_operator: BITWISE_NOT  */
#line 391 "parser_simple.y"
                  { (yyval.un_op) = UnaryOp::BITWISE_NOT; }
#line 1960 "parser.tab.cc"
    break;

  case 77: /* unary_operator: NOT  */
#line 392 "parser_simple.y"
          { (yyval.un_op) = UnaryOp::NOT; }
#line 1966 "parser.tab.cc"
    break;

  case 78: /* postfix_expression: primary_expression  */
#line 396 "parser_simple.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 1972 "parser.tab.cc"
    break;

  case 79: /* postfix_expression: postfix_expression LPAREN RPAREN  */
#line 397 "parser_simple.y"
                                       {
        auto func_call = new FunctionCall(std::unique_ptr<Expression>((Expression*)(yyvsp[-2].expr)));
        (yyval.expr) = func_call;
    }
#line 1981 "parser.tab.cc"
    break;

  case 80: /* postfix_expression: postfix_expression LPAREN argument_expression_list RPAREN  */
#line 401 "parser_simple.y"
                                                                {
        auto func_call = new FunctionCall(std::unique_ptr<Expression>((Expression*)(yyvsp[-3].expr)));
        // TODO: Add arguments from $3
        (yyval.expr) = func_call;
    }
#line 1991 "parser.tab.cc"
    break;

  case 81: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 406 "parser_simple.y"
                                                      {
        (yyval.expr) = new ArrayAccess(std::unique_ptr<Expression>((Expression*)(yyvsp[-3].expr)), 
                            std::unique_ptr<Expression>((Expression*)(yyvsp[-1].expr)));
    }
#line 2000 "parser.tab.cc"
    break;

  case 82: /* postfix_expression: postfix_expression INC  */
#line 410 "parser_simple.y"
                             {
        (yyval.expr) = new UnaryOp(UnaryOp::POST_INC, std::unique_ptr<Expression>((Expression*)(yyvsp[-1].expr)));
    }
#line 2008 "parser.tab.cc"
    break;

  case 83: /* postfix_expression: postfix_expression DEC  */
#line 413 "parser_simple.y"
                             {
        (yyval.expr) = new UnaryOp(UnaryOp::POST_DEC, std::unique_ptr<Expression>((Expression*)(yyvsp[-1].expr)));
    }
#line 2016 "parser.tab.cc"
    break;

  case 84: /* argument_expression_list: assignment_expression  */
#line 419 "parser_simple.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2022 "parser.tab.cc"
    break;

  case 85: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 420 "parser_simple.y"
                                                           { (yyval.expr) = (yyvsp[-2].expr); }
#line 2028 "parser.tab.cc"
    break;

  case 86: /* primary_expression: IDENTIFIER  */
#line 424 "parser_simple.y"
               {
        (yyval.expr) = new Identifier((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 2037 "parser.tab.cc"
    break;

  case 87: /* primary_expression: constant  */
#line 428 "parser_simple.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 2043 "parser.tab.cc"
    break;

  case 88: /* primary_expression: LPAREN expression RPAREN  */
#line 429 "parser_simple.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2051 "parser.tab.cc"
    break;

  case 89: /* constant: INT_LITERAL  */
#line 435 "parser_simple.y"
                {
        (yyval.expr) = new IntLiteral((yyvsp[0].int_val));
    }
#line 2059 "parser.tab.cc"
    break;

  case 90: /* constant: FLOAT_LITERAL  */
#line 438 "parser_simple.y"
                    {
        (yyval.expr) = new FloatLiteral((yyvsp[0].float_val));
    }
#line 2067 "parser.tab.cc"
    break;

  case 91: /* constant: DOUBLE_LITERAL  */
#line 441 "parser_simple.y"
                     {
        (yyval.expr) = new FloatLiteral((yyvsp[0].double_val));
    }
#line 2075 "parser.tab.cc"
    break;

  case 92: /* constant: CHAR_LITERAL  */
#line 444 "parser_simple.y"
                   {
        (yyval.expr) = new CharLiteral((yyvsp[0].char_val));
    }
#line 2083 "parser.tab.cc"
    break;

  case 93: /* constant: STRING_LITERAL  */
#line 447 "parser_simple.y"
                     {
        (yyval.expr) = new StringLiteral((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 2092 "parser.tab.cc"
    break;


#line 2096 "parser.tab.cc"

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

#line 453 "parser_simple.y"


void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
}
