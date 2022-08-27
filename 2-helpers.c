#include "shell.h"

/**
 * remove_comment - removes/ignores everything after a '#' char
 * @input: input to be used
 *
 * Return: void
 */
void remove_comment(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}


/**
 * _realloc - reallocate memory to a buffer
 * @ptr: pointer to buffer
 * @old_size: old size of buffer
 * @new_size: new size of buffer
 * Return: pointer to the new buffer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min;
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));
	else if (!new_size)
	{
		free(ptr);
		return (NULL);
	}
	if (old_size == new_size)
		return (ptr);
	min = (old_size > new_size) ?
		new_size :
		old_size;
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);
	for (i = 0; i < min; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	free(ptr);
	return (new_ptr);
}

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
 * @file
 * Return: pointer to full path
 */
char *check_path(char *file)
{
	char *path, *tmp, **paths, *res = 0;
	int i = 0;

	path = _getenv("PATH");
	if (!path || !(_strlen(path)))
		return (0);
	paths = tokenize(path, ":");
	if (!paths)
		return (0);
	res = malloc(_strlen(path) + _strlen(file) + 2);
	for (; paths[i] && res; i++)
	{
		tmp = _strcat(paths[i], "/");
		res = _strcat(tmp, file);
		if (access(res, F_OK) == 0)
		{
			free(paths);
			return(res);
		}
	}
	free_tokenized(paths, i);
	return (res);
}
