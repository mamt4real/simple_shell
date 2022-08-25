#ifndef SHELL_H
#define SHELL_H

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

/* other utility header for basic functions and macros */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define delimeter */
#define DELIM " \t\r\n\a"

/* token size and line read size */
#define RL_BUFSIZE 1024
#define TOK_BUFSIZE 64

/* shell utility functions */
void ctrl_C_func(int);

/* shell process funtions */
void shell_loop(void);
void non_interractive(void);
char **tokenized(char *, char *);

/* helper functions */
int _printf(char *, int);
void remove_comment(char *);
void *_realloc(char *, unsigned int);
int _putchar(char);
int _strlen(char *);
int startsWith(char *s, char *ndl);
int endsWith(char *s, char *ndl);
char *_strdup(char *s);
void free_tokenized(char **tokens);
char *_getenv(char *);
char *check_path(char *);
#endif /* SHELL_H */
