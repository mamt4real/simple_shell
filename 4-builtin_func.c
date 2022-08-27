#include "shell.h"

#define SETPWD(V) (V = _strdup(_getenv("OLDPWD")))
/**
 * ch_dir - handles change directory command (cd)
 * @command: command enterd, not used
 * @var: shell global variable
 */

void ch_dir(char **command, shell_t *var)
{
	char *home;
	home = _getenv("HOME");
	
	if (command[1] == NULL)
	{
		SETPWD(var->old_pwd);
		if (chdir(home) < 0)
			exit(EXIT_FAILURE);
	}
	else if (_strcmp(command[1],  "-") == 0)
	{
		if (var->old_pwd == NULL)
		{
			SETPWD(var->old_pwd);
			if (chdir(home) < 0)
				exit(EXIT_FAILURE);
		}
		else
		{
			SETPWD(var->old_pwd);
			if (chdir(var->old_pwd) < 0)
				exit(EXIT_FAILURE);
		}

	}
	else
	{
		SETPWD(var->old_pwd);
		if (chdir(command[1]) < 0)
			exit(EXIT_FAILURE);
	}

}

#undef GETCWD
/**
 * display_help - display help necessary help and docs for the shell
 * @command: command passed
 * @p: shell global variable
 */

void display_help(char **command, shell_t *p)
{
	(void) command;
	(void) p;
}


/**
 * env - prints the current_environnement
 * @tokenized_command: command entered
 * @p: shell global variable
 *
 */

void env(char **tokenized_command __attribute__((unused)),
		shell_t *p __attribute__((unused)))
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		_printf(environ[i], STDOUT_FILENO);
		_printf("\n", STDOUT_FILENO);
	}
}

/**
 * quit - exits the shell
 * @tokenized_command: command entered
 * @p: shell global variable
 *
 */

void quit(char **tokenized_command, shell_t *p)
{
	int num_token = 0, arg;

	for (; tokenized_command[num_token] != NULL; num_token++)
		;
	if (num_token == 1)
	{
		free_tokenized(tokenized_command);
		exit(1);
	}
	else if (num_token == 2)
	{
		arg = _atoi(tokenized_command[1]);
		if (arg == -1)
		{
			_printf(p->shell_name, STDERR_FILENO);
			_printf(": 1: exit: Illegal number: ", STDERR_FILENO);
			_printf(tokenized_command[1], STDERR_FILENO);
			_printf("\n", STDERR_FILENO);
			exit(2);
		}
		else
		{
			free_tokenized(tokenized_command);
			exit(arg);
		}
	}
	else
		_printf("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
