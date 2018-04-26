/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 51 "parser.y" /* yacc.c:1909  */

	typedef struct {
		char *str;
		char *addr;
	} attrib_t;

#line 51 "y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INCLUDE = 258,
    SEMI_COLON = 259,
    COMMA = 260,
    EQUAL = 261,
    ID = 262,
    OPEN_SQUARE = 263,
    CLOSE_SQUARE = 264,
    NUMCONST = 265,
    CHARCONST = 266,
    INT = 267,
    BOOL = 268,
    CHAR = 269,
    OPEN_FLOWER = 270,
    CLOSE_FLOWER = 271,
    PRINTF = 272,
    SCANF = 273,
    OPEN_SIMPLE = 274,
    CLOSE_SIMPLE = 275,
    IF = 276,
    WHILE = 277,
    BREAK = 278,
    RETURN = 279,
    PLUS_EQUAL = 280,
    MINUS_EQUAL = 281,
    MUL_EQUAL = 282,
    DIV_EQUAL = 283,
    PLUS_PLUS = 284,
    ELSE = 285,
    INT_MAIN = 286,
    MINUS_MINUS = 287,
    LOGIC_OR = 288,
    LOGIC_AND = 289,
    NOT = 290,
    LESS_EQUAL = 291,
    GREAT_EQUAL = 292,
    LESS = 293,
    GREAT = 294,
    NOT_EQUAL = 295,
    EQUAL_EQUAL = 296,
    PLUS = 297,
    MINUS = 298,
    STAR = 299,
    DIV = 300,
    MOD = 301,
    TRUE = 302,
    FALSE = 303
  };
#endif
/* Tokens.  */
#define INCLUDE 258
#define SEMI_COLON 259
#define COMMA 260
#define EQUAL 261
#define ID 262
#define OPEN_SQUARE 263
#define CLOSE_SQUARE 264
#define NUMCONST 265
#define CHARCONST 266
#define INT 267
#define BOOL 268
#define CHAR 269
#define OPEN_FLOWER 270
#define CLOSE_FLOWER 271
#define PRINTF 272
#define SCANF 273
#define OPEN_SIMPLE 274
#define CLOSE_SIMPLE 275
#define IF 276
#define WHILE 277
#define BREAK 278
#define RETURN 279
#define PLUS_EQUAL 280
#define MINUS_EQUAL 281
#define MUL_EQUAL 282
#define DIV_EQUAL 283
#define PLUS_PLUS 284
#define ELSE 285
#define INT_MAIN 286
#define MINUS_MINUS 287
#define LOGIC_OR 288
#define LOGIC_AND 289
#define NOT 290
#define LESS_EQUAL 291
#define GREAT_EQUAL 292
#define LESS 293
#define GREAT 294
#define NOT_EQUAL 295
#define EQUAL_EQUAL 296
#define PLUS 297
#define MINUS 298
#define STAR 299
#define DIV 300
#define MOD 301
#define TRUE 302
#define FALSE 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 58 "parser.y" /* yacc.c:1909  */

    char *str;
    attrib_t attrib;

#line 164 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
