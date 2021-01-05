#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"
#include <unistd.h>

void	print_vec(char **vec)
{
	while (*vec)
	{
		printf("%s\n", *vec);
		vec++;
	}
}

int main(int argc, char **argv, char **envp)
{
	char *ls = get_path(argv[1], envp);
	if (ls)
		printf("%s\n", ls);
	else
		printf("couldn't find the program\n");
	free(ls);
	return 0;
}
