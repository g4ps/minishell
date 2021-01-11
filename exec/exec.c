/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:53:18 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:11:06 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "libft.h"
#include "minishell.h"

int			run_exec_help(char *name, pid_t pid)
{
	int		status;

	free(name);
	signal(SIGINT, f);
	waitpid(pid, &status, 0);
	signal(SIGINT, f1);
	return (WEXITSTATUS(status));
}

int			run_exec(t_fds fd, t_list *job, t_list *env, char *sh)
{
	pid_t	pid;
	char	*name;

	name = get_prog_name(job);
	name = get_path(name, env);
	if (fd.in_fd < 0 || fd.out_fd < 0)
		return (-1);
	if (name == NULL)
		return (-2);
	pid = fork();
	if (pid > 0)
		return (run_exec_help(name, pid));
	else if (pid == 0)
	{
		fd.in_fd = dup2(fd.in_fd, 0);
		fd.out_fd = dup2(fd.out_fd, 1);
		if (execve(name, mvfl_t(job), mvfl(env)) < 0)
		{
			print_err(-4, sh, name);
			exit(1);
		}
	}
	return (-3);
}

int			exec_job(t_list *job, t_env env, char *sh, t_fds *fds)
{
	int		ret;
	t_list	*e;
	int		p;

	if ((p = is_piped(job)) > 0)
		return (exec_pipe(job, env, sh, fds));
	else if (p == 0)
	{
		e = list_comb(env);
		ret = -1;
		*fds = parse_for_fds(job, fds);
		if (is_builtin(((t_inp*)job->content)->token))
			ret = run_builtin(*fds, job, env);
		else if (is_set_var(job))
			ret = set_var(job, env);
		else
			ret = run_exec(*fds, job, env.envp, sh);
		if (ret < 0)
			print_err(ret, sh, get_prog_name(job));
		ft_lstclear(&e, free);
		return (ret);
	}
	print_err(-5, sh, get_prog_name(job));
	return (-5);
}

int			execute(t_list *job, t_env env, char *sh, t_fds *fds)
{
	int		ret;
	int		p;

	signal(SIGQUIT, f);
	if ((p = is_piped(job)) > 0)
	{
		exit(exec_pipe(job, env, sh, fds));
	}
	else if (p == 0)
	{
		ret = -1;
		*fds = parse_for_fds(job, fds);
		if (is_builtin(((t_inp*)job->content)->token))
			ret = run_builtin(*fds, job, env);
		else if (is_set_var(job))
			ret = set_var(job, env);
		else
			ret = run_exec(*fds, job, env.envp, sh);
		if (ret < 0)
			print_err(ret, sh, get_prog_name(job));
		exit(ret);
	}
	exit(1);
}

int			exec_line(t_list *jobs, t_env env, char *sh)
{
	int		ret;
	char	*p_name;
	t_list	*t;
	t_fds	fd;

	fd.in_fd = 0;
	fd.out_fd = 1;
	while (jobs)
	{
		p_name = ((t_inp*)((t_list*)jobs->content)->content)->token;
		ret = exec_job(jobs->content, env, sh, &fd);
		t = jobs;
		jobs = jobs->next;
	}
	return (ret);
}
