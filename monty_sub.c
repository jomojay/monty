#include "monty.h"

/**
 * monty_sub - A function that subtracts the second value from the top of a
 * stack linked by the top value.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The result is stored in the second node
 *              from the top and the top value is removed.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		f_errors(5, line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next->n - (*stack)->n;
	(*stack)->next->n = temp;
	monty_pop(stack, line_number);
}
