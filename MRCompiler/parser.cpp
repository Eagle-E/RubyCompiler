/* A Bison parser, made by GNU Bison 3.7.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





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

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_COMMA = 4,                      /* COMMA  */
  YYSYMBOL_LPAREN = 5,                     /* LPAREN  */
  YYSYMBOL_RPAREN = 6,                     /* RPAREN  */
  YYSYMBOL_INTEGER = 7,                    /* INTEGER  */
  YYSYMBOL_IDENTIFIER = 8,                 /* IDENTIFIER  */
  YYSYMBOL_BOOLEAN = 9,                    /* BOOLEAN  */
  YYSYMBOL_UNDEF = 10,                     /* UNDEF  */
  YYSYMBOL_DEF = 11,                       /* DEF  */
  YYSYMBOL_END = 12,                       /* END  */
  YYSYMBOL_RETURN = 13,                    /* RETURN  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_THEN = 15,                      /* THEN  */
  YYSYMBOL_ELSIF = 16,                     /* ELSIF  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_UNLESS = 18,                    /* UNLESS  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_UNTIL = 21,                     /* UNTIL  */
  YYSYMBOL_CASE = 22,                      /* CASE  */
  YYSYMBOL_WHEN = 23,                      /* WHEN  */
  YYSYMBOL_ASSIGN = 24,                    /* ASSIGN  */
  YYSYMBOL_PLUSASSIGN = 25,                /* PLUSASSIGN  */
  YYSYMBOL_MINUSASSIGN = 26,               /* MINUSASSIGN  */
  YYSYMBOL_MULASSIGN = 27,                 /* MULASSIGN  */
  YYSYMBOL_DIVASSIGN = 28,                 /* DIVASSIGN  */
  YYSYMBOL_ANDASSIGN = 29,                 /* ANDASSIGN  */
  YYSYMBOL_ORASSIGN = 30,                  /* ORASSIGN  */
  YYSYMBOL_PLUS = 31,                      /* PLUS  */
  YYSYMBOL_MINUS = 32,                     /* MINUS  */
  YYSYMBOL_MUL = 33,                       /* MUL  */
  YYSYMBOL_DIV = 34,                       /* DIV  */
  YYSYMBOL_GT = 35,                        /* GT  */
  YYSYMBOL_GE = 36,                        /* GE  */
  YYSYMBOL_LT = 37,                        /* LT  */
  YYSYMBOL_LE = 38,                        /* LE  */
  YYSYMBOL_EQ = 39,                        /* EQ  */
  YYSYMBOL_NE = 40,                        /* NE  */
  YYSYMBOL_AND = 41,                       /* AND  */
  YYSYMBOL_OR = 42,                        /* OR  */
  YYSYMBOL_NOT = 43,                       /* NOT  */
  YYSYMBOL_EOL = 44,                       /* EOL  */
  YYSYMBOL_PREC_ASSIGN = 45,               /* PREC_ASSIGN  */
  YYSYMBOL_UMINUS = 46,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_compstmt = 48,                  /* compstmt  */
  YYSYMBOL_zeroOrMore_stmt = 49,           /* zeroOrMore_stmt  */
  YYSYMBOL_stmt = 50,                      /* stmt  */
  YYSYMBOL_expr = 51,                      /* expr  */
  YYSYMBOL_literal = 52,                   /* literal  */
  YYSYMBOL_assignop = 53,                  /* assignop  */
  YYSYMBOL_program = 54,                   /* program  */
  YYSYMBOL_zeroOrMore_t = 55,              /* zeroOrMore_t  */
  YYSYMBOL_zeroOrOne_t = 56,               /* zeroOrOne_t  */
  YYSYMBOL_t = 57,                         /* t  */
  YYSYMBOL_then = 58,                      /* then  */
  YYSYMBOL_do = 59,                        /* do  */
  YYSYMBOL_expressions = 60,               /* expressions  */
  YYSYMBOL_zereOrOne_expressions = 61,     /* zereOrOne_expressions  */
  YYSYMBOL_arglist = 62,                   /* arglist  */
  YYSYMBOL_zereOrOne_arglist = 63,         /* zereOrOne_arglist  */
  YYSYMBOL_zeroOrMore_elseif = 64,         /* zeroOrMore_elseif  */
  YYSYMBOL_zeroOrOne_else = 65,            /* zeroOrOne_else  */
  YYSYMBOL_zeroOrMore_when = 66            /* zeroOrMore_when  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 53 "parser.y"

Program* program = new Program();
 // CompoundStatement* rootStatement = program->getRootStatement(); //new CompoundStatement();
CompoundStatement* rootStatement = new CompoundStatement();
int i = 0;

#line 177 "parser.cpp"

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
typedef yytype_int8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  53
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  69
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   122,   122,   124,   130,   146,   150,   162,   163,   167,
     168,   171,   172,   175,   176,   177,   179,   179,   179,   181,
     182,   183,   185,   193,   194,   195,   196,   197,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     215,   216,   218,   219,   220,   224,   228,   232,   233,   237,
     238,   242,   243,   247,   248,   252,   253,   260,   261,   265,
     266,   270,   271,   275,   276,   277,   278,   279,   280,   281
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
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "COMMA",
  "LPAREN", "RPAREN", "INTEGER", "IDENTIFIER", "BOOLEAN", "UNDEF", "DEF",
  "END", "RETURN", "IF", "THEN", "ELSIF", "ELSE", "UNLESS", "WHILE", "DO",
  "UNTIL", "CASE", "WHEN", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN",
  "MULASSIGN", "DIVASSIGN", "ANDASSIGN", "ORASSIGN", "PLUS", "MINUS",
  "MUL", "DIV", "GT", "GE", "LT", "LE", "EQ", "NE", "AND", "OR", "NOT",
  "EOL", "PREC_ASSIGN", "UMINUS", "$accept", "compstmt", "zeroOrMore_stmt",
  "stmt", "expr", "literal", "assignop", "program", "zeroOrMore_t",
  "zeroOrOne_t", "t", "then", "do", "expressions", "zereOrOne_expressions",
  "arglist", "zereOrOne_arglist", "zeroOrMore_elseif", "zeroOrOne_else",
  "zeroOrMore_when", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301
};
#endif

#define YYPACT_NINF (-97)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     164,    30,   -97,    52,   -97,    14,    21,    30,    30,    30,
      30,    30,    30,    30,    30,   -97,   -97,   210,   -97,    32,
     178,    30,   -97,   -97,   -97,   -97,   -97,   -97,   -97,    30,
     -97,    31,   210,   103,   103,   126,   126,   198,   -97,   -97,
     -97,    30,    30,    30,    30,    30,    30,    30,    30,    30,
      30,    30,    30,   -97,   -97,   210,    54,    58,   210,    57,
     -97,   -97,   -97,    55,    12,   164,   -97,    47,   164,   164,
      30,    89,    20,    20,   -97,   -97,   -15,   -15,   -15,   -15,
     -15,   -15,   -29,   156,    30,   -97,   -97,    67,    68,   -97,
     164,   -97,    69,   -97,    63,    72,   103,   -97,   -97,   210,
      80,   164,   -97,   164,    77,   -97,   -97,   164,   -97,    81,
      44,   -97,   -97,   -97,   -97,    30,    83,     8,   103,   -97,
      30,    92,   164,   103,   -97,   -97,   164,   -97
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,    61,    43,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     5,    27,    42,     0,
       0,    49,    63,    64,    65,    66,    67,    68,    69,     0,
      19,     0,    21,     0,     0,     0,     0,     0,    41,    40,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,    46,    47,    50,     0,    44,    53,
      11,    14,    12,    13,     9,     0,    17,    16,     0,     0,
       0,     4,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,     0,    45,    51,    54,     0,    15,
       0,    10,    57,    18,     0,     0,     0,     6,     8,    48,
       0,     0,    55,     0,     0,    24,    25,     0,    52,     0,
      57,    58,    23,    59,    20,     0,     0,    57,     0,    22,
       0,     0,     0,     0,    26,    56,     0,    60
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -97,   -35,   -97,    34,    -1,   -97,   -97,   -97,   -97,   -97,
     -12,   -33,    65,   -97,   -97,   -97,   -97,   -97,   -96,   -97
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    15,    40,    16,    17,    18,    29,    19,    71,    90,
      63,    64,    68,    56,    57,    87,    88,   110,   104,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,    65,    41,    42,    43,    44,    32,    33,    34,    35,
      36,    37,    38,    39,   116,    60,    41,    42,    43,    44,
      55,   121,    30,    67,    67,   103,    51,    52,    58,    31,
      92,   120,    53,    94,    95,     1,    59,     2,     3,     4,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    91,    43,    44,   102,    62,    21,    84,    98,
     115,   103,    13,   107,    85,    86,   109,    93,   111,    96,
      89,   100,   113,    14,   101,   105,    22,    23,    24,    25,
      26,    27,    28,    99,   106,   122,   103,   125,   108,   112,
     126,   127,    60,   114,     1,   119,     2,     3,     4,     5,
       6,    69,     7,     8,   124,    97,    60,     9,    10,     0,
      11,    12,     0,     0,   118,     0,     0,     0,    61,   123,
       0,    13,     0,     0,     0,     0,     0,     0,     0,    60,
       0,     0,    14,    62,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    66,    62,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     1,
      62,     2,     3,     4,     5,     6,     0,     7,     8,     0,
       0,     0,     9,    10,    54,    11,    12,    41,    42,    43,
      44,     0,     0,     0,     0,     0,    13,    51,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    70,     0,     0,     0,     0,     0,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52
};

static const yytype_int8 yycheck[] =
{
       1,    34,    31,    32,    33,    34,     7,     8,     9,    10,
      11,    12,    13,    14,   110,     3,    31,    32,    33,    34,
      21,   117,     8,    35,    36,    17,    41,    42,    29,     8,
      65,    23,     0,    68,    69,     5,     5,     7,     8,     9,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    64,    33,    34,    90,    44,     5,     4,    71,
      16,    17,    32,    96,     6,     8,   101,    20,   103,    70,
      15,     4,   107,    43,     6,    12,    24,    25,    26,    27,
      28,    29,    30,    84,    12,   118,    17,   122,     8,    12,
     123,   126,     3,    12,     5,    12,     7,     8,     9,    10,
      11,    36,    13,    14,    12,    71,     3,    18,    19,    -1,
      21,    22,    -1,    -1,   115,    -1,    -1,    -1,    15,   120,
      -1,    32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
      -1,    -1,    43,    44,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    20,    44,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,     5,
      44,     7,     8,     9,    10,    11,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,     6,    21,    22,    31,    32,    33,
      34,    -1,    -1,    -1,    -1,    -1,    32,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    43,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,     8,     9,    10,    11,    13,    14,    18,
      19,    21,    22,    32,    43,    48,    50,    51,    52,    54,
      51,     5,    24,    25,    26,    27,    28,    29,    30,    53,
       8,     8,    51,    51,    51,    51,    51,    51,    51,    51,
      49,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,     0,     6,    51,    60,    61,    51,     5,
       3,    15,    44,    57,    58,    58,    20,    57,    59,    59,
      23,    55,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,     4,     6,     8,    62,    63,    15,
      56,    57,    48,    20,    48,    48,    51,    50,    57,    51,
       4,     6,    48,    17,    65,    12,    12,    58,     8,    48,
      64,    48,    12,    48,    12,    16,    65,    66,    51,    12,
      23,    65,    58,    51,    12,    48,    58,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    54,    54,    48,    49,    49,    55,    55,    56,
      56,    57,    57,    58,    58,    58,    59,    59,    59,    50,
      50,    50,    50,    50,    50,    50,    50,    50,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    51,    51,    51,    51,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    52,    52,    53,    53,    53,    53,    53,    53,    53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     3,     0,     3,     0,     2,     0,
       1,     1,     1,     1,     1,     2,     1,     1,     2,     2,
       7,     2,     8,     6,     5,     5,     9,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     3,     4,     3,     1,     3,     0,
       1,     1,     3,     0,     1,     0,     5,     0,     2,     0,
       5,     1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 3: /* program: compstmt  */
