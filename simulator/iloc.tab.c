/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 18 "iloc.y" /* yacc.c:339  */

  #define YYERROR_VERBOSE 

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include "instruction.h"
  #include "machine.h"

  extern int yylex(void);
  char token[256];

  #define MAX_ERROR_MESSAGE_LENGTH 100

  Operands* new_operands(void);
  Operand* append_operands(Operand*,Operand*);
  int verify_args(Opcode*,int,int,int,int);

  extern char yytext[];

  extern int line_counter;
  extern Opcode* current_opcode;

  /* This function must be defined */
  void yyerror(char*);

  /* If an error is encountered during parsing this is changed to 1 */
  int error_found = 0;

  /* Pointer to the first instruction */
  Instruction* first_instruction;

  /* Pointer to the end of the instruction list */
  Instruction* EndOfList;

  /* address for data initializations */
  int Start;


#line 106 "iloc.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "iloc.tab.h".  */
#ifndef YY_YY_ILOC_TAB_H_INCLUDED
# define YY_YY_ILOC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    OPEN_BRACKET = 258,
    CLOSE_BRACKET = 259,
    SEMICOLON = 260,
    COMMA = 261,
    ARROW = 262,
    OPCODE = 263,
    DOUTPUT = 264,
    REGISTER = 265,
    NUMBER = 266,
    LABEL = 267,
    TARGET = 268,
    DATA_CHAR = 269,
    DATA_INT = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "iloc.y" /* yacc.c:355  */

  int ival;
  char cval;
  Instruction* inst_ptr;
  Operation* op_ptr;
  Operands* operands_ptr;
  Operand* operand_ptr;
  Opcode* opcode_ptr;

#line 172 "iloc.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ILOC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 189 "iloc.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   46

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  16
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  37
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  54

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   108,   108,   112,   118,   123,   130,   136,   146,   152,
     160,   164,   171,   185,   197,   209,   222,   228,   234,   241,
     247,   254,   260,   269,   279,   288,   296,   305,   306,   309,
     310,   313,   314,   317,   318,   321,   327,   333
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OPEN_BRACKET", "CLOSE_BRACKET",
  "SEMICOLON", "COMMA", "ARROW", "OPCODE", "DOUTPUT", "REGISTER", "NUMBER",
  "LABEL", "TARGET", "DATA_CHAR", "DATA_INT", "$accept", "iloc_program",
  "instruction_list", "instruction", "operation_list", "operation",
  "the_opcode", "operand_list", "reg", "const", "lbl", "label_def",
  "data_defs", "data_def", "listofchar", "listofint", "charinit",
  "intinit", "addr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270
};
# endif

#define YYPACT_NINF -22

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-22)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       4,     0,   -22,   -22,     9,     9,    11,     1,   -22,   -22,
      24,     2,     4,   -22,    17,     8,   -22,     3,    21,   -22,
     -22,     2,    18,   -22,   -22,   -22,    30,    32,    33,    34,
     -22,     1,   -22,   -22,     0,   -22,     3,   -22,   -22,    21,
     -22,   -22,   -22,    18,    18,    18,    18,   -22,   -22,   -22,
     -22,   -22,   -22,   -22
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    16,    26,     0,     0,     0,     2,     4,     8,
      15,     0,     0,    28,     0,    10,    37,     0,     0,     1,
       6,     0,     0,    23,    24,    25,    13,    17,    19,    21,
       5,     3,    27,     9,     0,    35,    29,    32,    36,    30,
      34,     7,    14,     0,     0,     0,     0,    11,    31,    33,
      12,    18,    20,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -22,   -22,    29,    -5,    10,    -1,   -22,   -21,   -22,   -22,
     -22,    -4,   -22,    31,   -22,   -22,     6,     7,    40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,    14,     9,    10,    26,    27,    28,
      29,    11,    12,    13,    36,    39,    37,    40,    17
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      15,    42,    20,    21,     1,     1,    30,     1,     2,     2,
       2,    19,     2,    34,     3,    35,    41,     3,     4,     5,
      16,    33,    50,    51,    52,    53,    20,    21,    23,    24,
      25,    22,    38,    15,    23,    24,    25,    43,    44,    45,
      46,    31,    48,    32,    47,    18,    49
};

