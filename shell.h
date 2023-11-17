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

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define MAX_COMMAND_LEN 100
#define TOK_DELIM " \t\r\n\a"

extern char **environ;

/**
 * struct data - structure of the shell data
 * @av: arguement value
 * @input: store raw input line
 * @args: parsed arguments of the command
 * @status: an integer to store last executed command
 * @counter: to keep track of number of commands executed
 * @_environ: used to store environment variables
 * @pid: process ID
 */
typedef struct data
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} data_shell;

/**
 * struct sep_list_s - the list of separators
 * @separator: ; | &
 * @next: the string
 * Description: the purpose and usage
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - structure of line list
 * @line: list in the line
 * @next: line list
 * Description: the purpose and usage
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;

/**
 * struct builtin_s - declaring vaariables of the builtin function
 * @name: the name of the function
 * @f: the execute command
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(data_shell *datash);
} builtin_t;

/**
 * struct r_var_list - the node in linked list that hold info
 * @len_var: this stores the length of the varaiable
 * @val: pointer to a character array
 * @len_val: length of a string
 * @next: string
 * Description: the purpose and usage of the struck
 */
typedef struct r_var_list
{
	int len_var;
	char *val;
	int len_val;
	struct r_var_list *next;
} r_var;



int _putchar(char c);
int main(int ac, char **av);

char *_getenv(const char *name, char **_environ);
int _env(data_shell *datash);

r_var *add_rvar_node(r_var **head, int lvar, char *var, int lval);
void free_rvar_list(r_var **head);

int exec_line(data_shell *datash);

char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);


char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);

void rev_string(char *s);
int get_error(data_shell *datash, int eval);

void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);

void cd_dot(data_shell *datash);
void cd_to(data_shell *datash);
void cd_previous(data_shell *datash);
void cd_to_home(data_shell *datash);

int get_help(data_shell *datash);
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);

void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);

void get_sigint(int sig);

int get_len(int n);
char *aux_itoa(int n);
int _atoi(char *s);

char *copy_info(char *name, char *value);
void set_env(char *name, char *value, data_shell *datash);
int _setenv(data_shell *datash);
int _unsetenv(data_shell *datash);

int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(data_shell *datash, char *input, int i, int bool);
int check_syntax_error(data_shell *datash, char *input);

int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(data_shell *datash);
int check_error_cmd(char *dir, data_shell *datash);
int cmd_exec(data_shell *datash);

char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
void go_next(sep_list **list_s, line_list **list_l, data_shell *datash);
int split_commands(data_shell *datash, char *input);
char **split_line(char *input);

void bring_line(char **lineptr, size_t *n, char *buffer, size_t j);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

int (*get_builtin(char *cmd))(data_shell *);

char *strcat_cd(data_shell *, char *, char *, char *);
char *error_get_cd(data_shell *datash);
char *error_not_found(data_shell *datash);
char *error_exit_shell(data_shell *datash);

char *error_get_alias(char **args);
char *error_env(data_shell *datash);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(data_shell *datash);


void check_env(r_var **h, char *in, data_shell *data);
int check_vars(r_var **h, char *in, char *st, data_shell *data);
char *rep_var(char *input, data_shell *datash);

sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
line_list *add_line_node_end(line_list **head, char *line);
void free_line_list(line_list **head);

char *read_line(int *i_eof);
int cd_shell(data_shell *datash);
int exit_shell(data_shell *datash);


char *without_comment(char *in);
void shell_loop(data_shell *datash);

#endif
