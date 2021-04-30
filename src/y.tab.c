/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "mongcc.y"

	#include "structure.h"
	void yyerror(char *s);

#line 75 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    VOID = 258,
    INT = 259,
    FOR = 260,
    WHILE = 261,
    IF = 262,
    ELSE = 263,
    SWITCH = 264,
    CASE = 265,
    DEFAULT = 266,
    BREAK = 267,
    RETURN = 268,
    PLUS = 269,
    MOINS = 270,
    MUL = 271,
    DIV = 272,
    LSHIFT = 273,
    RSHIFT = 274,
    BAND = 275,
    BOR = 276,
    LAND = 277,
    LOR = 278,
    LT = 279,
    GT = 280,
    GEQ = 281,
    LEQ = 282,
    EQ = 283,
    NEQ = 284,
    NOT = 285,
    EXTERN = 286,
    THEN = 287,
    REL = 288,
    IDENTIFICATEUR = 289,
    CONSTANTE = 290
  };
#endif
/* Tokens.  */
#define VOID 258
#define INT 259
#define FOR 260
#define WHILE 261
#define IF 262
#define ELSE 263
#define SWITCH 264
#define CASE 265
#define DEFAULT 266
#define BREAK 267
#define RETURN 268
#define PLUS 269
#define MOINS 270
#define MUL 271
#define DIV 272
#define LSHIFT 273
#define RSHIFT 274
#define BAND 275
#define BOR 276
#define LAND 277
#define LOR 278
#define LT 279
#define GT 280
#define GEQ 281
#define LEQ 282
#define EQ 283
#define NEQ 284
#define NOT 285
#define EXTERN 286
#define THEN 287
#define REL 288
#define IDENTIFICATEUR 289
#define CONSTANTE 290

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 19 "mongcc.y"

	char* label;
	char* type_var;
	struct _symbole *symbole;
	struct _arbre *arbre;

#line 204 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   244

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

#define YYUNDEFTOK  2
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      40,    41,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    44,    36,
       2,    45,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    38,     2,    39,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,     2,     2,     2,     2,
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
      35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    74,    80,    87,    92,    97,   101,   107,
     113,   118,   124,   128,   134,   149,   156,   160,   166,   172,
     178,   183,   188,   194,   199,   204,   208,   214,   218,   222,
     226,   230,   234,   240,   247,   254,   259,   265,   273,   277,
     282,   283,   287,   294,   298,   302,   309,   318,   325,   331,
     335,   342,   346,   352,   356,   361,   366,   371,   376,   381,
     386,   391,   396,   400,   404,   408,   414,   418,   421,   425,
     431,   435,   439,   443,   450,   451,   454,   455,   456,   457,
     458,   459
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VOID", "INT", "FOR", "WHILE", "IF",
  "ELSE", "SWITCH", "CASE", "DEFAULT", "BREAK", "RETURN", "PLUS", "MOINS",
  "MUL", "DIV", "LSHIFT", "RSHIFT", "BAND", "BOR", "LAND", "LOR", "LT",
  "GT", "GEQ", "LEQ", "EQ", "NEQ", "NOT", "EXTERN", "THEN", "REL",
  "IDENTIFICATEUR", "CONSTANTE", "';'", "','", "'['", "']'", "'('", "')'",
  "'{'", "'}'", "':'", "'='", "$accept", "programme", "liste_declarations",
  "liste_fonctions", "liste_fonctions_creator", "declaration",
  "liste_declarateurs", "declarateur", "fonction", "type", "parm",
  "liste_parms", "liste_parm_creator", "liste_instructions",
  "inst_liste_creator", "instruction", "iteration", "selection",
  "list_case_default", "case_default", "saut", "affectation", "bloc",
  "appel", "variable", "tableau", "expression", "liste_expressions",
  "expr_liste_creator", "condition", "binary_rel", "binary_comp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,    59,    44,    91,    93,
      40,    41,   123,   125,    58,    61
};
# endif