static const yytype_uint8 yycheck[] =
{
       1,    22,     7,     7,     3,     3,    11,     3,     8,     8,
       8,     0,     8,     5,    13,    12,    21,    13,    14,    15,
      11,     4,    43,    44,    45,    46,    31,    31,    10,    11,
      12,     7,    11,    34,    10,    11,    12,     7,     6,     6,
       6,    12,    36,    12,    34,     5,    39
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     8,    13,    14,    15,    17,    18,    19,    21,
      22,    27,    28,    29,    20,    21,    11,    34,    34,     0,
      19,    27,     7,    10,    11,    12,    23,    24,    25,    26,
      19,    18,    29,     4,     5,    12,    30,    32,    11,    31,
      33,    19,    23,     7,     6,     6,     6,    20,    32,    33,
      23,    23,    23,    23
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    16,    17,    17,    18,    18,    18,    18,    19,    19,
      20,    20,    21,    21,    21,    21,    22,    23,    23,    23,
      23,    23,    23,    24,    25,    26,    27,    28,    28,    29,
      29,    30,    30,    31,    31,    32,    33,    34
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     3,     1,     3,
       1,     3,     4,     2,     3,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     2,     1,     3,
       3,     2,     1,     2,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

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
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 109 "iloc.y" /* yacc.c:1646  */
    {
		     first_instruction = (yyvsp[0].inst_ptr);
		 }
#line 1298 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 113 "iloc.y" /* yacc.c:1646  */
    {
		     first_instruction = (yyvsp[0].inst_ptr);
		 }
#line 1306 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 119 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.inst_ptr) = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		 }
#line 1315 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 124 "iloc.y" /* yacc.c:1646  */
    {
		     Label* label_definition = get_label((yyvsp[-1].ival));
		     label_definition->target = (yyvsp[0].inst_ptr);
		     (yyval.inst_ptr) = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		 }
#line 1326 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 131 "iloc.y" /* yacc.c:1646  */
    {
		     EndOfList->next = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		     (yyval.inst_ptr) = (yyvsp[-1].inst_ptr);
		 }
#line 1336 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 137 "iloc.y" /* yacc.c:1646  */
    {
		     Label* label_definition = get_label((yyvsp[-1].ival));
		     label_definition->target = (yyvsp[0].inst_ptr);
		     EndOfList->next = (yyvsp[0].inst_ptr);
		     EndOfList = (yyvsp[0].inst_ptr);
		     (yyval.inst_ptr) = (yyvsp[-2].inst_ptr);
		 }
#line 1348 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 147 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.inst_ptr) = malloc(sizeof(Instruction));
		     (yyval.inst_ptr)->operations = (yyvsp[0].op_ptr);
		     (yyval.inst_ptr)->next = NULL;
		 }
#line 1358 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 153 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.inst_ptr) = malloc(sizeof(Instruction));
		     (yyval.inst_ptr)->operations = (yyvsp[-1].op_ptr);
		     (yyval.inst_ptr)->next = NULL;
		 }
#line 1368 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.op_ptr) = (yyvsp[0].op_ptr);
		 }
#line 1376 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 165 "iloc.y" /* yacc.c:1646  */
    {
		     (yyvsp[-2].op_ptr)->next = (yyvsp[0].op_ptr);
		     (yyval.op_ptr) = (yyvsp[-2].op_ptr);
		 }
#line 1385 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 172 "iloc.y" /* yacc.c:1646  */
    {
		     verify_args((yyvsp[-3].opcode_ptr),(yyvsp[-2].operands_ptr)->num_regs,(yyvsp[-2].operands_ptr)->num_consts+(yyvsp[0].operands_ptr)->num_consts,
				 (yyvsp[-2].operands_ptr)->num_labels+(yyvsp[0].operands_ptr)->num_labels,(yyvsp[0].operands_ptr)->num_regs);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[-3].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = (yyvsp[-2].operands_ptr)->regs;
		     (yyval.op_ptr)->consts = append_operands((yyvsp[-2].operands_ptr)->consts,(yyvsp[0].operands_ptr)->consts);
		     (yyval.op_ptr)->labels = append_operands((yyvsp[-2].operands_ptr)->labels,(yyvsp[0].operands_ptr)->labels);
		     (yyval.op_ptr)->defs = (yyvsp[0].operands_ptr)->regs;
		     (yyval.op_ptr)->next = NULL;
		     free((yyvsp[-2].operands_ptr));
		     free((yyvsp[0].operands_ptr));
		 }
