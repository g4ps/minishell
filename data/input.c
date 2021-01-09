/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:42:33 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/09 16:42:48 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

void		del_inp(void *i)
{
	t_inp	*in;

	in = i;
	free(in->token);
	free(in);
}

void		del_jobs(t_list *t)
{
	t_list	*jobs;
	t_list	*r;
	t_list	*next;

	jobs = t;
	while (t)
	{
		next = t->next;
		r = t->content;
		ft_lstclear(&r, del_inp);
		free(r);
		free(t);
		t = next;
	}
}

char		**mvfl_t(t_list *l)
{
	int		i;
	char	**ret;
	int		n;

	i = 0;
	n = ft_lstsize(l);
	ret = ft_calloc(sizeof(char**), n + 1);
	while (l)
	{
		ret[i] = ft_strdup(((t_inp*)l->content)->token);
		i++;
		l = l->next;
	}
	return (ret);
}

void		update_return(t_list **c, int k)
{
	t_list	*prev;
	t_list	*l;
	t_list	*next;
	char	*num;

	prev = NULL;
	l = *c;
	while (l)
	{
		next = l->next;
		if (ft_strncmp(l->content, "?=", 2) == 0)
		{
			if (prev)
				prev->next = next;
			else
				*c = next;
			ft_lstdelone(l, free);
			num = ft_itoa(k);
			ft_lstadd_back(c, ft_lstnew(ft_strjoin("?=", num)));
			free(num);
			return ;
		}
		prev = l;
		l = l->next;
	}
}
