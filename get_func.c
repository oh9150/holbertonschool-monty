#include "monty.h"

/**
 * get_func - finds the function to execute
 * @name: the name of the opcode
 *
 * Return: a function
 */
void (*get_func(char *name))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode)
	{
		if (strcmp(name, ops[i].opcode) == 0)
			return (ops[i].f);

		i++;
	}
	return (NULL);
}
