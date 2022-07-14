#include "monty.h"

/**
 * monty_pushq - A function that pushes an element to queue.
 * @stack: The pointer to the stck struct.
 * @token: The pointer to command.
 * @line_num: The number of the line.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on failure.
 */
int monty_pushq(stack_t **stack, char **token, unsigned int line_num)
{
	stack_t *new, *tmp = NULL;
	int i = 0;

	if (token[1] == NULL)
		return (f_errors(0, line_num));
	while (token[1][i])
	{
		if (token[1][i] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (token[1][i] < '0' || token[1][i] > '9')
		{
			free_stack(stack);
			return (f_errors(0, line_num));
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (usage_error(0));
	new->next = NULL;
	new->prev = NULL;
	new->n = atoi(token[1]);
	if (!stack || !(*stack))
	{
		(*stack) = new;
		return (EXIT_SUCCESS);
	}
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		new->prev = tmp;
		tmp->next = new;
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}
