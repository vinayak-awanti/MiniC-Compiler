#ifndef ST_H
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

#define ST_H

typedef struct token {
	char name[32];
	char type[32];
	char value[32];
	int line;
} token_t;

typedef struct sym_t {
	int parent_scope;
	int st_size;
	token_t token[100];
} sym_t;

sym_t symbol_table[30];

int fetch_token(char*, int);
int load_token(char*, char*, int, int);
int set_value(char*, char*, int);
char *get_value(char*, int);
void set_parent_scope(int, int);
void show_me();
extern char code[1024];
extern int line_no;
extern int size;
#endif
