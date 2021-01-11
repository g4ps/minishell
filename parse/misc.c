/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 17:22:40 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/10 02:59:21 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_list	*make_list_from_vector(char **vec)
{
	t_list	*ret;

	ret = NULL;
	while (*vec)
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_strdup(*vec)));
		vec++;
	}
	return (ret);
}

char	*get_prog_name(t_list *job)
{
	char	*ret;

	ret = ((t_inp*)job->content)->token;
	return (ret);
}

char	**mvfl(t_list *l)
{
	int		i;
	char	**ret;
	int		n;

	i = 0;
	n = ft_lstsize(l);
	ret = ft_calloc(sizeof(char**), n + 1);
	while (l)
	{
		ret[i] = ft_strdup(l->content);
		i++;
		l = l->next;
	}
	return (ret);
}
