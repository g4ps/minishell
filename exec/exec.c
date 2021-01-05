#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int	get_in_fd(t_list *job)
{
	int	ret;
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
			f = ((t_inp*)job->content)->token;
			if (job == NULL)
				return (-2);
			return (open(f, O_RDONLY));
		}
		prev = job;
		job = job->next;
	}
	return 0;
}


int	get_out_fd(t_list *job)
{
	int	ret;
	t_inp	*t;
	char	*f;
	char	*name;
	t_list	*prev;

	prev = NULL;
	while (job)
	{
		t = job->content;
		f = ((t_inp*)job->content)->token;
		if ((ft_strcmp(f, ">") == 0 || ft_strcmp(f, ">>") == 0) && !t->is_quoted)
		{
			job = job->next;
			if (prev && job)
				prev->next = job->next;
			if (job == NULL)
				return (-2);
			name = ((t_inp*)job->content)->token;
			if (ft_strcmp(f, ">") == 0)
				return (open(name, O_WRONLY | O_CREAT | O_TRUNC, 0644));
			else
				return (open(name, O_WRONLY | O_CREAT | O_APPEND, 0644));
		}
		prev = job;
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

int	run_exec(t_fds fd, t_list *job, t_list *env)
{
	pid_t	pid;
	int	status;
	char	*name;

	name = get_prog_name(job);
	name = get_path(name, env);
	if (fd.in_fd < 0 || fd.out_fd < 0)
		exit(1);
	if (name == NULL)
		return (-1);
	pid = fork();
	if (pid < 0)
		return -3;
	else if (pid != 0)
	{
		wait(&status);
		return (WEXITSTATUS(status));
	}
	else
	{
		fd.in_fd = dup2(fd.in_fd, 0);
		fd.out_fd = dup2(fd.out_fd, 1);
		execve(name, mvfl_t(job), mvfl(env));
		exit(1);
	}
}

int	exec_job(t_list *job, t_list *envp)
{
	int	ret;
	t_fds	fd;

	fd = parse_for_fds(job);
	if (is_builtin(((t_inp*)job->content)->token))
		return (run_builtin(fd, job, envp));
	ret = run_exec(fd, job, envp);
	return (ret);
}

int	exec_line(t_list *jobs, t_list *env, char *sh)
{
	int	ret;
	char	*err;

	while (jobs)
	{
		ret = exec_job(jobs->content, env);
		if (ret < 0)
		{
			err = ft_strjoin(sh, ": ");
			err = ft_strjoin(err, ((t_inp*)((t_list*)((t_list*)jobs->content)->content))->token);
			perror(err);
		}
		jobs = jobs->next;
	}
	return (ret);
}
