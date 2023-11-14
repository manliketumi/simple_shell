#include "shell.h"
/**
 * _getenv - function gets environment using global variable
 *
 * @data: pointer to the address
 * Return: NULL
 */
char *_getenv(const char *data)
{
	char **env;
	extern char **environ;

	if (strncmp(*env, data, strlen(data) == 0 && (*env)[strlen(data)] == '='))
	{
		return (*env + strlen(data) + 1);
	}
	return (NULL);
}
