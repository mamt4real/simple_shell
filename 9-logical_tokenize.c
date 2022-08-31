#include "shell.h"

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
