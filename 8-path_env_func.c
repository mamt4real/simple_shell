#include "shell.h"

/**
 * _getenv - gets an environment variable
 *
 * @key: key of the variable
 * Return: address of value of key if found
 * null if not found
 */
char *_getenv(char *key)
{
	char **envs;
	int i, j;

	if (!key)
		return (0);
	for (i = 0, envs = environ; envs[i]; i++)
	{
		j = startsWith(envs[i], key);
		if (j)
			return (envs[i] + 1 + j);
	}
	return (0);
}


/**
 * check_path - find the path of a cmd
 *
 * @file: the command to find its full path
 * Return: pointer to full path
 */
char *check_path(char *file)
{
	char *path, **paths, *res = NULL;
	int i = 0;

	path = _getenv("PATH");
	if (!path || !(_strlen(path)))
		return (0);
	paths = tokenize(path, ":");
	if (!paths)
		return (0);
	for (; paths[i]; i++)
	{
		res = malloc(_strlen(paths[i]) + _strlen(file) + 2);
		res[0] = '\0';
		res = _strcat(res, paths[i]);
		res = _strcat(res, "/");
		res = _strcat(res, file);
		if (access(res, F_OK) == 0)
		{
			free(paths);
			return (res);
		}
		free(res);
		res = 0;
	}
	free_tokenized(paths);
	return (res);
}
