#include "stack.h"

int main()
{

	struct List* stack = NULL;
	double value = 0.0;
	printf("Please, input only numbers and +, -, /, *, = \n");
	char c;
	scanf("%c", &c);
	while (c != '=')
	{
		if ((c <= '9' && c >= '0') || c == '.')
		{
			bool isPoint = false;
			double pow = 0.1;
			while (c != ' ')
			{
				isPoint = (isPoint || (c == '.'));
				if (c != '.')
				{
					if (isPoint) 
					{
						value = value + ((c - '0') * pow);
						pow = pow * 0.1;
					}
					else 
					{
						value = value * 10;
						value = value + (c - '0');
					}
				}
				scanf("%c", &c);
			}
			stack = Push(stack, value);
			value = 0.0;
		}
		
		else
		{
			double temp1 = 0.0 , temp2 = 0.0;
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
				stack = Push(stack, temp1 - temp2);
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
				if (temp1 == 0) break;
				stack = Push(stack, temp1 / temp2);
			};
		};
		scanf("%c", &c);
	};
	printf("%lg", Pop(&stack));



	return 0;
}
