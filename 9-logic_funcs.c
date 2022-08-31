#include "shell.h"


/**
 * execute_norm - Handles execution without logical && or ||
 * @args: command arguement to be executed
 * @var: global shell variable
 *
 * Return; 
 */

int execute_norm(char *args, shell_t *var)
{
	char **command;
	int command_type, status;

	command = tokenize(args, DELIM);
	if (!(command[0]))
	{
		free(command);
		return (0);
	}
	command_type = check_cmd_type(command[0]);
	status = shell_execute(command, command_type, var);
	free_tokenized(command);
	free(args);
	return (status);
}

/**
 * execute_and - Handles execution with logical &&
 * @args: command arguement to be executed
 * @var: global shell variable
 *
 * Return; 
 */

int execute_and(char *args, shell_t *var)
{
	(void)args;
	(void)var;

	return (0);
}

/**
 * execute_or - Handles execution with logical ||
 * @args: command arguement to be executed
 * @var: global shell variable
 *
 * Return; 
 */

int execute_or(char *args, shell_t *var)
{
	(void)args;
	(void)var;

	return (0);
}

/**
 * logic_token - split a string base on a string
 * @str: string to split
 * Return: pointer to new or NULL
 */
char **logic_token(char *str)
{
	int j = 0, i = 0;
	char **res;

	if (!str)
		return (0);
	res = malloc(3 * sizeof(char *));
	for (; str[i]; i++)
	{
		j = startsWith(str + i, "&&");
		if (j)
		{
			res[0] = _strndup(str, i);
			res[1] = _strdup("&&");
			res[2] = str + i + j;
			return (res);
		}
		j = startsWith(str + i, "||");
		if (j)
		{
			res[0] = _strndup(str, i);
			res[1] = _strdup("||");
			res[2] = str + i + j;
			return (res);
		}
	}
	res[0] = _strdup(str);
	res[1] = 0;
	res[2] = 0;
	return (res);
}