#define YYPACT_NINF (-74)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -74,     5,    13,   -74,   -74,   -74,     9,   -74,    13,   -74,
     -74,   -26,   -15,   -74,    -9,    -7,    52,    10,     3,    -7,
      56,   -74,    39,    45,    56,    49,   -74,    44,    54,   -74,
      10,    55,    68,   -74,    61,    56,   -74,    81,   -74,   -74,
     -74,    92,    79,    80,    83,    93,   108,    42,   -20,   -74,
      39,    88,    33,   -74,   -74,   -74,   -74,   123,   -74,   -74,
     132,   161,   153,    72,    72,    -8,   -74,    -8,    23,   -74,
     -74,    -8,   -74,   177,    -8,    92,   -74,   -74,   -74,    -8,
      -8,   162,   167,   168,    72,   200,    43,    91,   137,   109,
      -8,   149,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
     -74,   216,   160,   169,   159,   216,   165,    72,    72,   121,
     102,   -74,   -74,   -74,   -74,   -74,   -74,    -8,   -74,   -74,
      33,    72,    33,   163,   170,   -74,   155,   155,   109,   109,
      95,    95,   -74,   -74,   173,    -8,   -74,   -74,   -13,   166,
     -74,   216,   -74,   -74,   202,   150,   -74,   -74,   216,   153,
     -74,    33,   187,   179,    19,   -74,   171,   -74,   194,    33,
     -74,   -74,    33,    33,   -74,   -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     6,     1,    16,    17,     0,     2,     5,     3,
       8,     0,     0,     7,     0,    12,     0,    11,     0,     0,
      20,     9,     0,     0,    20,     0,    22,     0,    19,    12,
      10,     0,     0,    18,     0,     0,    13,     0,     4,    21,
      15,    24,     0,     0,     0,     0,     0,     0,    49,     4,
       0,     0,    23,    26,    27,    28,    29,     0,    31,    32,
       0,    50,     0,     0,     0,     0,    43,     0,    49,    63,
      44,     0,    64,     0,    67,    24,    14,    25,    30,     0,
       0,    49,     0,     0,     0,     0,     0,     0,     0,    62,
      67,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      45,    69,     0,    66,     0,    46,     0,     0,     0,     0,
       0,    76,    77,    78,    79,    80,    81,     0,    74,    75,
       0,     0,     0,     0,     0,    53,    54,    55,    57,    56,
      59,    58,    60,    61,     0,     0,    47,    52,     0,     0,
      72,    73,    34,    71,    35,    40,    65,    48,    68,     0,
      70,     0,     0,     0,     0,    39,     0,    36,     0,    24,
      37,    38,     0,    24,    42,    33,    41
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -35,   -74,   -74,   -74,   -74,   217,   232,    62,
     206,   218,   -74,   -73,   -74,   -51,   -74,   -74,   -74,    89,
     -74,   -56,   -74,   -74,   -41,   -74,   -43,   154,   -74,   -49,
     -74,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     7,     8,     9,    16,    17,    10,    50,
      26,    27,    28,    51,    52,    53,    54,    55,   154,   155,
      56,    57,    58,    59,    72,    61,    85,   102,   103,    86,
     121,   117
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      60,    77,   104,    41,    73,     3,    82,    67,    15,   118,
     119,    60,     4,     5,    75,    87,     4,     5,   -51,    18,
      74,    60,    88,   149,    89,    19,    68,    69,    91,   152,
     153,   101,    71,    20,    60,   110,   105,   106,    42,    43,
      44,   109,    45,    24,     6,    46,    47,   101,    23,   126,
     127,   128,   129,   130,   131,   132,   133,    67,   138,   139,
      25,   -51,   160,    90,    11,   118,   119,    48,    12,   142,
      14,   144,   143,    29,   141,    49,    68,    69,    70,    60,
      31,    60,    71,    33,   120,    34,   164,    67,    21,    22,
     166,    35,   148,   156,    36,     4,     5,    42,    43,    44,
     157,    45,    83,    38,    46,    47,    68,    69,    60,    37,
      60,   165,    84,   118,   119,    98,    99,    40,    60,    62,
      63,    60,    60,    64,   118,   119,    48,    96,    97,    98,
      99,    76,   122,    65,    49,    92,    93,    94,    95,    96,
      97,    98,    99,   140,    66,   111,   112,   113,   114,   115,
     116,    92,    93,    94,    95,    96,    97,    98,    99,    78,
     152,   153,   125,    92,    93,    94,    95,    96,    97,    98,
      99,    94,    95,    96,    97,    98,    99,    79,   123,    92,
      93,    94,    95,    96,    97,    98,    99,    81,   118,   119,
     125,    92,    93,    94,    95,    96,    97,    98,    99,    80,
     -51,   134,   136,   107,   137,   145,   135,   150,   108,   147,
     151,   146,   162,   100,    92,    93,    94,    95,    96,    97,
      98,    99,   158,   159,   111,   112,   113,   114,   115,   116,
      92,    93,    94,    95,    96,    97,    98,    99,   163,    30,
      13,    39,    32,   161,   124
};

