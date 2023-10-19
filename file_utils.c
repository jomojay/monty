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
	int cursor = 0;
	FILE *file_pointer;
	int line_number = 1;
	char *line = NULL;
	size_t line_buffer = 0;

	while (*(filename + cursor))
		cursor++;

	if ((filename[cursor - 2] == '.')
			&& (filename[cursor - 1] == 'm'))
	{
		file_pointer = fopen(filename, "r");

		while (getline(&line, &line_buffer, file_pointer) != -1)
		{
			printf("line %d: %s", line_number, line);
			line_number++;
		}
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
}
