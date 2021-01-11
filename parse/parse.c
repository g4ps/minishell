/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:58:30 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:24:34 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int		dss(char *str1, char *str2)
{
	int			len;

	len = ft_strlen(str2);
	if (ft_strncmp(str1, str2, len) == 0)
		return (1);
	return (0);
}

int				is_sh_symb(char *str)
{
	if (dss(str, ">>"))
		return (2);
	if (dss(str, ";") || dss(str, "\'") || dss(str, "\"")
			|| dss(str, "<") || dss(str, ">") ||
			dss(str, "|"))
		return (1);
	return (0);
}

char			*eval_help(char *str, char *ret, char *s)
{
	ret = ft_calloc(sizeof(char), dq_len(s));
	str = s;
	while (*str != '\0')
		str++;
	dq_strncpy(ret, s, str - s + 1);
	return (ret);
}

int				eval_count(char *str, int is_quoted)
{
	int			i;

	i = 0;
	while (*str != '$' && *str != '\0')
	{
		if ((is_spec_symb(str) && is_quoted) || (*str == '\\' && !is_quoted))
		{
			str++;
			i++;
		}
		str++;
		i++;
	}
	return (i);
}

char			*eval(char *str, t_list *envp, int is_quoted)
{
	char		*s;
	char		*prec;
	char		*ret;
	char		*t;

	s = str;
	str = str + eval_count(str, is_quoted);
	if (*str != '\0')
	{
		prec = ft_calloc(sizeof(char), dq_len_n(s, str - s) + 1);
		dq_strncpy(prec, s, str - s);
		s = str;
		str++;
		while (ft_iscname(*str) && *str != '\0')
			str++;
		t = ft_calloc(sizeof(char), dq_len_n(s, str - s) + 2);
		dq_strncpy(t, s + 1, str - s - 1);
		ret = ft_strjoin(prec, eval_var(t, envp));
		ret = ft_strjoin(ret, eval(str, envp, is_quoted));
		free(t);
		free(prec);
	}
	else
		ret = eval_help(str, NULL, s);
	return (ret);
}
