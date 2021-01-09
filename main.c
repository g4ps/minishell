#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include "minishell.h"
#include "libft.h"
#include <unistd.h>

void		run_prompt()
{
	ft_putstr_fd("> ", 1);
}

void		print_vec(char **vec)
{
	while (*vec)
	{
		printf("%s\n", *vec);
		vec++;
	}
}

void		f1(int k)
{
	ft_putstr_fd("\n", 1);
	run_prompt();
}

void		f(int k)
{
}

void		my_exit(int i)
{
	ft_putstr_fd(" exit\n", 1);
	exit(0);
}

void		signal_setup()
{
	signal(SIGQUIT, f);
	signal(SIGINT, f1);
}

int			main(int argc, char **argv, char **envp)
{
	char	*s;
	t_list	*env_p;
	t_list	*l;
	t_env	env;
	t_list	*j;
	t_list	*vars;
	t_list	*e;
	int		last_ret;

	env_p = make_list_from_vector(envp);
	vars = init_vars(argv);
	env.envp = env_p;
	env.vars = vars;
	signal_setup();
	while (1)
	{
		e = list_comb(env);
		s = NULL;
		run_prompt();
		if (get_next_line(0, &s) == 0)
			my_exit(0);
		l = parse_line(s, e);
		j = make_jobs(l);
		if (l && j)
			last_ret = exec_line(j, env, argv[0]);
		ft_lstclear(&l, del_inp);
		ft_lstclear(&e, free);
		del_jobs(j);
		free(s);
		update_return(&vars, last_ret);
	}
}