#line 124 "parser.y"
                                {
						//program->setRootStatement(rootStatement);
						program->setRootStatement((yyvsp[0].t_cmp_statement));
					}
#line 1239 "parser.cpp"
    break;

  case 4: /* compstmt: stmt zeroOrMore_stmt zeroOrMore_t  */
#line 131 "parser.y"
                                                                {
									cout << "@@@ + " << i << endl;
									string s("\t\t");
									(yyvsp[-2].t_statement)->print(s);
									i++;
									//rootStatement->prependStatement($stmt);
									cout << "<before>" << endl;
									(yyvsp[-1].t_cmp_statement)->prependStatement((yyvsp[-2].t_statement));
									(yyval.t_cmp_statement) = (yyvsp[-1].t_cmp_statement);
									cout << "<after>" << endl;
									
								}
#line 1256 "parser.cpp"
    break;

  case 5: /* zeroOrMore_stmt: %empty  */
#line 146 "parser.y"
                        { 
						cout << "@@@ * " << i << endl; i++; 
						(yyval.t_cmp_statement) = new CompoundStatement();
					}
#line 1265 "parser.cpp"
    break;

  case 6: /* zeroOrMore_stmt: zeroOrMore_stmt zeroOrMore_t stmt  */
#line 151 "parser.y"
                                                                {
									cout << "@@@ - " << i << endl;
									string s("\t\t");
									(yyvsp[0].t_statement)->print(s);
									i++;
									//rootStatement->appendStatement($stmt);
									(yyval.t_cmp_statement)->appendStatement((yyvsp[0].t_statement));
								}
