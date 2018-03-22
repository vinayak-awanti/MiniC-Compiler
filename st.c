#include "st.h"
int size=0;



void load_token(char *key,char *val,int line){
	int i,flag=-1;
	for(i=0;i<size;i++){
		if(strcmp(symbol_table.tokens[i].key,key)==0){
			flag=1;
			strcpy(symbol_table.tokens[i].key,key);
			strcpy(symbol_table.tokens[i].value,val);
			symbol_table.tokens[i].line=line;
			break;
		}
	}

	//printf("Here we are%s",key);
	if(flag==-1){
		strcpy(symbol_table.tokens[size].key,key);
		strcpy(symbol_table.tokens[size].value,val);
		symbol_table.tokens[size].line=line;
		//printf("Line no%d\n",symbol_table.tokens[size].line);		
		size+=1;
	}	
	//return

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
void show_me(){
	int i;
	printf("\tToken-No\tSymbol\tToken\tLine-No\n");
	for(i=0;i<size;i++){
		printf("\t  %d\t\t  %s\t  %s\t  %d\n",i+1,symbol_table.tokens[i].key,symbol_table.tokens[i].value,symbol_table.tokens[i].line);
	}
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