#line 1403 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 186 "iloc.y" /* yacc.c:1646  */
    {
		     verify_args((yyvsp[-1].opcode_ptr),(yyvsp[0].operands_ptr)->num_regs,(yyvsp[0].operands_ptr)->num_consts,(yyvsp[0].operands_ptr)->num_labels,0);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[-1].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = (yyvsp[0].operands_ptr)->regs;
		     (yyval.op_ptr)->consts = (yyvsp[0].operands_ptr)->consts;
		     (yyval.op_ptr)->labels = (yyvsp[0].operands_ptr)->labels;
		     (yyval.op_ptr)->defs = NULL;
		     (yyval.op_ptr)->next = NULL;
		     free((yyvsp[0].operands_ptr));
		 }
#line 1419 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 198 "iloc.y" /* yacc.c:1646  */
    {
		     verify_args((yyvsp[-2].opcode_ptr),0,(yyvsp[0].operands_ptr)->num_consts,(yyvsp[0].operands_ptr)->num_labels,(yyvsp[0].operands_ptr)->num_regs);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[-2].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = NULL;
		     (yyval.op_ptr)->consts = (yyvsp[0].operands_ptr)->consts;
		     (yyval.op_ptr)->labels = (yyvsp[0].operands_ptr)->labels;
		     (yyval.op_ptr)->defs = (yyvsp[0].operands_ptr)->regs;
		     (yyval.op_ptr)->next = NULL;
		     free((yyvsp[0].operands_ptr));
		 }
#line 1435 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 210 "iloc.y" /* yacc.c:1646  */
    {
		     verify_args((yyvsp[0].opcode_ptr),0,0,0,0);
		     (yyval.op_ptr) = malloc(sizeof(Operation));
		     (yyval.op_ptr)->opcode = (yyvsp[0].opcode_ptr)->name;
		     (yyval.op_ptr)->srcs = NULL;
		     (yyval.op_ptr)->consts = NULL;
		     (yyval.op_ptr)->labels = NULL;
		     (yyval.op_ptr)->defs = NULL;
		     (yyval.op_ptr)->next = NULL;
		 }
#line 1450 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 223 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.opcode_ptr) = current_opcode;
		 }
#line 1458 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 229 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operands_ptr) = new_operands();
		     (yyval.operands_ptr)->num_regs = 1;
		     (yyval.operands_ptr)->regs = (yyvsp[0].operand_ptr);
		 }
#line 1468 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 235 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operands_ptr) = (yyvsp[0].operands_ptr);
		     (yyval.operands_ptr)->num_regs += 1;
		     (yyvsp[-2].operand_ptr)->next = (yyval.operands_ptr)->regs;
		     (yyval.operands_ptr)->regs = (yyvsp[-2].operand_ptr);
		 }
#line 1479 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 242 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operands_ptr) = new_operands();
		     (yyval.operands_ptr)->num_consts = 1;
		     (yyval.operands_ptr)->consts = (yyvsp[0].operand_ptr);
		 }
#line 1489 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 248 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operands_ptr) = (yyvsp[0].operands_ptr);
		     (yyval.operands_ptr)->num_consts += 1;
		     (yyvsp[-2].operand_ptr)->next = (yyval.operands_ptr)->consts;
		     (yyval.operands_ptr)->consts = (yyvsp[-2].operand_ptr);
		 }
#line 1500 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 255 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operands_ptr) = new_operands();
		     (yyval.operands_ptr)->num_labels = 1;
		     (yyval.operands_ptr)->labels = (yyvsp[0].operand_ptr);
		 }
#line 1510 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 261 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operands_ptr) = (yyvsp[0].operands_ptr);
		     (yyval.operands_ptr)->num_labels += 1;
		     (yyvsp[-2].operand_ptr)->next = (yyval.operands_ptr)->labels;
		     (yyval.operands_ptr)->labels = (yyvsp[-2].operand_ptr);
		 }
#line 1521 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 270 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operand_ptr) = malloc(sizeof(Operand));
		     //$$->value = (int) strtol(yylval.ival, (char**) NULL, 10);
		     (yyval.operand_ptr)->value = yylval.ival;
		     //printf(" visited reg %d %s\n",(yylval.ival),&yytext[1]);
		     (yyval.operand_ptr)->next = NULL;
		 }
#line 1533 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 280 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operand_ptr) = malloc(sizeof(Operand));
		     (yyval.operand_ptr)->value = yylval.ival;
		     //printf(" \n Const: %d \n", yylval.ival);
		     (yyval.operand_ptr)->next = NULL;
		 }
#line 1544 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 289 "iloc.y" /* yacc.c:1646  */
    {
		     (yyval.operand_ptr) = malloc(sizeof(Operand));
		     (yyval.operand_ptr)->value = insert_label(token);
		     (yyval.operand_ptr)->next = NULL;
		 }
