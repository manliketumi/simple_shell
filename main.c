#include "shell.h"
/**
 * main - Entry point
 * @argc: the argument command
 * @argv: the argument value
 * Return: void
 */
int main(int argc, char **argv)
{
	int status = 0;
	char *line = NULL;
	/* char **command = NULL; */

	(void) argc;
	(void) argv;

	while (1)
	{
		/*staus = _execute(command, agrv);*/

		line = read_line();
		if (line == NULL)
		{
			return (status);
		}
		printf("%s", line);
		/*command = tokenizer(line);*/
	}
}
