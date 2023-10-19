#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

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
	char *line = NULL, delim[] = " \n\t\a\b", **args = NULL;
	size_t line_buffer = 0;

	while (*(filename + cursor))
		cursor++;

	if ((filename[cursor - 2] == '.')
			&& (filename[cursor - 1] == 'm'))
	{
		file_pointer = fopen(filename, "r");

		while (getline(&line, &line_buffer, file_pointer) != -1)
		{
			line_number++;
			args = instruction_parser(line, delim);
			printf("line <%d>; %s %s\n", line_number, args[0], args[1]);
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
