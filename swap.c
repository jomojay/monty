#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * swap - swaps the top two elements of the stack.
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument if any
 *
 * Return: 0 if successful, -1 on failure
 */

int swap(stack_type **stack, unsigned int line_number, char *arg)
{
	int tmp;
	(void)arg;

	if (*stack && (*stack)->next)
	{
		tmp = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = tmp;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	return (0);
}
