#include "monty.h"

/**
* add - adds (sums) the top two elements of the stack, the result is stored
* in the second element and the first one is removed
* @stack: the stack
* @line_number: the line number
*/
void add(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = *stack;

	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * nop - does literally nothing
 * @stack: the stack (annoying)
 * @line_number: the line number (annoying)
 * Return: void
 */
void nop(__attribute__((unused)) stack_t **stack, __attribute__((unused)) 
		unsigned int line_number)
{
	return;
}

/**
* sub - subtracts the top elements from the second, the result is stored
* in the second element and the first one is removed
* @stack: the stack
* @line_number: the line number
*/
void sub(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	stack_t *tmp = *stack;

	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	((*stack)->next)->n -= (*stack)->n;
	pop(stack, line_number);
}

