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

#line 134 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
