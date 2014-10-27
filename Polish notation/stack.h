#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifndef STACK_H
#define STACK_H

struct List
{
	int value;
	struct List* next;
};

bool isEmpty(struct List* stack);

struct List* Push(struct List* stack, int i);

int Pop(struct List** stack);

int getCount(struct List* stack);


#endif
