#include "monty.h"

/**
 * monty_pall - A function that prints the values of the stack_t.
 * @stack: The pointer to the top of a stack_t.
 * @line_num: The number of the line.
 * Return: Nothing.
 */
void monty_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;
	(void)line_num;

	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
