#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

typedef struct label1
{
	char name[10];
	int line_num;
}label;

typedef struct node
{
	double data;
	struct node* next;
}list;


void push(list** stack, double value);
double pop(list** stack);
bool is_empty(list* stack);
int get_count(list* stack);
void clear(list* stack);

void add(list** stack);
void sub(list** stack);
void mul(list** stack);
void divide(list** stack);
void sqr(list** stack);

void cmp(list** stack);



#endif