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
#line 2 "./compiler.y"

    #include "compiler_common.h"
    #include "compiler_util.h"
    #include "main.h"

    int yydebug = 1;
    ObjectType coutBuffer;
    ObjectType coutObjectType[50];
    int numberOfCoutObjectType = 0;
    char address[20][20]; // IDENT address
    int addressIndex = 0;
    
    int int2float = 0;
    int atLastOperator = 0;
    int operatorType[100]; // int:1  float:2  bool:3
    SymbolData tableOfVariableType[20];
    int numberOfVariable = 0;
    int coutCheck = 0;

    typedef struct _arraytable {
        char* name;
        int size;
        int elementValue[2000];
        ObjectType type;
    } arrayTabel;
    arrayTabel arrayTabel_1[20];
    int arraySize = 0;
    int numberOfArray = 0;


#line 102 "./build/y.tab.c"

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

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_COUT = 3,                       /* COUT  */
  YYSYMBOL_SHR = 4,                        /* SHR  */
  YYSYMBOL_SHL = 5,                        /* SHL  */
  YYSYMBOL_BAN = 6,                        /* BAN  */
  YYSYMBOL_BOR = 7,                        /* BOR  */
  YYSYMBOL_BNT = 8,                        /* BNT  */
  YYSYMBOL_BXO = 9,                        /* BXO  */
  YYSYMBOL_ADD = 10,                       /* ADD  */
  YYSYMBOL_SUB = 11,                       /* SUB  */
  YYSYMBOL_MUL = 12,                       /* MUL  */
  YYSYMBOL_DIV = 13,                       /* DIV  */
  YYSYMBOL_REM = 14,                       /* REM  */
  YYSYMBOL_NOT = 15,                       /* NOT  */
  YYSYMBOL_GTR = 16,                       /* GTR  */
  YYSYMBOL_LES = 17,                       /* LES  */
  YYSYMBOL_GEQ = 18,                       /* GEQ  */
  YYSYMBOL_LEQ = 19,                       /* LEQ  */
  YYSYMBOL_EQL = 20,                       /* EQL  */
  YYSYMBOL_NEQ = 21,                       /* NEQ  */
  YYSYMBOL_LAN = 22,                       /* LAN  */
  YYSYMBOL_LOR = 23,                       /* LOR  */
  YYSYMBOL_VAL_ASSIGN = 24,                /* VAL_ASSIGN  */
  YYSYMBOL_ADD_ASSIGN = 25,                /* ADD_ASSIGN  */
  YYSYMBOL_SUB_ASSIGN = 26,                /* SUB_ASSIGN  */
  YYSYMBOL_MUL_ASSIGN = 27,                /* MUL_ASSIGN  */
  YYSYMBOL_DIV_ASSIGN = 28,                /* DIV_ASSIGN  */
  YYSYMBOL_REM_ASSIGN = 29,                /* REM_ASSIGN  */
  YYSYMBOL_BAN_ASSIGN = 30,                /* BAN_ASSIGN  */
  YYSYMBOL_BOR_ASSIGN = 31,                /* BOR_ASSIGN  */
  YYSYMBOL_BXO_ASSIGN = 32,                /* BXO_ASSIGN  */
  YYSYMBOL_SHR_ASSIGN = 33,                /* SHR_ASSIGN  */
  YYSYMBOL_SHL_ASSIGN = 34,                /* SHL_ASSIGN  */
  YYSYMBOL_INC_ASSIGN = 35,                /* INC_ASSIGN  */
  YYSYMBOL_DEC_ASSIGN = 36,                /* DEC_ASSIGN  */
  YYSYMBOL_IF = 37,                        /* IF  */
  YYSYMBOL_ELSE = 38,                      /* ELSE  */
  YYSYMBOL_FOR = 39,                       /* FOR  */
  YYSYMBOL_WHILE = 40,                     /* WHILE  */
  YYSYMBOL_RETURN = 41,                    /* RETURN  */
  YYSYMBOL_BREAK = 42,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 43,                  /* CONTINUE  */
  YYSYMBOL_VARIABLE_T = 44,                /* VARIABLE_T  */
  YYSYMBOL_IDENT = 45,                     /* IDENT  */
  YYSYMBOL_INT_LIT = 46,                   /* INT_LIT  */
  YYSYMBOL_FLOAT_LIT = 47,                 /* FLOAT_LIT  */
  YYSYMBOL_STR_LIT = 48,                   /* STR_LIT  */
  YYSYMBOL_BOOL_LIT = 49,                  /* BOOL_LIT  */
  YYSYMBOL_50_ = 50,                       /* ';'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ','  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_58_ = 58,                       /* ':'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_Program = 60,                   /* Program  */
  YYSYMBOL_61_1 = 61,                      /* $@1  */
  YYSYMBOL_GlobalStmtList = 62,            /* GlobalStmtList  */
  YYSYMBOL_GlobalStmt = 63,                /* GlobalStmt  */
  YYSYMBOL_DefineVariableStmt = 64,        /* DefineVariableStmt  */
  YYSYMBOL_FunctionDefStmt = 65,           /* FunctionDefStmt  */
  YYSYMBOL_66_2 = 66,                      /* $@2  */
  YYSYMBOL_FunctionParameterStmtList = 67, /* FunctionParameterStmtList  */
  YYSYMBOL_FunctionParameterStmt = 68,     /* FunctionParameterStmt  */
  YYSYMBOL_StmtList = 69,                  /* StmtList  */
  YYSYMBOL_Stmt = 70,                      /* Stmt  */
  YYSYMBOL_71_3 = 71,                      /* $@3  */
  YYSYMBOL_IfStmt = 72,                    /* IfStmt  */
  YYSYMBOL_73_4 = 73,                      /* $@4  */
  YYSYMBOL_74_5 = 74,                      /* $@5  */
  YYSYMBOL_ElseStmt = 75,                  /* ElseStmt  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_WhileStmt = 77,                 /* WhileStmt  */
  YYSYMBOL_78_7 = 78,                      /* $@7  */
  YYSYMBOL_79_8 = 79,                      /* $@8  */
  YYSYMBOL_ForStmt = 80,                   /* ForStmt  */
  YYSYMBOL_81_9 = 81,                      /* $@9  */
  YYSYMBOL_Forcond = 82,                   /* Forcond  */
  YYSYMBOL_ForInitial = 83,                /* ForInitial  */
  YYSYMBOL_assignment = 84,                /* assignment  */
  YYSYMBOL_85_10 = 85,                     /* $@10  */
  YYSYMBOL_mutiAssignment = 86,            /* mutiAssignment  */
  YYSYMBOL_mutiInitialize = 87,            /* mutiInitialize  */
  YYSYMBOL_88_11 = 88,                     /* $@11  */
  YYSYMBOL_89_12 = 89,                     /* $@12  */
  YYSYMBOL_mutiElement = 90,               /* mutiElement  */
  YYSYMBOL_Element = 91,                   /* Element  */
  YYSYMBOL_CoutParmListStmt = 92,          /* CoutParmListStmt  */
  YYSYMBOL_Expression = 93,                /* Expression  */
  YYSYMBOL_identTerminal = 94,             /* identTerminal  */
  YYSYMBOL_LogicalExpression = 95,         /* LogicalExpression  */
  YYSYMBOL_operator14AssignmentType = 96,  /* operator14AssignmentType  */
  YYSYMBOL_operator12 = 97,                /* operator12  */
  YYSYMBOL_operator11 = 98,                /* operator11  */
  YYSYMBOL_operator10 = 99,                /* operator10  */
  YYSYMBOL_operator9 = 100,                /* operator9  */
  YYSYMBOL_operator8 = 101,                /* operator8  */
  YYSYMBOL_operator7 = 102,                /* operator7  */
  YYSYMBOL_operator6 = 103,                /* operator6  */
  YYSYMBOL_operator5 = 104,                /* operator5  */
  YYSYMBOL_operator4 = 105,                /* operator4  */
  YYSYMBOL_operator3 = 106,                /* operator3  */
  YYSYMBOL_operator2 = 107,                /* operator2  */
  YYSYMBOL_numbers1 = 108,                 /* numbers1  */
  YYSYMBOL_CallFunction = 109,             /* CallFunction  */
  YYSYMBOL_mutiFuncPara = 110,             /* mutiFuncPara  */
  YYSYMBOL_ParaTerminal = 111,             /* ParaTerminal  */
  YYSYMBOL_Casting = 112,                  /* Casting  */
  YYSYMBOL_DataTypeTerminal = 113          /* DataTypeTerminal  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   410

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  144
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  250

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   304


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
      51,    52,     2,     2,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    58,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    87,    88,    92,    93,    97,    98,   102,
     107,   107,   110,   111,   112,   115,   134,   157,   158,   161,
     162,   162,   163,   164,   165,   166,   167,   168,   169,   173,
     173,   173,   176,   176,   177,   181,   181,   181,   184,   184,
     187,   188,   191,   192,   194,   194,   195,   198,   199,   202,
     220,   238,   238,   238,   268,   295,   296,   299,   303,   308,
     309,   310,   313,   314,   317,   321,   327,   348,   379,   414,
     415,   416,   417,   418,   419,   422,   423,   424,   425,   426,
     427,   428,   429,   430,   431,   432,   433,   434,   436,   437,
     444,   445,   448,   449,   452,   453,   456,   457,   460,   461,
     464,   465,   466,   469,   470,   471,   472,   473,   476,   478,
     481,   482,   483,   486,   487,   488,   489,   492,   493,   494,
     495,   498,   500,   501,   506,   514,   520,   521,   522,   523,
     526,   529,   530,   533,   534,   535,   541,   544,   549,   554,
     559,   566,   567,   572,   575
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
  "\"end of file\"", "error", "\"invalid token\"", "COUT", "SHR", "SHL",
  "BAN", "BOR", "BNT", "BXO", "ADD", "SUB", "MUL", "DIV", "REM", "NOT",
  "GTR", "LES", "GEQ", "LEQ", "EQL", "NEQ", "LAN", "LOR", "VAL_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "REM_ASSIGN",
  "BAN_ASSIGN", "BOR_ASSIGN", "BXO_ASSIGN", "SHR_ASSIGN", "SHL_ASSIGN",
  "INC_ASSIGN", "DEC_ASSIGN", "IF", "ELSE", "FOR", "WHILE", "RETURN",
  "BREAK", "CONTINUE", "VARIABLE_T", "IDENT", "INT_LIT", "FLOAT_LIT",
  "STR_LIT", "BOOL_LIT", "';'", "'('", "')'", "'{'", "'}'", "','", "'['",
  "']'", "':'", "$accept", "Program", "$@1", "GlobalStmtList",
  "GlobalStmt", "DefineVariableStmt", "FunctionDefStmt", "$@2",
  "FunctionParameterStmtList", "FunctionParameterStmt", "StmtList", "Stmt",
  "$@3", "IfStmt", "$@4", "$@5", "ElseStmt", "$@6", "WhileStmt", "$@7",
  "$@8", "ForStmt", "$@9", "Forcond", "ForInitial", "assignment", "$@10",
  "mutiAssignment", "mutiInitialize", "$@11", "$@12", "mutiElement",
  "Element", "CoutParmListStmt", "Expression", "identTerminal",
  "LogicalExpression", "operator14AssignmentType", "operator12",
  "operator11", "operator10", "operator9", "operator8", "operator7",
  "operator6", "operator5", "operator4", "operator3", "operator2",
  "numbers1", "CallFunction", "mutiFuncPara", "ParaTerminal", "Casting",
  "DataTypeTerminal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-183)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-128)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      11,    20,    -7,  -183,    -4,    -7,  -183,  -183,  -183,    43,
    -183,    86,    26,   296,   296,   296,   -18,  -183,  -183,     1,
    -183,   110,    70,    80,     2,   113,   116,   134,   133,   146,
      28,   128,   156,    45,    17,  -183,  -183,  -183,  -183,   119,
    -183,   361,  -183,  -183,  -183,  -183,    54,   120,   115,   121,
    -183,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   314,   296,   296,   296,   296,   296,   296,   296,
     296,   296,   296,   296,   296,   296,   296,   296,   296,   296,
     296,   126,    -8,  -183,  -183,  -183,  -183,   123,   129,   130,
     -30,  -183,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   116,   134,   133,   146,    28,
     128,   128,   156,   156,   156,   156,    45,    17,    17,  -183,
    -183,  -183,   127,   132,   119,  -183,    54,  -183,   135,  -183,
    -183,  -183,  -183,   304,  -183,  -183,   131,    24,  -183,  -183,
    -183,  -183,  -183,  -183,   138,   143,  -183,   147,  -183,  -183,
      86,  -183,  -183,  -183,    42,  -183,   194,  -183,  -183,  -183,
    -183,   360,  -183,  -183,   296,   158,   159,   169,   179,  -183,
    -183,   233,   187,   157,   189,   296,  -183,   -16,   185,  -183,
      86,     4,  -183,    67,  -183,    24,   191,   296,   199,   190,
     179,  -183,    86,  -183,   192,   296,  -183,   181,  -183,   360,
    -183,   201,   185,  -183,    24,   198,     7,  -183,   196,  -183,
     226,   157,   296,   296,   296,   296,   296,   296,    24,   195,
    -183,   202,   205,   206,   208,   209,   210,   211,   242,   227,
     224,  -183,  -183,   216,  -183,  -183,   102,   225,  -183,  -183,
    -183,  -183,     5,  -183,    24,  -183,   102,   286,  -183,  -183
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,     3,     6,     7,     8,    10,
       5,     0,     0,     0,     0,     0,    67,   123,   125,   126,
     124,     0,     0,    88,   127,    89,    91,    93,    95,    97,
      99,   102,   107,   109,   112,   116,   120,   129,   128,    14,
     126,    88,   127,   119,   117,   118,   136,     0,     0,   127,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,   133,   134,   135,     0,   132,     0,
       0,   121,    75,    76,    77,    78,    79,    80,    83,    84,
      85,    81,    82,    86,    87,    90,    92,    94,    96,    98,
     100,   101,   103,   104,   105,   106,   108,   110,   111,   113,
     114,   115,    15,     0,     0,   130,   136,    68,    67,   141,
     143,   144,   142,     0,   138,   140,     0,    20,    12,   131,
     123,   125,   126,   124,   127,     0,    16,     0,    38,    35,
       0,    27,    44,    19,    20,    18,     0,    24,    25,    26,
      23,    46,   137,   139,     0,     0,     0,     0,     0,    11,
      17,     0,   127,    43,     0,     0,    22,    50,    45,    48,
       0,     0,    29,     0,    42,    20,   127,     0,     0,     0,
       0,    63,     0,    21,     0,     0,    41,    20,    36,    49,
      54,     0,    47,    62,    20,     0,   120,    39,     0,    52,
      20,     0,     0,     0,     0,     0,     0,     0,    20,     0,
      30,     0,   120,   120,   120,   120,   120,   120,    20,     0,
      34,    40,    37,     0,    32,    31,    61,     0,    57,    59,
      60,    58,     0,    56,    20,    53,    61,    20,    55,    33
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,   259,  -183,  -183,  -183,  -183,   161,
    -182,  -152,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -168,  -183,   105,  -183,  -183,
    -183,  -183,    52,  -183,  -146,   -10,  -183,   -11,   347,   235,
     237,   234,   236,   238,    29,   106,   230,    47,    49,    -1,
    -183,   182,  -183,  -183,   176
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     5,     6,     7,     8,    12,    82,    83,
     154,   155,   156,   157,   194,   230,   235,   237,   158,   166,
     208,   159,   165,   174,   183,   160,   168,   178,   179,   189,
     219,   242,   243,   181,    22,    41,   205,    42,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    87,    88,    38,   135
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    23,   170,   197,   167,   184,   -64,   -66,   187,   192,
      49,    -4,    43,    44,    45,   128,   129,   130,   131,   132,
       3,   133,   210,   212,   213,   214,   215,   216,   217,    78,
      79,    80,    13,    46,   191,    14,   228,     4,    47,    15,
     -51,     9,   188,   221,   123,   170,   203,   124,    69,    70,
      13,   -64,   -66,    14,   193,    76,    77,    15,   170,   245,
     246,   147,   247,   148,   149,   150,   151,    11,   152,    16,
      17,    18,    40,    20,   153,    21,   170,    39,   -28,   147,
     134,   148,   149,   150,   151,   -65,   152,    16,    17,    18,
      40,    20,   153,    21,    13,   170,   169,    14,   110,   111,
      84,    15,    85,    86,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   195,    13,   196,
      50,    14,   144,   117,   118,    15,   161,   119,   120,   121,
     -65,    16,    17,    18,    19,    20,    64,    21,    65,    24,
      23,    66,    67,   161,    71,    72,    73,    74,   238,   239,
     240,   241,    68,   172,    48,    16,    17,    18,    40,    20,
      75,    21,   161,    81,   186,    13,    89,    90,    14,    24,
      23,   122,    15,    91,   161,   125,   199,   112,   113,   114,
     115,    24,    23,   136,   126,   137,   161,   127,   146,    13,
     162,    47,    14,   161,   206,   163,    15,   171,   164,   161,
     161,   152,    16,    17,    18,    40,    20,   161,    21,   173,
     175,   222,   223,   224,   225,   226,   227,   161,   147,   176,
     148,   149,   150,   151,   177,   152,    16,    17,    18,    40,
      20,   153,    21,   161,    13,   207,   161,    14,   180,   182,
     190,    15,   185,   198,   200,   204,   201,   209,   211,   218,
      13,   233,   229,    14,   231,   -71,   -72,    15,   -73,   -74,
     -69,   -70,   234,   147,    10,   148,   149,   150,   151,   236,
     152,    16,    17,    18,    40,    20,   153,    21,   244,   147,
     220,   148,   149,   150,   151,   138,   152,    16,    17,    18,
      40,    20,   153,    21,    13,   202,   232,    14,   248,   105,
     107,    15,   106,   108,    13,   116,   109,    14,   139,   145,
       0,    15,    13,     0,     0,    14,     0,     0,     0,    15,
       0,     0,    13,   147,     0,   148,   149,   150,   151,    15,
     152,    16,    17,    18,    40,    20,   153,    21,     0,     0,
     249,    16,    17,    18,    40,    20,     0,    21,     0,    16,
     140,   141,   142,   143,     0,    21,     0,     0,     0,    16,
      17,    18,    40,    20,  -127,    21,  -127,  -127,     0,  -127,
    -127,     0,  -127,  -127,  -127,     0,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,     0,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104
};

static const yytype_int16 yycheck[] =
{
      11,    11,   154,   185,   150,   173,     5,     5,    24,     5,
      21,     0,    13,    14,    15,    45,    46,    47,    48,    49,
       0,    51,   204,    16,    17,    18,    19,    20,    21,    12,
      13,    14,     8,    51,   180,    11,   218,    44,    56,    15,
      56,    45,    58,   211,    52,   197,   192,    55,    20,    21,
       8,    50,    50,    11,    50,    10,    11,    15,   210,    54,
      55,    37,   244,    39,    40,    41,    42,    24,    44,    45,
      46,    47,    48,    49,    50,    51,   228,    51,    54,    37,
      90,    39,    40,    41,    42,     5,    44,    45,    46,    47,
      48,    49,    50,    51,     8,   247,    54,    11,    69,    70,
      46,    15,    48,    49,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    50,     8,    52,
      50,    11,   133,    76,    77,    15,   137,    78,    79,    80,
      50,    45,    46,    47,    48,    49,    23,    51,    22,   150,
     150,     7,     9,   154,    16,    17,    18,    19,    46,    47,
      48,    49,     6,   164,    44,    45,    46,    47,    48,    49,
       4,    51,   173,    44,   175,     8,    46,    52,    11,   180,
     180,    45,    15,    52,   185,    52,   187,    71,    72,    73,
      74,   192,   192,    56,    55,    53,   197,    57,    57,     8,
      52,    56,    11,   204,   195,    52,    15,     3,    51,   210,
     211,    44,    45,    46,    47,    48,    49,   218,    51,    51,
      51,   212,   213,   214,   215,   216,   217,   228,    37,    50,
      39,    40,    41,    42,    45,    44,    45,    46,    47,    48,
      49,    50,    51,   244,     8,    54,   247,    11,     5,    52,
      55,    15,    53,    52,    45,    53,    56,    46,    50,    53,
       8,    24,    57,    11,    52,    50,    50,    15,    50,    50,
      50,    50,    38,    37,     5,    39,    40,    41,    42,    53,
      44,    45,    46,    47,    48,    49,    50,    51,    53,    37,
      54,    39,    40,    41,    42,   124,    44,    45,    46,    47,
      48,    49,    50,    51,     8,   190,    54,    11,   246,    64,
      66,    15,    65,    67,     8,    75,    68,    11,   126,   133,
      -1,    15,     8,    -1,    -1,    11,    -1,    -1,    -1,    15,
      -1,    -1,     8,    37,    -1,    39,    40,    41,    42,    15,
      44,    45,    46,    47,    48,    49,    50,    51,    -1,    -1,
      54,    45,    46,    47,    48,    49,    -1,    51,    -1,    45,
      46,    47,    48,    49,    -1,    51,    -1,    -1,    -1,    45,
      46,    47,    48,    49,     4,    51,     6,     7,    -1,     9,
      10,    -1,    12,    13,    14,    -1,    16,    17,    18,    19,
      20,    21,    22,    23,    -1,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    60,    61,     0,    44,    62,    63,    64,    65,    45,
      63,    24,    66,     8,    11,    15,    45,    46,    47,    48,
      49,    51,    93,    94,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   112,    51,
      48,    94,    96,   108,   108,   108,    51,    56,    44,    96,
      50,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    23,    22,     7,     9,     6,    20,
      21,    16,    17,    18,    19,     4,    10,    11,    12,    13,
      14,    44,    67,    68,    46,    48,    49,   110,   111,    46,
      52,    52,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    98,    99,   100,   101,   102,
     103,   103,   104,   104,   104,   104,   105,   106,   106,   107,
     107,   107,    45,    52,    55,    52,    55,    57,    45,    46,
      47,    48,    49,    51,    94,   113,    56,    53,    68,   110,
      46,    47,    48,    49,    96,   113,    57,    37,    39,    40,
      41,    42,    44,    50,    69,    70,    71,    72,    77,    80,
      84,    96,    52,    52,    51,    81,    78,    93,    85,    54,
      70,     3,    96,    51,    82,    51,    50,    45,    86,    87,
       5,    92,    52,    83,    84,    53,    96,    24,    58,    88,
      55,    93,     5,    50,    73,    50,    52,    69,    52,    96,
      45,    56,    86,    93,    53,    95,   108,    54,    79,    46,
      69,    50,    16,    17,    18,    19,    20,    21,    53,    89,
      54,    84,   108,   108,   108,   108,   108,   108,    69,    57,
      74,    52,    54,    24,    38,    75,    53,    76,    46,    47,
      48,    49,    90,    91,    53,    54,    55,    69,    91,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    59,    61,    60,    60,    62,    62,    63,    63,    64,
      66,    65,    67,    67,    67,    68,    68,    69,    69,    70,
      71,    70,    70,    70,    70,    70,    70,    70,    70,    73,
      74,    72,    76,    75,    75,    78,    79,    77,    81,    80,
      82,    82,    83,    83,    85,    84,    84,    86,    86,    87,
      87,    88,    89,    87,    87,    90,    90,    91,    91,    91,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   102,   103,   103,   103,   103,   103,   104,   104,
     105,   105,   105,   106,   106,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   108,   108,   108,   108,   108,   108,
     109,   110,   110,   111,   111,   111,   111,   112,   112,   112,
     112,   113,   113,   113,   113
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     2,     0,     2,     1,     1,     1,     5,
       0,     9,     3,     1,     0,     2,     4,     2,     1,     1,
       0,     4,     3,     1,     1,     1,     1,     1,     0,     0,
       0,    10,     0,     5,     0,     0,     0,     9,     0,     6,
       7,     3,     1,     0,     0,     3,     1,     3,     1,     3,
       1,     0,     0,    10,     3,     3,     1,     1,     1,     1,
       1,     0,     3,     2,     1,     1,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     1,
       3,     3,     1,     3,     3,     3,     1,     2,     2,     2,
       1,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     3,     1,     1,     1,     1,     0,     6,     4,     6,
       4,     1,     1,     1,     1
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
  case 2: /* $@1: %empty  */
