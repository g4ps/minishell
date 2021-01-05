/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:38 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:54:39 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	i;
	unsigned long	j;
	char			*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2) + 1;
	ret = malloc(i);
	if (ret == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = i;
	i = 0;
	while (s2[i])
	{
		ret[j] = s2[i];
		j++;
		i++;
	}
	ret[j] = '\0';
	return (ret);
}
