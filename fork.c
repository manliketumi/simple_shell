#include "shell.h"
/**
 * execute_command - function execute the pid
 * @command: command to be executed
 *
 * Return: void
 */
void execute_command(char *command)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		int i = 0;
		char *args[MAX_INPUT_SIZE];
		char *token;

		token = strtok(command, " \t\n");
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, "\t\n");
		}
	args[i] = NULL;
	execvp(args[0], args);

	perror("execvp");
	exit(EXIT_FAILURE);
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

	}
}
