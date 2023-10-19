#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * read_instructions - read the instructions
 * line by line
 *
 * @filename: the full path to the monty file
 *
 * Return: nothing
 */

void read_instructions(char *filename)
{
	unsigned int line_number = 1;
	FILE *file_pointer;
	char *line = NULL, **args = NULL;
	size_t line_buffer = 0;
	opcode_func op_func;

	file_pointer = fopen(filename, "r");

	if (file_pointer)
	{
		while (getline(&line, &line_buffer, file_pointer) != -1)
		{
			args = instruction_parser(line);
			if (args)
			{
				op_func = get_opcode(args[0]);
				if (op_func)
				{
					op_func(&global_stack, line_number, args[1]);
				}
				else
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
					exit(EXIT_FAILURE);
				}
			}
			line_number++;
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}

/**
 * instruction_parser - A function that split the line.
 * @line: The pointer to bytecode line.
 * Return: The pointer to tokens.
 */

char **instruction_parser(char *line)
{
	char **tokens = malloc(sizeof(char *) * 3);
	char *token;
	char *line_copy = strdup(line);

	token = strtok(line_copy, DELIMS);
	if (!token)
	{
		return (NULL);
	}
	else
	{
		tokens[0] = token;
		tokens[1] = strtok(NULL, DELIMS);
		if (tokens[1])
			tokens[2] = NULL;
	}

	return (tokens);
}
