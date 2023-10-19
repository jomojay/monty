#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * push - The opcode push pushes
 * an element to the stack.
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: nothing
 */

void push(stack_type **stack, unsigned int line_number, char *arg)
{
	int element;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (strcmp(arg, "0") == 0)
	{
		element = 0;
		add_node_end(stack, element);
	}
	else
	{
		element = atoi(arg);
		if (element != 0)
		{
			add_node_end(stack, element);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - The opcode pall prints all
 * the values on the stack,
 * starting from the top of the stack.
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: nothing
 */

void pall(stack_type **stack, unsigned int line_number, char *arg)
{
	stack_type *cursor;
	(void)arg;
	(void)line_number;

	if (stack && *stack)
	{
		cursor = *stack;

		while (cursor->next != NULL)
			cursor = cursor->next;

		while (cursor != NULL)
		{
			printf("%d\n", cursor->n);
			cursor = cursor->prev;
		}
	}
}
