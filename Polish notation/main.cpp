#include "stack.h"

int main()
{

	struct List* stack = NULL;
	int value = 0;
	printf("Please, input only numbers and +, -, /, *, = \n");
	char c;
	scanf("%c", &c);
	while (c != '=')
	{
		if (c <= '9' && c >= '0')
		{
			while (c != ' ')
			{
				value = value * 10;
				value = value + (c - '0');
				scanf("%c", &c);
			}
			stack = Push(stack, value);
			value = 0;
		}

		else
		{
			int temp1 = 0, temp2 = 0;
			if (c == '+')
			{
				temp1 = Pop(&stack);
				if (isEmpty(stack)) break;
				temp2 = Pop(&stack);
				stack = Push(stack, temp1 + temp2);
			}
			else if (c == '-')
			{
				temp1 = Pop(&stack);
				if (isEmpty(stack)) break;
				temp2 = Pop(&stack);
				stack = Push(stack, temp2 - temp1);
			}
			else if (c == '*')
			{
				temp1 = Pop(&stack);
				if (isEmpty(stack)) break;
				temp2 = Pop(&stack);
				stack = Push(stack, temp1 * temp2);
			}
			else if (c == '/')
			{
				temp1 = Pop(&stack);
				if (isEmpty(stack)) break;
				temp2 = Pop(&stack);
				stack = Push(stack, temp2 / temp1);
			};
		};
		scanf("%c", &c);
	};
	printf("%d", Pop(&stack));



	system("pause");
	return 0;
}