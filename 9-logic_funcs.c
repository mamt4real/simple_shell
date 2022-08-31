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
