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
#include <memory>
#include "ast_full.h"

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

Program* root = nullptr;

#line 87 "parser.tab.cc"

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
  YYSYMBOL_translation_unit = 90,          /* translation_unit  */
  YYSYMBOL_external_declaration = 91,      /* external_declaration  */
  YYSYMBOL_function_definition = 92,       /* function_definition  */
  YYSYMBOL_declaration = 93,               /* declaration  */
  YYSYMBOL_type_specifier = 94,            /* type_specifier  */
  YYSYMBOL_struct_or_union_specifier = 95, /* struct_or_union_specifier  */
  YYSYMBOL_enum_specifier = 96,            /* enum_specifier  */
  YYSYMBOL_parameter_list_opt = 97,        /* parameter_list_opt  */
  YYSYMBOL_parameter_list = 98,            /* parameter_list  */
  YYSYMBOL_parameter_declaration = 99,     /* parameter_declaration  */
  YYSYMBOL_struct_declaration = 100,       /* struct_declaration  */
  YYSYMBOL_enum_declaration = 101,         /* enum_declaration  */
  YYSYMBOL_typedef_declaration = 102,      /* typedef_declaration  */
  YYSYMBOL_compound_statement = 103,       /* compound_statement  */
  YYSYMBOL_statement_list_opt = 104,       /* statement_list_opt  */
  YYSYMBOL_statement_list = 105,           /* statement_list  */
  YYSYMBOL_statement = 106,                /* statement  */
  YYSYMBOL_labeled_statement = 107,        /* labeled_statement  */
  YYSYMBOL_expression_statement = 108,     /* expression_statement  */
  YYSYMBOL_selection_statement = 109,      /* selection_statement  */
  YYSYMBOL_iteration_statement = 110,      /* iteration_statement  */
  YYSYMBOL_jump_statement = 111,           /* jump_statement  */
  YYSYMBOL_expression = 112,               /* expression  */
  YYSYMBOL_assignment_expression = 113,    /* assignment_expression  */
  YYSYMBOL_assignment_operator = 114,      /* assignment_operator  */
  YYSYMBOL_conditional_expression = 115,   /* conditional_expression  */
  YYSYMBOL_logical_or_expression = 116,    /* logical_or_expression  */
  YYSYMBOL_logical_and_expression = 117,   /* logical_and_expression  */
  YYSYMBOL_inclusive_or_expression = 118,  /* inclusive_or_expression  */
  YYSYMBOL_exclusive_or_expression = 119,  /* exclusive_or_expression  */
  YYSYMBOL_and_expression = 120,           /* and_expression  */
  YYSYMBOL_equality_expression = 121,      /* equality_expression  */
  YYSYMBOL_relational_expression = 122,    /* relational_expression  */
  YYSYMBOL_shift_expression = 123,         /* shift_expression  */
  YYSYMBOL_additive_expression = 124,      /* additive_expression  */
  YYSYMBOL_multiplicative_expression = 125, /* multiplicative_expression  */
  YYSYMBOL_cast_expression = 126,          /* cast_expression  */
  YYSYMBOL_unary_expression = 127,         /* unary_expression  */
  YYSYMBOL_unary_operator = 128,           /* unary_operator  */
  YYSYMBOL_postfix_expression = 129,       /* postfix_expression  */
  YYSYMBOL_primary_expression = 130,       /* primary_expression  */
  YYSYMBOL_constant = 131,                 /* constant  */
  YYSYMBOL_argument_expression_list_opt = 132, /* argument_expression_list_opt  */
  YYSYMBOL_argument_expression_list = 133  /* argument_expression_list  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  263

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
       0,   117,   117,   130,   134,   141,   142,   146,   171,   176,
     181,   187,   188,   189,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   206,   207,   208,   216,   220,   226,   230,
     239,   243,   250,   251,   255,   262,   272,   276,   281,   287,
     295,   303,   311,   324,   325,   329,   333,   340,   341,   342,
     343,   344,   345,   346,   350,   354,   357,   363,   366,   372,
     375,   378,   384,   387,   390,   397,   407,   411,   414,   417,
     420,   426,   427,   433,   434,   440,   441,   442,   443,   444,
     445,   446,   447,   448,   449,   450,   454,   455,   461,   462,
     468,   469,   475,   476,   482,   483,   489,   490,   496,   497,
     500,   506,   507,   510,   513,   516,   522,   523,   526,   532,
     533,   536,   542,   543,   546,   549,   555,   556,   562,   563,
     566,   569,   572,   575,   581,   582,   583,   584,   585,   586,
     590,   591,   594,   604,   608,   612,   615,   621,   625,   626,
     632,   635,   638,   641,   644,   651,   652,   656,   660
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
  "program", "translation_unit", "external_declaration",
  "function_definition", "declaration", "type_specifier",
  "struct_or_union_specifier", "enum_specifier", "parameter_list_opt",
  "parameter_list", "parameter_declaration", "struct_declaration",
  "enum_declaration", "typedef_declaration", "compound_statement",
  "statement_list_opt", "statement_list", "statement", "labeled_statement",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "logical_or_expression",
  "logical_and_expression", "inclusive_or_expression",
  "exclusive_or_expression", "and_expression", "equality_expression",
  "relational_expression", "shift_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression", "constant",
  "argument_expression_list_opt", "argument_expression_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-214)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-26)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     431,  -214,  -214,  -214,    15,  -214,  -214,  -214,  -214,  -214,
      25,   466,    34,  -214,  -214,    47,   431,  -214,  -214,  -214,
      61,  -214,  -214,  -214,  -214,  -214,    -7,    31,    97,   118,
     125,    57,  -214,  -214,   -38,    65,    68,    71,    77,   -69,
      74,   357,   466,   155,  -214,    76,    83,    80,    92,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,   364,  -214,  -214,
    -214,   411,   411,  -214,  -214,  -214,   310,    90,  -214,   -59,
     110,   107,   115,   121,    46,   106,    39,    75,   -10,  -214,
      32,   357,   -44,  -214,  -214,   189,   119,   122,  -214,   120,
    -214,  -214,  -214,  -214,   310,  -214,   357,  -214,  -214,   127,
     133,   -56,  -214,  -214,   357,   357,   357,   357,   357,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,   357,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,   357,  -214,  -214,  -214,  -214,   357,
     357,   212,   217,   143,   148,   466,   151,   167,   357,  -214,
     357,   110,   -64,   107,   115,   121,    46,   106,   106,    39,
      39,    39,    39,    75,    75,   -10,   -10,  -214,  -214,  -214,
    -214,  -214,   170,   165,   -65,  -214,  -214,   169,   178,  -214,
    -214,  -214,  -214,  -214,  -214,   357,  -214,   357,  -214,  -214,
       4,   171,   123,   173,   176,   178,   182,   247,   183,    72,
     185,   186,  -214,  -214,   258,  -214,   187,   178,  -214,  -214,
    -214,  -214,  -214,  -214,    38,  -214,  -214,   178,  -214,   190,
    -214,   178,   230,   226,   195,   357,  -214,    51,   357,   357,
     -34,  -214,  -214,  -214,  -214,   178,  -214,   202,   226,  -214,
     -52,  -214,    16,    17,  -214,   357,   233,   178,   178,   178,
      21,   178,    24,   255,  -214,  -214,   199,  -214,   178,   178,
    -214,  -214,  -214
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,    15,    20,     0,    19,    17,    18,    16,    21,
       0,     0,     0,    22,    14,     0,     2,     3,     5,     6,
       0,    23,    24,    11,    12,    13,    31,    28,     0,     0,
       0,    29,     1,     4,     0,     0,     0,    31,    28,     0,
       0,     0,    32,     0,     8,    30,    26,     0,     0,    41,
      27,   140,   141,   142,   144,   137,   143,     0,   126,   127,
     125,     0,     0,   129,   124,   128,     0,     0,    73,    86,
      88,    90,    92,    94,    96,    98,   101,   106,   109,   112,
     116,     0,   118,   130,   138,    38,     0,    33,    34,     0,
      40,    39,    30,    26,     0,   122,     0,   119,   120,   137,
       0,     0,    71,     9,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    75,    79,    80,    76,    77,    78,    81,
      82,    83,    85,    84,     0,   121,   116,   135,   136,   145,
       0,     0,     0,    36,     0,     0,     0,     0,     0,   139,
       0,    89,     0,    91,    93,    95,    97,    99,   100,   102,
     104,   103,   105,   107,   108,   110,   111,   113,   114,   115,
      74,   147,     0,   146,     0,   133,   134,     0,    43,     7,
      35,    10,   123,   117,    72,     0,   132,     0,   131,    37,
     137,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    58,    53,     0,    48,     0,    44,    45,    47,
      49,    50,    51,    52,     0,    87,   148,     0,    68,     0,
      67,     0,     0,     0,     0,     0,    70,     0,     0,     0,
       0,    42,    46,    57,    54,     0,    56,     0,     0,    66,
       0,    69,     0,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,    59,    61,    62,     0,    65,     0,     0,
      63,    64,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,   268,  -214,     8,     3,  -214,  -214,  -214,
    -214,   140,  -214,  -214,  -214,   142,  -214,  -214,   -83,  -214,
    -213,  -214,  -214,  -214,   -66,   -40,  -214,   102,  -214,   184,
     188,   191,   181,   192,    29,   130,    27,    35,   -50,   -55,
    -214,  -214,  -214,    98,  -214,  -214
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    15,    16,    17,    18,   203,   204,    21,    22,    86,
      87,    88,    23,    24,    25,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   102,   134,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   172,   173
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     101,    67,    95,    20,   137,   138,    97,    98,    19,   104,
     238,   -25,    41,   185,    30,    49,    41,   105,   188,    20,
     150,   150,    26,   149,    19,   246,   136,   247,   101,   150,
     101,   135,    27,   150,   139,   120,   121,   122,   140,   152,
      42,    31,   141,   142,    43,    85,    44,    32,    43,   136,
      44,   136,   136,   136,   136,   136,   136,   136,   136,   136,
     136,   136,   136,   136,   136,   136,   136,   136,    34,   100,
     167,   168,   169,    35,   174,    51,    52,    53,    54,    55,
      56,   217,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   136,   170,   248,   249,   147,   183,   171,
     256,   150,   150,   258,    37,    57,   150,   110,   111,   150,
     184,    36,   222,   116,   117,    58,    59,    60,   118,   119,
      61,    62,   233,   150,   232,    38,    51,    52,    53,    54,
     136,    56,    39,   227,   234,   241,   150,    40,   236,   157,
     158,    63,    64,   163,   164,    65,    45,   216,    85,    46,
      66,    47,   244,   165,   166,    50,   226,    48,    89,   240,
      90,    92,   242,   243,   253,   254,   255,    91,   257,   112,
     113,   114,   115,    93,   103,   261,   262,   106,   107,   250,
     252,    51,    52,    53,    54,   190,    56,   108,   191,   192,
       2,   109,   193,   194,   195,     3,   143,     4,   144,     5,
     196,   197,   198,   146,     6,     7,   -25,   145,   199,     8,
       9,    57,   148,    10,   200,    11,    12,    13,    14,   175,
     201,    58,    59,    60,   176,   177,    61,    62,   178,    51,
      52,    53,    54,    55,    56,   181,    51,    52,    53,    54,
      55,    56,   159,   160,   161,   162,   182,    63,    64,   186,
     187,    65,   189,   221,   224,   218,    66,   220,   178,    57,
     223,   225,   202,   228,   229,   230,    57,   235,   231,    58,
      59,    60,   237,   259,    61,    62,    58,    59,    60,   239,
     245,    61,    62,   260,    33,   180,   179,   215,   151,   155,
     219,     0,     0,     0,   153,    63,    64,     0,   154,    65,
       0,   156,    63,    64,    66,     0,    65,     0,     0,     0,
     202,    66,   251,    51,    52,    53,    54,    99,    56,     0,
       0,     0,     2,     0,     0,     0,     0,     3,     0,    28,
       0,     5,     0,     0,     0,     0,     6,     7,     0,     0,
       0,     8,     9,    57,     0,    29,     0,     0,    12,    13,
      14,     0,     0,    58,    59,    60,     0,     0,    61,    62,
      51,    52,    53,    54,    55,    56,     0,    51,    52,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,    63,
      64,     0,     0,    65,     0,     0,     0,     0,    66,     0,
      57,     0,     0,     0,     0,     0,     0,    57,     0,     0,
      58,    59,    60,     0,     0,    61,    62,    58,    59,    60,
       0,     0,    61,    62,    51,    52,    53,    54,    55,    56,
       0,     0,     0,     0,     0,     0,    63,    64,     0,     0,
      65,     0,     0,    63,    64,    66,     0,    65,     1,     0,
       0,     0,    94,     2,    57,     0,     0,     0,     3,     0,
       4,     0,     5,     0,    58,    59,    60,     6,     7,    61,
      62,     0,     8,     9,     0,     0,    10,     0,    11,    12,
      13,    14,     0,     1,     0,     0,     0,     0,     2,     0,
      63,    64,     0,     3,    65,    28,     0,     5,     0,    96,
       0,     0,     6,     7,     0,     0,     0,     8,     9,     0,
       0,    29,     0,     0,    12,    13,    14
};

static const yytype_int16 yycheck[] =
{
      66,    41,    57,     0,    48,    49,    61,    62,     0,    68,
     223,     7,    50,    77,    11,    84,    50,    76,    83,    16,
      85,    85,     7,    79,    16,   238,    81,    79,    94,    85,
      96,    81,     7,    85,    78,    45,    46,    47,    82,   105,
      78,     7,    86,    87,    82,    42,    84,     0,    82,   104,
      84,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,     7,    66,
     120,   121,   122,    80,   140,     3,     4,     5,     6,     7,
       8,    77,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,   148,   134,    79,    79,    94,   148,   139,
      79,    85,    85,    79,     7,    33,    85,    61,    62,    85,
     150,    80,   195,    74,    75,    43,    44,    45,    43,    44,
      48,    49,    84,    85,   207,     7,     3,     4,     5,     6,
     185,     8,     7,   199,   217,    84,    85,    80,   221,   110,
     111,    69,    70,   116,   117,    73,    81,   187,   145,    81,
      78,    80,   235,   118,   119,    81,    84,    80,     3,   225,
      84,    81,   228,   229,   247,   248,   249,    84,   251,    63,
      64,    65,    66,    81,    84,   258,   259,    67,    71,   245,
     246,     3,     4,     5,     6,     7,     8,    72,    10,    11,
      12,    70,    14,    15,    16,    17,     7,    19,    79,    21,
      22,    23,    24,    83,    26,    27,    79,    85,    30,    31,
      32,    33,    79,    35,    36,    37,    38,    39,    40,     7,
      42,    43,    44,    45,     7,    82,    48,    49,    80,     3,
       4,     5,     6,     7,     8,    84,     3,     4,     5,     6,
       7,     8,   112,   113,   114,   115,    79,    69,    70,    79,
      85,    73,    83,    77,     7,    84,    78,    84,    80,    33,
      78,    78,    84,    78,    78,     7,    33,    77,    81,    43,
      44,    45,    42,    18,    48,    49,    43,    44,    45,    84,
      78,    48,    49,    84,    16,   145,   144,   185,   104,   108,
     192,    -1,    -1,    -1,   106,    69,    70,    -1,   107,    73,
      -1,   109,    69,    70,    78,    -1,    73,    -1,    -1,    -1,
      84,    78,    79,     3,     4,     5,     6,     7,     8,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    17,    -1,    19,
      -1,    21,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    31,    32,    33,    -1,    35,    -1,    -1,    38,    39,
      40,    -1,    -1,    43,    44,    45,    -1,    -1,    48,    49,
       3,     4,     5,     6,     7,     8,    -1,     3,     4,     5,
       6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      70,    -1,    -1,    73,    -1,    -1,    -1,    -1,    78,    -1,
      33,    -1,    -1,    -1,    -1,    -1,    -1,    33,    -1,    -1,
      43,    44,    45,    -1,    -1,    48,    49,    43,    44,    45,
      -1,    -1,    48,    49,     3,     4,     5,     6,     7,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    -1,    -1,
      73,    -1,    -1,    69,    70,    78,    -1,    73,     7,    -1,
      -1,    -1,    78,    12,    33,    -1,    -1,    -1,    17,    -1,
      19,    -1,    21,    -1,    43,    44,    45,    26,    27,    48,
      49,    -1,    31,    32,    -1,    -1,    35,    -1,    37,    38,
      39,    40,    -1,     7,    -1,    -1,    -1,    -1,    12,    -1,
      69,    70,    -1,    17,    73,    19,    -1,    21,    -1,    78,
      -1,    -1,    26,    27,    -1,    -1,    -1,    31,    32,    -1,
      -1,    35,    -1,    -1,    38,    39,    40
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,    12,    17,    19,    21,    26,    27,    31,    32,
      35,    37,    38,    39,    40,    89,    90,    91,    92,    93,
      94,    95,    96,   100,   101,   102,     7,     7,    19,    35,
      94,     7,     0,    91,     7,    80,    80,     7,     7,     7,
      80,    50,    78,    82,    84,    81,    81,    80,    80,    84,
      81,     3,     4,     5,     6,     7,     8,    33,    43,    44,
      45,    48,    49,    69,    70,    73,    78,   113,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,    94,    97,    98,    99,     3,
      84,    84,    81,    81,    78,   127,    78,   127,   127,     7,
      94,   112,   113,    84,    68,    76,    67,    71,    72,    70,
      61,    62,    63,    64,    65,    66,    74,    75,    43,    44,
      45,    46,    47,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   114,   126,   127,    48,    49,    78,
      82,    86,    87,     7,    79,    85,    83,    94,    79,    79,
      85,   117,   112,   118,   119,   120,   121,   122,   122,   123,
     123,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     113,   113,   132,   133,   112,     7,     7,    82,    80,   103,
      99,    84,    79,   126,   113,    77,    79,    85,    83,    83,
       7,    10,    11,    14,    15,    16,    22,    23,    24,    30,
      36,    42,    84,    93,    94,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   115,   113,    77,    84,   131,
      84,    77,   106,    78,     7,    78,    84,   112,    78,    78,
       7,    81,   106,    84,   106,    77,   106,    42,   108,    84,
     112,    84,   112,   112,   106,    78,   108,    79,    79,    79,
     112,    79,   112,   106,   106,   106,    79,   106,    79,    18,
      84,   106,   106
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    90,    91,    91,    92,    93,    93,
      93,    93,    93,    93,    94,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    95,    95,    95,    95,
      96,    96,    97,    97,    98,    98,    99,    99,    99,   100,
     101,   102,   103,   104,   104,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   107,   108,   108,   109,
     109,   109,   110,   110,   110,   110,   111,   111,   111,   111,
     111,   112,   112,   113,   113,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   115,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   120,   120,   121,   121,
     121,   122,   122,   122,   122,   122,   123,   123,   123,   124,
     124,   124,   125,   125,   125,   125,   126,   126,   127,   127,
     127,   127,   127,   127,   128,   128,   128,   128,   128,   128,
     129,   129,   129,   129,   129,   129,   129,   130,   130,   130,
     131,   131,   131,   131,   131,   132,   132,   133,   133
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     6,     3,     5,
       6,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     2,     2,
       4,     2,     0,     1,     1,     3,     2,     4,     1,     5,
       5,     4,     3,     0,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     3,     4,     3,     2,     1,     5,
       7,     5,     5,     7,     7,     6,     3,     2,     2,     3,
       2,     1,     3,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     4,     1,     2,
       2,     2,     2,     4,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     3,     3,     2,     2,     1,     1,     3,
       1,     1,     1,     1,     1,     0,     1,     1,     3
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
  case 2: /* program: translation_unit  */
