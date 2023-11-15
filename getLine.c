#include "shell.h"
/**
 * my_getline - function involves managing a buffer to read characters
 * @lineptr: line double pointer
 * @n: number of characters
 * @stream: buffer size adjusts as needed from the length
 * Return: -1 or number of characters
 */
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t len = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}

	if (*lineptr == NULL)
	{
		*lineptr = malloc(INITIAL_BUFFER_SIZE);

		if (*lineptr == NULL)
		{
			return (-1);
		}
		*n = INITIAL_BUFFER_SIZE;
	}
	while ((c = fgetc(stream)) != EOF && c != '\n')
	{
		if (len + 1 >= *n)
		{
			size_t new_size = *n + INITIAL_BUFFER_SIZE;
			char *new_ptr = realloc(*lineptr, new_size);

			if (new_ptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[len++] = c;
	}
	(*lineptr)[len] = '\0';
	return (len);
}
