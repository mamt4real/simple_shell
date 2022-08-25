#include "main.h"

/**
 * strtow - split a string
 * @str: string to split
 * @delim: charcter to split str
 * Return: pointer to new or NULL
 */
char **strtow(char *str, char delim)
{
	int k, j = 0, i = 0, size = 0, lens[1200];
	char **arr;

	if (str == NULL || !(*str))
		return (NULL);
	/* calc no of words and lengths */
	for (i = 0; str[i]; i++)
	{
		/* skip delimeters */
		if (str[i] == delim)
			continue;
		/* get the word length */
		j = i;
		while (str[i] != delim && str[i])
			i++;
		if (i > j)
			lens[size++] = i - j;
		if (!str[i])
			break;
	}
	if (!size)
		return (NULL);
	/* create array of strings */
	arr = malloc((size + 1) * sizeof(char *));
	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim)
			continue;
		/* copy the word */
		arr[k] = malloc((lens[k] + 1) * sizeof(char));
		j = 0;
		while (str[i] != delim && str[i])
			arr[k][j++] = str[i++];
		arr[k++][j] = '\0';
		if (!str[i])
			break;
	}
	arr[size] = NULL;
	return (arr);
}
