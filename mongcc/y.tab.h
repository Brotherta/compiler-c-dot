/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
    ID = 258,
    CONST = 259,
    EXTERN = 260,
    INT = 261,
    VOID = 262,
    FOR = 263,
    WHILE = 264,
    IF = 265,
    ELSE = 266,
    SWITCH = 267,
    CASE = 268,
    DEFAULT = 269,
    BREAK = 270,
    RETURN = 271,
    RSHIFT = 272,
    LSHIFT = 273,
    AND = 274,
    OR = 275,
    LEQ = 276,
    GEQ = 277,
    GT = 278,
    LT = 279,
    EQ = 280,
    NEQ = 281,
    AFFECT = 282,
    NOT = 283,
    DEB_BLOCK = 284,
    FIN_BLOCK = 285,
    PV = 286,
    COM = 287,
    OTHER = 288,
    DP = 289,
    VIRG = 290,
    DIV = 291,
    MOINS = 292,
    MUL = 293,
    PLUS = 294,
    LCRT = 295,
    RCRT = 296,
    LPRT = 297,
    RPRT = 298,
    OP = 299,
    REL = 300
  };
#endif
/* Tokens.  */
#define ID 258
#define CONST 259
#define EXTERN 260
#define INT 261
#define VOID 262
#define FOR 263
#define WHILE 264
#define IF 265
#define ELSE 266
#define SWITCH 267
#define CASE 268
#define DEFAULT 269
#define BREAK 270
#define RETURN 271
#define RSHIFT 272
#define LSHIFT 273
#define AND 274
#define OR 275
#define LEQ 276
#define GEQ 277
#define GT 278
#define LT 279
#define EQ 280
#define NEQ 281
#define AFFECT 282
#define NOT 283
#define DEB_BLOCK 284
#define FIN_BLOCK 285
#define PV 286
#define COM 287
#define OTHER 288
#define DP 289
#define VIRG 290
#define DIV 291
#define MOINS 292
#define MUL 293
#define PLUS 294
#define LCRT 295
#define RCRT 296
#define LPRT 297
#define RPRT 298
#define OP 299
#define REL 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 22 "mongcc.y"

	char* name;
	int entier;

#line 152 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
