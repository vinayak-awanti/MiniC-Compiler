#include "st.h"
int size=0;

sym_t symbol_table;

void load_token(char *key,char *val){
	strcpy(symbol_table.tokens[size].key,key);
	strcpy(symbol_table.tokens[size].value,val);
	size+=1;

}
int fetch_token(char *key){
	int i,flag=-1;

	for(i=0;i<MAX;i++){
		if(strcmp(symbol_table.tokens[i].key,key)==0){
			flag=1;
			return i;
		}
	}
	return flag;

}
/*
int main(){
	int index;
	//printf("Hello");
	load_token("int","keyword");
	index=fetch_token("int");
	printf("Key:%s\nValue:%s\n",symbol_table.tokens[index].key,symbol_table.tokens[index].value);
}
*/