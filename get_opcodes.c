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
		{"push", push}, {"pall", pall},
		{"swap", swap}, {"add", add},
		{"pop", pop}, {"pint", pint},
		{"nop", nop}, {"sub", sub},
		{"mul", mul}, {"div", div_monty},
		{"mod", mod_monty}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {NULL, NULL}
	};
	int i = 0;

	if (op_string[0] == '#')
		return (instructions[6].f);

	while (instructions[i].opcode != NULL)
	{
		if (strcmp(op_string, instructions[i].opcode) == 0)
			return (instructions[i].f);

		i++;
	}

	return (NULL);
}
