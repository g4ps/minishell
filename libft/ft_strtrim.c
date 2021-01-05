/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:56:12 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:56:13 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		is_there(char c, char const *str)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	j;

	if (!s1)
		return (NULL);
	i = 0;
	while (is_there(s1[i], set))
	{
		if (s1[i] == '\0')
			return (ft_substr(s1, 0, 0));
		i++;
	}
	j = 0;
	while (s1[j])
		j++;
	j--;
	while (is_there(s1[j], set) && j != 0)
		j--;
	if (j > i)
		return (ft_substr(s1, i, j - i + 1));
	else
		return (ft_substr(s1, 0, 0));
}
