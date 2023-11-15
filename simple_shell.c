#include "shell.h"
/**
 * print_prompt - Entry point
 *
 * Return: void
 */
void print_prompt(void)
{
	printf(PROMPT);
}

/**
 * read_command - function reads a command from user
 *
 * Return: NULL on EOF
 */
char *read_command(void)
{
	static char command[MAX_COMMAND_LEN];

	if (fgets(command, MAX_COMMAND_LEN, stdin) == NULL)
	{
		printf("\n");
		return (NULL);
	}
	command[strcspn(command, "\n")] = 0; /* Removes newline */
	return (command);
}
/**
 * execute_command - function executes the given command
 * @command: the command to be executed
 *
 * Return: void
 */
void execute_command(const char *command)
{
	char *argv[2];
	char *envp[] = { NULL };
	pid_t pid;

	argv[0] = (char *)command;
	argv[1] = NULL;

	pid = fork();

	if (pid == 0)
	{
		if (execve(command, argv, envp) == -1)
		{
			perror("Error executing command");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking");
	}
	else
	{
		wait(NULL);
	}
}
/**
 * main - function orchestrates these calls
 * @argc: argument command
 * @argv: argument value of the prompt
 * Return: 0 on success
 */
int main(void)
{
	char *command;

	while (1)
	{
		print_prompt();
		command = read_command();

		if (command == NULL)
		break;

		if (strlen(command) == 0)
		continue;

		execute_command(command);
	}
	return (0);
}
