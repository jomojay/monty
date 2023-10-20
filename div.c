#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * div - divides the second top element of the stack
 * by the top element of the stack
 * from the second top element of the stack.
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: 0 if successful, -1 on failure
 */

int div_monty(stack_type **stack, unsigned int line_number, char *arg)
{
	int tmp;
	(void)arg;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			if (global_stack)
				free_stack(global_stack);
			return (-1);
		}
		tmp = (*stack)->next->n / (*stack)->n;
		(*stack)->next->n = tmp;
		pop(stack, line_number, arg);
	}
	else
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	return (0);
}
