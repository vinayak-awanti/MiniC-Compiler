%{

#include <stdio.h>
#include <stdlib.h>	
#include "st.h"
void yyerror(const char *error_msg);
int yylex();

void func4(char *s);
void func5();
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

FILE *ic_file;
%}
%union {
    char *str;
};

%token INCLUDE SEMI_COLON COMMA EQUAL ID OPEN_SQUARE CLOSE_SQUARE NUMCONST CHARCONST  INT BOOL CHAR OPEN_FLOWER CLOSE_FLOWER PRINTF SCANF OPEN_SIMPLE CLOSE_SIMPLE IF WHILE BREAK RETURN PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS ELSE INT_MAIN MINUS_MINUS LOGIC_OR LOGIC_AND NOT LESS_EQUAL GREAT_EQUAL LESS GREAT NOT_EQUAL EQUAL_EQUAL PLUS MINUS STAR DIV MOD TRUE FALSE

%type<str>  typeSpecifier varDeclList INT BOOL CHAR varDeclInitialize varDeclId simpleExpression ID NUMCONST CLOSE_SQUARE OPEN_SQUARE unaryExpression breakStmt expression  andExpression unaryRelExpression unaryop factor mutable immutable constant BREAK SEMI_COLON NOT relExpression  OPEN_SIMPLE  CLOSE_SIMPLE  CHARCONST TRUE FALSE sumExpression term DIV MOD STAR mulop PLUS MINUS sumop LESS_EQUAL LESS GREAT GREAT_EQUAL EQUAL_EQUAL NOT_EQUAL relop LOGIC_AND LOGIC_OR PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS MINUS_MINUS EQUAL 
%%

program : declarationList
        ;
declarationList : declarationList declaration
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
varDeclaration : typeSpecifier varDeclList SEMI_COLON {fprintf(ic_file, "%s %s \n", $1, $2);}
               ;
varDeclList : varDeclList COMMA varDeclInitialize {sprintf($$, "%s, %s", $1, $3);}
            | varDeclInitialize {sprintf($$, "%s", $1);}
            ;
varDeclInitialize : varDeclId				
                  | varDeclId EQUAL simpleExpression {
                 	if (is_number($3)) {
                 		set_value($1, $3, current_scope);
                 	}
                 	sprintf($$, "%s = %s", $1, $3);
                 }
                  ;
varDeclId : ID	{
		if(load_token($1, (strcmp($<str>0, ",") ? $<str>0 : $<str>-2), line_no, current_scope)) {
			char buf[50]; sprintf(buf, "redeclaration of %s", $1);
			yyerror(buf);
			YYABORT;
		}
	}
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE {
		char type[20] = {0};
		sprintf(type, "%s[%s]", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2), $3);
		if(load_token($1, type, line_no, current_scope)) {
			char buf[50]; sprintf(buf, "redeclaration of %s", $1);
			yyerror(buf);
			YYABORT;
		}
		sprintf($$, "%s%s%s%s", $1, $2, $3, $4);
          }
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE OPEN_SQUARE NUMCONST CLOSE_SQUARE {
  		char type[20] = {0};
  		sprintf(type, "%s[%s][%s]", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2), $3, $6);
  		if(load_token($1, type, line_no, current_scope)) {
			char buf[50]; sprintf(buf, "redeclaration of %s", $1);
			yyerror(buf);
			YYABORT;
		}
		sprintf($$, "%s%s%s%s%s%s%s", $1, $2, $3, $4, $5, $6, $7);
          }	
          | STAR ID {
		char type[20] = {0};
		sprintf(type, "%s*", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2));
		if(load_token($2, type, line_no, current_scope)) {
			char buf[50]; sprintf(buf, "redeclaration of %s", $2);
			yyerror(buf);
			YYABORT;
		}
		sprintf($$, "%s%s", $1, $2);
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
selectionStmt : IF OPEN_SIMPLE simpleExpression {func1($<str>3);} CLOSE_SIMPLE statement {func2($<str>6);} ELSE statement {func3($<str>9);}
              ;
iterationStmt : WHILE {fprintf(ic_file,"L%d:\n",label_num+1);} OPEN_SIMPLE simpleExpression {func4($<str>4);} CLOSE_SIMPLE statement {func5();} 
returnStmt : RETURN SEMI_COLON
           | RETURN expression SEMI_COLON
           ;
breakStmt : BREAK SEMI_COLON
          ;
