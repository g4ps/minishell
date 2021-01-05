/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:56:27 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:56:27 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	unsigned long	l;
	char			*ret;

	if (s == NULL)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
		l++;
	i = 0;
	if (l - start > len)
		l = len;
	if (start >= l)
		return (ft_calloc(1, 1));
	ret = malloc(sizeof(char) * l + 1);
	if (ret == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
