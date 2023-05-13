#include "monty.h"

/**
 * __exit - prints @message and exits with @status
 * @message: the message to print in STDERR
 * @status: the status to exit
 *
 * Return: nothing
 */
void __exit(char *message)
{
	dprintf(2, "%s", message);
	exit(EXIT_FAILURE);
}

/**
 * main - entry point
 * @argc: ammount of arguments
 * @argv: the arguments
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *opcode = NULL, *buf = NULL;
	void (*func)(stack_t **stack, unsigned int line_number);
	size_t n = 0, line_number = 1;
	FILE *fp = NULL;
	stack_t *stack = NULL;

	if (argc != 2)
		__exit("USAGE: monty file\n");

	fp = check_file(argv[1]);

	opcode = get_opcode(buf, n, fp, line_number);
	while (opcode != NULL)
	{
		func = get_func(opcode);
		if (!func)
		{
			dprintf(2, "L%lu: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
		}
		func(&stack, line_number);
		line_number++;
		opcode = get_opcode(buf, n, fp, line_number);
	}
	free(stack);
}