static const yytype_uint8 yycheck[] =
{
      41,    52,    75,    38,    47,     0,    62,    15,    34,    22,
      23,    52,     3,     4,    49,    64,     3,     4,    38,    34,
      40,    62,    65,    36,    67,    34,    34,    35,    71,    10,
      11,    74,    40,    40,    75,    84,    79,    80,     5,     6,
       7,    84,     9,    40,    31,    12,    13,    90,    38,    92,
      93,    94,    95,    96,    97,    98,    99,    15,   107,   108,
       4,    38,    43,    40,     2,    22,    23,    34,     6,   120,
       8,   122,   121,    34,   117,    42,    34,    35,    36,   120,
      35,   122,    40,    34,    41,    41,   159,    15,    36,    37,
     163,    37,   135,   149,    39,     3,     4,     5,     6,     7,
     151,     9,    30,    42,    12,    13,    34,    35,   149,    41,
     151,   162,    40,    22,    23,    20,    21,    36,   159,    40,
      40,   162,   163,    40,    22,    23,    34,    18,    19,    20,
      21,    43,    41,    40,    42,    14,    15,    16,    17,    18,
      19,    20,    21,    41,    36,    24,    25,    26,    27,    28,
      29,    14,    15,    16,    17,    18,    19,    20,    21,    36,
      10,    11,    41,    14,    15,    16,    17,    18,    19,    20,
      21,    16,    17,    18,    19,    20,    21,    45,    41,    14,
      15,    16,    17,    18,    19,    20,    21,    34,    22,    23,
      41,    14,    15,    16,    17,    18,    19,    20,    21,    38,
      38,    41,    43,    36,    39,    42,    37,    41,    40,    36,
       8,    41,    41,    36,    14,    15,    16,    17,    18,    19,
      20,    21,    35,    44,    24,    25,    26,    27,    28,    29,
      14,    15,    16,    17,    18,    19,    20,    21,    44,    22,
       8,    35,    24,   154,    90
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    48,     0,     3,     4,    31,    49,    50,    51,
      54,    55,    55,    54,    55,    34,    52,    53,    34,    34,
      40,    36,    37,    38,    40,     4,    56,    57,    58,    34,
      53,    35,    57,    34,    41,    37,    39,    41,    42,    56,
      36,    48,     5,     6,     7,     9,    12,    13,    34,    42,
      55,    59,    60,    61,    62,    63,    66,    67,    68,    69,
      70,    71,    40,    40,    40,    40,    36,    15,    34,    35,
      36,    40,    70,    72,    40,    48,    43,    61,    36,    45,
      38,    34,    67,    30,    40,    72,    75,    75,    72,    72,
      40,    72,    14,    15,    16,    17,    18,    19,    20,    21,
      36,    72,    73,    74,    59,    72,    72,    36,    40,    72,
      75,    24,    25,    26,    27,    28,    29,    77,    22,    23,
      41,    76,    41,    41,    73,    41,    72,    72,    72,    72,
      72,    72,    72,    72,    41,    37,    43,    39,    75,    75,
      41,    72,    61,    75,    61,    42,    41,    36,    72,    36,
      41,     8,    10,    11,    64,    65,    67,    61,    35,    44,
      43,    65,    41,    44,    59,    61,    59
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    56,    57,
      57,    58,    58,    59,    59,    60,    60,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    64,    64,
      65,    65,    65,    66,    66,    66,    67,    68,    69,    70,
      70,    71,    71,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    75,    76,    76,    77,    77,    77,    77,
      77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     0,     2,     1,     3,
       3,     1,     1,     4,     9,     7,     1,     1,     2,     1,
       0,     3,     1,     1,     0,     2,     1,     1,     1,     1,
       2,     1,     1,     9,     5,     5,     7,     7,     2,     1,
       0,     4,     3,     2,     2,     3,     3,     4,     5,     1,
       1,     1,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     1,     1,     4,     1,     0,     3,     1,
       4,     3,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 67 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("programme", (yyvsp[0].arbre), NULL, MON_AUTRE);
		affichage_arbre((yyval.arbre));
		//generer_dot($$);
	}
