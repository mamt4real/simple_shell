#include "shell.h"

/**
 * shell_loop - read a line(user input)
 *			check if the shell should be ran interactively or not
 *			remove comments from line if any
 *			parse or tokenize the read line
 *			execute the parsed command
 *			runs infinitely unless user types exit or CTRL-D
 * @var: shell global variable
 */

void shell_loop(shell_t *var)
{
	char *line, *op;
	char **args, **logic_cmd;
	int status, i;

	/* handle program interruption if CTRL-C is pressed */
	signal(SIGINT, ctrl_C_func);
	do {
		i = 0;
		non_interractive(var);
		_printf(" ($) ", STDOUT_FILENO);
		line = shell_readline();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				break;
		}
		remove_comment(line);
		args = tokenize(line, ";");
		while (args[i])
		{
			logic_cmd = logic_token(args[i++]);
			op = logic_cmd[1];
			
			if (!op)
				status = execute_norm(logic_cmd[0], var);

			else if (_strcmp(op, AND_DELIM) == 0)
			{
				status = execute_and(logic_cmd[0], var);
				if (status > 0)
					logic_cmd = logic_token(logic_cmd[2]);
				else
					break;
			}
			else
			{
				status = execute_or(logic_cmd[0], var);
				if (status < 0)
					logic_cmd = logic_token(logic_cmd[2]);
				else
					break;
			}
			free(op);
		}
		free_tokenized(args);
	} while (status);
	free(line);
}


/**
 * non_interractive - runs the shell in non interactive mode
 * @p: shell Global variable
 */

void non_interractive(shell_t *p)
{
	char **args, **command;
	char *line;
	int i = 0, command_type = 0, status;

	if (isatty(STDIN_FILENO) == 0)
	{
		line = shell_readline();
		remove_comment(line);
		args = tokenize(line, ";");
		while (args[i])
		{
			command = tokenize(args[i++], DELIM);
			if (!(command[0]))
			{
				free_tokenized(command);
				break;
			}
			command_type = check_cmd_type(command[0]);
			status = shell_execute(command, command_type, p);
			free_tokenized(command);
		}
		free_tokenized(args);
		free(line);
		exit(status);
	}
}


/**
 * check_cmd_type - determines the type of the command
 * @command: command to be checked
 *
 * Return: constant variable representing the type of command
 */

int check_cmd_type(char *command)
{
	char *internal_cmd[] = {"exit", "cd", "help", "env", NULL};
	char *path = NULL;
	int i = 0;

	while (command[i])
	{
		if (command[i++] == '/')
			return (TERM_CMD);
	}
	for (i = 0; internal_cmd[i]; i++)
	{
		if (_strcmp(command, internal_cmd[i]) == 0)
			return (INTERNAL_CMD);
	}
	path = check_path(command);
	if (path)
	{
		free(path);
		return (PATH_CMD);
	}
	return (INVALID_CMD);
}

/**
 * shell_execute - launches the command to be executed
 * @command: command to be launched
 * @cmd_type: type of the command to be executed
 * @var: struct for shell name and old path
 * Return: 1 always
 */
int shell_execute(char **command, int cmd_type, shell_t *var)
{
	pid_t PID;
	int status;

	if (cmd_type == PATH_CMD || cmd_type == TERM_CMD)
	{
		PID = fork();
		if (PID == 0)
		{
			shell_launch(command, cmd_type, var);
		}
		else if (PID < 0)
		{
			perror("Error Creating fork");
			return (1);
		}
		else
			waitpid(PID, &status, WUNTRACED);
		return (1);
	}
	else
		shell_launch(command, cmd_type, var);
	return (1);
}