#line 87 "./compiler.y"
      { pushScope(); }
#line 1417 "./build/y.tab.c"
    break;

  case 3: /* Program: $@1 GlobalStmtList  */
#line 87 "./compiler.y"
                                      { dumpScope(); }
#line 1423 "./build/y.tab.c"
    break;

  case 10: /* $@2: %empty  */
#line 107 "./compiler.y"
                       { createFunction((yyvsp[-1].var_type), (yyvsp[0].s_var)); }
#line 1429 "./build/y.tab.c"
    break;

  case 11: /* FunctionDefStmt: VARIABLE_T IDENT $@2 '(' FunctionParameterStmtList ')' '{' StmtList '}'  */
#line 107 "./compiler.y"
                                                                                                                       { dumpScope(); }
#line 1435 "./build/y.tab.c"
    break;

  case 15: /* FunctionParameterStmt: VARIABLE_T IDENT  */
#line 115 "./compiler.y"
                       {    pushFunParm((yyvsp[-1].var_type), (yyvsp[0].s_var), VAR_FLAG_DEFAULT);
                            tableOfVariableType[numberOfVariable].type = (yyvsp[-1].var_type);
                            tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen((yyvsp[0].s_var)) + 1);
                            strcpy(tableOfVariableType[numberOfVariable].name, (yyvsp[0].s_var));
                            numberOfVariable++;
                            tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;

                            // check address table, if this IDENT in the table find it and print 
                            for (int i = 0; i < 20; i++){
                                if (strcmp(address[i], (yyvsp[0].s_var)) == 0){
                                    break;
                                }
                                if (i == 19){
                                    // if this IDENT NOT in the table print it and add in to table 
                                    strcpy(address[addressIndex], (yyvsp[0].s_var));
                                    addressIndex++;
                                }
                            }
                       }
