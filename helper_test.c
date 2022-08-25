#include "shell.h"
#include <stdio.h>

void print_arr(char **arr)
{
	int i = 0;

	if (!arr)
		return;
	while (arr[i])
		printf("%s\n", arr[i++]);
	free_tokenized(arr);
}

int main(int a, char **b, char **c)
{
	char *d = " :\r\t;\n";
	char *s = "hello world lawal",
	     *s2 = "abc;geh ijk\txyz",
	      *path = getenv("PATH");

	print_arr(tokenized(s, d));
	print_arr(tokenized(s2, d));
	print_arr(tokenized(path, d));
	printf(">> %d\n", startsWith(s, "hel"));
	printf("<< %d\n", endsWith(s, "wal"));
	printf(">> %d\n", startsWith(s, "gar"));
	printf("<< %d\n", endsWith(s, "isa"));

	return (0);
}
