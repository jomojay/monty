#include "monty.h"
#include <string.h>

/**
 * get_opcode - function that selects
 * the correct function to perform
 * the operation asked by the user.
 * @op_string: string opcode
 *
 * Return: pointer to a function
 */

opcode_func get_opcode(char *op_string)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"swap", swap},
		{"add", add},
		{"pop", pop},
		{"pint", pint},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(op_string, instructions[i].opcode) == 0)
			return (instructions[i].f);

		i++;
	}

	return (NULL);
}