#line 1278 "parser.cpp"
    break;

  case 11: /* t: SEMICOLON  */
#line 171 "parser.y"
              { cout <<"[t]: " << ";" <<  endl;}
#line 1284 "parser.cpp"
    break;

  case 12: /* t: EOL  */
#line 172 "parser.y"
                  { cout <<"[t]: " << "EOL" <<  endl;}
#line 1290 "parser.cpp"
    break;

  case 13: /* then: t  */
#line 175 "parser.y"
                        { cout <<"[then]: " << "<t>" <<  endl;}
#line 1296 "parser.cpp"
    break;

  case 14: /* then: THEN  */
#line 176 "parser.y"
                        { cout <<"[then]: " << "then" <<  endl;}
#line 1302 "parser.cpp"
    break;

  case 15: /* then: t THEN  */
#line 177 "parser.y"
                        { cout <<"[then]: " << "<t> then" <<  endl;}
#line 1308 "parser.cpp"
    break;

  case 19: /* stmt: UNDEF IDENTIFIER  */
#line 181 "parser.y"
                                {cout << "undef" << endl;}
#line 1314 "parser.cpp"
    break;

  case 20: /* stmt: DEF IDENTIFIER LPAREN zereOrOne_arglist RPAREN compstmt END  */
#line 182 "parser.y"
                                                                              {cout << "function def" << endl;}
