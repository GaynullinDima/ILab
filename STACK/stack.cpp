#include "stack.h"

void push(list** stack, int value)
{
	// if stack is empty, you should reset pointer

	list* temp;
	temp = *stack;
	*stack = (list*)calloc(1, sizeof (list*));
	(*stack)->data = value;
	(*stack)->next = temp;
};

int pop(list** stack)
{
	int top_elem = 0;
	if ((*stack) == NULL)
		return(stack_is_empty);
	top_elem = (*stack)->data;
	(*stack) = ((*stack)->next);
	return(top_elem);

};


bool is_empty(list* stack)
{
	if (stack == NULL)
		return true;
	return false;
};

int get_count(list* stack)
{
	if (stack == NULL) return 0;

	list* temp;
	temp = stack;
	int count = 1;

	while (temp->next != NULL)
	{
		temp = temp->next;
		count++;
	}
	return count;

};

void clear(list* stack)
{
	list* temp = NULL;
	if (stack != NULL)
	{
		temp = ((*stack) -> next);
		while (temp != NULL)
		{
			temp = ((*stack) -> next);
			free(*stack);
			stack = &temp;
		};
		free(stack);
	};
	
}; 