#line 1459 "./build/y.tab.c"
    break;

  case 16: /* FunctionParameterStmt: VARIABLE_T IDENT '[' ']'  */
#line 134 "./compiler.y"
                               {    pushFunParm((yyvsp[-3].var_type), (yyvsp[-2].s_var), VAR_FLAG_DEFAULT);
                                    tableOfVariableType[numberOfVariable].type = (yyvsp[-3].var_type);
                                    tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen((yyvsp[-2].s_var)) + 1);
                                    strcpy(tableOfVariableType[numberOfVariable].name, (yyvsp[-2].s_var));
                                    numberOfVariable++;
                                    tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;

                                    // check address table, if this IDENT in the table find it and print
                                    for (int i = 0; i < 20; i++){
                                        if (strcmp(address[i], (yyvsp[-2].s_var)) == 0){
                                            break;
                                        }
                                        if (i == 19){
                                            // if this IDENT NOT in the table print it and add in to table 
                                            strcpy(address[addressIndex], (yyvsp[-2].s_var));
                                            addressIndex++;
                                        }
                                    }
                               }
#line 1483 "./build/y.tab.c"
    break;

  case 20: /* $@3: %empty  */
#line 162 "./compiler.y"
      { coutCheck = 1; }
#line 1489 "./build/y.tab.c"
    break;

  case 21: /* Stmt: $@3 COUT CoutParmListStmt ';'  */
