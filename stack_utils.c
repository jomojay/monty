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

stack_type *add_node(stack_type **head, const int n)
{
	if (head)
	{
		stack_type *new_node = (stack_type *)malloc(sizeof(stack_type));

		if (!new_node)
			return (NULL);

		new_node->n = n;
		new_node->next = *head;
		new_node->prev = NULL;

		if (*head)
			(*head)->prev = new_node;
		*head = new_node;

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