expression : mutable EQUAL expression {
	
	fprintf(ic_file, "%s %s %s\n", $1, $2, $3);
	
	if (is_number($3)) {
		set_value($1, $3, current_scope);
	}
}
           | mutable PLUS_EQUAL expression {
	
	$$ = new_temp();
	fprintf(ic_file, "%s = %s + %s\n", $$, $1, $3);
	fprintf(ic_file, "%s = %s\n", $1, $$);
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

	$$ = new_temp();
	fprintf(ic_file, "%s = %s - %s\n", $$, $1, $3);
	fprintf(ic_file, "%s = %s\n", $1, $$);
	
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

	$$ = new_temp();
	fprintf(ic_file, "%s = %s * %s\n", $$, $1, $3);
	fprintf(ic_file, "%s = %s\n", $1, $$);
	
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
           
	$$ = new_temp();
	fprintf(ic_file, "%s = %s / %s\n", $$, $1, $3);
	fprintf(ic_file, "%s = %s\n", $1, $$);
	
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
	fprintf(ic_file, "%s = %s + 1\n", $$, $1);
	fprintf(ic_file, "%s = %s\n", $1, $$);
	
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
	fprintf(ic_file, "%s = %s - 1\n", $$, $1);
	fprintf(ic_file, "%s = %s\n", $1, $$);
	
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
simpleExpression : simpleExpression LOGIC_OR andExpression	{$$ = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$, $1, $2, $3);}
                 | andExpression
                 ;
andExpression : andExpression LOGIC_AND unaryRelExpression	{$$ = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$, $1, $2, $3);}
              | unaryRelExpression
              ;
unaryRelExpression : NOT unaryRelExpression			{$$ = new_temp(); fprintf(ic_file, "%s = %s %s\n", $$, $1, $2);}
                   | relExpression
                   ;
relExpression : sumExpression relop sumExpression	{$$ = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$, $1, $2, $3);}
              | sumExpression
              ;
relop : LESS_EQUAL
      | LESS
      | GREAT
      | GREAT_EQUAL
      | EQUAL_EQUAL
      | NOT_EQUAL
      ;
sumExpression : sumExpression sumop term	{$$ = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$, $1, $2, $3);}
              | term
              ;
sumop : PLUS
      | MINUS
      ;
term : term mulop unaryExpression			{$$ = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$, $1, $2, $3);}
     | unaryExpression
     ;
mulop : STAR
      | DIV
      | MOD
      ;
unaryExpression : unaryop unaryExpression	{$$ = new_temp(); fprintf(ic_file, "%s = %s%s\n", $$, $1, $2);}
                | factor
                ;
unaryop : MINUS
        | STAR
        ;
factor : immutable
       | mutable
       ;
mutable : ID {
	if (fetch_token($1, current_scope)) {
		printf("undeclared variable %s\n", $1);
		YYABORT;
	}
}
        | mutable OPEN_SQUARE expression CLOSE_SQUARE {
        	if (fetch_token($1, current_scope)) {
        		printf("undeclared variable %s\n", $1);
        		YYABORT;
        	}
		char *idx = new_temp();
		fprintf(ic_file, "%s = 4 * %s\n", idx, $3);
		$$ = new_temp();
		sprintf($$, "%s[%s]", $1, idx);
        }
        ;
immutable : OPEN_SIMPLE expression CLOSE_SIMPLE	{$$ = $2;}
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
	system("figlet MiniC-Compiler");
	set_parent_scope(0, -1);
	ic_file = fopen("ic", "w");
	if (!yyparse()) {
		printf("\n\nClean code after removing comments :-> \n");
		printf("**********************************************\n");
		printf("\n%s\n",code);
		printf("**********************************************\n\n\n");
		printf("Symbol Table :->\n\n");
		show_me();
		printf("successful\n");
		fclose(ic_file);
		printf("**********************************************\n\n");
		printf("Intermediate code :->\n\n");
		system("cat ic");
		system("python3 optmz.py");
		printf("**********************************************\n\n");
		printf("Constant Folded code :->\n\n");
		system("cat folding.txt");
		printf("**********************************************\n\n");
		printf("Constant propagated code :->\n\n");
		system("cat propagation.txt");
		printf("**********************************************\n\n");
		printf("Final optimized code :->\n\n");
		system("cat final.txt");
		printf("**********************************************\n\n");
		printf("successful\n");
	} else {
		fclose(ic_file);
		printf("unsuccessful\n");
	}
	
	return 0;
}

void func1( char *s ) {
	label_num++;
	char * temp = new_temp();
	fprintf(ic_file, "%s = not %s\n", temp, s);
	fprintf(ic_file, "if %s goto L%d\n", temp, label_num);
	labels[++label_top]=label_num;
}


void func2( char *s ) {
	label_num++;
	int x = labels[label_top--];
	fprintf(ic_file, "goto L%d\n",label_num);
	fprintf(ic_file, "L%d: \n",x);
	labels[++label_top] = label_num;	
}

void func3( char *s) {
	int y = labels[label_top];
	label_top--;
	fprintf(ic_file, "L%d: \n",y); 
}


int is_number(char *num) {
	return (strcmp("0", num) == 0 || atoi(num));
}

void func4(char * s) {

	char * temp = new_temp();
	fprintf(ic_file, "%s = not %s\n", temp, s);
	fprintf(ic_file, "if %s goto L%d\n", temp, label_num + 2);
	labels[++label_top] = label_num + 2;
	labels[++label_top] = label_num + 1;   
	label_num += 2;
}

void func5() {
	fprintf(ic_file,"goto L%d\n",labels[label_top]);
	label_top--;
	fprintf(ic_file, "L%d:\n",labels[label_top]);
	label_top--;
}