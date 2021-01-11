/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 03:31:02 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 03:33:24 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "libft.h"
#include "minishell.h"

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