#line 162 "./compiler.y"
                                                   { coutCheck = 0; stdoutPrint(); int2float = 0; numberOfCoutObjectType = 0; }
#line 1495 "./build/y.tab.c"
    break;

  case 22: /* Stmt: RETURN Expression ';'  */
#line 163 "./compiler.y"
                            { printf("RETURN\n"); }
#line 1501 "./build/y.tab.c"
    break;

  case 27: /* Stmt: BREAK  */
#line 168 "./compiler.y"
            { printf("BREAK\n"); }
#line 1507 "./build/y.tab.c"
    break;

  case 29: /* $@4: %empty  */
#line 173 "./compiler.y"
                                          { printf("IF\n"); pushScope(); }
#line 1513 "./build/y.tab.c"
    break;

  case 30: /* $@5: %empty  */
#line 173 "./compiler.y"
                                                                                            { dumpScope();}
#line 1519 "./build/y.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 176 "./compiler.y"
           { printf("ELSE\n"); pushScope(); }
#line 1525 "./build/y.tab.c"
    break;

  case 33: /* ElseStmt: ELSE $@6 '{' StmtList '}'  */
#line 176 "./compiler.y"
                                                               { dumpScope(); }
#line 1531 "./build/y.tab.c"
    break;

  case 35: /* $@7: %empty  */
