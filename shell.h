#ifndef SHELL_H
#define SHELL_H

/* other utility header for basic functions and macros */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * header - The header below is used for the following function and system call
 *
 * chdir()
 * fork()
 * execve()
 * pid_t()
 */
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

/* ANSI C signal handling */
#include <signal.h>

/* header file for waitpid and associated macros */
#include <sys/wait.h>

#include <errno.h>
#include <dirent.h>
/* define the type of command */
#define TERM_CMD 1
#define PATH_CMD 2
#define INTERNAL_CMD 3
#define INVALID_CMD -1

/* define delimeter */
#define DELIM " \t\r\n\a"

/* token size and line read size */
#define RL_BUFSIZE 1024
#define TOK_BUFSIZE 64

/* shell utility functions */
void ctrl_C_func(int);
char *shell_readline(void);
void shell_launch(char **, int);
int shell_execute(char **, int);
void (*get_func(char *))(char **);

/* declare global variable */
extern char **environ;
extern char *shellName;

/**
 * struct mapFunc - maps a command to a function
 * @command_name: name of command
 * @func: the function that executes the command
 */
typedef struct map
{
	char *command_name;
	void (*func)(char **command);
} function_map;


/* shell process funtions */
void shell_loop(void);
void non_interractive(void);
int check_cmd_type(char *);
int shell_execute(char **, int);

/* helper functions */
int _printf(char *, int);
void remove_comment(char *);
void *_realloc(void *, unsigned int, unsigned int);
int _putchar(char);
int _strlen(char *);
int _strcmp(char *, char *);
int _atoi(char *);
char *_strcat(char *dst, char *src);

/* builtin funct */
void env(char **);
void quit(char **);

/* function to handle tokenization */

char **tokenize(char *, const char *);
int startsWith(char *s, char *ndl);
int endsWith(char *s, char *ndl);
char *_strdup(char *s);
void free_tokenized(char **tokens, int);

/* Environmemt Functions */
char *_getenv(char *);
char *check_path(char *);

#endif /* SHELL_H */
