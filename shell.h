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

int _isalpha(int c);
int _atoi(char *s);

int _putchar(char c);
int _setenv(const char *name, const char *value, int overwrite);

char *_strncpy(char *dest, char *src, int n);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);

int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
char *read_line(void);

#endif
