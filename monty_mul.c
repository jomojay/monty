#include "monty.h"

/**
 * monty_mul - A function that multiply the two top values of a stack.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(8, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n * (*stack)->next->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}
