#include "monty.h"

/**
 * addit - adds data
 * description: adds the value from top two elements
 * @stack: dbl ptr to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void f_addit(stack_tt **stack, unsigned int counter)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		first->f_error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_one + value_two;
	f_popit(stack, counter);
}

/**
 * nope - nop opcode
 * description: doesn't do a thing
 * @stack: dbl ptr to stack
 * @line_number: ln count for errors
 * Return: void
 */
void f_nope(stack_tt **stack, unsigned int counter)
{
	(void) stack;
	(void)counter;

}

/**
* subit - adds data
* description: adds the value from top two elements
* @stack: dbl ptr to a stack
* @line_number: ln count for errors
* Return: void
*/

void f_subit(stack_tt **stack, unsigned int counter)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		first->f_error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_two - value_one;
	f_popit(stack, counter);
}

/**
 * mullet - multiplies top two numbers and pop top of stack
 * @stack: head of stack
 * @line_number: line number in file
 * Return: void
 */

void f_mullet(stack_tt **stack, unsigned int counter)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		first->f_error_code = -1;
		return;
	}
	for (; itr->next != NULL; itr = itr->next)
		;
	value_one = itr->n;
	prev = itr->prev;
	value_two = prev->n;
	prev->n = value_one * value_two;
	f_popit(stack, counter);
}

/**
 * divit - adds data
 * description: divides the value from top two elements
 * @stack: dbl ptr to a stack
 * @line_number: ln count for errors
 * Return: void
 */

void f_divit(stack_tt **stack, unsigned int counter)
{
	stack_tt *itr = *stack, *prev = NULL;
	int value_one = 0, value_two = 0;

	if ((*stack == NULL) || (itr->next == NULL))
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
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
	prev->n = value_two / value_one;
	f_popit(stack, counter);
}