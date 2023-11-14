#include "shell.h"
/**
 * read_line - function that dynamically allocates memory
 *
 * Return: void
 */
char *read_line(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t n;

	write(STDOUT_FILENO, "$ ", 2);
	n = getline(&line, &len, stdin);
	if (n == -1)
	{
		free(line);
		return (NULL);
	}

}
