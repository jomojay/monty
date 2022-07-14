#include "monty.h"

/**
 * monty_pstr - A function that prints the string starting at the top of the
 * stack, followed by a new line.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}
	while (tmp != NULL)
	{
		if (tmp->n > 0 && tmp->n <= 127)
		{
			printf("%c", tmp->n);
			tmp = tmp->next;
		}
		else
			break;
	}
	printf("\n");
}