#line 1515 "y.tab.c"
    break;

  case 3:
#line 75 "mongcc.y"
        {			
		TABLE[ACC]=ajouter_symbole(TABLE[ACC], (yyvsp[0].symbole));
		struct _symbole *tmp = TABLE[ACC];	
	}
#line 1524 "y.tab.c"
    break;

  case 4:
#line 80 "mongcc.y"
        {  
		nouvelle_adresse(); 
		//printf("nouvelle décl %d\n",ACC);
	}
#line 1533 "y.tab.c"
    break;

  case 5:
#line 88 "mongcc.y"
        {
		(yyval.arbre)=(yyvsp[0].arbre);
	}
#line 1541 "y.tab.c"
    break;

  case 6:
#line 92 "mongcc.y"
        {
		
	}
#line 1549 "y.tab.c"
    break;

  case 7:
#line 98 "mongcc.y"
        {
		ajouter_frere((yyvsp[-1].arbre),(yyvsp[0].arbre));
	}
#line 1557 "y.tab.c"
    break;

  case 8:
#line 102 "mongcc.y"
        {
		(yyval.arbre)=(yyvsp[0].arbre);
	}
#line 1565 "y.tab.c"
    break;

  case 9:
#line 108 "mongcc.y"
        {
		(yyval.symbole) = fixer_type((yyvsp[-1].symbole),(yyvsp[-2].type_var));
	}
#line 1573 "y.tab.c"
    break;

  case 10:
#line 114 "mongcc.y"
        { 		
		(yyval.symbole) = ajouter_symbole((yyvsp[-2].symbole), (yyvsp[0].symbole));
		
	}
#line 1582 "y.tab.c"
    break;

  case 11:
#line 119 "mongcc.y"
        { 
		(yyval.symbole) = (yyvsp[0].symbole); 
	}
#line 1590 "y.tab.c"
    break;

  case 12:
#line 125 "mongcc.y"
        { 
		(yyval.symbole) = creer_symbole((yyvsp[0].label), NULL);  
	}
#line 1598 "y.tab.c"
    break;

  case 13:
#line 129 "mongcc.y"
        {
		
	}
#line 1606 "y.tab.c"
    break;

  case 14:
#line 135 "mongcc.y"
        {
		detruire_table_fonction();
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],creer_symbole((yyvsp[-7].label), (yyvsp[-8].type_var)));
		struct _arbre *bloc = creer_arbre("BLOC", (yyvsp[-1].arbre), NULL, MON_BLOC);

		char* buf = malloc(256);
		snprintf(buf,256,"%s, %s",(yyvsp[-7].label),(yyvsp[-8].type_var));

		char* copy = malloc(256);
		strcpy(copy, buf);

		(yyval.arbre) = creer_arbre(copy, bloc, NULL, MON_FONCTION);
		free(buf);
	}