#line 181 "./compiler.y"
            { printf("WHILE\n"); }
#line 1537 "./build/y.tab.c"
    break;

  case 36: /* $@8: %empty  */
#line 181 "./compiler.y"
                                                                    { pushScope(); }
#line 1543 "./build/y.tab.c"
    break;

  case 37: /* WhileStmt: WHILE $@7 '(' operator14AssignmentType ')' $@8 '{' StmtList '}'  */
#line 181 "./compiler.y"
                                                                                                      { dumpScope();}
#line 1549 "./build/y.tab.c"
    break;

  case 38: /* $@9: %empty  */
#line 184 "./compiler.y"
          { printf("FOR\n"); pushScope(); }
#line 1555 "./build/y.tab.c"
    break;

  case 39: /* ForStmt: FOR $@9 Forcond '{' StmtList '}'  */
#line 184 "./compiler.y"
                                                                     { dumpScope(); }
#line 1561 "./build/y.tab.c"
    break;

  case 44: /* $@10: %empty  */
#line 194 "./compiler.y"
                 { tableOfVariableType[numberOfVariable].type = (yyvsp[0].var_type); }
#line 1567 "./build/y.tab.c"
    break;

  case 49: /* mutiInitialize: IDENT VAL_ASSIGN operator14AssignmentType  */
#line 202 "./compiler.y"
                                                {   pushFunParm(tableOfVariableType[numberOfVariable].type, (yyvsp[-2].s_var), VAR_FLAG_DEFAULT);
                                                    tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen((yyvsp[-2].s_var)) + 1);
                                                    strcpy(tableOfVariableType[numberOfVariable].name, (yyvsp[-2].s_var));
                                                    numberOfVariable++;
                                                    tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;

                                                    /* check address table, if this IDENT in the table find it and print */
                                                    for (int i = 0; i < 20; i++){
                                                        if (strcmp(address[i], (yyvsp[-2].s_var)) == 0){
                                                            break;
                                                        }
                                                        if (i == 19){
                                                            /* if this IDENT NOT in the table print it and add in to table */
                                                            strcpy(address[addressIndex], (yyvsp[-2].s_var));
                                                            addressIndex++;
                                                        }
                                                    }
                                                }
#line 1590 "./build/y.tab.c"
    break;

  case 50: /* mutiInitialize: IDENT  */
#line 220 "./compiler.y"
            {   pushFunParm(tableOfVariableType[numberOfVariable].type, (yyvsp[0].s_var), VAR_FLAG_DEFAULT);
                tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen((yyvsp[0].s_var)) + 1);
                strcpy(tableOfVariableType[numberOfVariable].name, (yyvsp[0].s_var));
                numberOfVariable++;
                tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                
                // check address table, if this IDENT in the table find it and print
                for (int i = 0; i < 20; i++){
                    if (strcmp(address[i], (yyvsp[0].s_var)) == 0){
                        break;
                    }
                    if (i == 19){
                        // if this IDENT NOT in the table print it and add in to table
                        strcpy(address[addressIndex], (yyvsp[0].s_var));
                        addressIndex++;
                    }
                }
            }
#line 1613 "./build/y.tab.c"
    break;

  case 51: /* $@11: %empty  */
#line 238 "./compiler.y"
            { arrayTabel_1[numberOfArray].name = (yyvsp[0].s_var); }
#line 1619 "./build/y.tab.c"
    break;

  case 52: /* $@12: %empty  */
#line 238 "./compiler.y"
                                                                          { printf("INT_LIT %d\n", (yyvsp[0].i_var)); arrayTabel_1[numberOfArray].size = (yyvsp[0].i_var); }
#line 1625 "./build/y.tab.c"
    break;

  case 53: /* mutiInitialize: IDENT $@11 '[' INT_LIT $@12 ']' VAL_ASSIGN '{' mutiElement '}'  */
#line 239 "./compiler.y"
                                        {   if ( arraySize ){
                                                printf("create array: %d\n", arraySize);
                                            }else{
                                                printf("create array: %d\n", 0);
                                            }
                                            arrayTabel_1[numberOfArray].type = tableOfVariableType[numberOfVariable].type;
                                            pushFunParm(arrayTabel_1[numberOfArray].type, arrayTabel_1[numberOfArray].name, VAR_FLAG_DEFAULT);
                                            // vvvvvvvvvvvvvvvvv   array also variable   vvvvvvvvvvvvvvvvv
                                            tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen((yyvsp[-9].s_var)) + 1);
                                            strcpy(tableOfVariableType[numberOfVariable].name, (yyvsp[-9].s_var));
                                            numberOfVariable++;
                                            tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                                            // check address table, if this IDENT in the table find it and print
                                            for (int i = 0; i < 20; i++){
                                                        if (strcmp(address[i], (yyvsp[-9].s_var)) == 0){
                                                            break;
                                                        }
                                                        if (i == 19){
                                                            // if this IDENT NOT in the table print it and add in to table
                                                            strcpy(address[addressIndex], (yyvsp[-9].s_var));
                                                            addressIndex++;
                                                        }
                                                    }
                                            // ^^^^^^^^^^^^^^^^^   array also variable   ^^^^^^^^^^^^^^^^^
                                            numberOfArray++;
                                            arraySize = 0;
                                            
                                            tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                                        }
#line 1659 "./build/y.tab.c"
    break;

  case 54: /* mutiInitialize: IDENT ':' IDENT  */
