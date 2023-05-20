#include "monty.h"

int value;

/**
 * get_opcode - reads the file and finds an opcode and its argument
 * @file: the file in question
 * @line: the current line to read
 * @value: the variable to copy the argument to
 *
 * Return: a string containing the opcode, NULL when failed
 */
char *get_opcode(char *buf, size_t len, FILE *fp, size_t line_number)
{
	size_t i = 0;
	char *opcode, *num;

	if (getline(&buf, &len, fp) == -1)
		return (NULL);

	opcode = strtok(buf, " ");
	num = strtok(NULL, " ");
	opcode = strtok(opcode, "\n");
	if (!opcode)
		return (NULL);

	if (strcmp(opcode, "push") == 0)
	{
		if (!num)
			num = "a";
		while ((num[i] != '\0') && (num[i] != '\n'))
		{
			if (isdigit(num[i]) == 0)
			{
				fprintf(stderr, "L%lu: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		value = atoi(num);
	}

	return (opcode);
}
