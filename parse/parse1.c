/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 03:17:17 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:40:52 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

t_inp			*get_quote(char **str)
{
	char		*s;
	t_inp		*ret;

	(*str)++;
	s = *str;
	ret = ft_calloc(sizeof(t_inp), 1);
	ret->is_quoted = 1;
	while (**str != '\'' && **str != '\0')
	{
		(*str)++;
	}
	ret->token = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret->token, s, *str - s + 1);
	(*str)++;
	return (ret);
}

t_inp			*get_dquote(char **str)
{
	char		*s;
	t_inp		*ret;

	(*str)++;
	s = *str;
	while (**str != '\"' && **str != '\0')
	{
		if (**str == '\\' && *(*str + 1) == '\"')
			(*str) += 2;
		else
			(*str)++;
	}
	ret = ft_calloc(sizeof(t_inp), 1);
	ret->is_quoted = 1;
	ret->token = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret->token, s, *str - s + 1);
	(*str)++;
	return (ret);
}

t_inp			*get_normal(char **str)
{
	char		*s;
	int			n;
	t_inp		*ret;
	char		prev;

	prev = '\0';
	s = *str;
	if ((n = is_sh_symb(*str)))
		(*str) += n;
	else
	{
		while ((prev == '\\' || (!ft_isspace(**str) && \
!is_sh_symb(*str))) && **str != '\0')
		{
			prev = **str;
			(*str)++;
		}
	}
	ret = ft_calloc(sizeof(t_inp), 1);
	ret->token = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret->token, s, *str - s + 1);
	return (ret);
}

t_inp			*get_arg(char **str, t_list *envp)
{
	t_inp		*ret;
	t_inp		*t;
	char		*k;

	while (ft_isspace(**str))
		(*str)++;
	if (**str == '\'')
		ret = get_quote(str);
	else if (**str == '\"')
		ret = eval_token(get_dquote(str), envp);
	else if (**str == '\0')
		return (NULL);
	else
		ret = (eval_token(get_normal(str), envp));
	if (!ft_isspace(**str) && **str != '\0' && **str != ';')
	{
		if ((t = get_arg(str, envp)) != NULL)
		{
			k = ret->token;
			ret->token = ft_strjoin(ret->token, t->token);
			free(k);
			del_inp(t);
		}
	}
	return (ret);
}

t_inp			*eval_token(t_inp *tok, t_list *envp)
{
	char	*prev;

	prev = tok->token;
	tok->token = eval(tok->token, envp, tok->is_quoted);
	free(prev);
	return (tok);
}