#line 117 "parser.y"
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
#line 1466 "parser.tab.cc"
    break;

  case 3: /* translation_unit: external_declaration  */
#line 130 "parser.y"
                         {
        (yyval.decl_list) = new std::vector<Declaration*>();
        if ((yyvsp[0].decl)) (yyval.decl_list)->push_back((yyvsp[0].decl));
    }
#line 1475 "parser.tab.cc"
    break;

  case 4: /* translation_unit: translation_unit external_declaration  */
#line 134 "parser.y"
                                            {
        (yyval.decl_list) = (yyvsp[-1].decl_list);
        if ((yyvsp[0].decl)) (yyval.decl_list)->push_back((yyvsp[0].decl));
    }
#line 1484 "parser.tab.cc"
    break;

  case 5: /* external_declaration: function_definition  */
#line 141 "parser.y"
                        { (yyval.decl) = (yyvsp[0].decl); }
#line 1490 "parser.tab.cc"
    break;

  case 6: /* external_declaration: declaration  */
#line 142 "parser.y"
                  { (yyval.decl) = (yyvsp[0].decl); }
#line 1496 "parser.tab.cc"
    break;

  case 7: /* function_definition: type_specifier IDENTIFIER LPAREN parameter_list_opt RPAREN compound_statement  */
#line 146 "parser.y"
                                                                                  {
        auto func_decl = new FunctionDeclaration((yyvsp[-4].str_val), std::unique_ptr<Type>((yyvsp[-5].type_node)));
        if ((yyvsp[-2].param_list)) {
            func_decl->parameters = *(yyvsp[-2].param_list);
            delete (yyvsp[-2].param_list);
        }
        func_decl->body = std::unique_ptr<Block>((yyvsp[0].block));
        (yyval.decl) = func_decl;
        free((yyvsp[-4].str_val));
    }
