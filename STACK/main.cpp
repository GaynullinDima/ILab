#include "stack.h"

int main(void)
{
	list** stack = (list**)calloc(1, sizeof(list*)) ;
	*stack = NULL;
	int value;
	printf("Input value and press enter. \n");
	scanf_s("%d", &value);
	push(stack, value);
	push(stack, value + 1);
	printf("%d\n", pop(stack));
	printf("%d\n", is_empty(*stack));
	clear(*stack);
	printf("%d\n", is_empty(*stack));
	printf("%d\n", pop(stack));
	system("pause");
	return 0;
}