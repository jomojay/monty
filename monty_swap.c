#include "monty.h"

/**
 * monty_swap - A function that swaps the two values at the top of stack.
 * @stack: The pointer to the top of a stack list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	int tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(3, line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next->n;
	(*stack)->next->n = (*stack)->n;
	(*stack)->n = tmp;
}
