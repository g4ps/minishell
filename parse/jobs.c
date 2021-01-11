/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jobs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:58:14 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:43:43 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

t_list	*make_new_job(t_list *line, t_list *end)
{
	t_list	*ret;
	t_list	*next;
	t_inp	*i;

	ret = NULL;
	while (line != end)
	{
		i = ft_calloc(sizeof(t_inp), 1);
		if (i == NULL)
			return (NULL);
		i->token = ft_strdup(((t_inp*)line->content)->token);
		i->is_quoted = ((t_inp*)line->content)->is_quoted;
		next = line->next;
		ft_lstadd_back(&ret, ft_lstnew(i));
		line = next;
	}
	return (ret);
}

t_list	*parse_line(char *str, t_list *envp)
{
	t_list	*ret;
	t_inp	*s;

	ret = NULL;
	while ((s = get_arg(&str, envp)) != NULL)
	{
		ft_lstadd_back(&ret, ft_lstnew(s));
	}
	return (ret);
}

t_list	*make_jobs(t_list *line)
{
	t_list	*ret;
	t_list	*s;
	t_list	*prev;
	char	*tk;

	if (!line)
		return (NULL);
	ret = NULL;
	prev = NULL;
	s = line;
	while (line)
	{
		tk = ((t_inp *)line->content)->token;
		if (ft_strcmp(tk, ";") == 0)
		{
			if (prev && s != line)
				ft_lstadd_back(&ret, ft_lstnew(make_new_job(s, prev->next)));
			s = line->next;
		}
		prev = line;
		line = line->next;
	}
	if (ft_strcmp(tk, ";") != 0 && prev)
		ft_lstadd_back(&ret, ft_lstnew(make_new_job(s, prev->next)));
	return (ret);
}
