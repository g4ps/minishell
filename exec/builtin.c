/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:43:17 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/11 18:15:20 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <unistd.h>

int			run_echo(t_fds fd, t_list *job, t_env env)
{
	char	*k;
	int		nl;

	env.vars = NULL;
	nl = 1;
	while (job)
	{
		k = ((t_inp*)job->content)->token;
		if (ft_strcmp(k, "-n") == 0)
			nl = 0;
		else
		{
			ft_putstr_fd(k, fd.out_fd);
			if (job->next)
				ft_putstr_fd(" ", fd.out_fd);
		}
		job = job->next;
	}
	if (nl)
		ft_putstr_fd("\n", fd.out_fd);
	return (0);
}

int			run_cd(t_fds fd, t_list *job, t_env env)
{
	int		ret;
	char	*k;
	t_list	*envp;

	fd.in_fd = 0;
	envp = list_comb(env);
	if (job)
		k = ((t_inp*)job->content)->token;
	else
		k = get_var("HOME", env.envp);
	ret = chdir(k);
	if (ret < 0)
		ret = -4;
	return (ret);
}

int			run_pwd(t_fds fd, t_list *job, t_env env)
{
	char	*k;
	t_list	*envp;

	if (job != NULL)
	{
		ft_putstr_fd("pwd: too many arguments\n", 2);
		return (0);
	}
	envp = list_comb(env);
	k = getcwd(NULL, 0);
	ft_putstr_fd(k, fd.out_fd);
	ft_putstr_fd("\n", fd.out_fd);
	return (0);
}

int			run_export(t_fds fd, t_list *job, t_env env)
{
	char	*tk;
	char	*ret;

	fd.in_fd = 0;
	if (!job)
		return (0);
	tk = ((t_inp*)job->content)->token;
	ret = get_full_var(env.vars, tk);
	if (ret == NULL)
		return (0);
	rm_var(&(env.vars), tk);
	ft_lstadd_back(&(env.envp), ft_lstnew(ret));
	return (0);
}
