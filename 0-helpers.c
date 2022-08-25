#include "main.h"

/**
 * _putchar - print a character
 * @c: character to print
 * Return: 0
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string
 *
 * @str: pointer to string
 * @fd: file descriptor to print to
 * Return: number of chars printed
 */
int print_str(char *str, int fd)
{
	if (!str)
		return (-1);
	return (write(fd, str, _strlen(str)));
}
