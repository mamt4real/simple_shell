#include "shell.h"
#include <stdio.h>

void print_arr(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
		printf("%s\n", arr[i++]);
	free_tokenized(arr, -1);
}

int main(int a, char **b, char **c)
{
	environ = c;
	char *d = " :\r\t;\n";
	char *s = "hello world lawal",
	     *s2 = "abc;geh ijk\txyz",
	      *path = getenv("PATH");

	print_arr(tokenize(s, d));
	print_arr(tokenize(s2, d));
	print_arr(tokenize(path, d));
	printf(">> %d\n", startsWith(s, "hel"));
	printf("<< %d\n", endsWith(s, "wal"));
	printf(">> %d\n", startsWith(s, "gar"));
	printf("<< %d\n", endsWith(s, "isa"));
	printf("PATH: %s\n", _getenv("PATH"));
	printf("ls: %s\n", check_path("ls"));

	return (0);
}
