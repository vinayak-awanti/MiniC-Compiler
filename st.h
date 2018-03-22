#ifndef ST_H
#include<stdio.h>
#include<string.h>
#define MAX 100

#define ST_H

typedef struct token{
	char key[32];
	char value[32];
	int line;
} token;

typedef struct sym_t{
	token tokens[100];
} sym_t;

sym_t symbol_table;
int fetch_token(char *);
void load_token(char *key,char *val,int line);
void show_me();
extern int line_no;
extern int size;
#endif
