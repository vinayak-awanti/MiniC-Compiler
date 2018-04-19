%{

#include <stdio.h>
#include "st.h"
void yyerror(const char *error_msg);
int yylex();

void func4();
void func1(char *s);
void func2(char *s);
void func3(char *s);
int labels[20];
int label_num = 0;
int label_top = 0;

int num_scope = 0;
int current_scope = 0;
int parent_scope = -1;
int scope_stack_top = 1;
int scope_stack[50];

static int temp_nb;
char* new_temp();
int is_number(char *num);

%}
%union {
    char *str;
};

%token INCLUDE SEMI_COLON COMMA EQUAL ID OPEN_SQUARE CLOSE_SQUARE NUMCONST CHARCONST  INT BOOL CHAR OPEN_FLOWER CLOSE_FLOWER PRINTF SCANF OPEN_SIMPLE CLOSE_SIMPLE IF WHILE BREAK RETURN PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS ELSE INT_MAIN MINUS_MINUS LOGIC_OR LOGIC_AND NOT LESS_EQUAL GREAT_EQUAL LESS GREAT NOT_EQUAL EQUAL_EQUAL PLUS MINUS STAR DIV MOD TRUE FALSE

%type<str>  typeSpecifier varDeclList INT BOOL CHAR varDeclInitialize varDeclId simpleExpression ID NUMCONST CLOSE_SQUARE OPEN_SQUARE unaryExpression breakStmt expression  andExpression unaryRelExpression unaryop factor mutable immutable constant BREAK SEMI_COLON NOT relExpression  OPEN_SIMPLE  CLOSE_SIMPLE  CHARCONST TRUE FALSE sumExpression term DIV MOD STAR mulop PLUS MINUS sumop LESS_EQUAL LESS GREAT GREAT_EQUAL EQUAL_EQUAL NOT_EQUAL relop LOGIC_AND LOGIC_OR PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS MINUS_MINUS EQUAL 
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
                ;
varDeclaration : typeSpecifier {printf("%s ", $1);} varDeclList SEMI_COLON {printf("\n");}
               ;
varDeclList : varDeclList COMMA {printf(", ");} varDeclInitialize {}
            | varDeclInitialize
            ;
varDeclInitialize : varDeclId				
                  | varDeclId EQUAL simpleExpression {
                 	printf(" = %s", $3);
                 	if (is_number($3)) {
                 		set_value($1, $3, current_scope);
                 	}
                 }
                  ;
varDeclId : ID	{
			printf("%s", $1);
			if(load_token($1, (strcmp($<str>-1, ",") ? $<str>-1 : $<str>-4), line_no, current_scope)) {
				char buf[50]; sprintf(buf, "redeclaration of %s", $1);
				yyerror(buf);
				YYABORT;
			}
		}
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE {
          	printf("%s%s%s%s", $1, $2, $3, $4);
			char type[20] = {0};
			sprintf(type, "%s[%s]", (strcmp($<str>-1, ",") ? $<str>-1 : $<str>-4), $3);
			if(load_token($1, type, line_no, current_scope)) {
				char buf[50]; sprintf(buf, "redeclaration of %s", $1);
				yyerror(buf);
				YYABORT;
			}
          	}
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE OPEN_SQUARE NUMCONST CLOSE_SQUARE {
          		printf("%s%s%s%s%s%s%s", $1, $2, $3, $4, $5, $6, $7);
          		char type[20] = {0};
          		sprintf(type, "%s[%s][%s]", (strcmp($<str>-1, ",") ? $<str>-1 : $<str>-4), $3, $6);
          		if(load_token($1, type, line_no, current_scope)) {
				char buf[50]; sprintf(buf, "redeclaration of %s", $1);
				yyerror(buf);
				YYABORT;
			}
          	}	
          | STAR ID {
       		printf("%s%s", $1, $2);
			char type[20] = {0};
			sprintf(type, "%s*", (strcmp($<str>-1, ",") ? $<str>-1 : $<str>-4));
			if(load_token($2, type, line_no, current_scope)) {
				char buf[50]; sprintf(buf, "redeclaration of %s", $2);
				yyerror(buf);
				YYABORT;
			}         	
          }
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
compoundStmt : OPEN_FLOWER {
			parent_scope = scope_stack[scope_stack_top - 1];
			scope_stack[scope_stack_top++] = ++num_scope;
			current_scope = num_scope;
			set_parent_scope(current_scope, parent_scope);
		} statementList CLOSE_FLOWER {
			current_scope = parent_scope;
			--scope_stack_top;
		}
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
selectionStmt : IF OPEN_SIMPLE simpleExpression {$<str>3=new_temp();func1($<str>3);} CLOSE_SIMPLE statement {func2($<str>6);} ELSE statement {func3($<str>9);}
              ;
iterationStmt : WHILE {printf("L%d:\n",label_num);label_num+=1;} OPEN_SIMPLE simpleExpression {func1($<str>4);} CLOSE_SIMPLE statement {func4();func3($<str>6);} 
returnStmt : RETURN SEMI_COLON
           | RETURN expression SEMI_COLON
           ;
breakStmt : BREAK SEMI_COLON
          ;
