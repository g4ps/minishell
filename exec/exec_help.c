/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_help.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 03:03:15 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:13:36 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft.h"

char		*get_token(t_list *job)
{
	if (!job)
		return (NULL);
	return (((t_inp*)job->content)->token);
}

void		free_vec(char **vec)
{
	char	**s;
	char	**n;

	if (vec == NULL)
		return ;
	s = vec;
	while (*vec)
	{
		n = vec + 1;
		free(*vec);
		vec = n;
	}
	free(*vec);
	free(s);
}

void		f1(int k)
{
	k = 0;
	ft_putstr_fd("\n", 1);
	run_prompt();
}

void		f(int k)
{
	k = 0;
}
