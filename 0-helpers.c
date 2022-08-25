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
 * Return: number of chars printed
 */
int print_str(char *str)
{
	int i = 0;

	if (!str)
		return (-1);
	while (str[i])
		_putchar(str[i++]);
	return (i);
}
