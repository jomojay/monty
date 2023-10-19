#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

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
} stack_t;

extern stack_t *global_stack;

/* stack utility functions */
stack_t *add_node_end(stack_t **head, const int n);
void free_stack(stack_t *head);

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
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void read_instructions(char *filename);
char **instruction_parser(char *instruction_line);

#endif
