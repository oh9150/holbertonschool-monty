#include "monty.h"

int value;

/**
 * push - pushes an element to the stack
 * @stack: the stack
 * @line_number: the line number
 * return: nothing
 */
void push(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
		__exit("Error: malloc failed\n");

	new_node->n = value;
	if (!(*stack))
	{
		*stack = new_node;
		return;
	}

	(*stack)->prev = new_node;
	new_node->next = *stack;
	*stack = new_node;
}

/**
 * pall - prints all of the stack, from the top to the bottom
 * @stack: the stack
 * @line_number: the line number
 * return: nothing
 */
void pall(stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp)
		return;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/** pint - prints the value at the top of the stack
 * @stack: the stack
 * @line_number: the line number
 * return: nothing
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * pop - removes the first element from the stack
 * @stack: the stack
 * @line_number: the line number
 * return: nothing
 */
void pop(stack_t **stack, unsigned int line_number)
{
	if (!stack)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: the stack
 * @line_number: the line number
 * Return: void
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int aux, i = 0;
	stack_t *tmp = *stack;

	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	aux = (*stack)->n;
	(*stack)->n = ((*stack)->next)->n;
	((*stack)->next)->n = aux;
}
