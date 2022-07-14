#include "monty.h"

/**
 * op_handler - Function that checks for a command "opcode" and execute the
 * function if there's a match.
 * @token: Tokane containing the opcode to execute.
 * @stack: Doubly linked list representation of a stack.
 * @line_num: Line number where the opcode was found.
 * Return: EXIT_SUCCESS in success, or EXIT_FAILURE on failure.
 */

int op_handler(char **token, stack_t **stack, unsigned int line_num)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"pall", monty_pall},
		{"pint", monty_pint},
		{"pop", monty_pop},
		{"swap", monty_swap},
		{"add", monty_add},
		{"sub", monty_sub},
		{"mul", monty_mul},
		{"div", monty_div},
		{"mod", monty_mod},
		{"pchar", monty_pchar},
		{"pstr", monty_pstr},
		{"rotl", monty_rotl},
		{"rotr", monty_rotr},
		{"null", NULL}
	};

	for (i = 0; i < 14; i++)
	{
		if (strcmp(op[i].opcode, token[0]) == 0)
		{
			op[i].f(stack, line_num);
			return (EXIT_SUCCESS);
		}
	}
	free_stack(stack);
	fprintf(stderr, "L%i: unknown instruction %s\n", line_num, token[0]);
	return (EXIT_FAILURE);
}
