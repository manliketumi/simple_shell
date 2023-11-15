#include "shell.h"
/**
 * _strcmp - function compares two strings
 * @s1: the first string
 * @s2:the second string
 * Return: 0 on success
 */
int _strcmp(const char *s1, const char *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (INT_MAX);
	}

	while (*s1 == *s2)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * _strcat - function concatenates two strings
 * @src: the first input string
 * @dest: the second input string
 * Return: destination
 */
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i] != '\0')
		i++;

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}

	dest[i] = '\0';

	return (dest);
}
/**
 * _strchr - function that locates a character in a string
 * @s: a string
 * @c: character that returns
 * Return: a pointer to the occurrence of the first character
 */
char *_strchr(char *s, char c)
{
	int t;

	while (1)
	{
		t = *s++;
		if (t == c)
		{
			return (s - 1);
		}
		if (t == 0)
		{
			return (NULL);
		}
	}
}
/**
 * _strcpy - function that copies the string pointed to by src
 * @dest: Pointer to the destination buffer
 * @src: Pointer to the source string to be copied
 * Return: dest value
 */
char *_strcpy(char *dest, const char *src)
{
	char *dest_start;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	dest_start = dest;

	while (*src != '\0')
	{
		*dest++ = *src++;
	}

	*dest = '\0';
	return (dest_start);
}