#line 1320 "parser.cpp"
    break;

  case 21: /* stmt: RETURN expr  */
#line 183 "parser.y"
                                        {cout << "return" << endl;}
#line 1326 "parser.cpp"
    break;

  case 22: /* stmt: IF expr then zeroOrOne_t compstmt zeroOrMore_elseif zeroOrOne_else END  */
#line 186 "parser.y"
                        {
				cout << "IF STMT" << endl;
				IfStatement * ifStm = new IfStatement();
				ifStm->setIfStatement(new ConditionExpression((yyvsp[-6].t_expression)), (yyvsp[-3].t_cmp_statement));
				(yyval.t_statement) = ifStm;
			}
#line 1337 "parser.cpp"
    break;

  case 23: /* stmt: UNLESS expr then compstmt zeroOrOne_else END  */
#line 193 "parser.y"
                                                               {cout << "unless" << endl;}
#line 1343 "parser.cpp"
    break;

  case 24: /* stmt: WHILE expr do compstmt END  */
#line 194 "parser.y"
                                             {cout << "while" << endl;}
#line 1349 "parser.cpp"
    break;

  case 25: /* stmt: UNTIL expr do compstmt END  */
#line 195 "parser.y"
                                             {cout << "until" << endl;}
#line 1355 "parser.cpp"
    break;

  case 26: /* stmt: CASE expr WHEN expr then compstmt zeroOrMore_when zeroOrOne_else END  */
#line 196 "parser.y"
                                                                                       {cout << "case" << endl;}
#line 1361 "parser.cpp"
    break;

  case 27: /* stmt: expr  */
#line 197 "parser.y"
                                {(yyval.t_statement) = new ExpressionStatement((yyvsp[0].t_expression));}
#line 1367 "parser.cpp"
    break;

  case 28: /* expr: expr PLUS expr  */
#line 202 "parser.y"
                                                {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new Add());}
#line 1373 "parser.cpp"
    break;

  case 29: /* expr: expr MINUS expr  */
#line 203 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new Sub());}
#line 1379 "parser.cpp"
    break;

  case 30: /* expr: expr MUL expr  */
#line 204 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new Mul());}
#line 1385 "parser.cpp"
    break;

  case 31: /* expr: expr DIV expr  */
#line 205 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new Div());}
#line 1391 "parser.cpp"
    break;

  case 32: /* expr: expr GT expr  */
#line 206 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new GreaterThan());}
#line 1397 "parser.cpp"
    break;

  case 33: /* expr: expr GE expr  */
#line 207 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new GreaterOrEqual());}
#line 1403 "parser.cpp"
    break;

  case 34: /* expr: expr LT expr  */
#line 208 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new LessThan());}
#line 1409 "parser.cpp"
    break;

  case 35: /* expr: expr LE expr  */
#line 209 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new LessOrEqual());}
#line 1415 "parser.cpp"
    break;

  case 36: /* expr: expr EQ expr  */
#line 210 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new Equal());}
#line 1421 "parser.cpp"
    break;

  case 37: /* expr: expr NE expr  */
