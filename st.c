#include "st.h"

// returns 0 if token was successfully inserted, 1 otherwise.
int load_token(char *name, char *type, int line, int scope, int parent_scope){
	int i;
	
	// return 1 if token already exists. redeclaration.
	for(i = 0; i < symbol_table[scope].st_size; ++i){
		if(strcmp(symbol_table[scope].token[i].name, name) == 0){
			return 1;
		}
	}
	
	// if token does not exist insert it.
	
	int tmp_size = symbol_table[scope].st_size;
	strcpy(symbol_table[scope].token[tmp_size].name, name);
	strcpy(symbol_table[scope].token[tmp_size].type, type);
	symbol_table[scope].token[tmp_size].line = line;
	symbol_table[scope].parent_scope = parent_scope;
	++symbol_table[scope].st_size;
	
	return 0;
}

/*int fetch_token(char *key){*/
/*	int i, flag = -1;*/

/*	for(i = 0; i < MAX; ++i){*/
/*		if(strcmp(symbol_table.token[i].key,key)==0){*/
/*			flag = 1;*/
/*			return i;*/
/*		}*/
/*	}*/
/*	return flag;*/
/*}*/

void show_me(){
	int i, j;
	for (i = 0; i < 10; ++i) {
		printf("Scope: %d\tParent scope: %d\n", i, symbol_table[i].parent_scope);
		printf("|        Token-No |            Name |            Type |         Line-No |\n");
		printf("-------------------------------------------------------------------------\n");	
		for (j = 0; j < symbol_table[i].st_size; ++j) {
			printf("| %15d | %15s | %15s | %15d |\n", j, symbol_table[i].token[j].name, symbol_table[i].token[j].type, symbol_table[i].token[j].line);
		}
		printf("\n");
	}
}

/*int main(){*/
/*	load_token("a", "int", 1, 0);*/
/*	int rv = load_token("a", "int", 2, 0);*/
/*	printf("rv: %d", rv);*/
/*	*/
/*	show_me();*/
/*	*/
/*	return 0;*/
/*}*/
