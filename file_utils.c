#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * open_file - open a file with error checking
 * @filename: full path to file
 *
 * Return: file pointer
 */

FILE *open_file(char *filename)
{
	FILE *file_pointer;

	file_pointer = fopen(filename, "r");

	if (file_pointer == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file_pointer);
}

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

	file_pointer = open_file(filename);

	while (getline(&line, &line_buffer, file_pointer) != -1)
	{
		args = instruction_parser(line);
		if (args)
		{
			op_func = get_opcode(args[0]);
			if (op_func != NULL)
			{
				if (op_func(&global_stack, line_number, args[1]) == -1)
				{
					free(args);
					free(line);
					fclose(file_pointer);
					exit(EXIT_FAILURE);
				}
			}
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, args[0]);
				free(args);
				if (global_stack)
					free_stack(global_stack);
				exit(EXIT_FAILURE);
			}
			free(args);
		}
		line_number++;
	}

	free(line);
	fclose(file_pointer);
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

	if (!tokens)
	{
		return (NULL);
	}

	token = strtok(line, DELIMS);
	if (!token)
	{
		free(tokens);
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
