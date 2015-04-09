#include "stack.h"


/* Assembler commands:
"add"   to 111
"sub"   to 112
"mul"   to 113
"div"   to 114
"sqr"	to 115
"psh"   to 211 with value
"pop"   to 212
"mvv"   to 311 with variable (to) and variable  (from) (variables are 'AX', 'BX', 'CX', 'DX')
"mvs"   to 312 with variable (to) (variables are 'AX', 'BX', 'CX', 'DX');	  stack(from)
"msv"	to 313 with variable (from) (variables are 'AX', 'BX', 'CX', 'DX');   stack(to)
"jmp"   to 411 with labelname
"jme"   to 412 with labelname
"jml"   to 413 with labelname
"jmg"	to 414 with labelname
"cmp"   to 511
label   to 611 with labelname
*/

//use cmp with jme, jml, jmg

int main(void)
{
	list** stack = (list**)calloc(1, sizeof(list*));
	*stack = NULL;
	FILE* input = fopen("input.txt", "r");

	
	double data[100];
	memset(data, 0, 100 * sizeof(double));
	double reg[4];
	memset(reg, 0, 4 * sizeof(double));
	int com[100];
	memset(com, 0, 100 * sizeof(int));
	label labels[10];
	memset(labels, 0, 10 * sizeof(label));
	
	double value = 0;
	int label_count = 0, com_count = 0, data_count = 0; 
	int count = 0;
	bool label_exists = false;
	int label_number = 0;

	char str[4];
	char label_name[10];
	char from[10];
	int i = 0;


	assert(input != NULL);


		fscanf(input, "%s", str);
		while (strcmp(str, "end") != 0)
		{
			assert(label_count < 10);
			assert(com_count < 100);
			assert(data_count < 100);
			if (strcmp(str, "add") == 0)
			{
				com[com_count++] = 111;
			}
			else if (strcmp(str, "sub") == 0)
			{
				com[com_count++] = 112;
			}
			else if (strcmp(str, "mul") == 0)
			{
				com[com_count++] = 113;
			}
			else if (strcmp(str, "div") == 0)
			{
				com[com_count++] = 114;
			}
			else if (strcmp(str, "sqr") == 0)
			{
				com[com_count++] = 115;
			}
			else if (strcmp(str, "psh") == 0)
			{
				com[com_count++] = 211;
				fscanf(input, "%lg", &value);
				data[data_count] = value;
				com[com_count++] = data_count;
				data_count++;
			}
			else if (strcmp(str, "pop") == 0)
			{
				com[com_count++] = 212;
			}
			else if (strcmp(str, "mvv") == 0)
			{
				com[com_count++] = 311;
				fscanf(input, "%s", from);
				com[com_count++] = (from[0] - 'A');
				assert(com[(com_count - 1)] < 4);
				assert(com[(com_count - 1)] >= 0);
				fscanf(input, "%s", from);
				com[com_count++] = (from[0] - 'A');
				assert(com[(com_count - 1)] < 4);
				assert(com[(com_count - 1)] >= 0);
			}
			else if (strcmp(str, "mvs") == 0)
			{
				com[com_count++] = 312;
				fscanf(input, "%s", from);
				com[com_count++] = (from[0] - 'A');
				assert(com[(com_count - 1)] < 4);
				assert(com[(com_count - 1)] >= 0);
			}
			else if (strcmp(str, "msv") == 0)
			{
				com[com_count++] = 313;
				fscanf(input, "%s", from);
				com[com_count++] = (from[0] - 'A');
				assert(com[(com_count - 1)] < 4);
				assert(com[(com_count - 1)] >= 0);
			}
			else if (strcmp(str, "jmp") == 0)
			{
				com[com_count++] = 411;
				fscanf(input, "%s", label_name);
				label_exists = false;
				for(i = 0; i <= label_count; i++) 
				{
					if (strcmp(labels[i].name, label_name) == 0) 
					{
						label_exists = true;
						label_number = i;
					}

				};
				if (label_exists) 
					com[com_count++] = label_number;
				else
				{
					com[com_count++] = label_count;
					strcpy(labels[label_count++].name, label_name);
				};
			}
			else if (strcmp(str, "jme") == 0)
			{
				com[com_count++] = 412;
				fscanf(input, "%s", label_name);
				label_exists = false;
				for(i = 0; i <= label_count; i++) 
				{
					if (strcmp(labels[i].name, label_name) == 0) 
					{
						label_exists = true;
						label_number = i;
					}

				};
				if (label_exists) 
					com[com_count++] = label_number;
				else
				{
					com[com_count++] = label_count;
					strcpy(labels[label_count++].name, label_name);
				};
			}
			else if (strcmp(str, "jml") == 0)
			{
				com[com_count++] = 413;
				fscanf(input, "%s", label_name);
				label_exists = false;
				for(i = 0; i <= label_count; i++) 
				{
					if (strcmp(labels[i].name, label_name) == 0) 
					{
						label_exists = true;
						label_number = i;
					}

				};
				if (label_exists) 
					com[com_count++] = label_number;
				else
				{
					com[com_count++] = label_count;
					strcpy(labels[label_count++].name, label_name);
				};
			}
			else if (strcmp(str, "jmg") == 0)
			{
				com[com_count++] = 414;
				fscanf(input, "%s", label_name);
				label_exists = false;
				for(i = 0; i <= label_count; i++) 
				{
					if (strcmp(labels[i].name, label_name) == 0) 
					{
						label_exists = true;
						label_number = i;
					}

				};
				if (label_exists) 
					com[com_count++] = label_number;
				else
				{
					com[com_count++] = label_count;
					strcpy(labels[label_count++].name, label_name);
				};
			}
			else if (strcmp(str, "cmp") == 0)
			{
				com[com_count++] = 511;
			}
			else 
			{
				com[com_count++] = 611;
				label_exists = false;
				for(i = 0; i <= label_count; i++) 
				{
					if (strcmp(labels[i].name, str) == 0) 
					{
						label_exists = true;
						label_number = i;
					};

				};
				
				if (label_exists) 
				{
					labels[label_number].line_num = com_count;
				}
				else
				{
					strcpy(labels[label_count++].name, str);
					labels[label_count].line_num = com_count;
				};
			};
			fscanf(input, "%s", str);
		};
	fclose(input);
	
	

	
	for(i = 0; i < com_count; i++) 
	{
		printf("commands \n %d %d\n  ", com[i], i);
	};

	for(i = 0; i < data_count; i++) 
	{
		printf("data \n %lf   %d\n  ", data[i], i);
	};

	for(i = 0; i <  4; i++) 
	{
		printf("reg \n %lf   %d\n  ", reg[i], i);
	};

	for(i = 0; i <  label_count; i++) 
	{
		printf("label \n %s  %d %d\n  ", labels[i].name, labels[i].line_num, i);
	};
	
	
	//----------------------------------------------I'm here(Нормально парсится)
	while (count < com_count)
	{
		switch (com[count])
		{
		case 111:
			add(stack);
			break;
		case 112:
			sub(stack);
			break;
		case 113:
			mul(stack);
			break;
		case 114:
			divide(stack);
			break;
		case 115:
			sqr(stack);
			break;
		case 211:
			push(stack, data[com[++count]]);
			break;
		case 212:
			value = pop(stack);
			break;
		case 311:
			count++;
			reg[com[count]] = reg[com[++count]];
			break;
		case 312:
			value = pop(stack);
			reg[com[++count]] = value;
			push(stack, value);
			break;
		case 313:
			value = reg[com[++count]];
			push(stack, value);
			break;
		case 411:
			count = labels[com[++count]].line_num;
			break;
		case 412:
			value = pop(stack);
			if (value == 0) 
			{
				count = labels[com[++count]].line_num;
			}
			else
				push(stack, value);
			break;
		case 413:
			value = pop(stack);
			if (value < 0) 
			{
				count = labels[com[++count]].line_num;
			}
			else
				push(stack, value);
			break;
		case 414:
			value = pop(stack);
			if (value > 0) 
			{
				count = labels[com[++count]].line_num;
			}
			else
				push(stack, value);
			break;
		case 511:
			cmp(stack);
			break;
		};
		printf("\n%d\n\n", count);
	count++;
	};
	


	/*for(i = 0; i < com_count; i++) 
	{
		printf("commands \n %d %d\n  ", com[i], i);
	};

	for(i = 0; i < data_count; i++) 
	{
		printf("data \n %lf   %d\n  ", data[i], i);
	};

	for(i = 0; i <  4; i++) 
	{
		printf("reg \n %lf   %d\n  ", reg[i], i);
	};

	for(i = 0; i <  label_count; i++) 
	{
		printf("label \n %s  %d %d\n  ", labels[i].name, labels[i].line_num, i);
	};*/
	value = pop(stack);
	printf("Your final values:\nx1 = %lg\nx2 = %lg\n", pop(stack), pop(stack));
	return 0;
}