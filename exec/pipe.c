#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"

int	is_piped(t_list *job)
{
	while (job)
	{
		if (ft_strcmp(((t_inp*)job->content)->token, "|") == 0)
			return 1;
		job = job->next;
	}
	return 0;
}

t_list	*get_prev_job(t_list **l)
{
	t_list	*c;
	t_list	*prev;
	t_list	*s;
	char	*tk;

	s = *l;
	prev = NULL;
	c = *l;
	while (c)
	{
		tk = ((t_inp*)c->content)->token;
		if (ft_strcmp(tk, "|") == 0)
		{
			if (prev == NULL)
				return NULL;
			prev->next = NULL;
			*l = c->next;
			return (s);
		}
		prev = c;
		c = c->next;
	}
	return (s);
}

int	exec_pipe(t_list *job, t_env env, char *sh, t_fds fds)
{
	t_list	*pr_j;
	int	f[2];
	pid_t	pid;
	int	status;
	int	opt;

	pr_j = get_prev_job(&job);
	if (pipe(f) < 0)
		return (-5);
	pid = fork();
	if (pid == 0)
	{
		close(f[1]);
		dup2(f[0], 0);
		exit(exec_job(pr_j, env, sh, fds));
	}
	else if (pid > 0)
	{
		close(f[0]);
		fds.out_fd = f[1];
		exec_job(job, env, sh, fds);
		waitpid(pid, &status, 0);
		return WEXITSTATUS(status);
	}
	return -6;
}
