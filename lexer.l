%{

#include <stdio.h>
#include <string.h>
#include "y.tab.h"  
#include "st.h"
int line_no=0;
void yyerror(const char* error_msg);
%}

letter  					[a-zA-Z]
digit						[0-9]
notquote					[^\']
quote						[\']
letdig						{digit} | {letter}
id							{letter}{letdig}
numconst					{digit}+	
charconst					{quote}{notquote}{quote} 
commentBody						(.|\n)*

%%

\/\/.*						;

\/\*{commentBody}\*\/		;

"int main()"				{yylval.str = strdup(yytext); return INT_MAIN;}

"#include <stdio.h>"		{yylval.str = strdup(yytext); return INCLUDE;}

"int"						{yylval.str = strdup(yytext); return INT;}

"bool"						{yylval.str = strdup(yytext); return BOOL;}

"char"						{yylval.str = strdup(yytext); return CHAR;}

"printf"					{yylval.str = strdup(yytext); return PRINTF;}

"scanf"						{yylval.str = strdup(yytext); return SCANF;}

"if"						{yylval.str = strdup(yytext); return IF;}

"else"						{yylval.str = strdup(yytext); return ELSE;}

"while"						{yylval.str = strdup(yytext); return WHILE;}

"return"					{yylval.str = strdup(yytext); return RETURN;}

"break"						{yylval.str = strdup(yytext); return BREAK;}

"="							{yylval.str = strdup(yytext); return EQUAL;}

"+="						{yylval.str = strdup(yytext); return PLUS_EQUAL;}

"-="						{yylval.str = strdup(yytext); return MINUS_EQUAL;}

"*="						{yylval.str = strdup(yytext); return MUL_EQUAL;}

"/="						{yylval.str = strdup(yytext); return DIV_EQUAL;}

"++"						{yylval.str = strdup(yytext); return PLUS_PLUS;}

"--"						{yylval.str = strdup(yytext); return MINUS_MINUS;}

"||"						{yylval.str = strdup(yytext); return LOGIC_OR;}

"&&"						{yylval.str = strdup(yytext); return LOGIC_AND;}

"!"							{yylval.str = strdup(yytext); return NOT;}

";"							{yylval.str = strdup(yytext); return SEMI_COLON;}

","							{yylval.str = strdup(yytext); return COMMA;}

"+"							{yylval.str = strdup(yytext); return PLUS;}

"-"							{yylval.str = strdup(yytext); return MINUS;}

"<="						{yylval.str = strdup(yytext); return LESS_EQUAL;}

"<"							{yylval.str = strdup(yytext); return LESS;}

">"							{yylval.str = strdup(yytext); return GREAT;}

"["							{yylval.str = strdup(yytext); return OPEN_SQUARE;}

"]"							{yylval.str = strdup(yytext); return CLOSE_SQUARE;}

"{"							{yylval.str = strdup(yytext); return OPEN_FLOWER;}

"}"							{yylval.str = strdup(yytext); return CLOSE_FLOWER;}

"*"							{yylval.str = strdup(yytext); return STAR;}

"("							{yylval.str = strdup(yytext); return OPEN_SIMPLE;}

")"							{yylval.str = strdup(yytext); return CLOSE_SIMPLE;}

">="						{yylval.str = strdup(yytext); return GREAT_EQUAL;}

"=="						{yylval.str = strdup(yytext); return EQUAL_EQUAL;}

"!="						{yylval.str = strdup(yytext); return NOT_EQUAL;}

"/"							{yylval.str = strdup(yytext); return DIV;}

"%"							{yylval.str = strdup(yytext); return MOD;}

"true"						{yylval.str = strdup(yytext); return TRUE;}

"false"						{yylval.str = strdup(yytext); return FALSE;}

[a-zA-Z][[0-9]|[a-zA-Z]]*	{yylval.str = strdup(yytext); return ID;}

[0-9]+						{yylval.str = strdup(yytext); return NUMCONST;}

{charconst}					{yylval.str = strdup(yytext); return CHARCONST;}

[\n]						{line_no++	;}
[ \t]						;

.							{
								
								yyerror("\ninvalid character");
								return *yytext;
							}


