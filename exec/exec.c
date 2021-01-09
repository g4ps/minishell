#include <stdlib.h>
#include <signal.h>
#include "libft.h"
#include "minishell.h"

int			get_in_fd(t_list *job)
{
	int		ret;
	t_inp	*t;
	t_list	*prev;
	char	*f;

	prev = NULL;
	while (job)
	{
		t = job->content;
		f = ((t_inp*)job->content)->token;
		if (ft_strcmp(f, "<") == 0 && !t->is_quoted)
		{
			job = job->next;
			if (prev && job)
				prev->next = job->next;
			if (job == NULL || !prev || !job)
				return (-2);
			f = ((t_inp*)job->content)->token;
			ret = open(f, O_RDONLY);
			return (ret);
			if (ret < 0)
				return (-4);
		}
		prev = job;
		job = job->next;
	}
	return (0);
}

int			get_out_fd(t_list *job)
{
	int		ret;
	t_inp	*t;
	char	*f;
	char	*name;
	t_list	*prev;

	prev = NULL;
	while (job)
	{
		t = job->content;
		f = ((t_inp*)job->content)->token;
		if ((ft_strcmp(f, ">") == 0 || ft_strcmp(f, ">>") == 0) \
		&& !t->is_quoted)
		{
			job = job->next;
			if (prev && job)
				prev->next = job->next;
			if (job == NULL || !prev || !job)
				return (-1);
			name = ((t_inp*)job->content)->token;
			if (ft_strcmp(f, ">") == 0)
				return (open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644));
			else
				return (open(name, O_WRONLY | O_CREAT | O_APPEND, 0644));
		}
		prev = job;
		job = job->next;
	}
	return (0);
}

t_fds		parse_for_fds(t_list *job, t_fds *fd)
{
	t_fds	ret;

	ret.in_fd = get_in_fd(job);
	ret.out_fd = get_out_fd(job);
	if (ret.in_fd == 0)
		ret.in_fd = fd->in_fd;
	if (ret.out_fd == 0)
		ret.out_fd = fd->out_fd;
	return (ret);
}

int			is_builtin(char *s)
{
	if (ft_strcmp(s, "echo") == 0 ||
		ft_strcmp(s, "cd") == 0 ||
		ft_strcmp(s, "pwd") == 0 ||
		ft_strcmp(s, "export") == 0 ||
		ft_strcmp(s, "unset") == 0 ||
		ft_strcmp(s, "env") == 0 ||
		ft_strcmp(s, "exit") == 0)
		return (1);
	return (0);
}

int			run_builtin(t_fds fd, t_list *job, t_env envp)
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
	return (0);
}

int			run_exec(t_fds fd, t_list *job, t_list *env, char *sh)
{
	pid_t	pid;
	int		status;
	char	*name;

	name = get_prog_name(job);
	name = get_path(name, env);
	if (fd.in_fd < 0 || fd.out_fd < 0)
		return (-1);
	if (name == NULL)
		return -2;
	pid = fork();
	if (pid > 0)
	{
		free(name);
		signal(SIGINT, f);
		waitpid(pid, &status, 0);
		signal(SIGINT, f1);
		return (WEXITSTATUS(status));
	}
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
	t_list		*e;
	int		p;

	if ((p = is_piped(job)) > 0)
		return (exec_pipe(job, env, sh, fds));
	else if ( p == 0)
	{
		e = list_comb(env);
		ret = -1;
		*fds = parse_for_fds(job, fds);
		if (is_builtin(((t_inp*)job->content)->token))
			ret =  run_builtin(*fds, job, env);
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
	return -5;
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
			ret =  run_builtin(*fds, job, env);
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
	char	*err;
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
