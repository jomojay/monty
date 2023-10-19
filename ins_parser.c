#include "monty.h"

/**
 * instruction_parser - A function that split the line.
 * @line: The pointer to bytecode line.
 * @delim: Array with 5 delimiters " \n\t\a\b".
 * Return: The pointer to tokens.
 */
char **instruction_parser(char *line, char *delim)
{
	char *token = NULL, **tokens = NULL;
	size_t bufsize = 0;
	int i = 0;

	if (line == NULL || !*line)
		return (NULL);

	bufsize = strlen(line);
	tokens = malloc(bufsize * sizeof(char *));
	if (tokens == NULL)
	{
		free(line);
		free(tokens);
		exit(usage_error(0));
	}
	token = strtok(line, delim);
	if (token == NULL)
	{
		free(token);
		free(line);
		return (NULL);
	}
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;
	return (tokens);
}
