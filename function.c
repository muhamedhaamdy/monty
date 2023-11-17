#include "monty.h"

/**
 * valid_int - check if the string is a valid integer
 *
 * @integer : the string to be checked
 * Return: 1 if the string is a valid integer, 0 otherwise
 */
int valid_int(char *integer)
{
	int i = 0;

	if (integer[0] == '-')
		i++;
	while (integer[i])
	{
		if (integer[i] < '0' || integer[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * push - push an element to the stack
 * @stack : the stack
 * @line_number : the line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int num;

	UNSUSED(stack);
	UNSUSED(line_number);
	if (!valid_int(info.arr[1]))
		fprintf(stderr, "L%d: usage: push integer", info.line_num);
	info.line_num++;
	num = atoi(info.arr[1]);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!info.head)
	{
		info.head = new_node;
		info.tail = new_node;
	}
	else
	{
		new_node->next = info.head;
		info.head->prev = new_node;
		info.head = new_node;
	}

}


void pint(stack_t **stack, unsigned int line_number)
{
	UNSUSED(stack);
	UNSUSED(line_number);
	if (!info.head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", info.line_num);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", info.head->n);
}

/**
 * print_all - print all the elements of the stack
 *
 * @stack : the stack
 * @line_number : the line number
 */
void print_all(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = info.head;

	UNSUSED(line_number);
	UNSUSED(stack);
	while (temp)
	{
		printf("%i\n", temp->n);
		temp = temp->next;
	}
}

/**
 * exe_func - execute the function
 * @arr : 2d array that holds the function
*/
void exe_func(char **arr)
{
	int i = 0;
	instruction_t inst[] = {
		{"push", push},
		{"pall", print_all},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{NULL, NULL}
	};
	info.line_num++;
	while (inst[i].opcode)
	{
		if (!strcmp(inst[i].opcode, arr[0]))
		{
			inst[i].f(&info.head, info.line_num);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s", info.line_num, arr[0]);
	exit(EXIT_FAILURE);
}


