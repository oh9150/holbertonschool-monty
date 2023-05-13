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

	getline(&buf, &len, fp);
	opcode = strtok(buf, " ");
	printf("%s\n", opcode);
	if (strcmp(opcode, "push") == 0)
	{
		num = strtok(NULL, " ");
		printf("%s\n", num);

		while ((num[i] != '\0') && (num[i] != '\n'))
		{
			if (isdigit(num[i]) == 0)
			{
				printf("L%lu: usage: push integer\n", line_number);
				exit(EXIT_FAILURE);
			}
			i++;
		}
		printf("%s\n", num);
		value = atoi(num);
	}

	return (opcode);
}