#line 1625 "y.tab.c"
    break;

  case 15:
#line 150 "mongcc.y"
        { 
		detruire_table();
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],creer_symbole((yyvsp[-4].label), (yyvsp[-5].type_var)));
	}
#line 1634 "y.tab.c"
    break;

  case 16:
#line 157 "mongcc.y"
        { 
		(yyval.type_var) = "VOID";
	}
#line 1642 "y.tab.c"
    break;

  case 17:
#line 161 "mongcc.y"
        { 
		(yyval.type_var) = "INT"; 
	}
#line 1650 "y.tab.c"
    break;

  case 18:
#line 167 "mongcc.y"
        {
		(yyval.symbole)=creer_symbole((yyvsp[0].label),"INT");
	}
#line 1658 "y.tab.c"
    break;

  case 19:
#line 173 "mongcc.y"
        {
		nouvelle_adresse();
		TABLE[ACC] = ajouter_symbole(TABLE[ACC],(yyvsp[0].symbole));
	}
#line 1667 "y.tab.c"
    break;

  case 20:
#line 178 "mongcc.y"
        {
		nouvelle_adresse();
	}
#line 1675 "y.tab.c"
    break;

  case 21:
#line 184 "mongcc.y"
        {
		(yyval.symbole) = ajouter_symbole((yyvsp[-2].symbole), (yyvsp[0].symbole));
		
	}
#line 1684 "y.tab.c"
    break;

  case 22:
#line 189 "mongcc.y"
        {
		
	}
#line 1692 "y.tab.c"
    break;

  case 23:
#line 195 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 1700 "y.tab.c"
    break;

  case 24:
#line 199 "mongcc.y"
        {
	
	}
#line 1708 "y.tab.c"
    break;

  case 25:
#line 205 "mongcc.y"
        {
		ajouter_frere((yyvsp[-1].arbre),(yyvsp[0].arbre));
	}
#line 1716 "y.tab.c"
    break;

  case 26:
#line 209 "mongcc.y"
        {
		(yyval.arbre)=(yyvsp[0].arbre);
	}
#line 1724 "y.tab.c"
    break;

  case 27:
#line 215 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 1732 "y.tab.c"
    break;

  case 28:
#line 219 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 1740 "y.tab.c"
    break;

  case 29:
#line 223 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 1748 "y.tab.c"
    break;

  case 30:
#line 227 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[-1].arbre);
	}
#line 1756 "y.tab.c"
    break;

  case 31:
#line 231 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("BLOC", (yyvsp[0].arbre), NULL, MON_BLOC);
	}
#line 1764 "y.tab.c"
    break;

  case 32:
#line 235 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 1772 "y.tab.c"
    break;

  case 33:
#line 241 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("FOR", (yyvsp[-6].arbre), NULL, MON_ITERATION);
		ajouter_frere((yyvsp[-6].arbre), (yyvsp[-4].arbre));
		ajouter_frere((yyvsp[-4].arbre), (yyvsp[-2].arbre));
		ajouter_frere((yyvsp[-2].arbre), (yyvsp[0].arbre));
	}
#line 1783 "y.tab.c"
    break;

  case 34:
#line 248 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("WHILE",(yyvsp[-2].arbre),NULL, MON_ITERATION);
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
	}
#line 1792 "y.tab.c"
    break;

  case 35:
#line 255 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("IF", (yyvsp[-2].arbre), NULL, MON_IF);
		ajouter_frere((yyvsp[-2].arbre), (yyvsp[0].arbre));
	}
#line 1801 "y.tab.c"
    break;

  case 36:
#line 260 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("IF", (yyvsp[-4].arbre), NULL, MON_IF);
		ajouter_frere((yyvsp[-4].arbre),(yyvsp[-2].arbre));
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
	}
#line 1811 "y.tab.c"
    break;

  case 37:
#line 266 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("SWITCH", (yyvsp[-4].arbre), NULL, MON_SWITCH);
		ajouter_frere((yyvsp[-4].arbre), (yyvsp[-1].arbre));
	}
#line 1820 "y.tab.c"
    break;

  case 38:
#line 274 "mongcc.y"
        {
		ajouter_frere((yyvsp[-1].arbre),(yyvsp[0].arbre));
	}
#line 1828 "y.tab.c"
    break;

  case 39:
#line 278 "mongcc.y"
        {
		(yyval.arbre)=(yyvsp[0].arbre);
	}
#line 1836 "y.tab.c"
    break;

  case 41:
#line 284 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("CASE", creer_arbre((yyvsp[-2].label),NULL,(yyvsp[0].arbre), MON_AUTRE), NULL, MON_CASE);
	}
#line 1844 "y.tab.c"
    break;

  case 42:
#line 288 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("DEFAULT", (yyvsp[0].arbre), NULL, MON_DEFAUT);
	}
#line 1852 "y.tab.c"
    break;

  case 43:
#line 295 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("BREAK", NULL, NULL, MON_BREAK);
	}
#line 1860 "y.tab.c"
    break;

  case 44:
#line 299 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("RETURN",NULL,NULL, MON_RETURN);
	}
#line 1868 "y.tab.c"
    break;

  case 45:
#line 303 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("RETURN",(yyvsp[-1].arbre),NULL,MON_RETURN);
	}
#line 1876 "y.tab.c"
    break;

  case 46:
#line 310 "mongcc.y"
        { 
		rechercher_symbole((yyvsp[-2].arbre)->label);
		ajouter_frere((yyvsp[-2].arbre), (yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre(":=", (yyvsp[-2].arbre), NULL,MON_AUTRE);
	}
#line 1886 "y.tab.c"
    break;

  case 47:
#line 319 "mongcc.y"
        { 										
		detruire_table();
		(yyval.arbre) = (yyvsp[-1].arbre);
	}
#line 1895 "y.tab.c"
    break;

  case 48:
#line 326 "mongcc.y"
        { 
		(yyval.arbre)=creer_arbre((yyvsp[-4].label),(yyvsp[-2].arbre),NULL,MON_APPEL);
	}
#line 1903 "y.tab.c"
    break;

  case 49:
#line 332 "mongcc.y"
        {
			(yyval.arbre) = creer_arbre((yyvsp[0].label), NULL, NULL,MON_AUTRE); 
	}
#line 1911 "y.tab.c"
    break;

  case 50:
#line 336 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("TAB", (yyvsp[0].arbre), NULL, MON_TABLEAU);
	}
#line 1919 "y.tab.c"
    break;

  case 51:
#line 343 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre((yyvsp[0].label), NULL, NULL,MON_AUTRE); 
	}
#line 1927 "y.tab.c"
    break;

  case 52:
#line 347 "mongcc.y"
        {
		ajouter_frere((yyvsp[-3].arbre),(yyvsp[-1].arbre));
	}
#line 1935 "y.tab.c"
    break;

  case 53:
#line 353 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[-1].arbre);
	}
#line 1943 "y.tab.c"
    break;

  case 54:
#line 357 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("+",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 1952 "y.tab.c"
    break;

  case 55:
#line 362 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("-",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 1961 "y.tab.c"
    break;

  case 56:
#line 367 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("/",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 1970 "y.tab.c"
    break;

  case 57:
#line 372 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("*",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 1979 "y.tab.c"
    break;

  case 58:
#line 377 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre(">>",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 1988 "y.tab.c"
    break;

  case 59:
#line 382 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("<<",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 1997 "y.tab.c"
    break;

  case 60:
#line 387 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("&",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 2006 "y.tab.c"
    break;

  case 61:
#line 392 "mongcc.y"
        { 
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre("|",(yyvsp[-2].arbre),NULL,MON_AUTRE);
	}
#line 2015 "y.tab.c"
    break;

  case 62:
