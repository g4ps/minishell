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
	char	*s;
	t_list	*l;
	t_list	*j;

	s = ft_strdup("echo something; tar xvf fuck ; something else");
	l = parse_line(s, envp);
	printf("All line:\n");
	print_line(l);
	printf("------\n");
	j = make_jobs(l);
	print_jobs(j);
	return 0;
}
