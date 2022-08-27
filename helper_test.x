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
	environ = c;
	char *d = " :\r\t;\n";
	char *s = "hello world lawal",
	     *s2 = "abc;geh ijk\txyz",
	      *path = getenv("PATH"),
	      *tmp;

	print_arr(tokenize(s, d));
	print_arr(tokenize(s2, d));
	print_arr(tokenize(path, d));
	printf(">> %d\n", startsWith(s, "hel"));
	printf("<< %d\n", endsWith(s, "wal"));
	printf(">> %d\n", startsWith(s, "gar"));
	printf("<< %d\n", endsWith(s, "isa"));

	printf("PATH: %s\n", _getenv("PATH"));
	tmp = check_path("ls");
	printf("ls: %s\n", tmp);
	free(tmp);
	return (0);
}
