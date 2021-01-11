/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:45:03 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/11 18:22:55 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int			run_unset(t_fds fd, t_list *job, t_env env)
{
	char	*tk;

	fd.in_fd = 0;
	env.vars = NULL;
	tk = get_token(job);
	if (!tk)
		return (0);
	rm_var(&(env.envp), tk);
	rm_var(&(env.vars), tk);
	return (0);
}

int			run_env(t_fds fd, t_list *job, t_env env)
{
	fd.in_fd = 0;
	job = NULL;
	print_list(env.envp);
	return (0);
}

int			run_exit(t_fds fd, t_list *job, t_env env)
{
	int		k;
	char	*s;

	fd.in_fd = 0;
	env.vars = NULL;
	if (job)
	{
		s = ((t_inp*)job->content)->token;
		k = ft_atoi(s);
	}
	else
		k = 0;
	exit(k);
}
