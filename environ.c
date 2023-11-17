#include "shell.h"

/**
 * cmp_env_name - function compare the environment with global variable
 * @nenv: the parameter environment
 * @name: the name of the nenv to be compared
 * Return: 0 on success
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - function gets an environment using the global variable
 * @name: the pointer parameter
 * @_environ: the environment
 * Return: pointer environment
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Init ptr_env val */
	ptr_env = NULL;
	mov = 0;
	/* */
	/*  */
	for (i = 0; _environ[i]; i++)
	{
		/* comments here */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - function prints the address
 * @datash: the pointer to be printed
 * Return: 1 on success
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
