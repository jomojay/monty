#include "monty.h"

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
