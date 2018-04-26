%{

#include <stdio.h>
#include "st.h"
void yyerror(const char *error_msg);
int yylex();

void func1(char *s);
void func2(char *s);
void func3(char *s);
void func4(char *s);
void func5();

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

FILE *ic_file, *ast_file;

// ast
typedef struct {
	char val[50];
	int num_child;
	int child[50];
} ast_node_t;

ast_node_t ast[500];
char ast_value[50];

int num_node = 0;
int current_node = 1;
int parent_node = 0;
int node_stack_top = 0;
int node_stack[50];

void add_child(int parent_node, int child_node, char *val);
void dfs(int cur_node);

%}

%code requires {
	typedef struct {
		char *str;
		char *addr;
	} attrib_t;
}

%union {
    char *str;
    attrib_t attrib;
};

%token INCLUDE SEMI_COLON COMMA EQUAL ID OPEN_SQUARE CLOSE_SQUARE NUMCONST CHARCONST  INT BOOL CHAR OPEN_FLOWER CLOSE_FLOWER PRINTF SCANF OPEN_SIMPLE CLOSE_SIMPLE IF WHILE BREAK RETURN PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS ELSE INT_MAIN MINUS_MINUS LOGIC_OR LOGIC_AND NOT LESS_EQUAL GREAT_EQUAL LESS GREAT NOT_EQUAL EQUAL_EQUAL PLUS MINUS STAR DIV MOD TRUE FALSE

%type<str>  typeSpecifier varDeclList INT BOOL CHAR varDeclInitialize ID NUMCONST CLOSE_SQUARE OPEN_SQUARE breakStmt unaryop factor constant BREAK SEMI_COLON NOT OPEN_SIMPLE  CLOSE_SIMPLE  CHARCONST TRUE FALSE DIV MOD STAR mulop PLUS MINUS sumop LESS_EQUAL LESS GREAT GREAT_EQUAL EQUAL_EQUAL NOT_EQUAL relop LOGIC_AND LOGIC_OR PLUS_EQUAL MINUS_EQUAL MUL_EQUAL DIV_EQUAL PLUS_PLUS MINUS_MINUS EQUAL 

%type<attrib> immutable mutable unaryExpression relExpression sumExpression term unaryRelExpression andExpression simpleExpression expression varDeclId

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
varDeclaration : {
	node_stack[node_stack_top++] = parent_node;
	current_node = ++num_node;
	parent_node = current_node;
} typeSpecifier varDeclList SEMI_COLON {
	fprintf(ic_file, "%s %s \n", $2, $3);
	current_node = parent_node;
	char decl_val[50] = {0};
	sprintf(decl_val, "decl (%d)", current_node);
	parent_node = node_stack[--node_stack_top];
	add_child(parent_node, current_node, decl_val);
}
               ;
varDeclList : varDeclList COMMA varDeclInitialize {sprintf($$, "%s, %s", $1, $3);}
            | varDeclInitialize {sprintf($$, "%s", $1);}
            ;
varDeclInitialize : varDeclId {
	$$ = $1.str;
}		
                  | varDeclId EQUAL simpleExpression {
 	if (is_number($3.str)) {
 		set_value($1.str, $3.str, current_scope);
 	}
 	sprintf($$, "%s = %s", $1.str, $3.str);
}
                  ;
