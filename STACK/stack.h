#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>

enum
{
	stack_is_empty;
};

typedef struct list
{
	int data;
	struct list* next;
}


void push( list* stack, int value );
int pop(list* stack);
bool is_empty(list* stack);
int get_count(list* stack);
void clear(list* stack);

#endif