#line 1511 "parser.tab.cc"
    break;

  case 8: /* declaration: type_specifier IDENTIFIER SEMICOLON  */
#line 171 "parser.y"
                                        {
        auto var_decl = new VariableDeclaration((yyvsp[-1].str_val), std::unique_ptr<Type>((yyvsp[-2].type_node)));
        (yyval.decl) = var_decl;
        free((yyvsp[-1].str_val));
    }
#line 1521 "parser.tab.cc"
    break;

  case 9: /* declaration: type_specifier IDENTIFIER ASSIGN assignment_expression SEMICOLON  */
#line 176 "parser.y"
                                                                       {
        auto var_decl = new VariableDeclaration((yyvsp[-3].str_val), std::unique_ptr<Type>((yyvsp[-4].type_node)), std::unique_ptr<Expression>((yyvsp[-1].expr)));
        (yyval.decl) = var_decl;
        free((yyvsp[-3].str_val));
    }
#line 1531 "parser.tab.cc"
    break;

  case 10: /* declaration: type_specifier IDENTIFIER LBRACKET INT_LITERAL RBRACKET SEMICOLON  */
#line 181 "parser.y"
                                                                        {
        auto array_type = std::make_unique<ArrayType>(std::unique_ptr<Type>((yyvsp[-5].type_node)), (yyvsp[-2].int_val));
        auto var_decl = new VariableDeclaration((yyvsp[-4].str_val), std::move(array_type));
        (yyval.decl) = var_decl;
        free((yyvsp[-4].str_val));
    }
