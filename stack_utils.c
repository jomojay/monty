#include "monty.h"

/**
 * add_node_end - add a new node to
 * the end of a doubly linked list
 *
 * @head: double pointer to head node
 * @n: integer value
 *
 * Return: pointer to the new node
 */

stack_type *add_node_end(stack_type **head, const int n)
{
	stack_type *new_node;
	stack_type *cursor;

	if (head)
	{
		new_node = (stack_type *)malloc(sizeof(stack_type));

		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = NULL;

		if (*head)
		{
			cursor = *head;
			while (cursor->next)
				cursor = cursor->next;
			cursor->next = new_node;
			new_node->prev = cursor;
		}
		else
		{
			new_node->prev = NULL;
			*head = new_node;
		}

		return (new_node);
	}
	else
		return (NULL);

}

/**
 * free_stack - empty the stack
 * @head: pointer to the head node
 *
 * Return: nothing
 */

void free_stack(stack_type *head)
{
	stack_type *temp_node;

	if (head)
	{
		while (head)
		{
			temp_node = head->next;
			free(head);
			head = temp_node;
		}
	}

}
