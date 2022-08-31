#include "shell.h"


char **logic_token(char *str);

int main(void)
{
	char *temp = "abc && ghi || xyz fgh";
	int i = 1;


	printf("line: %s\n\n", temp);


	char **args = logic_token(temp);
	while (args[1])
	{
		printf("Round %d\n", i++);
		printf("args[0]: %s\n", args[0]);
		printf("args[1]: %s\n", args[1]);
		printf("args[2]: %s\n", args[2]);
		printf("======={=======\n");
		free(args[0]);
		free(args[1]);
		free(args);
		args = logic_token(args[2]);
	}
	free(args[0]);
	free(args);

	return (0);
}
