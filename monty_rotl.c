#include "monty.h"

/**
 * monty_rotl - A function that rotates the stack to the top.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The top element of the stack becomes the last one,
 * and the second top element of the stack becomes the first one.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cursor = *stack;
	(void)line_number;

	if (*stack)
	{
		temp = cursor->n;
		while (cursor->next != NULL)
		{
			cursor->n = cursor->next->n;
			cursor = cursor->next;
		}
		cursor->n = temp;
	}
}
