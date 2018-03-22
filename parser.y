%{

#include <stdio.h>
#include "st.h"
void yyerror(const char *error_msg);
int yylex();

%}
%union {
    char *str;
};

%token INCLUDE SEMI_COLON COMMA EQUAL ID OPEN_SQUARE CLOSE_SQUARE NUMCONST CHARCONST  INT BOOL CHAR OPEN_FLOWER CLOSE_FLOWER PRINTF SCANF OPEN_SIMPLE CLOSE_SIMPLE IF WHILE BREAK RETURN PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS ELSE INT_MAIN MINUS_MINUS LOGIC_OR LOGIC_AND NOT LESS_EQUAL GREAT_EQUAL LESS GREAT NOT_EQUAL EQUAL_EQUAL PLUS MINUS STAR DIV MOD TRUE FALSE 

%type<str>  typeSpecifier varDeclList INT BOOL CHAR varDeclInitialize varDeclId simpleExpression ID  NUMCONST CLOSE_SQUARE OPEN_SQUARE  STAR unaryExpression breakStmt expression  andExpression unaryRelExpression unaryop factor mutable immutable constant BREAK SEMI_COLON NOT MINUS relExpression  OPEN_SIMPLE  CLOSE_SIMPLE  CHARCONST TRUE FALSE sumExpression term
%%

program : declarationList
        ;
declarationList : declarationList declarationList
                | declaration
                ;
declaration : varDeclaration
            | mainDeclaration
            | headerDeclaration
            ;
headerDeclaration : INCLUDE
                  ;
mainDeclaration : INT_MAIN statement
                  {
                   // printf("Once here");
                  }
                ;
varDeclaration : typeSpecifier varDeclList SEMI_COLON
                {
                //printf("%d",line_no);
               // printf("%s",$3);
                int index;
                load_token($2,$1,line_no);
                //printf("Key:%s\nValue:%s\n",symbol_table.tokens[index].key,symbol_table.tokens[index].value);
                }
               ;
varDeclList : varDeclList COMMA varDeclInitialize
            | varDeclInitialize
            
            ;
varDeclInitialize : varDeclId
                  | varDeclId EQUAL simpleExpression

                  ;
varDeclId : ID
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE OPEN_SQUARE NUMCONST CLOSE_SQUARE
          | STAR ID
          ;
typeSpecifier : INT
              | BOOL
              | CHAR
              
              ;
statement : declStmt
          | expressionStmt
          | compoundStmt
          | selectionStmt
          | iterationStmt
          | returnStmt
          | breakStmt
          | printfStmt
          | scanfStmt
          ;
compoundStmt : OPEN_FLOWER statementList CLOSE_FLOWER
             ;
statementList : statementList statement
              |
              ;
declStmt : varDeclaration
         ;
printfStmt : PRINTF OPEN_SIMPLE args CLOSE_SIMPLE SEMI_COLON
           ;
scanfStmt : SCANF OPEN_SIMPLE args CLOSE_SIMPLE SEMI_COLON
          ;
args : argList
     |
     ;
argList : argList COMMA expression
        | expression
        ;
expressionStmt : expression SEMI_COLON
               | SEMI_COLON
               ;
selectionStmt : IF OPEN_SIMPLE simpleExpression CLOSE_SIMPLE
              | IF OPEN_SIMPLE simpleExpression CLOSE_SIMPLE ELSE statement
              ;
iterationStmt : WHILE OPEN_SIMPLE simpleExpression CLOSE_SIMPLE statement
returnStmt : RETURN SEMI_COLON
           | RETURN expression SEMI_COLON
           ;
breakStmt : BREAK SEMI_COLON
          ;
expression : mutable EQUAL expression
           | mutable PLUS_EQUAL expression
           | mutable MINUS_EQUAL expression
           | mutable MUL_EQUAL expression
           | mutable DIV_EQUAL expression
           | mutable PLUS_PLUS
           | mutable MINUS_MINUS
           | simpleExpression
           ;
simpleExpression : simpleExpression LOGIC_OR andExpression
                 | andExpression
                 ;
andExpression : andExpression LOGIC_AND unaryRelExpression
              | unaryRelExpression
              ;
unaryRelExpression : NOT unaryRelExpression
                   | relExpression
                   ;
relExpression : sumExpression relop sumExpression
              | sumExpression
              ;
relop : LESS_EQUAL
      | LESS
      | GREAT
      | GREAT_EQUAL
      | EQUAL_EQUAL
      | NOT_EQUAL
      ;
sumExpression : sumExpression sumop term
              | term
              ;
sumop : PLUS
      | MINUS
      ;
term : term mulop unaryExpression
     | unaryExpression
     ;
mulop : STAR
      | DIV
      | MOD
      ;
unaryExpression : unaryop unaryExpression
                | factor
                ;
unaryop : MINUS
        | STAR
        ;
factor : immutable
       | mutable
       ;
mutable : ID
        | mutable OPEN_SQUARE expression CLOSE_SQUARE
        | mutable OPEN_SQUARE expression CLOSE_SQUARE OPEN_SQUARE expression CLOSE_SQUARE
        ;
immutable : OPEN_SIMPLE expression CLOSE_SIMPLE
          | constant
          ;
constant : NUMCONST
         | CHARCONST
         | TRUE
         | FALSE
         ;
%%
void yyerror(const char *error_msg) {
	printf("error_msg: %s\n", error_msg);
}

int main() {
	if (!yyparse()) {
    show_me();
		printf("successful\n");
	} else {
		printf("unsuccessful\n");
	}
	return 0;
}

