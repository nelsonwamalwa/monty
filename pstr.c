#include "monty.h"
/**
 * f_pstr - This prints string starting at the top of stack,
 * followed by a new one
 * @head: This the stack head
 * @counter: Given line_number
 * Return: Always no return
*/
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}