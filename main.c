#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"
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
	char	*s = ft_strdup("my name is : $USER |");
	free(s);
	s = ft_strdup("$USER");
	s = eval(s, envp);
	printf("%s\n", s);
	return 0;
}
