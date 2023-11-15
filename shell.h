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



#endif
