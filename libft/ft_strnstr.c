/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:55:46 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:55:47 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *h, const char *nd, unsigned long n)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	j = 0;
	if (ft_strlen(nd) == 0)
		return ((char*)h);
	while (i < n && h[i] != '\0')
	{
		j = 0;
		while (nd[j] == h[j + i] && i + j < n)
		{
			if (nd[j + 1] == '\0')
				return ((char*)h + i);
			j++;
		}
		i++;
	}
	return ((char*)0);
}
