#include "shell.h"
/**
 * parse_command - function tokenizes the input string
 * @input: string that is suitable for the list
 *
 * Return: argv
 */
char **parse_command(char *input)
{
	int argc = 0;
	static char *argv[MAX_ARGS];

	char *token = strtok(input, DELIMS);

	while (token != NULL && argc < MAX_ARGS - 1)
	{
		argv[argc++] = token;
		token = strtok(NULL, DELIMS);
	}
	argv[argc] = NULL;

	return (argv);
}
/**
 * ex_com - command to be executed
 * @argv: the argument value
 *
 * Return: void
 */
void ex_com(char **argv)
{
	pid_t pid;

	if (argv[0] == NULL)
	{
		return;
	}

	pid = fork();

	if (pid == 0)
	{
		if (execvp(argv[0], argv) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}

	else
	{
		wait(NULL);
	}
}
