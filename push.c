#include "monty.h"
/**
 * f_push - This adds node to the stack
 * @head: The stack head
 * @counter: The line_number
 * Return: Always no return
*/
void f_push(stack_t **head, unsigned int counter)
{
	stack_t *new, *tail = *head;
	int n = first->n;
	(void) counter;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		first->error_code = -1;
		return;
	}
	if (*head == NULL)
	{
		new->prev = NULL;
		new->next = NULL;
		new->n = n;
		*head = new;
		return;
	}
	while (tail->next != NULL)
		tail = tail->next;
	new->n = n;
	tail->next = new;
	new->prev = tail;
	new->next = NULL;
}
