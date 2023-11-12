#include "shell.h"
/**
 * _strncpy - function that copies a string
 * @dest: pointer to the destination
 * @src: pointer to the source string
 * @n: max number of bytes to be copied from src
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}

	for (; i < n; i++)
	{
		dest[i] = '\0';
	}

	return (dest);
}
