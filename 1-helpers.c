#include "shell.h"

/**
 * _strcat - concatenates src to destination
 * @src: pointer to the source string
 * @dst: pointer to the destination string
 * Return: pointer to destination
 */

char *_strcat(char *dst, char *src)
{
	int x = 0, y = 0;

	if (!dst || !src)
		return (dst);
	/* Get the length of destination */
	while (dst[y])
		y++;
	/* concatenate */
	while (src[x])
	{
		dst[y++] = src[x];
		x++;
	}
	dst[y] = '\0';
	return (dst);
}
