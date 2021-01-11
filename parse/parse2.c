/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 06:45:42 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 06:52:07 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char			*eval_var(char *str, t_list *envp)
{
	char		*ret;

	ret = get_var(str, envp);
	if (ret == NULL)
		return (ft_strdup(""));
	return (ft_strdup(ret));
}