#line 1554 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 297 "iloc.y" /* yacc.c:1646  */
    {
		   int last_char = strlen(token) - 1; /* take off ':' */
		   token[last_char] = '\0';
		   (yyval.ival) = insert_label(token);
		 }
#line 1564 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 309 "iloc.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 1570 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 310 "iloc.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 1576 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 314 "iloc.y" /* yacc.c:1646  */
    { (yyval.ival) = 0; }
#line 1582 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 321 "iloc.y" /* yacc.c:1646  */
    { (yyval.cval) = (unsigned int) token[0]; 
		     set_memory(Start,(char) (yyval.cval));
		     Start += 1; /* sizeof character in simulator */
                   }
#line 1591 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 327 "iloc.y" /* yacc.c:1646  */
    { (yyval.ival) = atoi(token); 
                      set_word(Start,(int) (yyval.ival));
		      Start += 4; /* sizeof int in simulator */
                    }
#line 1600 "iloc.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 334 "iloc.y" /* yacc.c:1646  */
    { (yyval.ival) = atoi(token);
               Start = (yyval.ival);
	     }
#line 1608 "iloc.tab.c" /* yacc.c:1646  */
    break;


#line 1612 "iloc.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 339 "iloc.y" /* yacc.c:1906  */
 /* Support Code */

/* Create a new initialized Operands structure */
Operands* new_operands()
{
    Operands* operands_ptr = malloc(sizeof(Operands));
    operands_ptr->num_regs = 0;
    operands_ptr->regs = NULL;
    operands_ptr->num_consts = 0;
    operands_ptr->consts = NULL;
    operands_ptr->num_labels = 0;
    operands_ptr->labels = NULL;
    
    return(operands_ptr);
}

/* Append the second list of operands to the end of the first */
Operand* append_operands(Operand* list1, Operand* list2)
{
    Operand* start = list1;

    if (!list1)
	return list2;
    
    while(list1->next)
	list1 = list1->next;

    list1->next = list2;

    return(start);
}

/* debugging code -- kdc */
void PrintOperands( Operand *o ) {
  if (!o)
    fprintf(stdout,"<nil>");
  else while( o ) {
      fprintf(stdout,"%d ",o->value);
      o = o->next;
    }
}
void PrintOperation( Operation *op ) {

  fprintf(stdout,"%s:\tsrcs:\t",opcode_specs[op->opcode].string);
  PrintOperands(op->srcs);
  fprintf(stdout,"\n\tconsts:\t");
  PrintOperands(op->consts);
  fprintf(stdout,"\n\tlabels:\t");
  PrintOperands(op->labels);
  fprintf(stdout,"\n\tdefs:\t");
  PrintOperands(op->defs);
  fprintf(stdout,"\n\n");
}

/* Make sure that the operation was called with the correct number and type
   of arguments */
int verify_args(Opcode* operation,int srcs, int consts, int labels, int defs)
{
    char* error_message;

    if (operation->srcs != srcs)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of source registers",
		operation->string);
	yyerror(error_message);
	free(error_message);
	return 0;
    }
    
    if (operation->consts != consts)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of constants",
		operation->string);
	yyerror(error_message);
	free(error_message);
	return 0;
    }

    if (operation->labels != labels)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of labels (%d vs %d)",
		operation->string,operation->labels,labels);
	yyerror(error_message);
	free(error_message);
	return 0;
    }

    if (operation->defs != defs)
    {
	error_message = malloc(MAX_ERROR_MESSAGE_LENGTH*sizeof(char));
	sprintf(error_message,"%s used with incorrect number of defined registers",
		operation->string);
	yyerror(error_message);
	free(error_message);
	return 0;
    }

    return 1;
}
    
	
void yyerror(char* s)
{
  // bad hack to make this friendlier for students
  // Added a check for an empty file in sim.c, but that doesn't catch the case
  // when the input comes via a pipe.
  //
  // So, find the error message.
  if (strcmp(s,"syntax error, unexpected $end") == 0) {
    // empty input file, indicates prior process in the piped command
    // produced no output; hence no input to the simulator
    fprintf(stderr,"Error: \tFile passed to the simulator is empty.\n\n");
    fprintf(stderr,"\tIn a test script, this usually indicates that the\n");
    fprintf(stderr,"\tcomponent under test terminated in an abnormal way.\n\n");
    exit(-1);
  }
  (void) fprintf(stderr, "Line %d: %s\n", line_counter, s);
  error_found = 1;
}

