#include "monty.h"

/**
 * monty_pop - A function that removes the top value in the stack.
 * @stack: The pointer to the stack_t list.
 * @line_number: The line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(2, line_number);
		exit(EXIT_FAILURE);
	}

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);
}