varDeclId : ID {
	char type[20] = {0};
	sprintf(type, "%s", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2));
	if(load_token($1, type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", $1);
		yyerror(buf);
		YYABORT;
	}
	memset(ast_value, 0, sizeof(ast_value));
	current_node = ++num_node;
	sprintf(ast_value, "%s %s (%d)", type, $1, current_node);
	add_child(parent_node, current_node, ast_value);
}
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE {
	char type[20] = {0};
	sprintf(type, "%s[%s]", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2), $3);
	if(load_token($1, type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", $1);
		yyerror(buf);
		YYABORT;
	}
	sprintf($$.str, "%s%s%s%s", $1, $2, $3, $4);
}
          | ID OPEN_SQUARE NUMCONST CLOSE_SQUARE OPEN_SQUARE NUMCONST CLOSE_SQUARE {
	char type[20] = {0};
	sprintf(type, "%s[%s][%s]", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2), $3, $6);
	if(load_token($1, type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", $1);
		yyerror(buf);
		YYABORT;
	}
	sprintf($$.str, "%s%s%s%s%s%s%s", $1, $2, $3, $4, $5, $6, $7);
}	
          | STAR ID {
	char type[20] = {0};
	sprintf(type, "%s*", (strcmp($<str>0, ",") ? $<str>0 : $<str>-2));
	if(load_token($2, type, line_no, current_scope)) {
		char buf[50]; sprintf(buf, "redeclaration of %s", $2);
		yyerror(buf);
		YYABORT;
	}
	sprintf($$.str, "%s%s", $1, $2);
}
          ;
typeSpecifier : INT
              | BOOL
              | CHAR
              ;
statement : declStmt
          | expressionStmt	{}
          | compoundStmt
          | selectionStmt	{}
          | iterationStmt	{}
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
selectionStmt : IF OPEN_SIMPLE simpleExpression {func1($3.str);} CLOSE_SIMPLE statement {func2($<str>6);} ELSE statement {func3($<str>9);}
              ;
iterationStmt : WHILE {fprintf(ic_file, "L%d:\n",label_num+1);} OPEN_SIMPLE simpleExpression {func4($4.str);} CLOSE_SIMPLE statement {func5();} 
returnStmt : RETURN SEMI_COLON
           | RETURN expression SEMI_COLON
           ;
breakStmt : BREAK SEMI_COLON
          ;
expression : mutable EQUAL expression {
	
	fprintf(ic_file, "%s %s %s\n", $1.str, $2, $3.str);
	
	if (is_number($3.str)) {
		set_value($1.str, $3.str, current_scope);
	}
}
           | mutable PLUS_EQUAL expression {
	
	$$.str = new_temp();
	fprintf(ic_file, "%s = %s + %s\n", $$.str, $1.str, $3.str);
	fprintf(ic_file, "%s = %s\n", $1.str, $$.str);
}
           | mutable MINUS_EQUAL expression {

	$$.str = new_temp();
	fprintf(ic_file, "%s = %s - %s\n", $$.str, $1.str, $3.str);
	fprintf(ic_file, "%s = %s\n", $1.str, $$.str);
}
           | mutable MUL_EQUAL expression {

	$$.str = new_temp();
	fprintf(ic_file, "%s = %s * %s\n", $$.str, $1.str, $3.str);
	fprintf(ic_file, "%s = %s\n", $1.str, $$.str);
}
           | mutable DIV_EQUAL expression {
           
	$$.str = new_temp();
	fprintf(ic_file, "%s = %s / %s\n", $$.str, $1.str, $3.str);
	fprintf(ic_file, "%s = %s\n", $1.str, $$.str);
}
           | mutable PLUS_PLUS {
	
	$$.str = new_temp();
	fprintf(ic_file, "%s = %s + 1\n", $$.str, $1.str);
	fprintf(ic_file, "%s = %s\n", $1.str, $$.str);
} 
           | mutable MINUS_MINUS {
	$$.str = new_temp();
	fprintf(ic_file, "%s = %s - 1\n", $$.str, $1.str);
	fprintf(ic_file, "%s = %s\n", $1.str, $$.str);
}
           | simpleExpression					{$$.str = $1.str;}
           ;
simpleExpression : simpleExpression LOGIC_OR andExpression	{$$.str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$.str, $1.str, $2, $3.str);}
                 | andExpression							{$$.str = $1.str;}
                 ;
andExpression : andExpression LOGIC_AND unaryRelExpression	{$$.str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$.str, $1.str, $2, $3.str);}
              | unaryRelExpression							{$$.str = $1.str;}
              ;
