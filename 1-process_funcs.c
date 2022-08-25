#include "shell.h"

/**
 * shell_loop - read a line(user input)
 *			check if the shell should be ran interactively or not
 *			remove comments from line if any
 *			parse or tokenize the read line
 *			execute the parsed command
 *			runs infinitely unless user types exit or CTRL-D
 */

void shell_loop(void)
{
	char *line;
	char **args, **command;
	int status, i = 0, command_type = 0;

	/* handle program interruption if CTRL-C is pressed */
	signal(SIGINT, ctrl_C_func);
	
	do {
		non_interractive();
		_printf(" ($) ", STDOUT_FILENO);
		line = shell_readline();
		remove_comment(line);

		args = tokenize(line, ";");

		while (args[i])
		{
			command = tokenize(args[i++], DELIM);
			if (!(command[0]))
			{
				free(command);
				break;
			}
			command_type = check_cmd_type(command[0]);
			status = shell_execute(command, command_type);
			free(command);
		}
		free(args);

	} while (status);

	free(line);
}


/**
 * non_interractive - runs the shell in non interactive mode
 */

void non_interractive(void)
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
				free(command);
				break;
			}
			command_type = check_cmd_type(command[0]);
			status = shell_execute(command, command_type);
			free(command);
		}
		free(args);
		free(line);
		exit(status);
	}
}

/**
 * tokenize - split a line into an array of strings
 * @line: the command read from the user
 * @delim: delimeter for spliting the word
 *
 * Return: an array of strings on success
 */

char **tokenize(char *line, char *delim)
{
	int position = 0, bufsize = TOK_BUFSIZE;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		perror("Unable to allocate buffer");
		exit(EXIT_FAILURE);
	}

	token = _strtok(line, delim);
	
	while (token)
	{
		tokens[position++] = token;

		if (position >= bufsize)
		{
			bufsize += TOK_BUFSIZE;
			tokens = _realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				perror("Unable to reallocate memory");
				exit(EXIT_FAILURE);
			}
		}

		token = _strtok(NULL, delim);
	}
	tokens[position] = NULL;
	return (tokens);
}
