#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

stack_type *global_stack = NULL;
/**
 * main - Entry point
 *
 * @argc: argument constant
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS
 */

int main(int argc, char *argv[])
{
	char *filename;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	filename = argv[1];

	read_instructions(filename);
	free_stack(global_stack);

	return (EXIT_SUCCESS);
}
