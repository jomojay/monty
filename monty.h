#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define DELIMS "\n\t\a\b "

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_type;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_type **stack, unsigned int line_number);
} instruction_t;

void read_instructions(char *filename);
char **instruction_parser(char *line);

/** ## error printers ## */
int usage_error(int flag);

#endif
