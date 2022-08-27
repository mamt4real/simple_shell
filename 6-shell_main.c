#include "shell.h"

/**
 * main - the main function that starts the shell
 *			and calls the shell_loop function
 *
 * @argc: arguement count passed to main attribute unused
 * @argv: character array passed to the main function
 *
 * Return: 1 on success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	shell_t var;

	var.shell_name = argv[0];
	var.old_pwd = NULL;

	/* call the loop function */
	shell_loop(&var);

	return (EXIT_SUCCESS);
}
