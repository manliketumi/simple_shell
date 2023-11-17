#include "shell.h"
/**
 * read_line - function read line
 * @i_eof: the integer parameter
 * Return: an integer
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
