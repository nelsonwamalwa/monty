#include "monty.h"

/**
 * print_q - prints queue
 * @h: list to print
 * Return: number of nodes
 */

size_t f_print_q(const stack_tt *h)
{
	int count;

	for (count = 0; h != NULL; count++)
	{
		h = h->next;
	}
	return (count);
}

/**
 * stack_len - returns length of list
 * @h: list
 * Return: length of list
 */

size_t f_stack_len(const stack_tt *h)
{
	int count;

	for (count = 0; h != NULL; count++)
		h = h->next;
	return (count);
}

/**
 * add_stackstart - add node to beginning of linked list
 * @head: head of linked list
 * @n: value of node
 * Return: pointer to node or NULL
 */

stack_tt *f_add_stackstart(stack_tt **head, const int n)
{
	stack_tt *new, *tmp;

	new = malloc(sizeof(stack_tt));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->n = n;
	if (*head != NULL)
	{
		new->next = *head;
		tmp = new->next;
		tmp->prev = new;
	}
	else
		new->next = NULL;
	*head = new;
	return (new);
}

/**
 * push_stack - adds node to end
 * @head: head of linked list
 * @n: value to put into node
 * Return: pointer to node or NULL
 */

stack_tt *f_push_stack(stack_tt **head, const int n)
{
	stack_tt *new, *node = *head;

	new = malloc(sizeof(stack_tt));
	if (!new)
		return (NULL);
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		new->n = n;
		*head = new;
		return (new);
	}
	while (node->next != NULL)
	{
		node = node->next;
	}
	new->prev = node;
	new->next = NULL;
	new->n = n;
	node->next = new;
	return (new);
}

/**
 * free_stack - frees doubly linked list
 * @stack: dbl ptr to stack
 * Return: null
 */

void f_free_stack(stack_tt *stack)
{
	stack_tt *tmp = NULL;

	if (stack == NULL)
		return;
	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
	stack = NULL;
}