#line 1542 "parser.tab.cc"
    break;

  case 11: /* declaration: struct_declaration  */
#line 187 "parser.y"
                         { (yyval.decl) = (yyvsp[0].decl); }
#line 1548 "parser.tab.cc"
    break;

  case 12: /* declaration: enum_declaration  */
#line 188 "parser.y"
                       { (yyval.decl) = (yyvsp[0].decl); }
#line 1554 "parser.tab.cc"
    break;

  case 13: /* declaration: typedef_declaration  */
#line 189 "parser.y"
                          { (yyval.decl) = (yyvsp[0].decl); }
#line 1560 "parser.tab.cc"
    break;

  case 14: /* type_specifier: VOID  */
#line 193 "parser.y"
         { (yyval.type_node) = new Type(Type::VOID_TYPE); }
#line 1566 "parser.tab.cc"
    break;

  case 15: /* type_specifier: CHAR_TYPE  */
#line 194 "parser.y"
                { (yyval.type_node) = new Type(Type::CHAR_TYPE); }
#line 1572 "parser.tab.cc"
    break;

  case 16: /* type_specifier: SHORT  */
#line 195 "parser.y"
            { (yyval.type_node) = new Type(Type::SHORT_TYPE); }
#line 1578 "parser.tab.cc"
    break;

  case 17: /* type_specifier: INT  */
#line 196 "parser.y"
          { (yyval.type_node) = new Type(Type::INT_TYPE); }
#line 1584 "parser.tab.cc"
    break;

  case 18: /* type_specifier: LONG  */
#line 197 "parser.y"
           { (yyval.type_node) = new Type(Type::LONG_TYPE); }
#line 1590 "parser.tab.cc"
    break;

  case 19: /* type_specifier: FLOAT_TYPE  */
#line 198 "parser.y"
                 { (yyval.type_node) = new Type(Type::FLOAT_TYPE); }
#line 1596 "parser.tab.cc"
    break;

  case 20: /* type_specifier: DOUBLE_TYPE  */
#line 199 "parser.y"
                  { (yyval.type_node) = new Type(Type::DOUBLE_TYPE); }
#line 1602 "parser.tab.cc"
    break;

  case 21: /* type_specifier: SIGNED  */
#line 200 "parser.y"
             { (yyval.type_node) = new Type(Type::INT_TYPE); }
#line 1608 "parser.tab.cc"
    break;

  case 22: /* type_specifier: UNSIGNED  */
#line 201 "parser.y"
               { 
        auto type = new Type(Type::INT_TYPE);
        type->is_unsigned = true;
        (yyval.type_node) = type;
    }
#line 1618 "parser.tab.cc"
    break;

  case 23: /* type_specifier: struct_or_union_specifier  */
#line 206 "parser.y"
                                { (yyval.type_node) = (yyvsp[0].type_node); }
#line 1624 "parser.tab.cc"
    break;

  case 24: /* type_specifier: enum_specifier  */
#line 207 "parser.y"
                     { (yyval.type_node) = (yyvsp[0].type_node); }
#line 1630 "parser.tab.cc"
    break;

  case 25: /* type_specifier: IDENTIFIER  */
#line 208 "parser.y"
                 { 
        // TODO: Look up typedef name
        (yyval.type_node) = new Type(Type::INT_TYPE);
        free((yyvsp[0].str_val));
    }
#line 1640 "parser.tab.cc"
    break;

  case 26: /* struct_or_union_specifier: STRUCT IDENTIFIER LBRACE RBRACE  */
#line 216 "parser.y"
                                    {
        (yyval.type_node) = new StructType((yyvsp[-2].str_val));
        free((yyvsp[-2].str_val));
    }
#line 1649 "parser.tab.cc"
    break;

  case 27: /* struct_or_union_specifier: UNION IDENTIFIER LBRACE RBRACE  */
#line 220 "parser.y"
                                     {
        auto struct_type = new StructType((yyvsp[-2].str_val));
        struct_type->kind = Type::UNION_TYPE;
        (yyval.type_node) = struct_type;
        free((yyvsp[-2].str_val));
    }
#line 1660 "parser.tab.cc"
    break;

  case 28: /* struct_or_union_specifier: STRUCT IDENTIFIER  */
