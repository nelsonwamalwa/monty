#include "monty.h"

/**
 * f_modit - Modulus of top values in stack
 * description: Remaider of second to top divided by top
 * @stack: Pointer to a stack
 * @counter: Count for errors
 * Return: void(NULL)
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
 * f_pcharit - Prints a chars value
 * description: Prints value at top of stack lists
 * @stack: Pointer to stack
 * @Counter: Count for errors
 * Return: void(NULL)
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
 * f_pstrit - Print the string at the top of the stack
 * decription: Prints the ascii of an int value
 * @stack: Point to stack
 * @Counter: Count for errors
 * Return: void(NULL)
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
 * f_rotlit - Rotates the stack to top
 * description: Any top element of the stack becomes the last
 * @stack: Pointer to a stack
 * @Counter: Count for error
 * Return: Void(NULL)
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
 * f_rotrit - Rotate the stack to the bottom of list
 * description: Any last element of the stack becomes the top
 * @stack: Pointer to a stack
 * @Counter: Count for error
 * Return: Void(NULL)
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