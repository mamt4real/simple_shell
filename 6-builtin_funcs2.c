#include "shell.h"

/**
 * handle_setenv - sets an environment var
 * @args: command entered
 * @p: shell global variable
 *
 */
void handle_setenv(char **args, shell_t *p)
{
	int i = 0;

	while (args[i])
		i++;
	if (i != 3 || !args[1] || !args[2])
	{
		p->err_status = -1;
		print_error(args, p);
		return;
	}
	i = _setenv(args[1], args[2]);
	if (i)
		_printf("setenv: invalid arguments\n", STDERR_FILENO);

	p->err_status = 0;
}

/**
 * handle_unsetenv - unsets an environment var
 * @args: command entered
 * @p: shell global variable
 *
 */
void handle_unsetenv(char **args, shell_t *p)
{
	int i = 0;

	while (args[i])
		i++;
	if (i != 2 || !args[1])
	{
		p->err_status = -1;
		print_error(args, p);
		return;
	}
	i = _unsetenv(args[1]);
	if (i)
	{
		p->err_status = -1;
		print_error(args, p);
		return;
	}

	p->err_status = 0;
}

/**
 * aliasFunc - handles aliases for commands
 * @args: command entered
 * @p: shell global variable
 *
 */
void aliasFunc(char **args, shell_t *p)
{
	(void)args;
	(void)p;
}
