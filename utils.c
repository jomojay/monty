#include "monty.h"

/**
 * is_number - check if a string is a number
 * @str: string
 *
 * Return: 1 if string is a number else 0
 */

int is_number(char *str)
{
	int pos = 0;

	while (*(str + pos))
	{
		if (*(str + pos) > 57 || *(str + pos) < 48)
		{
			if (*(str + pos) != 45)
				return (0);
		}
		pos++;
	}

	return (1);
}
