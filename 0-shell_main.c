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
	shellName = argv[0];

	/* call the loop function */
	shell_loop();

	return (EXIT_SUCCESS);
}
