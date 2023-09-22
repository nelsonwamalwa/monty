#include "monty.h"

/**
 * f_addit - Adds data in stack
 * description: Adds data in stack
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
 * f_nope - Does nothing on opcode
 * description: none
 * @stack: Pointer to stack
 * @counter: Count for errors
 * Return: void(NULL)
 */
void f_nope(stack_tt **stack, unsigned int counter)
{
	(void) stack;
	(void)counter;

}

/**
* f_subit - Subtracts data from stack
* description: Subtracts data from the stack
* @stack: Pointer to a stack
* @counter: Count for errors
* Return: void(NULL)
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
 * f_mullet - Multiplies top two numbers and pop top of stack
 * @stack: Pointer to the head of stack
 * @counter: index of line in file
 * Return: void(NULL)
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
 * f_divit - Divides data in stack
 * description: Divides the value from top two elements in stack
 * @stack: Pointer to a stack
 * @line_number: Count for errors
 * Return: void(NULL)
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