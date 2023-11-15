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

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

#define MAX_COMMAND_LEN 100
#define PROMPT "$ "

int _isalpha(int c);
int _atoi(char *s);

int _putchar(char c);
int main();
void print_prompt(void);
void execute_command(const char *command);
char *read_command(void);

#endif
