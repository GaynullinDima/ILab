#include <stdio.h>
#include <stack.h>

void push( list* stack, int value )
{
	// if stack is empty, you should reset pointer

	if (stack == NULL)
	{
		stack = ( list* )calloc( 1, sizeof ( list ) );
		stack -> next = NULL;
		stack -> data = value;
	}
	else
	{
		list* temp;
		temp = stack;
		stack = ( list* )calloc( 1, sizeof ( list ) );
		stack -> data = value;
		stack -> next = temp;
		free(temp);
	}
};

int pop( list* stack )
{
	int top_elem = 0;
	list* temp;
	if ( stack == NULL )
		return( stack_is_empty );
	else
	{
		top_elem = stack -> value;
		stack == stack -> next;
		return( top_elem );
	}
};

bool is_empty( list* stack )
{
	if ( stack == NULL )
		return true;
	else
		return false;
};

int get_count( list* stack )
{
	list* temp1;
	list* temp2;
	int count = 0;
	temp1 = stack;
	temp2 = stack -> next;

	if (temp1 == NULL)
		return(0);
	else
	{
		while (temp2 != NULL)
		{
			temp1 = temp2;
			count++;
			temp2 = temp1 -> next;
		}
		count++;
		return(count);
	}
	free(temp1);
	free(temp2);
};

void clear(list* stack)
{
	list* temp;
	if (stack != 0)
	{
		temp = stack -> next;
		while (temp != NULL)
		{
			temp = stack -> next;
			free(stack);
			stack = temp;
		};
		free(stack);
	};
	free(temp);
};