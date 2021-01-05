#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int	get_in_fd(t_list *job)
{
	int	ret;
	t_inp	*t;
	char	*f;

	while (job)
	{
		f = job->content;
		if (ft_strcmp(f, "<") == 0 && !t->is_quoted)
		{
			job = job->next;
			if (job == NULL)
				return (-2);
			return (open(job->content, O_RDONLY));
		}
		job = job->next;
	}
	return 0;
}


int	get_out_fd(t_list *job)
{
	int	ret;
	t_inp	*t;
	char	*f;

	while (job)
	{
		f = job->content;
		if ((ft_strcmp(f, ">") == 0 || ft_strcmp(f, ">>") == 0) && !t->is_quoted)
		{
			job = job->next;
			if (job == NULL)
				return (-2);
			if (ft_strcmp(f, ">") == 0)
				return (open(job->content, O_WRONLY | O_CREAT | O_TRUNC, 0644));
			else
				return (open(job->content, O_WRONLY | O_CREAT | O_APPEND, 0644));
		}
		job = job->next;
	}
	return 1;
}

t_fds	parse_for_fds(t_list *job)
{
	t_fds	ret;

	ret.in_fd = get_in_fd(job);
	ret.out_fd = get_out_fd(job);
	return (ret);
}

int	is_builtin(char *s)
{
	if (ft_strcmp(s, "echo") == 0 ||
		ft_strcmp(s, "cd") == 0 ||
		ft_strcmp(s, "pwd") == 0 ||
		ft_strcmp(s, "export") == 0 ||
		ft_strcmp(s, "unset") == 0 ||
		ft_strcmp(s, "env") == 0 ||
		ft_strcmp(s, "exit") == 0)
		return 1;
	return 0;
}

int	run_builtin(t_fds fd, t_list *job, t_list *envp)
{
	char	*l;

	l = ((t_inp*)job->content)->token;
	if (ft_strcmp(l, "echo") == 0)
		return (run_echo(fd, job->next, envp));
	else if (ft_strcmp(l, "cd") == 0)
		return (run_cd(fd, job->next, envp));
	else if (ft_strcmp(l, "pwd") == 0)
		return (run_pwd(fd, job->next, envp));
	else if (ft_strcmp(l, "export") == 0)
		return (run_export(fd, job->next, envp));
	else if (ft_strcmp(l, "unset") == 0)
		return (run_unset(fd, job->next, envp));
	else if (ft_strcmp(l, "env") == 0)
		return (run_env(fd, job->next, envp));
	else if (ft_strcmp(l, "exit") == 0)
		return (run_exit(fd, job->next, envp));
	return 0;
}

int	exec_job(t_list *job, t_list *envp)
{
	t_fds	fd;

	fd = parse_for_fds(job);
	if (is_builtin(((t_inp*)job->content)->token))
		return (run_builtin(fd, job, envp));
	return 0;
}
