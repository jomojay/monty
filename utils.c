#include "monty.h"

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
