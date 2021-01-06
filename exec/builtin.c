#include "libft.h"
#include "minishell.h"
#include <unistd.h>

int			run_echo(t_fds fd, t_list *job, t_env env)
{
	char	*k;
	t_list	*envp;

	envp = list_comb(env);
	while (job)
	{
		k = ((t_inp*)job->content)->token;
		ft_putstr_fd(k, fd.out_fd);
		ft_putstr_fd(" ", fd.out_fd);
		job = job->next;
	}
	ft_putstr_fd("\n", fd.out_fd);
	return (0);
}

int			run_cd(t_fds fd, t_list *job, t_env env)
{
	int		ret;
	char	*k;
	t_list	*envp;

	envp = list_comb(env);
	k = ((t_inp*)job->content)->token;
	ret = 0 - chdir(k);
	return (ret);
}

int			run_pwd(t_fds fd, t_list *job, t_env env)
{
	char	*k;
	t_list	*envp;

	envp = list_comb(env);
	k = getcwd(NULL, 0);
	ft_putstr_fd(k, fd.out_fd);
	ft_putstr_fd("\n", fd.out_fd);
	return (0);
}

int			run_export(t_fds fd, t_list *job, t_env env)
{
	return (0);
}

int			run_unset(t_fds fd, t_list *job, t_env env)
{
	return (0);
}

int			run_env(t_fds fd, t_list *job, t_env env)
{
	t_list	*envp;

	print_list(env.envp);
	return (0);
}

int			run_exit(t_fds fd, t_list *job, t_env env)
{
	int		k;
	char	*s;

	if (job)
	{
		s = ((t_inp*)job->content)->token;
		k = ft_atoi(s);
	}
	else
		k = 0;
	exit(k);
}
