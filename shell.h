#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <limits.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_ARGS 64
#define MAX_COMMAND_LEN 100
#define DELIMS " \t\r\n"
#define PROMPT "$ "
#define INITIAL_BUFFER_SIZE 100
#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"

extern char **environ;


typedef struct Alias {
	char *name;
	char *value;
	struct Alias *next;
} Alias;

void print_alias(Alias *alias)
{
	printf("%s='%s'\n", alias->name, alias->value);
}

int _isalpha(int c);
int _atoi(char *s);

int _putchar(char c);
int main(void);
void print_prompt(void);
void execute_command(const char *command);
char *read_command(void);

int _strcmp(const char *s1,const char *s2);
int _strspn(char *s, char *accept);
char *_strcat(char *dest, char *src);
char *_strchr(char *s, char c);
char *_strcpy(char *dest, const char *src);

char **parse_command(char *input);
void ex_com(char **argv);

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

int (*get_builtin(char *cmd))(data_shell *datash);

char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);


#endif
