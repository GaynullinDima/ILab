#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

enum
{
	stack_is_empty = 83655
};

typedef struct node
{
	int data;
	struct node* next;
}list;


void push(list** stack, int value);
int pop(list** stack);
bool is_empty(list* stack);
int get_count(list* stack);
void clear(list* stack);

#endif