#line 397 "mongcc.y"
        { 
		(yyval.arbre) = creer_arbre("-", (yyvsp[0].arbre), NULL,MON_AUTRE);
	}
#line 2023 "y.tab.c"
    break;

  case 63:
#line 401 "mongcc.y"
        { 
		(yyval.arbre) = creer_arbre((yyvsp[0].label),NULL,NULL,MON_AUTRE);
	}
#line 2031 "y.tab.c"
    break;

  case 64:
#line 405 "mongcc.y"
        { 
		(yyval.arbre) = (yyvsp[0].arbre); 
	}
#line 2039 "y.tab.c"
    break;

  case 65:
#line 409 "mongcc.y"
        { 
		(yyval.arbre) = creer_arbre((yyvsp[-3].label), (yyvsp[-1].arbre),NULL,MON_AUTRE);
	}
#line 2047 "y.tab.c"
    break;

  case 66:
#line 415 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 2055 "y.tab.c"
    break;

  case 67:
#line 418 "mongcc.y"
          {/* rien */}
#line 2061 "y.tab.c"
    break;

  case 68:
#line 422 "mongcc.y"
        {
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
	}
#line 2069 "y.tab.c"
    break;

  case 69:
#line 426 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[0].arbre);
	}
#line 2077 "y.tab.c"
    break;

  case 70:
#line 432 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre("NOT", (yyvsp[-1].arbre), NULL, MON_AUTRE);
	}
#line 2085 "y.tab.c"
    break;

  case 71:
#line 436 "mongcc.y"
        {
		(yyval.arbre) = creer_arbre((yyvsp[-1].label), (yyvsp[-2].arbre), (yyvsp[0].arbre), MON_AUTRE);
	}
#line 2093 "y.tab.c"
    break;

  case 72:
#line 440 "mongcc.y"
        {
		(yyval.arbre) = (yyvsp[-1].arbre);
	}
#line 2101 "y.tab.c"
    break;

  case 73:
#line 444 "mongcc.y"
        {
		ajouter_frere((yyvsp[-2].arbre),(yyvsp[0].arbre));
		(yyval.arbre) = creer_arbre((yyvsp[-1].label), (yyvsp[-2].arbre),NULL, MON_AUTRE);
	}
#line 2110 "y.tab.c"
    break;

  case 74:
#line 450 "mongcc.y"
                     { (yyval.label) = "&&"; }
#line 2116 "y.tab.c"
    break;

  case 75:
#line 451 "mongcc.y"
                     { (yyval.label) = "||"; }
#line 2122 "y.tab.c"
    break;

  case 76:
#line 454 "mongcc.y"
                   { (yyval.label) = "<"; }
#line 2128 "y.tab.c"
    break;

  case 77:
#line 455 "mongcc.y"
                   { (yyval.label) = ">"; }
#line 2134 "y.tab.c"
    break;

  case 78:
#line 456 "mongcc.y"
                    { (yyval.label) = ">=";}
#line 2140 "y.tab.c"
    break;

  case 79:
#line 457 "mongcc.y"
                    { (yyval.label) = "<=";}
#line 2146 "y.tab.c"
    break;

  case 80:
#line 458 "mongcc.y"
                   { (yyval.label) = "==";}
#line 2152 "y.tab.c"
    break;

  case 81:
#line 459 "mongcc.y"
                    { (yyval.label) = "!=";}
#line 2158 "y.tab.c"
    break;


#line 2162 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 461 "mongcc.y"


void yyerror(char *s)
{
	fprintf( stderr, "%s\n", s );
}

int main()
{
	// nouvel=creer_arbre("a", creer_arbre("b",creer_arbre("e",NULL ,creer_arbre("f", creer_arbre("g",NULL ,NULL), NULL)) ,creer_arbre("c",NULL ,creer_arbre("d", NULL, NULL))), NULL);
	//affichage_arbre(nouvel);
	
	//init_table();

	yyparse();
	//creation_dot();
	return 0;
}
