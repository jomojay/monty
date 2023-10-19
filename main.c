#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * @argc - argument constant
 * @argv - argument vector
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

	return (EXIT_SUCCESS);
}
