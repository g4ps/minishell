/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:49:18 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/09 16:50:18 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

int		is_set_var(t_list *job)
{
	char	*t;

	t = get_prog_name(job);
	if (ft_strchr(t, '=') != NULL)
		return (1);
	return (0);
}

int		set_var(t_list *job, t_env env)
{
	char	*tk;

	tk = get_prog_name(job);
	ft_lstadd_back(&env.vars, ft_lstnew(ft_strdup(tk)));
	return (0);
}

int		is_var_name(char *var, char *var_name)
{
	int		len;
	int		len_var;

	len = ft_strlen(var_name);
	if (ft_strncmp(var, var_name, len) == 0 && var[len] == '=')
		return (1);
	return (0);
}

char	*get_full_var(t_list *l, char *var)
{
	while (l)
	{
		if (is_var_name(l->content, var))
			return (ft_strdup(l->content));
		l = l->next;
	}
	return (NULL);
}

int		rm_var(t_list **l, char *var)
{
	t_list	*prev;
	t_list	*curr;
	char	*tk;
	int		len;

	prev = NULL;
	curr = *l;
	while (curr)
	{
		tk = curr->content;
		if (is_var_name(tk, var))
		{
			if (prev)
				prev->next = curr->next;
			else
			{
				*l = curr->next;
			}
			ft_lstdelone(curr, free);
			return (1);
		}
		prev = curr;
		curr = curr->next;
	}
	return (0);
}

char*	get_token(t_list *job)
{
	if (!job)
		return (NULL);
	return (((t_inp*)job->content)->token);
}
