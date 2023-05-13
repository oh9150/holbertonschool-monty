#include "test.h"

/**
 * main - entry point
 * @argc: int
 * @argv: args
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *buf = NULL, *pathname = argv[1], *holder;
	size_t n = 0;
	FILE *fp;

	printf("# args: %d\n", argc);
	fp = fopen(pathname, "r");
	while (getline(&buf, &n, fp) != -1)
	{
		printf("%s", buf);

		holder = strtok(buf, " ");
		holder = strtok(holder, "\n");
		while (holder)
		{
			printf("%s ", holder);
			holder = strtok(NULL, " ");
		}
	}
	getline(&buf, &n, fp);

	return (0);
}