#line 211 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new NotEqual());}
#line 1427 "parser.cpp"
    break;

  case 38: /* expr: expr AND expr  */
#line 212 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new And());}
#line 1433 "parser.cpp"
    break;

  case 39: /* expr: expr OR expr  */
#line 213 "parser.y"
                                                        {(yyval.t_expression) = new BinOpExpression((yyvsp[-2].t_expression), (yyvsp[0].t_expression), new Or());}
#line 1439 "parser.cpp"
    break;

  case 40: /* expr: NOT expr  */
#line 215 "parser.y"
                                                        {(yyval.t_expression) = new UnaryBooleanNegationExpression((yyvsp[0].t_expression)); }
#line 1445 "parser.cpp"
    break;

  case 41: /* expr: MINUS expr  */
#line 216 "parser.y"
                                        {(yyval.t_expression) = new UnaryNumericNegationExpression((yyvsp[0].t_expression)); }
#line 1451 "parser.cpp"
    break;

  case 42: /* expr: literal  */
#line 218 "parser.y"
                                                        {(yyval.t_expression) = new LiteralExpression((yyvsp[0].t_literal)); }
#line 1457 "parser.cpp"
    break;

  case 43: /* expr: IDENTIFIER  */
#line 219 "parser.y"
                                                {(yyval.t_expression) = new IdentifierExpression((yyvsp[0].t_str));	}
#line 1463 "parser.cpp"
    break;

  case 44: /* expr: IDENTIFIER assignop expr  */
#line 221 "parser.y"
                                                                        {
										(yyval.t_expression) = new AssignmentExpression(new IdentifierExpression((yyvsp[-2].t_str)), (yyvsp[0].t_expression), (yyvsp[-1].t_assignop));
									}
#line 1471 "parser.cpp"
    break;

  case 45: /* expr: IDENTIFIER LPAREN zereOrOne_expressions RPAREN  */
#line 225 "parser.y"
                                                                        {
										/*cout << "function call" << endl;*/
									}
#line 1479 "parser.cpp"
    break;

  case 46: /* expr: LPAREN expr RPAREN  */
#line 228 "parser.y"
                                                {(yyval.t_expression) = (yyvsp[-1].t_expression); }
#line 1485 "parser.cpp"
    break;

  case 56: /* zeroOrMore_elseif: zeroOrMore_elseif ELSIF expr then compstmt  */
#line 254 "parser.y"
                {
			
		}
#line 1493 "parser.cpp"
    break;

  case 58: /* zeroOrOne_else: ELSE compstmt  */
#line 261 "parser.y"
                        {/*$$ = $2;*/ }
#line 1499 "parser.cpp"
    break;

  case 61: /* literal: INTEGER  */
#line 270 "parser.y"
                  { (yyval.t_literal) = new IntegerLiteral((yyvsp[0].t_int)); }
#line 1505 "parser.cpp"
    break;

  case 62: /* literal: BOOLEAN  */
#line 271 "parser.y"
                  { (yyval.t_literal) = new BooleanLiteral((yyvsp[0].t_int)); }
#line 1511 "parser.cpp"
    break;

  case 63: /* assignop: ASSIGN  */
#line 275 "parser.y"
                                {(yyval.t_assignop) = new AssignOp(); }
#line 1517 "parser.cpp"
    break;

  case 64: /* assignop: PLUSASSIGN  */
#line 276 "parser.y"
                        {(yyval.t_assignop) = new AssignPlus(); }
#line 1523 "parser.cpp"
    break;

  case 65: /* assignop: MINUSASSIGN  */
#line 277 "parser.y"
                        {(yyval.t_assignop) = new AssignMinus(); }
#line 1529 "parser.cpp"
    break;

  case 66: /* assignop: MULASSIGN  */
#line 278 "parser.y"
                        {(yyval.t_assignop) = new AssignTimes(); }
#line 1535 "parser.cpp"
    break;

  case 67: /* assignop: DIVASSIGN  */
#line 279 "parser.y"
                        {(yyval.t_assignop) = new AssignDivide(); }
#line 1541 "parser.cpp"
    break;

  case 68: /* assignop: ANDASSIGN  */
#line 280 "parser.y"
                        {(yyval.t_assignop) = new AssignAnd(); }
#line 1547 "parser.cpp"
    break;

  case 69: /* assignop: ORASSIGN  */
#line 281 "parser.y"
                                {(yyval.t_assignop) = new AssignOr(); }
#line 1553 "parser.cpp"
    break;


#line 1557 "parser.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 292 "parser.y"






void yyerror (const char *s)
{
    cerr << s << endl;
}
