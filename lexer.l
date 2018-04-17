%{

#include <stdio.h>
#include <string.h>
#include "y.tab.h"  
#include "st.h"
int line_no=0;
char code[1024];
void yyerror(const char* error_msg);
%}

letter  					[a-zA-Z]
digit						[0-9]
notquote					[^\']
quote						[\']
numconst					{digit}+	
charconst					{quote}{notquote}{quote} 
commentBody					(.|\n)*

%%

\/\/.*						;

\/\*{commentBody}\*\/				;

"int main()"					{yylval.str = strdup(yytext);strcat(code,yytext); return INT_MAIN;}

"#include <stdio.h>"				{yylval.str = strdup(yytext);strcat(code,yytext); return INCLUDE;}

"int"						{yylval.str = strdup(yytext);strcat(code,yytext); return INT;}

"bool"						{yylval.str = strdup(yytext);strcat(code,yytext); return BOOL;}

"char"						{yylval.str = strdup(yytext);strcat(code,yytext); return CHAR;}

"printf"					{yylval.str = strdup(yytext);strcat(code,yytext); return PRINTF;}

"scanf"						{yylval.str = strdup(yytext);strcat(code,yytext); return SCANF;}

"if"						{yylval.str = strdup(yytext);strcat(code,yytext); return IF;}

"else"						{yylval.str = strdup(yytext);strcat(code,yytext); return ELSE;}

"while"						{yylval.str = strdup(yytext);strcat(code,yytext); return WHILE;}

"return"					{yylval.str = strdup(yytext);strcat(code,yytext); return RETURN;}

"break"						{yylval.str = strdup(yytext);strcat(code,yytext); return BREAK;}

"="						{yylval.str = strdup(yytext);strcat(code,yytext); return EQUAL;}

"+="						{yylval.str = strdup(yytext);strcat(code,yytext); return PLUS_EQUAL;}

"-="						{yylval.str = strdup(yytext);strcat(code,yytext); return MINUS_EQUAL;}

"*="						{yylval.str = strdup(yytext);strcat(code,yytext); return MUL_EQUAL;}

"/="						{yylval.str = strdup(yytext);strcat(code,yytext); return DIV_EQUAL;}

"++"						{yylval.str = strdup(yytext);strcat(code,yytext); return PLUS_PLUS;}

"--"						{yylval.str = strdup(yytext);strcat(code,yytext); return MINUS_MINUS;}

"||"						{yylval.str = strdup(yytext);strcat(code,yytext); return LOGIC_OR;}

"&&"						{yylval.str = strdup(yytext);strcat(code,yytext); return LOGIC_AND;}

"!"						{yylval.str = strdup(yytext);strcat(code,yytext); return NOT;}

";"						{yylval.str = strdup(yytext);strcat(code,yytext); return SEMI_COLON;}

","						{yylval.str = strdup(yytext);strcat(code,yytext); return COMMA;}

"+"						{yylval.str = strdup(yytext);strcat(code,yytext); return PLUS;}

"-"						{yylval.str = strdup(yytext);strcat(code,yytext); return MINUS;}

"<="						{yylval.str = strdup(yytext);strcat(code,yytext); return LESS_EQUAL;}

"<"						{yylval.str = strdup(yytext);strcat(code,yytext); return LESS;}

">"						{yylval.str = strdup(yytext);strcat(code,yytext); return GREAT;}

"["						{yylval.str = strdup(yytext);strcat(code,yytext); return OPEN_SQUARE;}

"]"						{yylval.str = strdup(yytext);strcat(code,yytext); return CLOSE_SQUARE;}

"{"						{yylval.str = strdup(yytext);strcat(code,yytext); return OPEN_FLOWER;}

"}"						{yylval.str = strdup(yytext);strcat(code,yytext); return CLOSE_FLOWER;}

"*"						{yylval.str = strdup(yytext);strcat(code,yytext); return STAR;}

"("						{yylval.str = strdup(yytext);strcat(code,yytext); return OPEN_SIMPLE;}

")"						{yylval.str = strdup(yytext);strcat(code,yytext); return CLOSE_SIMPLE;}

">="						{yylval.str = strdup(yytext);strcat(code,yytext); return GREAT_EQUAL;}

"=="						{yylval.str = strdup(yytext);strcat(code,yytext); return EQUAL_EQUAL;}

"!="						{yylval.str = strdup(yytext);strcat(code,yytext); return NOT_EQUAL;}

"/"						{yylval.str = strdup(yytext);strcat(code,yytext); return DIV;}

"%"						{yylval.str = strdup(yytext);strcat(code,yytext); return MOD;}

"true"						{yylval.str = strdup(yytext);strcat(code,yytext); return TRUE;}

"false"						{yylval.str = strdup(yytext);strcat(code,yytext); return FALSE;}

{letter}({letter}|{digit})*			{yylval.str = strdup(yytext);strcat(code,yytext); return ID;}

[0-9]+						{yylval.str = strdup(yytext);strcat(code,yytext); return NUMCONST;}

{charconst}					{yylval.str = strdup(yytext);strcat(code,yytext); return CHARCONST;}

[\n]						{line_no++;strcat(code,yytext);}

[ \t]						{strcat(code,yytext);};

.						{yyerror("\ninvalid character"); return *yytext;}


