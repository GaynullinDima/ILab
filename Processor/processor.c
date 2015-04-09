#include "stack.h"


void add(list** stack)
{
	double temp1 = 0; double temp2 = 0;
	temp1 = pop(stack);
	temp2 = pop(stack);
	push(stack, temp1 + temp2);
};

void sub(list** stack)
{
	double temp1 = 0; double temp2 = 0;
	temp1 = pop(stack);
	temp2 = pop(stack);
	push(stack, temp2 - temp1);
};

void mul(list** stack)
{
	double temp1 = 0; double temp2 = 0;
	temp1 = pop(stack);
	temp2 = pop(stack);
	push(stack, temp1 * temp2);
};

void divide(list** stack)
{
	double temp1 = 0; double temp2 = 0;
	temp1 = pop(stack);
	temp2 = pop(stack);
	assert(temp1 != 0);
	push(stack, temp2 / temp1);
};

void sqr(list** stack)
{
	double temp1 = 0;
	temp1 = pop(stack);
	assert(temp1 >= 0);
	push(stack, sqrt(temp1));
};

void cmp(list** stack)
{
	double temp1 = 0; double temp2 = 0;
	temp1 = pop(stack);
	temp2 = pop(stack);
	if (temp2 > temp1)
		push(stack, 1);
	else if (temp2 == temp1)
		push(stack, 0);
	else
		push(stack, -1);
};





