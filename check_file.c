#include "monty.h"

/**
 * check_file - checks if the file exists and can be read
 * @pathname: the file
 * Return: a pointer to a file pointer
 */
FILE *check_file(char *pathname)
{
	FILE *fp = fopen(pathname, "r");

	if (!fp)
	{
		dprintf(2, "Error: Can't open file %s\n", pathname);
		exit(EXIT_FAILURE);
	}
	return (fp);
}
