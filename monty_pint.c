#include "monty.h"

/**
 * monty_pint - A function that prints the top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(1, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", tmp->n);
}
