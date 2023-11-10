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

#define MAX_INPUT_SIZE 1024

void execute_command(char *command);
int main(int argc, char *argv[]);
int _isalpha(int c);
int _atoi(char *s);
void _puts(char *str);

















































#endif
