#define _GNU_SOURCE
#include "monty.h"

/**
 * monty_run - A function that runs a Monty bytecodes script.
 * @fd: File descriptor for an open Monty bytecodes script.
 * Return: EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
int monty_run(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, **token = NULL, delim[] = " \n\t\a\b";
	size_t len = 0, mode = 1;
	unsigned int line_num = 0, exit_status = EXIT_SUCCESS;

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		if (empty_line(line, delim))
			continue;
		token = tokening(line, delim);
		if (token[0][0] == '#' || strcmp(token[0], "nop") == 0)
		{
			free(token);
			continue;
		}
		else if (strcmp(token[0], "stack") == 0)
			mode = 1;
		else if (strcmp(token[0], "queue") == 0)
			mode = 0;
		else if (strcmp(token[0], "push") == 0 && mode == 0)
			exit_status = monty_pushq(&stack, token, line_num);
		else if (strcmp(token[0], "push") == 0 && mode == 1)
			exit_status = monty_push(&stack, token, line_num);
		else
			exit_status = op_handler(token, &stack, line_num);
		free(token);
		if (exit_status == EXIT_FAILURE)
			break;
	}
	free_stack(&stack);
	free(line);
	return (exit_status);
}
