/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:53:30 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:15:56 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>
#include "minishell.h"

int			is_piped(t_list *job)
{
	while (job)
	{
		if (ft_strcmp(((t_inp*)job->content)->token, "|") == 0)
		{
			if (!job->next)
				return (-1);
			if (ft_strcmp(((t_inp*)job->next->content)->token, "|") == 0)
				return (-1);
			return (1);
		}
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

	s = NULL;
	prev = NULL;
	t = *l;
	c = *l;
	while (c)
	{
		if (ft_strcmp(((t_inp*)c->content)->token, "|") == 0)
		{
			t = c->next;
			s = prev;
		}
		prev = c;
		c = c->next;
	}
	if (s)
		s->next = NULL;
	prev = make_new_job(t, s->next);
	ft_lstclear(&(s->next), del_inp);
	return (prev);
}

int			exec_pipe_help(t_list *pr_j, pid_t pid, int status)
{
	ft_lstclear(&pr_j, del_inp);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

int			exec_pipe(t_list *job, t_env env, char *sh, t_fds *fds)
{
	t_list	*pr_j;
	int		f[2];
	pid_t	pid;
	t_fds	fd;

	pr_j = get_last_job(&job);
	if ((pr_j == NULL) || (pipe(f) < 0))
		return (-5);
	if ((pid = fork()) == 0)
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
		fd.out_fd = fds->out_fd;
		exec_job(pr_j, env, sh, &fd);
		return (exec_pipe_help(pr_j, pid, 0));
	}
	return (-6);
}