#line 268 "./compiler.y"
                      { if(tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                            for (int i = 0; i <= numberOfVariable; i++){
                                if (strcmp(tableOfVariableType[i].name, (yyvsp[0].s_var)) == 0){
                                    tableOfVariableType[numberOfVariable].type = tableOfVariableType[i].type;
                                    break;
                                }
                            }
                        }
                        pushFunParm(tableOfVariableType[numberOfVariable].type, (yyvsp[-2].s_var), VAR_FLAG_DEFAULT);
                        tableOfVariableType[numberOfVariable].name = (char*) malloc (strlen((yyvsp[-2].s_var)) + 1);
                        strcpy(tableOfVariableType[numberOfVariable].name, (yyvsp[-2].s_var));
                        numberOfVariable++;
                        tableOfVariableType[numberOfVariable].type = tableOfVariableType[numberOfVariable - 1].type;
                        
                        // check address table, if this IDENT in the table find it and print
                        for (int i = 0; i < 20; i++){
                            if (strcmp(address[i], (yyvsp[0].s_var)) == 0){
                                printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_var), i);
                            }else if (i == 19){
                                // if this IDENT NOT in the table print it and add in to table
                                strcpy(address[addressIndex], (yyvsp[-2].s_var));
                                addressIndex++;
                            }
                        }
                      }
#line 1689 "./build/y.tab.c"
    break;

  case 57: /* Element: INT_LIT  */
#line 299 "./compiler.y"
                { printf("INT_LIT %d\n", (yyvsp[0].i_var));
                  arrayTabel_1[numberOfArray].elementValue[arraySize] = (yyvsp[0].i_var);
                  arraySize++;
                }
#line 1698 "./build/y.tab.c"
    break;

  case 58: /* Element: BOOL_LIT  */
#line 303 "./compiler.y"
                { if ((yyvsp[0].b_var) == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ((yyvsp[0].b_var) == 0)
                    printf("BOOL_LIT FALSE\n");
                }
#line 1708 "./build/y.tab.c"
    break;

  case 59: /* Element: FLOAT_LIT  */
#line 308 "./compiler.y"
                { printf("FLOAT_LIT %.6f\n", (yyvsp[0].f_var)); }
#line 1714 "./build/y.tab.c"
    break;

  case 60: /* Element: STR_LIT  */
#line 309 "./compiler.y"
                { printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); }
#line 1720 "./build/y.tab.c"
    break;

  case 62: /* CoutParmListStmt: CoutParmListStmt SHL Expression  */
#line 313 "./compiler.y"
                                      { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1726 "./build/y.tab.c"
    break;

  case 63: /* CoutParmListStmt: SHL Expression  */
#line 314 "./compiler.y"
                     { pushFunInParm(&(yyvsp[0].object_val)); }
#line 1732 "./build/y.tab.c"
    break;

  case 64: /* Expression: STR_LIT  */
#line 317 "./compiler.y"
              { printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var));
                coutObjectType[numberOfCoutObjectType] = OBJECT_TYPE_STR;
                numberOfCoutObjectType++;
              }
#line 1741 "./build/y.tab.c"
    break;

  case 65: /* Expression: identTerminal  */
#line 321 "./compiler.y"
                    {   if(coutBuffer){
                            coutObjectType[numberOfCoutObjectType] = coutBuffer;
                            numberOfCoutObjectType++;
                            coutBuffer = 0;
                        }
                    }
#line 1752 "./build/y.tab.c"
    break;

  case 66: /* Expression: operator14AssignmentType  */
#line 327 "./compiler.y"
                               { if (coutCheck){
                                    if (operatorType[atLastOperator - 1] == 1){
                                        if (int2float){
                                            coutBuffer = OBJECT_TYPE_FLOAT;
                                        } else{
                                            coutBuffer = OBJECT_TYPE_INT;
                                        }
                                    }else if (operatorType[atLastOperator - 1] == 3){
                                        coutBuffer = OBJECT_TYPE_BOOL;
                                    }
                                    if(coutBuffer){
                                        coutObjectType[numberOfCoutObjectType] = coutBuffer;
                                        numberOfCoutObjectType++;
                                        coutBuffer = 0;
                                    }
                                 }
                                }
#line 1774 "./build/y.tab.c"
    break;

  case 67: /* identTerminal: IDENT  */
#line 348 "./compiler.y"
              { if (coutCheck){
                    for (int i = 0; i < numberOfVariable; i++){
                        if (strcmp("endl", (yyvsp[0].s_var)) == 0){
                            coutObjectType[numberOfCoutObjectType] = OBJECT_TYPE_STR;
                            numberOfCoutObjectType++;
                            break;
                        }
                        if (strcmp((yyvsp[0].s_var), tableOfVariableType[i].name) == 0){
                            coutBuffer = tableOfVariableType[i].type;
                            //numberOfCoutObjectType++;
                            break;
                        }
                    }
                }
                // check address table, if this IDENT in the table find it and print
                for (int i = 0; i < 20; i++){
                    if (strcmp("endl", (yyvsp[0].s_var)) == 0){
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_var), -1);
                        break;
                    }
                    if (strcmp(address[i], (yyvsp[0].s_var)) == 0){
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_var), i);
                        break;
                    }else if (i == 19){
                        // if this IDENT NOT in the table print it and add in to table
                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[0].s_var), addressIndex);
                        strcpy(address[addressIndex], (yyvsp[0].s_var));
                        addressIndex++;
                    }
                }
              }
#line 1810 "./build/y.tab.c"
    break;

  case 68: /* identTerminal: IDENT '[' INT_LIT ']'  */
#line 379 "./compiler.y"
                            {   for (int i = 0; i < numberOfArray; i++){
                                    if (strcmp(arrayTabel_1[i].name, (yyvsp[-3].s_var)) == 0){
                                        if (arrayTabel_1[i].type == OBJECT_TYPE_INT){
                                            printf("INT_LIT %d\n",(yyvsp[-1].i_var));
                                            for (int j = 0; j <= 20; j++ ){
                                                if (strcmp((yyvsp[-3].s_var), address[i]) == 0){
                                                    printf("IDENT (name=%s, address=%d)\n", (yyvsp[-3].s_var), j );
                                                }
                                            }
                                            if (coutCheck){
                                                coutBuffer = OBJECT_TYPE_INT;
                                                //numberOfCoutObjectType++;
                                            }
                                        }
                                        break;
                                    }
                                }
                                for (int i = 1; i < 20; i++){
                                    if (strcmp("endl", (yyvsp[-3].s_var)) == 0){
                                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-3].s_var), -1);
                                        break;
                                    }
                                    if (strcmp(address[i], (yyvsp[-3].s_var)) == 0){
                                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-3].s_var), i);
                                        break;
                                    }else if (i == 19){
                                        // if this IDENT NOT in the table print it and add in to table
                                        printf("IDENT (name=%s, address=%d)\n", (yyvsp[-3].s_var), addressIndex);
                                        strcpy(address[addressIndex], (yyvsp[-3].s_var));
                                        addressIndex++;
                                    }
                                }
                            }
