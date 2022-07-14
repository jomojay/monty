#include "monty.h"

/**
 * monty_pchar - A function that prints char at top value of the stack.
 * @stack: The pointer to the stack list.
 * @line_number: The current working line number of a Monty bytecodes file.
 */
void monty_pchar(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	stack_t *tmp = *stack;

	if (!tmp)
	{
		f_errors(11, line_number);
		exit(EXIT_FAILURE);
	}
	number = tmp->n;
	if (number < 0 || number > 127)
	{
		f_errors(10, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", tmp->n);
}
