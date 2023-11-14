#include "shell.h"
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
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: always 0
 */

int _strcmp(char *s1, char *s2)
{
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
