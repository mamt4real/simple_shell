#include "shell.h"
#include <stdio.h>

void print_arr(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
		printf("%s\n", arr[i++]);
}

int main(int a, char **b, char **c)
{
	const char *d = " :\r\t;\n";
	char *s = "hello world lawal",
	     *s2 = "abc;geh ijk\txyz",
	      *path = getenv("PATH");

	print_arr(_strtok(s, d));
	print_arr(_strtok(s2, d));
	print_arr(_strtok(path, d));
	print_arr(c);

	return (0);
}
