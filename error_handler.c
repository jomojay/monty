#include "monty.h"

/**
 * usage_error - Afunction that prints usage error message.
 * @flag: Type of error: 0 malloc'd failed, or 1 usage.
 * Return: EXIT_FAILURE.
 */
int usage_error(int flag)
{
	char *errors[2] = {"Error: malloc failed", "USAGE: monty file"};

	fprintf(stderr, "%s\n", errors[flag]);
	return (EXIT_FAILURE);
}