#line 1848 "./build/y.tab.c"
    break;

  case 69: /* LogicalExpression: numbers1 EQL numbers1  */
#line 414 "./compiler.y"
                            { printf("EQL\n"); }
#line 1854 "./build/y.tab.c"
    break;

  case 70: /* LogicalExpression: numbers1 NEQ numbers1  */
#line 415 "./compiler.y"
                            { printf("NEQ\n"); }
#line 1860 "./build/y.tab.c"
    break;

  case 71: /* LogicalExpression: numbers1 GTR numbers1  */
#line 416 "./compiler.y"
                            { printf("GTR\n"); }
#line 1866 "./build/y.tab.c"
    break;

  case 72: /* LogicalExpression: numbers1 LES numbers1  */
#line 417 "./compiler.y"
                            { printf("LES\n"); }
#line 1872 "./build/y.tab.c"
    break;

  case 73: /* LogicalExpression: numbers1 GEQ numbers1  */
#line 418 "./compiler.y"
                            { printf("GEQ\n"); }
#line 1878 "./build/y.tab.c"
    break;

  case 74: /* LogicalExpression: numbers1 LEQ numbers1  */
#line 419 "./compiler.y"
                            { printf("LEQ\n"); }
#line 1884 "./build/y.tab.c"
    break;

  case 75: /* operator14AssignmentType: identTerminal VAL_ASSIGN operator12  */
#line 422 "./compiler.y"
                                          { printf("EQL_ASSIGN\n"); }
#line 1890 "./build/y.tab.c"
    break;

  case 76: /* operator14AssignmentType: identTerminal ADD_ASSIGN operator12  */
#line 423 "./compiler.y"
                                          { printf("ADD_ASSIGN\n"); }
#line 1896 "./build/y.tab.c"
    break;

  case 77: /* operator14AssignmentType: identTerminal SUB_ASSIGN operator12  */
#line 424 "./compiler.y"
                                          { printf("SUB_ASSIGN\n"); }
#line 1902 "./build/y.tab.c"
    break;

  case 78: /* operator14AssignmentType: identTerminal MUL_ASSIGN operator12  */
#line 425 "./compiler.y"
                                          { printf("MUL_ASSIGN\n"); }
#line 1908 "./build/y.tab.c"
    break;

  case 79: /* operator14AssignmentType: identTerminal DIV_ASSIGN operator12  */
#line 426 "./compiler.y"
                                          { printf("DIV_ASSIGN\n"); }
#line 1914 "./build/y.tab.c"
    break;

  case 80: /* operator14AssignmentType: identTerminal REM_ASSIGN operator12  */
#line 427 "./compiler.y"
                                          { printf("REM_ASSIGN\n"); }
#line 1920 "./build/y.tab.c"
    break;

  case 81: /* operator14AssignmentType: identTerminal SHR_ASSIGN operator12  */
#line 428 "./compiler.y"
                                          { printf("SHR_ASSIGN\n"); }
#line 1926 "./build/y.tab.c"
    break;

  case 82: /* operator14AssignmentType: identTerminal SHL_ASSIGN operator12  */
#line 429 "./compiler.y"
                                          { printf("SHL_ASSIGN\n"); }
#line 1932 "./build/y.tab.c"
    break;

  case 83: /* operator14AssignmentType: identTerminal BAN_ASSIGN operator12  */
#line 430 "./compiler.y"
                                          { printf("BAN_ASSIGN\n"); }
#line 1938 "./build/y.tab.c"
    break;

  case 84: /* operator14AssignmentType: identTerminal BOR_ASSIGN operator12  */
#line 431 "./compiler.y"
                                          { printf("BOR_ASSIGN\n"); }
#line 1944 "./build/y.tab.c"
    break;

  case 85: /* operator14AssignmentType: identTerminal BXO_ASSIGN operator12  */
#line 432 "./compiler.y"
                                          { printf("BXO_ASSIGN\n"); }
#line 1950 "./build/y.tab.c"
    break;

  case 86: /* operator14AssignmentType: identTerminal INC_ASSIGN operator12  */
#line 433 "./compiler.y"
                                          { printf("INC_ASSIGN\n"); }
#line 1956 "./build/y.tab.c"
    break;

  case 87: /* operator14AssignmentType: identTerminal DEC_ASSIGN operator12  */
#line 434 "./compiler.y"
                                          { printf("DEC_ASSIGN\n"); }
#line 1962 "./build/y.tab.c"
    break;

  case 90: /* operator12: operator12 LOR operator11  */