unaryRelExpression : NOT unaryRelExpression			{$$.str = new_temp(); fprintf(ic_file, "%s = %s %s\n", $$.str, $1, $2.str);}
                   | relExpression					{$$.str = $1.str;}
                   ;
relExpression : sumExpression relop sumExpression	{$$.str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$.str, $1.str, $2, $3.str);}
              | sumExpression						{$$.str = $1.str;}
              ;
relop : LESS_EQUAL
      | LESS
      | GREAT
      | GREAT_EQUAL
      | EQUAL_EQUAL
      | NOT_EQUAL
      ;
sumExpression : sumExpression sumop term	{$$.str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$.str, $1.str, $2, $3.str);}
              | term						{$$.str = $1.str;}
              ;
sumop : PLUS
      | MINUS
      ;
term : term mulop unaryExpression			{$$.str = new_temp(); fprintf(ic_file, "%s = %s %s %s\n", $$.str, $1.str, $2, $3.str);}
     | unaryExpression						{$$.str = $1.str;}
     ;
mulop : STAR
      | DIV
      | MOD
      ;
unaryExpression : unaryop unaryExpression	{$$.str = new_temp(); fprintf(ic_file, "%s = %s%s\n", $$.str, $1, $2.str);}
                | factor					{$$.str = $1;}
                ;
unaryop : MINUS
        | STAR
        ;
factor : immutable		{strcpy($$, $1.str);}
       | mutable		{strcpy($$, $1.str);}
       ;
mutable : ID {
	$$.str = strdup($1);
	if (fetch_token($1, current_scope)) {
		printf("undeclared variable %s\n", $1);
		YYABORT;
	}
}
        | mutable OPEN_SQUARE expression CLOSE_SQUARE {
        
	char *idx = new_temp();
	fprintf(ic_file, "%s = 4 * %s\n", idx, $3.str);
	sprintf($$.str, "%s[%s]", $1.str, idx);
}
        ;
immutable : OPEN_SIMPLE expression CLOSE_SIMPLE	{$$.str = strdup($2.str);}
          | constant							{$$.str = strdup($1);}				
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
	ic_file = fopen("ic", "w");
	ast_file = fopen("ast.dot", "w");
	fprintf(ast_file, "digraph ast {\n");
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
	dfs(0);
	fprintf(ast_file, "}\n");
	fclose(ic_file);
	fclose(ast_file);
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

void func4(char *s){
	char * temp = new_temp();
	fprintf(ic_file, "%s = not %s\n", temp, s);
	fprintf(ic_file, "if %s goto L%d\n", temp, label_num + 2);
	labels[++label_top] = label_num + 2;
	labels[++label_top] = label_num + 1;
	label_num += 2;
}

void func5() {
	fprintf(ic_file, "goto L%d\n", labels[label_top]);
	label_top--;
	fprintf(ic_file, "L%d:\n", labels[label_top]);
	label_top--;
}

int is_number(char *num) {
	return (strcmp("0", num) == 0 || atoi(num));
}

void add_child(int parent_node, int child_node, char val[]) {
//	printf("par_nod: %d, child_nod: %d, val: %s num_child: %d\n", parent_node, child_node, val, ast[parent_node].num_child);
	strcpy(ast[child_node].val, val);
	ast[parent_node].child[ast[parent_node].num_child] = child_node;
	++ast[parent_node].num_child;
}

void dfs(int cur_node) {
//	printf("node: %d val: %s num_chlid: %d\n\n", cur_node, ast[cur_node].val, ast[cur_node].num_child);
	for (int i = 0; i < ast[cur_node].num_child; ++i) {
		fprintf(ast_file, "\t\"%s\" -> \"%s\";\n", ast[cur_node].val, ast[ast[cur_node].child[i]].val);
		dfs(ast[cur_node].child[i]);
	}
}
