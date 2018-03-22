#ifndef ST_H
#include<stdio.h>
#include<string.h>
#define MAX 100

#define ST_H

typedef struct token{
	char key[32];
	char value[32];
} token;

typedef struct sym_t{
	token tokens[100];
} sym_t;
int fetch_token(char *);
void load_token(char *key,char *val);

#endif