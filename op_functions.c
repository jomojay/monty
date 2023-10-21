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
 * Return: 0 if successful, -1 on failure
 */

int push(stack_type **stack, unsigned int line_number, char *arg)
{
	int element;

	if (arg == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	if (is_number(arg))
	{
		element = atoi(arg);
		add_node(stack, element);
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	return (0);
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
 * Return: 0 if successful, -1 on failure
 */

int pall(stack_type **stack, unsigned int line_number, char *arg)
{
	stack_type *cursor;
	(void)arg;
	(void)line_number;

	if (stack && *stack)
	{
		cursor = *stack;

		while (cursor != NULL)
		{
			fprintf(stdout, "%d\n", cursor->n);
			fflush(stdout);
			cursor = cursor->next;
		}
	}

	return (0);
}

/**
 * pint - The opcode pint prints
 * the value at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: 0 if successful, -1 on failure
 */

int pint(stack_type **stack, unsigned int line_number, char *arg)
{
	stack_type *tmp = *stack;
	(void)arg;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	printf("%d\n", tmp->n);
	return (0);
}

/**
 * pchar - The opcode pint prints
 * the char at the top of the stack,
 * followed by a new line
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: 0 if successful, -1 on failure
 */

int pchar(stack_type **stack, unsigned int line_number, char *arg)
{
	stack_type *tmp = *stack;
	(void)arg;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	if (tmp->n < 0 || tmp->n > 127)
	{
		putchar(tmp->n);
		putchar(10);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}
	return (0);

}

/**
 * nop - The opcode nop doesn’t do anything.
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: 0 if successful, -1 on failure
 */

int nop(stack_type **stack, unsigned int line_number, char *arg)
{
	(void)stack;
	(void)line_number;
	(void)arg;
	return (0);
}
