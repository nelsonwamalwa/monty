#include "monty.h"

/**
 * modit - modulus of top values
 * description: remaider of second to top value divided by top value
 * becomes second to top value and top of stack is popped
 *
 * @stack: dbl ptr to a stack
 * @counter: ln count for errors
 * Return: void
 */

void f_modit(stack_tt **stack, unsigned int counter)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		first->f_error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	if (value_one == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		first->f_error_code = -1;
		return;
	}
	prev->n = value_two % value_one;
	f_popit(stack, counter);
}

/**
 * pcharit - prints a value
 * description: prints value at top of stack
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void f_pcharit(stack_tt **stack, unsigned int counter)
{
	int n = 0;
	stack_tt *itr;
	(void) counter;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		first->f_error_code = -1;
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
	;
	if (itr->n >= 0 && itr->n <= 127)
	{
		n = itr->n;
		putchar(n);
		putchar('\n');
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		first->f_error_code = -1;
		return;
	}
}

/**
 * pstrit - print the string at the top of the stack
 * decription: prints the ascii of an int
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void f_pstrit(stack_tt **stack, unsigned int counter)
{
	int i = 0;
	stack_tt *itr;
	(void) counter;

	if (*stack == NULL)
	{
		putchar('\n');
		return;
	}
	for (itr = *stack; itr->next != NULL; itr = itr->next)
		i++;
	i++;
	for (; i != 0; itr = itr->prev, i--)
	{
		if (itr->n == 0)
			break;
		if (itr->n < 0 || itr->n > 127)
			break;
		putchar(itr->n);
	}
	putchar('\n');
}


/**
 * rotlit - rotates the stack to the top
 * description: top element of the stack becomes the last one
 * @stack: dbl ptr to a stack
 * @line_number: ln count for error
 * Return: void
 */

void f_rotlit(stack_tt **stack, unsigned int counter)
{
	stack_tt *head, *tail, *newtail;

	head = *stack;
	if (*stack == NULL)
		return;
	for (tail = head; tail->next != NULL; tail = tail->next)
		;
	if (tail == head)
		return;
	if (tail->prev == head)
	{
		f_swapit(stack, counter);
		return;
	}
	newtail = tail->prev;
	newtail->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
}


/**
 * rotrit - rotates the stack to the bottom
 * description: last element of the stack becomes the top one
 * @stack: dbl ptr to a stack
 * @line_number: ln count for error
 * Return: void
 */

void f_rotrit(stack_tt **stack, unsigned int counter)
{
	stack_tt *head, *tail, *newhead;

	head = *stack;
	if (*stack == NULL)
		return;
	for (tail = head; tail->next != NULL; tail = tail->next)
		;
	if (tail == head)
		return;
	if (tail->prev == head)
	{
		f_swapit(stack, counter);
		return;
	}
	newhead = head->next;
	newhead->prev = NULL;
	head->next = NULL;
	head->prev = tail;
	tail->next = head;
	*stack = newhead;
}