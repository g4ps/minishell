/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 03:11:11 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:12:55 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include "libft.h"
#include "minishell.h"

int			get_in_fd_help(t_list *job, t_list *prev, int ret, char *f)
{
	job = job->next;
	if (prev && job)
		prev->next = job->next;
	if (job == NULL || !prev || !job)
		return (-2);
	f = ((t_inp*)job->content)->token;
	ret = open(f, O_RDONLY);
	if (ret < 0)
		return (-4);
	return (ret);
}

int			get_in_fd(t_list *job)
{
	int		ret;
	t_inp	*t;
	t_list	*prev;
	char	*f;

	ret = 0;
	prev = NULL;
	while (job)
	{
		t = job->content;
		f = ((t_inp*)job->content)->token;
		if (ft_strcmp(f, "<") == 0 && !t->is_quoted)
			return (get_in_fd_help(job, prev, ret, f));
		prev = job;
		job = job->next;
	}
	return (0);
}

int			get_out_fd_help(t_list *job, t_list *prev, char *name, char *f)
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

int			get_out_fd(t_list *job)
{
	int		ret;
	t_inp	*t;
	char	*f;
	char	*name;
	t_list	*prev;

	name = NULL;
	ret = 0;
	prev = NULL;
	while (job)
	{
		t = job->content;
		f = ((t_inp*)job->content)->token;
		if ((ft_strcmp(f, ">") == 0 || ft_strcmp(f, ">>") == 0) \
		&& !t->is_quoted)
			return (get_out_fd_help(job, prev, name, f));
		prev = job;
		job = job->next;
	}
	return (0);
}
