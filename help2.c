#include "monty.h"

/**
 * f_add_dnodeint_end - Add node to the list
 * description: Adds a node at the end of linked list
 * @head: header node
 * @n: New node data
 * Return: address or NULL
 */

stack_tt *f_add_dnodeint_end(stack_tt **head, const int n)
{
	stack_tt *endnode;
	stack_tt *tail;

	endnode = malloc(sizeof(stack_tt));
	if (endnode == NULL)
		return (NULL);
	endnode->n = n;
	if (*head == NULL)
		*head = endnode;
	else
	{
		tail = *head;
		while (tail->next != NULL)
			tail = tail->next;
		tail->next = endnode;
		endnode->prev = tail;
		endnode->next = NULL;
		endnode = tail;
	}
	return (endnode);
}