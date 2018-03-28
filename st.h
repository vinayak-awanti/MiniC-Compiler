#ifndef ST_H
#include<stdio.h>
#include<string.h>
#define MAX 100

#define ST_H

typedef union {
	int num;
	char str[32];
	float fl;
}value_t;


typedef struct token {
	char name[32];      //key   -> name
	char type[32];      //value -> type
	value_t value;      //like 10
	int size;	        //size
} token;

typedef struct sym_t {
	token tokens[100];
	int parent_idx;
} sym_t;



int fetch_token(char *);
void load_token(char *key,char *val);

#endif