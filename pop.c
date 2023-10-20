#include "monty.h"

/**
 * pop - A function that removes the top value in the stack.
 * @stack: The pointer to the stack_t list.
 * @line_number: The line number of a Monty bytecodes file.
 * @arg: argument to work with if necessary
 */
int pop(stack_type **stack, unsigned int line_number, char *arg)
{
	stack_type *tmp = NULL;
	(void)arg;

	tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		if (global_stack)
			free_stack(global_stack);
		return (-1);
	}

	if (tmp->next)
		tmp->next->prev = tmp->prev;
	*stack = tmp->next;
	free(tmp);

	return (0);
}
