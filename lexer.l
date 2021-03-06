%{

#include <stdio.h>
#include <string.h>
#include "y.tab.h"  
void yyerror(const char* error_msg);

%}

letter	[a-z]
digit	[0-9]
id	{letter}({letter}|{digit})*
notquote					[^\']
quote						[\']
numconst					{digit}+	
charconst					{quote}{notquote}{quote}
commentBody						(.|\n)*

%%

\/\/.*						;

\/\*{commentBody}\*\/		;

"int main()"				{return INT_MAIN;}

"#include <stdio.h>"		{return INCLUDE;}

"int"						{return INT;}

"bool"						{return BOOL;}

"char"						{return CHAR;}

"printf"					{return PRINTF;}

"scanf"						{return SCANF;}

"if"						{return IF;}

"else"						{return ELSE;}

"while"						{return WHILE;}

"return"					{return RETURN;}

"break"						{return BREAK;}

"="							{return EQUAL;}

"+="						{return PLUS_EQUAL;}

"-="						{return MINUS_EQUAL;}

"*="						{return MUL_EQUAL;}

"/="						{return DIV_EQUAL;}

"++"						{return PLUS_PLUS;}

"--"						{return MINUS_MINUS;}

"||"						{return LOGIC_OR;}

"&&"						{return LOGIC_AND;}

"!"							{return NOT;}

";"							{return SEMI_COLON;}

","							{return COMMA;}

"+"							{return PLUS;}

"-"							{return MINUS;}

"<="						{return LESS_EQUAL;}

"<"							{return LESS;}

">"							{return GREAT;}

"["							{return OPEN_SQUARE;}

"]"							{return CLOSE_SQUARE;}

"{"							{return OPEN_FLOWER;}

"}"							{return CLOSE_FLOWER;}

"*"							{return STAR;}

"("							{return OPEN_SIMPLE;}

")"							{return CLOSE_SIMPLE;}

">="						{return GREAT_EQUAL;}

"=="						{return EQUAL_EQUAL;}

"!="						{return NOT_EQUAL;}

"/"							{return DIV;}

"%"							{return MOD;}

"true"						{return TRUE;}

"false"						{return FALSE;}

{id}						{return ID;}

{numconst}					{return NUMCONST;}

{charconst}					{return CHARCONST;}

[ \n\t\r]						;

.							{
								printf("%d\n", *yytext);	
								yyerror("invalid character");
								return *yytext;
							}


