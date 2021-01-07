#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"

int			is_piped(t_list *job)
{
	while (job)
	{
		if (ft_strcmp(((t_inp*)job->content)->token, "|") == 0)
			return (1);
		job = job->next;
	}
	return (0);
}

t_list		*get_last_job(t_list **l)
{
	t_list	*c;
	t_list	*prev;
	t_list	*s;
	t_list	*t;
	char	*tk;

	s = NULL;
	prev = NULL;
	t = *l;
	c = *l;
	while (c)
	{
		tk = ((t_inp*)c->content)->token;
		if (ft_strcmp(tk, "|") == 0)
		{
			t = c->next;
			s = prev;
		}
		prev = c;
		c = c->next;
	}
	prev = NULL;
	if (s)
		s->next = NULL;
	return (t);
}

int			exec_pipe(t_list *job, t_env env, char *sh, t_fds *fds)
{
	t_list	*pr_j;
	int		f[2];
	pid_t	pid;
	int		status;
	int		opt;
	t_fds	fd;

	pr_j = get_last_job(&job);
	if (pipe(f) < 0)
		return (-5);
	pid = fork();
	if (pid == 0)
	{
		close(f[0]);
		fd.out_fd = f[1];
		fd.in_fd = fds->in_fd;
		execute(job, env, sh, &fd);
	}
	else if (pid > 0)
	{
		close(f[1]);
		fd.in_fd = f[0];
		exec_job(pr_j, env, sh, &fd);
		waitpid(pid, &status, 0);
		return (WEXITSTATUS(status));
	}
	return (-6);
}