#line 226 "parser.y"
                        {
        (yyval.type_node) = new StructType((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 1669 "parser.tab.cc"
    break;

  case 29: /* struct_or_union_specifier: UNION IDENTIFIER  */
#line 230 "parser.y"
                       {
        auto struct_type = new StructType((yyvsp[0].str_val));
        struct_type->kind = Type::UNION_TYPE;
        (yyval.type_node) = struct_type;
        free((yyvsp[0].str_val));
    }
#line 1680 "parser.tab.cc"
    break;

  case 30: /* enum_specifier: ENUM IDENTIFIER LBRACE RBRACE  */
#line 239 "parser.y"
                                  {
        (yyval.type_node) = new Type(Type::ENUM_TYPE);
        free((yyvsp[-2].str_val));
    }
#line 1689 "parser.tab.cc"
    break;

  case 31: /* enum_specifier: ENUM IDENTIFIER  */
#line 243 "parser.y"
                      {
        (yyval.type_node) = new Type(Type::ENUM_TYPE);
        free((yyvsp[0].str_val));
    }
#line 1698 "parser.tab.cc"
    break;

  case 32: /* parameter_list_opt: %empty  */
#line 250 "parser.y"
                { (yyval.param_list) = nullptr; }
#line 1704 "parser.tab.cc"
    break;

  case 33: /* parameter_list_opt: parameter_list  */
#line 251 "parser.y"
                     { (yyval.param_list) = (yyvsp[0].param_list); }
#line 1710 "parser.tab.cc"
    break;

  case 34: /* parameter_list: parameter_declaration  */
#line 255 "parser.y"
                          {
        (yyval.param_list) = new std::vector<Parameter>();
        if ((yyvsp[0].param)) {
            (yyval.param_list)->push_back(*(yyvsp[0].param));
            delete (yyvsp[0].param);
        }
    }
#line 1722 "parser.tab.cc"
    break;

  case 35: /* parameter_list: parameter_list COMMA parameter_declaration  */
#line 262 "parser.y"
                                                 {
        (yyval.param_list) = (yyvsp[-2].param_list);
        if ((yyvsp[0].param)) {
            (yyval.param_list)->push_back(*(yyvsp[0].param));
            delete (yyvsp[0].param);
        }
    }
#line 1734 "parser.tab.cc"
    break;

  case 36: /* parameter_declaration: type_specifier IDENTIFIER  */
#line 272 "parser.y"
                              {
        (yyval.param) = new Parameter((yyvsp[0].str_val), std::unique_ptr<Type>((yyvsp[-1].type_node)));
        free((yyvsp[0].str_val));
    }
#line 1743 "parser.tab.cc"
    break;

  case 37: /* parameter_declaration: type_specifier IDENTIFIER LBRACKET RBRACKET  */
#line 276 "parser.y"
                                                  {
        auto array_type = std::make_unique<ArrayType>(std::unique_ptr<Type>((yyvsp[-3].type_node)), 0);
        (yyval.param) = new Parameter((yyvsp[-2].str_val), std::move(array_type));
        free((yyvsp[-2].str_val));
    }
#line 1753 "parser.tab.cc"
    break;

  case 38: /* parameter_declaration: type_specifier  */
#line 281 "parser.y"
                     {
        (yyval.param) = new Parameter("", std::unique_ptr<Type>((yyvsp[0].type_node)));
    }
#line 1761 "parser.tab.cc"
    break;

  case 39: /* struct_declaration: STRUCT IDENTIFIER LBRACE RBRACE SEMICOLON  */
#line 287 "parser.y"
                                              {
        auto struct_decl = new StructDeclaration((yyvsp[-3].str_val));
        (yyval.decl) = struct_decl;
        free((yyvsp[-3].str_val));
    }
#line 1771 "parser.tab.cc"
    break;

  case 40: /* enum_declaration: ENUM IDENTIFIER LBRACE RBRACE SEMICOLON  */
#line 295 "parser.y"
                                            {
        auto enum_decl = new EnumDeclaration((yyvsp[-3].str_val));
        (yyval.decl) = enum_decl;
        free((yyvsp[-3].str_val));
    }
#line 1781 "parser.tab.cc"
    break;

  case 41: /* typedef_declaration: TYPEDEF type_specifier IDENTIFIER SEMICOLON  */
#line 303 "parser.y"
                                                {
        auto typedef_decl = new TypedefDeclaration((yyvsp[-1].str_val), std::unique_ptr<Type>((yyvsp[-2].type_node)));
        (yyval.decl) = typedef_decl;
        free((yyvsp[-1].str_val));
    }
#line 1791 "parser.tab.cc"
    break;

  case 42: /* compound_statement: LBRACE statement_list_opt RBRACE  */
#line 311 "parser.y"
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
#line 1806 "parser.tab.cc"
    break;

  case 43: /* statement_list_opt: %empty  */
#line 324 "parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 1812 "parser.tab.cc"
    break;

  case 44: /* statement_list_opt: statement_list  */
#line 325 "parser.y"
                     { (yyval.stmt_list) = (yyvsp[0].stmt_list); }
#line 1818 "parser.tab.cc"
    break;

  case 45: /* statement_list: statement  */
#line 329 "parser.y"
              {
        (yyval.stmt_list) = new std::vector<Statement*>();
        if ((yyvsp[0].stmt)) (yyval.stmt_list)->push_back((yyvsp[0].stmt));
    }
#line 1827 "parser.tab.cc"
    break;

  case 46: /* statement_list: statement_list statement  */
#line 333 "parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) (yyval.stmt_list)->push_back((yyvsp[0].stmt));
    }
#line 1836 "parser.tab.cc"
    break;

  case 47: /* statement: labeled_statement  */
#line 340 "parser.y"
                      { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1842 "parser.tab.cc"
    break;

  case 48: /* statement: compound_statement  */
#line 341 "parser.y"
                         { (yyval.stmt) = (yyvsp[0].block); }
#line 1848 "parser.tab.cc"
    break;

  case 49: /* statement: expression_statement  */
#line 342 "parser.y"
                           { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1854 "parser.tab.cc"
    break;

  case 50: /* statement: selection_statement  */
#line 343 "parser.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1860 "parser.tab.cc"
    break;

  case 51: /* statement: iteration_statement  */
#line 344 "parser.y"
                          { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1866 "parser.tab.cc"
    break;

  case 52: /* statement: jump_statement  */
#line 345 "parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1872 "parser.tab.cc"
    break;

  case 53: /* statement: declaration  */
#line 346 "parser.y"
                  { (yyval.stmt) = (yyvsp[0].decl); }
#line 1878 "parser.tab.cc"
    break;

  case 54: /* labeled_statement: IDENTIFIER COLON statement  */
#line 350 "parser.y"
                               {
        (yyval.stmt) = new LabelStatement((yyvsp[-2].str_val), std::unique_ptr<Statement>((yyvsp[0].stmt)));
        free((yyvsp[-2].str_val));
    }
#line 1887 "parser.tab.cc"
    break;

  case 55: /* labeled_statement: CASE constant COLON statement  */
#line 354 "parser.y"
                                    {
        (yyval.stmt) = new CaseStatement(std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1895 "parser.tab.cc"
    break;

  case 56: /* labeled_statement: DEFAULT COLON statement  */
#line 357 "parser.y"
                              {
        (yyval.stmt) = new CaseStatement(nullptr, std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1903 "parser.tab.cc"
    break;

  case 57: /* expression_statement: expression SEMICOLON  */
#line 363 "parser.y"
                         {
        (yyval.stmt) = new ExpressionStatement(std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 1911 "parser.tab.cc"
    break;

  case 58: /* expression_statement: SEMICOLON  */
#line 366 "parser.y"
                {
        (yyval.stmt) = new ExpressionStatement(nullptr);
    }
#line 1919 "parser.tab.cc"
    break;

  case 59: /* selection_statement: IF LPAREN expression RPAREN statement  */
#line 372 "parser.y"
                                          {
        (yyval.stmt) = new IfStatement(std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1927 "parser.tab.cc"
    break;

  case 60: /* selection_statement: IF LPAREN expression RPAREN statement ELSE statement  */
#line 375 "parser.y"
                                                           {
        (yyval.stmt) = new IfStatement(std::unique_ptr<Expression>((yyvsp[-4].expr)), std::unique_ptr<Statement>((yyvsp[-2].stmt)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1935 "parser.tab.cc"
    break;

  case 61: /* selection_statement: SWITCH LPAREN expression RPAREN statement  */
#line 378 "parser.y"
                                                {
        (yyval.stmt) = new SwitchStatement(std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1943 "parser.tab.cc"
    break;

  case 62: /* iteration_statement: WHILE LPAREN expression RPAREN statement  */
#line 384 "parser.y"
                                             {
        (yyval.stmt) = new WhileStatement(std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Statement>((yyvsp[0].stmt)));
    }
#line 1951 "parser.tab.cc"
    break;

  case 63: /* iteration_statement: DO statement WHILE LPAREN expression RPAREN SEMICOLON  */
#line 387 "parser.y"
                                                            {
        (yyval.stmt) = new DoWhileStatement(std::unique_ptr<Statement>((yyvsp[-5].stmt)), std::unique_ptr<Expression>((yyvsp[-2].expr)));
    }
#line 1959 "parser.tab.cc"
    break;

  case 64: /* iteration_statement: FOR LPAREN expression_statement expression_statement expression RPAREN statement  */
#line 390 "parser.y"
                                                                                       {
        (yyval.stmt) = new ForStatement(std::unique_ptr<Statement>((yyvsp[-4].stmt)), 
                             std::unique_ptr<Expression>(static_cast<ExpressionStatement*>((yyvsp[-3].stmt))->expression.release()),
                             std::unique_ptr<Expression>((yyvsp[-2].expr)), 
                             std::unique_ptr<Statement>((yyvsp[0].stmt)));
        delete (yyvsp[-3].stmt);
    }
#line 1971 "parser.tab.cc"
    break;

  case 65: /* iteration_statement: FOR LPAREN expression_statement expression_statement RPAREN statement  */
#line 397 "parser.y"
                                                                            {
        (yyval.stmt) = new ForStatement(std::unique_ptr<Statement>((yyvsp[-3].stmt)), 
                             std::unique_ptr<Expression>(static_cast<ExpressionStatement*>((yyvsp[-2].stmt))->expression.release()),
                             nullptr, 
                             std::unique_ptr<Statement>((yyvsp[0].stmt)));
        delete (yyvsp[-2].stmt);
    }
#line 1983 "parser.tab.cc"
    break;

  case 66: /* jump_statement: GOTO IDENTIFIER SEMICOLON  */
#line 407 "parser.y"
                              {
        (yyval.stmt) = new GotoStatement((yyvsp[-1].str_val));
        free((yyvsp[-1].str_val));
    }
#line 1992 "parser.tab.cc"
    break;

  case 67: /* jump_statement: CONTINUE SEMICOLON  */
#line 411 "parser.y"
                         {
        (yyval.stmt) = new ContinueStatement();
    }
#line 2000 "parser.tab.cc"
    break;

  case 68: /* jump_statement: BREAK SEMICOLON  */
#line 414 "parser.y"
                      {
        (yyval.stmt) = new BreakStatement();
    }
#line 2008 "parser.tab.cc"
    break;

  case 69: /* jump_statement: RETURN expression SEMICOLON  */
#line 417 "parser.y"
                                  {
        (yyval.stmt) = new ReturnStatement(std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 2016 "parser.tab.cc"
    break;

  case 70: /* jump_statement: RETURN SEMICOLON  */
#line 420 "parser.y"
                       {
        (yyval.stmt) = new ReturnStatement();
    }
#line 2024 "parser.tab.cc"
    break;

  case 71: /* expression: assignment_expression  */
#line 426 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2030 "parser.tab.cc"
    break;

  case 72: /* expression: expression COMMA assignment_expression  */
#line 427 "parser.y"
                                             {
        (yyval.expr) = new BinaryOp(BinaryOp::COMMA, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2038 "parser.tab.cc"
    break;

  case 73: /* assignment_expression: conditional_expression  */
#line 433 "parser.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 2044 "parser.tab.cc"
    break;

  case 74: /* assignment_expression: unary_expression assignment_operator assignment_expression  */
#line 434 "parser.y"
                                                                 {
        (yyval.expr) = new BinaryOp((yyvsp[-1].bin_op), std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2052 "parser.tab.cc"
    break;

  case 75: /* assignment_operator: ASSIGN  */
#line 440 "parser.y"
           { (yyval.bin_op) = BinaryOp::ASSIGN; }
#line 2058 "parser.tab.cc"
    break;

  case 76: /* assignment_operator: MULT_ASSIGN  */
#line 441 "parser.y"
                  { (yyval.bin_op) = BinaryOp::MULT_ASSIGN; }
#line 2064 "parser.tab.cc"
    break;

  case 77: /* assignment_operator: DIV_ASSIGN  */
#line 442 "parser.y"
                 { (yyval.bin_op) = BinaryOp::DIV_ASSIGN; }
#line 2070 "parser.tab.cc"
    break;

  case 78: /* assignment_operator: MOD_ASSIGN  */
#line 443 "parser.y"
                 { (yyval.bin_op) = BinaryOp::MOD_ASSIGN; }
#line 2076 "parser.tab.cc"
    break;

  case 79: /* assignment_operator: PLUS_ASSIGN  */
#line 444 "parser.y"
                  { (yyval.bin_op) = BinaryOp::PLUS_ASSIGN; }
#line 2082 "parser.tab.cc"
    break;

  case 80: /* assignment_operator: MINUS_ASSIGN  */
#line 445 "parser.y"
                   { (yyval.bin_op) = BinaryOp::MINUS_ASSIGN; }
#line 2088 "parser.tab.cc"
    break;

  case 81: /* assignment_operator: LSHIFT_ASSIGN  */
#line 446 "parser.y"
                    { (yyval.bin_op) = BinaryOp::LSHIFT_ASSIGN; }
#line 2094 "parser.tab.cc"
    break;

  case 82: /* assignment_operator: RSHIFT_ASSIGN  */
#line 447 "parser.y"
                    { (yyval.bin_op) = BinaryOp::RSHIFT_ASSIGN; }
#line 2100 "parser.tab.cc"
    break;

  case 83: /* assignment_operator: AND_ASSIGN  */
#line 448 "parser.y"
                 { (yyval.bin_op) = BinaryOp::AND_ASSIGN; }
#line 2106 "parser.tab.cc"
    break;

  case 84: /* assignment_operator: XOR_ASSIGN  */
#line 449 "parser.y"
                 { (yyval.bin_op) = BinaryOp::XOR_ASSIGN; }
#line 2112 "parser.tab.cc"
    break;

  case 85: /* assignment_operator: OR_ASSIGN  */
#line 450 "parser.y"
                { (yyval.bin_op) = BinaryOp::OR_ASSIGN; }
#line 2118 "parser.tab.cc"
    break;

  case 86: /* conditional_expression: logical_or_expression  */
#line 454 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2124 "parser.tab.cc"
    break;

  case 87: /* conditional_expression: logical_or_expression QUESTION expression COLON conditional_expression  */
#line 455 "parser.y"
                                                                             {
        (yyval.expr) = new ConditionalOp(std::unique_ptr<Expression>((yyvsp[-4].expr)), std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2132 "parser.tab.cc"
    break;

  case 88: /* logical_or_expression: logical_and_expression  */
#line 461 "parser.y"
                           { (yyval.expr) = (yyvsp[0].expr); }
#line 2138 "parser.tab.cc"
    break;

  case 89: /* logical_or_expression: logical_or_expression OR logical_and_expression  */
#line 462 "parser.y"
                                                      {
        (yyval.expr) = new BinaryOp(BinaryOp::OR, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2146 "parser.tab.cc"
    break;

  case 90: /* logical_and_expression: inclusive_or_expression  */
#line 468 "parser.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2152 "parser.tab.cc"
    break;

  case 91: /* logical_and_expression: logical_and_expression AND inclusive_or_expression  */
#line 469 "parser.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::AND, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2160 "parser.tab.cc"
    break;

  case 92: /* inclusive_or_expression: exclusive_or_expression  */
#line 475 "parser.y"
                            { (yyval.expr) = (yyvsp[0].expr); }
#line 2166 "parser.tab.cc"
    break;

  case 93: /* inclusive_or_expression: inclusive_or_expression BITWISE_OR exclusive_or_expression  */
#line 476 "parser.y"
                                                                 {
        (yyval.expr) = new BinaryOp(BinaryOp::BITWISE_OR, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2174 "parser.tab.cc"
    break;

  case 94: /* exclusive_or_expression: and_expression  */
#line 482 "parser.y"
                   { (yyval.expr) = (yyvsp[0].expr); }
#line 2180 "parser.tab.cc"
    break;

  case 95: /* exclusive_or_expression: exclusive_or_expression BITWISE_XOR and_expression  */
#line 483 "parser.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::BITWISE_XOR, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2188 "parser.tab.cc"
    break;

  case 96: /* and_expression: equality_expression  */
#line 489 "parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2194 "parser.tab.cc"
    break;

  case 97: /* and_expression: and_expression BITWISE_AND equality_expression  */
#line 490 "parser.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::BITWISE_AND, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2202 "parser.tab.cc"
    break;

  case 98: /* equality_expression: relational_expression  */
#line 496 "parser.y"
                          { (yyval.expr) = (yyvsp[0].expr); }
#line 2208 "parser.tab.cc"
    break;

  case 99: /* equality_expression: equality_expression EQ relational_expression  */
#line 497 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::EQ, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2216 "parser.tab.cc"
    break;

  case 100: /* equality_expression: equality_expression NE relational_expression  */
#line 500 "parser.y"
                                                   {
        (yyval.expr) = new BinaryOp(BinaryOp::NE, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2224 "parser.tab.cc"
    break;

  case 101: /* relational_expression: shift_expression  */
#line 506 "parser.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2230 "parser.tab.cc"
    break;

  case 102: /* relational_expression: relational_expression LT shift_expression  */
#line 507 "parser.y"
                                                {
        (yyval.expr) = new BinaryOp(BinaryOp::LT, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2238 "parser.tab.cc"
    break;

  case 103: /* relational_expression: relational_expression GT shift_expression  */
#line 510 "parser.y"
                                                {
        (yyval.expr) = new BinaryOp(BinaryOp::GT, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2246 "parser.tab.cc"
    break;

  case 104: /* relational_expression: relational_expression LE shift_expression  */
#line 513 "parser.y"
                                                {
        (yyval.expr) = new BinaryOp(BinaryOp::LE, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2254 "parser.tab.cc"
    break;

  case 105: /* relational_expression: relational_expression GE shift_expression  */
#line 516 "parser.y"
                                                {
        (yyval.expr) = new BinaryOp(BinaryOp::GE, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2262 "parser.tab.cc"
    break;

  case 106: /* shift_expression: additive_expression  */
#line 522 "parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 2268 "parser.tab.cc"
    break;

  case 107: /* shift_expression: shift_expression LSHIFT additive_expression  */
#line 523 "parser.y"
                                                  {
        (yyval.expr) = new BinaryOp(BinaryOp::LSHIFT, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2276 "parser.tab.cc"
    break;

  case 108: /* shift_expression: shift_expression RSHIFT additive_expression  */
#line 526 "parser.y"
                                                  {
        (yyval.expr) = new BinaryOp(BinaryOp::RSHIFT, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2284 "parser.tab.cc"
    break;

  case 109: /* additive_expression: multiplicative_expression  */
#line 532 "parser.y"
                              { (yyval.expr) = (yyvsp[0].expr); }
#line 2290 "parser.tab.cc"
    break;

  case 110: /* additive_expression: additive_expression PLUS multiplicative_expression  */
#line 533 "parser.y"
                                                         {
        (yyval.expr) = new BinaryOp(BinaryOp::ADD, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2298 "parser.tab.cc"
    break;

  case 111: /* additive_expression: additive_expression MINUS multiplicative_expression  */
#line 536 "parser.y"
                                                          {
        (yyval.expr) = new BinaryOp(BinaryOp::SUB, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2306 "parser.tab.cc"
    break;

  case 112: /* multiplicative_expression: cast_expression  */
#line 542 "parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 2312 "parser.tab.cc"
    break;

  case 113: /* multiplicative_expression: multiplicative_expression MULT cast_expression  */
#line 543 "parser.y"
                                                     {
        (yyval.expr) = new BinaryOp(BinaryOp::MUL, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2320 "parser.tab.cc"
    break;

  case 114: /* multiplicative_expression: multiplicative_expression DIV cast_expression  */
#line 546 "parser.y"
                                                    {
        (yyval.expr) = new BinaryOp(BinaryOp::DIV, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2328 "parser.tab.cc"
    break;

  case 115: /* multiplicative_expression: multiplicative_expression MOD cast_expression  */
#line 549 "parser.y"
                                                    {
        (yyval.expr) = new BinaryOp(BinaryOp::MOD, std::unique_ptr<Expression>((yyvsp[-2].expr)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2336 "parser.tab.cc"
    break;

  case 116: /* cast_expression: unary_expression  */
#line 555 "parser.y"
                     { (yyval.expr) = (yyvsp[0].expr); }
#line 2342 "parser.tab.cc"
    break;

  case 117: /* cast_expression: LPAREN type_specifier RPAREN cast_expression  */
#line 556 "parser.y"
                                                   {
        (yyval.expr) = new CastExpression(std::unique_ptr<Type>((yyvsp[-2].type_node)), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2350 "parser.tab.cc"
    break;

  case 118: /* unary_expression: postfix_expression  */
#line 562 "parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2356 "parser.tab.cc"
    break;

  case 119: /* unary_expression: INC unary_expression  */
#line 563 "parser.y"
                           {
        (yyval.expr) = new UnaryOp(UnaryOp::PRE_INC, std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2364 "parser.tab.cc"
    break;

  case 120: /* unary_expression: DEC unary_expression  */
#line 566 "parser.y"
                           {
        (yyval.expr) = new UnaryOp(UnaryOp::PRE_DEC, std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2372 "parser.tab.cc"
    break;

  case 121: /* unary_expression: unary_operator cast_expression  */
#line 569 "parser.y"
                                     {
        (yyval.expr) = new UnaryOp((yyvsp[-1].un_op), std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2380 "parser.tab.cc"
    break;

  case 122: /* unary_expression: SIZEOF unary_expression  */
#line 572 "parser.y"
                              {
        (yyval.expr) = new SizeofExpression(std::unique_ptr<Expression>((yyvsp[0].expr)));
    }
#line 2388 "parser.tab.cc"
    break;

  case 123: /* unary_expression: SIZEOF LPAREN type_specifier RPAREN  */
#line 575 "parser.y"
                                          {
        (yyval.expr) = new SizeofExpression(std::unique_ptr<Type>((yyvsp[-1].type_node)));
    }
#line 2396 "parser.tab.cc"
    break;

  case 124: /* unary_operator: BITWISE_AND  */
#line 581 "parser.y"
                { (yyval.un_op) = UnaryOp::ADDRESS_OF; }
#line 2402 "parser.tab.cc"
    break;

  case 125: /* unary_operator: MULT  */
#line 582 "parser.y"
           { (yyval.un_op) = UnaryOp::DEREF; }
#line 2408 "parser.tab.cc"
    break;

  case 126: /* unary_operator: PLUS  */
#line 583 "parser.y"
           { (yyval.un_op) = UnaryOp::PLUS; }
#line 2414 "parser.tab.cc"
    break;

  case 127: /* unary_operator: MINUS  */
#line 584 "parser.y"
            { (yyval.un_op) = UnaryOp::MINUS; }
#line 2420 "parser.tab.cc"
    break;

  case 128: /* unary_operator: BITWISE_NOT  */
#line 585 "parser.y"
                  { (yyval.un_op) = UnaryOp::BITWISE_NOT; }
#line 2426 "parser.tab.cc"
    break;

  case 129: /* unary_operator: NOT  */
#line 586 "parser.y"
          { (yyval.un_op) = UnaryOp::NOT; }
#line 2432 "parser.tab.cc"
    break;

  case 130: /* postfix_expression: primary_expression  */
#line 590 "parser.y"
                       { (yyval.expr) = (yyvsp[0].expr); }
#line 2438 "parser.tab.cc"
    break;

  case 131: /* postfix_expression: postfix_expression LBRACKET expression RBRACKET  */
#line 591 "parser.y"
                                                      {
        (yyval.expr) = new ArrayAccess(std::unique_ptr<Expression>((yyvsp[-3].expr)), std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 2446 "parser.tab.cc"
    break;

  case 132: /* postfix_expression: postfix_expression LPAREN argument_expression_list_opt RPAREN  */
#line 594 "parser.y"
                                                                    {
        auto func_call = new FunctionCall(std::unique_ptr<Expression>((yyvsp[-3].expr)));
        if ((yyvsp[-1].expr_list)) {
            for (auto& expr : *(yyvsp[-1].expr_list)) {
                func_call->arguments.push_back(std::unique_ptr<Expression>(expr));
            }
            delete (yyvsp[-1].expr_list);
        }
        (yyval.expr) = func_call;
    }
#line 2461 "parser.tab.cc"
    break;

  case 133: /* postfix_expression: postfix_expression DOT IDENTIFIER  */
#line 604 "parser.y"
                                        {
        (yyval.expr) = new MemberAccess(std::unique_ptr<Expression>((yyvsp[-2].expr)), (yyvsp[0].str_val), false);
        free((yyvsp[0].str_val));
    }
#line 2470 "parser.tab.cc"
    break;

  case 134: /* postfix_expression: postfix_expression ARROW IDENTIFIER  */
#line 608 "parser.y"
                                          {
        (yyval.expr) = new MemberAccess(std::unique_ptr<Expression>((yyvsp[-2].expr)), (yyvsp[0].str_val), true);
        free((yyvsp[0].str_val));
    }
#line 2479 "parser.tab.cc"
    break;

  case 135: /* postfix_expression: postfix_expression INC  */
#line 612 "parser.y"
                             {
        (yyval.expr) = new UnaryOp(UnaryOp::POST_INC, std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 2487 "parser.tab.cc"
    break;

  case 136: /* postfix_expression: postfix_expression DEC  */
#line 615 "parser.y"
                             {
        (yyval.expr) = new UnaryOp(UnaryOp::POST_DEC, std::unique_ptr<Expression>((yyvsp[-1].expr)));
    }
#line 2495 "parser.tab.cc"
    break;

  case 137: /* primary_expression: IDENTIFIER  */
#line 621 "parser.y"
               {
        (yyval.expr) = new Identifier((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 2504 "parser.tab.cc"
    break;

  case 138: /* primary_expression: constant  */
#line 625 "parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 2510 "parser.tab.cc"
    break;

  case 139: /* primary_expression: LPAREN expression RPAREN  */
#line 626 "parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2518 "parser.tab.cc"
    break;

  case 140: /* constant: INT_LITERAL  */
#line 632 "parser.y"
                {
        (yyval.expr) = new IntLiteral((yyvsp[0].int_val));
    }
#line 2526 "parser.tab.cc"
    break;

  case 141: /* constant: FLOAT_LITERAL  */
#line 635 "parser.y"
                    {
        (yyval.expr) = new FloatLiteral((yyvsp[0].float_val));
    }
#line 2534 "parser.tab.cc"
    break;

  case 142: /* constant: DOUBLE_LITERAL  */
#line 638 "parser.y"
                     {
        (yyval.expr) = new FloatLiteral((yyvsp[0].double_val));
    }
#line 2542 "parser.tab.cc"
    break;

  case 143: /* constant: CHAR_LITERAL  */
#line 641 "parser.y"
                   {
        (yyval.expr) = new CharLiteral((yyvsp[0].char_val));
    }
#line 2550 "parser.tab.cc"
    break;

  case 144: /* constant: STRING_LITERAL  */
#line 644 "parser.y"
                     {
        (yyval.expr) = new StringLiteral((yyvsp[0].str_val));
        free((yyvsp[0].str_val));
    }
#line 2559 "parser.tab.cc"
    break;

  case 145: /* argument_expression_list_opt: %empty  */
#line 651 "parser.y"
                { (yyval.expr_list) = nullptr; }
#line 2565 "parser.tab.cc"
    break;

  case 146: /* argument_expression_list_opt: argument_expression_list  */
#line 652 "parser.y"
                               { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 2571 "parser.tab.cc"
    break;

  case 147: /* argument_expression_list: assignment_expression  */
#line 656 "parser.y"
                          {
        (yyval.expr_list) = new std::vector<Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 2580 "parser.tab.cc"
    break;

  case 148: /* argument_expression_list: argument_expression_list COMMA assignment_expression  */
#line 660 "parser.y"
                                                           {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 2589 "parser.tab.cc"
    break;


#line 2593 "parser.tab.cc"

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

#line 666 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Parse error at line %d: %s\n", yylineno, s);
}
