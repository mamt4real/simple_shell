#include "shell.h"


void print_error(char **commands, shell_t *build)
{
	if (_strcmp(commands[0], "exit") == 0)
	{
		exit_error(commands, build);
	}
	else if (_strcmp(commands[0], "cd") == 0)
	{
		chdir_error(commands, build);
	}
	else if (_strcmp(commands[0], "env") == 0)
	{
		env_error(commands, build);
	}
	else
	{
		invalid_cmd_error(commands, build);
	}

}