expression : mutable EQUAL expression {
	
	printf("%s %s %s\n", $1, $2, $3);
	
	if (is_number($3)) {
		set_value($1, $3, current_scope);
	}
}
           | mutable PLUS_EQUAL expression {
	
	printf("%s %s %s\n", $1, $2, $3);
	if (is_number($3)) {
		char *value = get_value($1, current_scope);
		if (value == NULL) {
			printf("variable %s unitialized\n", $1);
			YYABORT;
		}
		char *res = malloc(20);
		sprintf(res, "%d", atoi(value) + atoi($3));
		set_value($1, res, current_scope);
		free(res);
	}
}
           | mutable MINUS_EQUAL expression {

	printf("%s %s %s\n", $1, $2, $3);
	
	if (is_number($3)) {
		char *value = get_value($1, current_scope);
		if (value == NULL) {
			printf("variable %s unitialized\n", $1);
			YYABORT;
		}
		char *res = malloc(20);
		sprintf(res, "%d", atoi(value) - atoi($3));
		set_value($1, res, current_scope);
		free(res);
	}
}
           | mutable MUL_EQUAL expression {

	printf("%s %s %s\n", $1, $2, $3);
	
	if (is_number($3)) {
		char *value = get_value($1, current_scope);
		if (value == NULL) {
			printf("variable %s unitialized\n", $1);
			YYABORT;
		}
		char *res = malloc(20);
		sprintf(res, "%d", atoi(value) * atoi($3));
		set_value($1, res, current_scope);
		free(res);
	}
}
           | mutable DIV_EQUAL expression {
           
	printf("%s %s %s\n", $1, $2, $3);
	
	if (is_number($3)) {
		if (atoi($3) == 0) {
			printf("division by zero\n");
			YYABORT;
		}
		char *value = get_value($1, current_scope);
		if (value == NULL) {
			printf("variable %s unitialized\n", $1);
			YYABORT;
		}
		char *res = malloc(20);
		sprintf(res, "%d", atoi(value) / atoi($3));
		set_value($1, res, current_scope);
		free(res);
	}
}
           | mutable PLUS_PLUS {
	
	$$ = new_temp();
	printf("%s = %s + 1\n", $$, $1);
	printf("%s = %s\n", $1, $$);
	
	char *value = get_value($1, current_scope);
	if (value == NULL) {
		printf("variable %s unitialized\n", $1);
		YYABORT;
	}
	char *res = malloc(20);
	sprintf(res, "%d", atoi(value) + 1);
	set_value($1, res, current_scope);
	free(res);
} 
           | mutable MINUS_MINUS {
	$$ = new_temp();
	printf("%s = %s - 1\n", $$, $1);
	printf("%s = %s\n", $1, $$);
	
	char *value = get_value($1, current_scope);
	if (value == NULL) {
		printf("variable %s unitialized\n", $1);
		YYABORT;
	}
	char *res = malloc(20);
	sprintf(res, "%d", atoi(value) - 1);
	set_value($1, res, current_scope);
	free(res);
}
           | simpleExpression					{}
           ;
simpleExpression : simpleExpression LOGIC_OR andExpression	{$$ = new_temp(); printf("%s = %s %s %s\n", $$, $1, $2, $3);}
                 | andExpression
                 ;
andExpression : andExpression LOGIC_AND unaryRelExpression	{$$ = new_temp(); printf("%s = %s %s %s\n", $$, $1, $2, $3);}
              | unaryRelExpression
              ;
unaryRelExpression : NOT unaryRelExpression			{$$ = new_temp(); printf("%s = %s %s\n", $$, $1, $2);}
                   | relExpression
                   ;
relExpression : sumExpression relop sumExpression	{$$ = new_temp(); printf("%s = %s %s %s\n", $$, $1, $2, $3);}
              | sumExpression
              ;
relop : LESS_EQUAL
      | LESS
      | GREAT
      | GREAT_EQUAL
      | EQUAL_EQUAL
      | NOT_EQUAL
      ;
sumExpression : sumExpression sumop term	{$$ = new_temp(); printf("%s = %s %s %s\n", $$, $1, $2, $3);}
              | term
              ;
sumop : PLUS
      | MINUS
      ;
term : term mulop unaryExpression			{$$ = new_temp(); printf("%s = %s %s %s\n", $$, $1, $2, $3);}
     | unaryExpression
     ;
mulop : STAR
      | DIV
      | MOD
      ;
unaryExpression : unaryop unaryExpression	{$$ = new_temp(); printf("%s = %s%s\n", $$, $1, $2);}
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
char* new_temp() {
	char* tmp = malloc(10);
	tmp[0] = 't';
	sprintf(tmp + 1, "%d", temp_nb);
	++temp_nb;
	strcat(tmp, "\0");
	return tmp;
}

void yyerror(const char *error_msg) {
	printf("error_msg: %s\n", error_msg);
}

int main() {
	set_parent_scope(0, -1);
	if (!yyparse()) {
		printf("\n\nClean code after removing comments :-> \n");
		printf("**********************************************\n");
		printf("\n%s\n",code);
		printf("**********************************************\n\n\n");
		printf("Symbol Table :->\n\n");
		show_me();
		printf("successful\n");
	} else {
		printf("unsuccessful\n");
	}
	return 0;
}

void func1( char *s ) {
	label_num++;
	char * temp = new_temp();
	printf("%s = not %s\n", temp, s);
	printf("if %s goto L%d\n", temp, label_num);
	labels[++label_top]=label_num;
}


void func2( char *s ) {
	label_num++;
	int x = labels[label_top--];
	printf("goto L%d\n",label_num);
	printf("L%d : \n",x);
	labels[++label_top] = label_num;	
}

void func3( char *s) {
	int y = labels[label_top--];
	printf("L%d: \n",y); 
}

void func4(){
	int y=labels[label_top-1];
	printf("goto L%d\n",y);
}

int is_number(char *num) {
	return (strcmp("0", num) == 0 || atoi(num));
}
