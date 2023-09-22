#include "monty.h"

/**
 * add_dnodeint_end - add node
 * description: adds a node at the end of a list
 * @head: first node
 * @n: data for new node
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