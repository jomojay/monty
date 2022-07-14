#include "monty.h"

/**
 * monty_rotr - A function that rotates the stack to the bottom.
 * @stack: The pointer to the stack list.
 * @line_number: The line number of a Monty bytecodes file.
 * Description: The last element of the stack becomes the top element
 * of the stack.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *cursor = *stack;
	(void)line_number;

	if (*stack)
	{
		while (cursor->next != NULL)
			cursor = cursor->next;
		temp = cursor->n;
		while (cursor->prev != NULL)
		{
			cursor->n = cursor->prev->n;
			cursor = cursor->prev;
		}
		cursor->n = temp;
	}
}
