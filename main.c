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

	s = ft_strdup("echo something  '||| HH |||' \"my name is : $USER\"   'Something'  $USER");
	l = parse_line(s, envp);
	print_line(l);
	return 0;
}
