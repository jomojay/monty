#include "monty.h"

/**
 * rotl - The opcode rotl rotates
 * the stack to the top.
 *
 * @stack: pointer to head of stack
 * @line_number: line number for current instruction
 * @arg: argument, if any
 *
 * Return: 0 if successful, -1 on failure
 */

int rotl(stack_type **stack, unsigned int line_number, char *arg)
{
	stack_type *temp;

	if (stack && *stack)
	{
		temp = *stack;

		while (*stack)
		{
			swap(&global_stack, 0, NULL);
			*stack = (*stack)->next;
		}

		*stack = temp;
	}

	return (0);
}
