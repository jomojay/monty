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
	unsigned int cursor = 0, line_number = 0;
	FILE *file_pointer;
	char *line = NULL, **args = NULL;
	size_t line_buffer = 0;

	while (*(filename + cursor))
		cursor++;

	if ((filename[cursor - 2] == '.')
			&& (filename[cursor - 1] == 'm'))
	{
		file_pointer = fopen(filename, "r");

		while (getline(&line, &line_buffer, file_pointer) != -1)
		{
			printf("line %d: ", line_number);
			args = instruction_parser(line);
			if (args)
				printf("[%s, %s]", args[0], args[1]);
			putchar('\n');
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
		printf("Blank line");
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
