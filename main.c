#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"
#include <unistd.h>

void	run_prompt()
{
	ft_putstr_fd("> ", 1);
}

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
	t_list	*env;
	t_list	*l;
	t_list	*j;
	size_t	t;
	int	i = 0;

	t = 8096;
	env = make_list_from_vector(envp);
	while (1)
	{
		s = NULL;
		run_prompt();
		getline(&s, &t, stdin);
		while (s[i] != '\n' && s[i] != '\0')
			i++;
		s[i] = '\0';
		l = parse_line(s, env);
		j = make_jobs(l);
		if (l)
			exec_job(l, env);
		free(s);
	}
}