#line 444 "./compiler.y"
                                { printf("LOR\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 1968 "./build/y.tab.c"
    break;

  case 92: /* operator11: operator11 LAN operator10  */
#line 448 "./compiler.y"
                                { printf("LAN\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 1974 "./build/y.tab.c"
    break;

  case 94: /* operator10: operator10 BOR operator9  */
#line 452 "./compiler.y"
                               { printf("BOR\n"); }
#line 1980 "./build/y.tab.c"
    break;

  case 96: /* operator9: operator9 BXO operator8  */
#line 456 "./compiler.y"
                              { printf("BXO\n"); }
#line 1986 "./build/y.tab.c"
    break;

  case 98: /* operator8: operator8 BAN operator7  */
#line 460 "./compiler.y"
                              { printf("BAN\n"); }
#line 1992 "./build/y.tab.c"
    break;

  case 100: /* operator7: operator7 EQL operator6  */
#line 464 "./compiler.y"
                              { printf("EQL\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 1998 "./build/y.tab.c"
    break;

  case 101: /* operator7: operator7 NEQ operator6  */
#line 465 "./compiler.y"
                              { printf("NEQ\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 2004 "./build/y.tab.c"
    break;

  case 103: /* operator6: operator6 GTR operator5  */
#line 469 "./compiler.y"
                              { printf("GTR\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 2010 "./build/y.tab.c"
    break;

  case 104: /* operator6: operator6 LES operator5  */
#line 470 "./compiler.y"
                              { printf("LES\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 2016 "./build/y.tab.c"
    break;

  case 105: /* operator6: operator6 GEQ operator5  */
#line 471 "./compiler.y"
                              { printf("GEQ\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 2022 "./build/y.tab.c"
    break;

  case 106: /* operator6: operator6 LEQ operator5  */
#line 472 "./compiler.y"
                              { printf("LEQ\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 2028 "./build/y.tab.c"
    break;

  case 108: /* operator5: operator5 SHR operator4  */
#line 476 "./compiler.y"
                              { printf("SHR\n"); }
#line 2034 "./build/y.tab.c"
    break;

  case 110: /* operator4: operator4 ADD operator3  */
#line 481 "./compiler.y"
                              { printf("ADD\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
#line 2040 "./build/y.tab.c"
    break;

  case 111: /* operator4: operator4 SUB operator3  */
#line 482 "./compiler.y"
                              { printf("SUB\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
#line 2046 "./build/y.tab.c"
    break;

  case 113: /* operator3: operator3 MUL operator2  */
#line 486 "./compiler.y"
                              { printf("MUL\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
#line 2052 "./build/y.tab.c"
    break;

  case 114: /* operator3: operator3 DIV operator2  */
#line 487 "./compiler.y"
                              { printf("DIV\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
#line 2058 "./build/y.tab.c"
    break;

  case 115: /* operator3: operator3 REM operator2  */
#line 488 "./compiler.y"
                              { printf("REM\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
#line 2064 "./build/y.tab.c"
    break;

  case 117: /* operator2: SUB numbers1  */
#line 492 "./compiler.y"
                   { printf("NEG\n"); operatorType[atLastOperator] = 1; atLastOperator++;}
#line 2070 "./build/y.tab.c"
    break;

  case 118: /* operator2: NOT numbers1  */
#line 493 "./compiler.y"
                   { printf("NOT\n"); operatorType[atLastOperator] = 3; atLastOperator++;}
#line 2076 "./build/y.tab.c"
    break;

  case 119: /* operator2: BNT numbers1  */
#line 494 "./compiler.y"
                   { printf("BNT\n"); }
#line 2082 "./build/y.tab.c"
    break;

  case 122: /* numbers1: identTerminal INC_ASSIGN  */
#line 500 "./compiler.y"
                               { printf("INC_ASSIGN\n"); }
#line 2088 "./build/y.tab.c"
    break;

  case 123: /* numbers1: INT_LIT  */
#line 501 "./compiler.y"
                { printf("INT_LIT %d\n", (yyvsp[0].i_var));
                  if (tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                    tableOfVariableType[numberOfVariable].type = OBJECT_TYPE_INT;
                  }
                }
#line 2098 "./build/y.tab.c"
    break;

  case 124: /* numbers1: BOOL_LIT  */
#line 506 "./compiler.y"
                { if ((yyvsp[0].b_var) == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ((yyvsp[0].b_var) == 0)
                    printf("BOOL_LIT FALSE\n");
                  if (tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                    tableOfVariableType[numberOfVariable].type = OBJECT_TYPE_BOOL;
                  }
                }
#line 2111 "./build/y.tab.c"
    break;

  case 125: /* numbers1: FLOAT_LIT  */
#line 514 "./compiler.y"
                { printf("FLOAT_LIT %.6f\n", (yyvsp[0].f_var));
                  int2float = 1;
                  if (tableOfVariableType[numberOfVariable].type == OBJECT_TYPE_AUTO){
                    tableOfVariableType[numberOfVariable].type = OBJECT_TYPE_FLOAT;
                  }
                }
#line 2122 "./build/y.tab.c"
    break;

  case 126: /* numbers1: STR_LIT  */
#line 520 "./compiler.y"
                { printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); }
#line 2128 "./build/y.tab.c"
    break;

  case 130: /* CallFunction: IDENT '(' mutiFuncPara ')'  */
#line 526 "./compiler.y"
                                 { printf("IDENT (name=%s, address=%d)\ncall: %s(IILjava/lang/String;B)B\n", (yyvsp[-3].s_var), -1, (yyvsp[-3].s_var)); }
#line 2134 "./build/y.tab.c"
    break;

  case 133: /* ParaTerminal: INT_LIT  */
#line 533 "./compiler.y"
               { printf("INT_LIT %d\n", (yyvsp[0].i_var)); }
#line 2140 "./build/y.tab.c"
    break;

  case 134: /* ParaTerminal: STR_LIT  */
#line 534 "./compiler.y"
               { printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); }
#line 2146 "./build/y.tab.c"
    break;

  case 135: /* ParaTerminal: BOOL_LIT  */
#line 535 "./compiler.y"
               { if ((yyvsp[0].b_var) == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ((yyvsp[0].b_var) == 0)
                    printf("BOOL_LIT FALSE\n");
               }
#line 2156 "./build/y.tab.c"
    break;

  case 137: /* Casting: '(' VARIABLE_T ')' '(' operator14AssignmentType ')'  */
#line 544 "./compiler.y"
                                                          { if ((yyvsp[-4].var_type) == OBJECT_TYPE_INT)
                                                                printf("Cast to int\n");
                                                            if ((yyvsp[-4].var_type) == OBJECT_TYPE_FLOAT)
                                                                printf("Cast to float\n");
                                                          }
#line 2166 "./build/y.tab.c"
    break;

  case 138: /* Casting: '(' VARIABLE_T ')' identTerminal  */
#line 549 "./compiler.y"
                                       {if ((yyvsp[-2].var_type) == OBJECT_TYPE_INT)
                                            printf("Cast to int\n");
                                        if ((yyvsp[-2].var_type) == OBJECT_TYPE_FLOAT)
                                            printf("Cast to float\n");
                                       }
#line 2176 "./build/y.tab.c"
    break;

  case 139: /* Casting: '(' VARIABLE_T ')' '(' DataTypeTerminal ')'  */
#line 554 "./compiler.y"
                                                  { if ((yyvsp[-4].var_type) == OBJECT_TYPE_INT)
                                                        printf("Cast to int\n");
                                                    if ((yyvsp[-4].var_type) == OBJECT_TYPE_FLOAT)
                                                        printf("Cast to float\n");
                                                  }
#line 2186 "./build/y.tab.c"
    break;

  case 140: /* Casting: '(' VARIABLE_T ')' DataTypeTerminal  */
#line 559 "./compiler.y"
                                          { if ((yyvsp[-2].var_type) == OBJECT_TYPE_INT)
                                                printf("Cast to int\n");
                                            if ((yyvsp[-2].var_type) == OBJECT_TYPE_FLOAT)
                                                printf("Cast to float\n");
                                          }
#line 2196 "./build/y.tab.c"
    break;

  case 141: /* DataTypeTerminal: INT_LIT  */
#line 566 "./compiler.y"
                { printf("INT_LIT %d\n", (yyvsp[0].i_var));}
#line 2202 "./build/y.tab.c"
    break;

  case 142: /* DataTypeTerminal: BOOL_LIT  */
#line 567 "./compiler.y"
                { if ((yyvsp[0].b_var) == 1)
                    printf("BOOL_LIT TRUE\n");
                  if ((yyvsp[0].b_var) == 0)
                    printf("BOOL_LIT FALSE\n");
                }
#line 2212 "./build/y.tab.c"
    break;

  case 143: /* DataTypeTerminal: FLOAT_LIT  */
#line 572 "./compiler.y"
                { printf("FLOAT_LIT %.6f\n", (yyvsp[0].f_var));
                  int2float = 1;
                }
#line 2220 "./build/y.tab.c"
    break;

  case 144: /* DataTypeTerminal: STR_LIT  */
#line 575 "./compiler.y"
                { printf("STR_LIT \"%s\"\n", (yyvsp[0].s_var)); }
#line 2226 "./build/y.tab.c"
    break;


#line 2230 "./build/y.tab.c"

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

#line 578 "./compiler.y"

/* C code section */
