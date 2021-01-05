/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:07 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 13:00:20 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static long	get_num_words(char const *str, char c)
{
	int		status;
	long	ret;

	ret = 0;
	status = 1;
	while (*str)
	{
		if (*str == c)
		{
			if (status == 0)
				ret++;
			status = 1;
		}
		else
			status = 0;
		str++;
	}
	if (status == 0)
		ret++;
	return (ret);
}

static char	*get_new_word(char **str, char c)
{
	long	l;
	char	*k;

	while (**str == c && **str != '\0')
		(*str)++;
	l = 0;
	k = *str;
	while (k[l] != c && k[l] != '\0')
		l++;
	k = ft_substr(*str, 0, l);
	while (**str != c && **str != '\0')
		(*str)++;
	return (k);
}

static void	clean_all(char **s)
{
	long	l;

	l = 0;
	while (s[l] != NULL)
	{
		free(s[l]);
		l++;
	}
	free(s[l]);
	free(s);
}

static char	**ft_split2(char const *str, char **ret, char c, long i)
{
	long		j;
	char		*s;

	s = (char*)str;
	j = 0;
	while (j < i)
	{
		ret[j] = get_new_word(&s, c);
		if (ret[j] == NULL)
		{
			clean_all(ret);
			free(ret);
			return (NULL);
		}
		j++;
	}
	return (ret);
}

char		**ft_split(char const *str, char c)
{
	char	**ret;
	long	i;

	if (str == NULL)
		return (NULL);
	i = get_num_words(str, c);
	ret = ft_calloc(i + 1, sizeof(char**));
	if (ret == NULL)
		return (NULL);
	return (ft_split2(str, ret, c, i));
}
