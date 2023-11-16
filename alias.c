#include "shell.h"
/**
 * set_alias - function maintain data structure
 * @name: the name of the alias
 * @value: value of the alias
 * Return: void
 */
void set_alias(char *name, char *value)
{
	Alias *current;

	while (current)
	{
		if (strcmp(current->name, name) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			return;
		}
		current = current->next;
	}

	Alias *new_alias = malloc(sizeof(Alias));

	new_alias->name = strdup(name);
	new_alias->value = strdup(value);
	new_alias->next = aliases;
	aliases = new_alias;
}

/**
 * alias_handle - function to handle alias
 * @args: argument structure
 *
 * Return: void
 */
void alias_handle(char **args)
{
	int i;

	if (args[1] == NULL)
	{
		Alias *current;

		while (current)
		{
			print_alias(current);
			current = current->next;
		}
	}
	else
	{
		for (i = 1; args[i] != NULL; i++)
		{
			char *arg = args[i];
			char *equal_sign = strchr(arg, '=');

			if (equal_sign != NULL)
			{
				*equal_sign = '\0';
				set_alias(arg, equal_sign + 1);
			}
			else
			{
				Alias *current;

				while (current)
				{
					if (strcmp(current->name, arg) == 0)
					{
						print_alias(current);
						break;
					}
					current = current->next;
				}
			}
		}
	}
}

/**
 * free_aliases - function clean up aliases list
 *
 * Return: free
 */
void free_aliases(void)
{
	while (current)
	{
		Alias *temp = current;

		current = current->next;
		free(temp->name);
		free(temp->value);
		free(temp);
	}
}

/**
 * main - Entry point
 *
 * Return: void
 */
int main(void)
{
	char *test_args1[] = {"alias", "ls='ls -la'", "grep='grep --color'", NULL};

	alias_handle(test_args1);

	char *test_args2[] = {"alias", NULL};

	alias_handle(test_args2);

	char *test_args3[] = {"alias", "ls", "grep", NULL};

	alias_handle(test_args3);

	free_aliases();
	return (0);
}
