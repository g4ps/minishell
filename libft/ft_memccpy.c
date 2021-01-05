/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:52:29 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:52:31 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, unsigned long n)
{
	char			*d;
	char			*s;
	char			k;
	unsigned int	i;

	i = 0;
	k = c;
	d = (char*)dest;
	s = (char*)src;
	if (d == NULL && s == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == k)
			return ((void*)d + i + 1);
		i++;
	}
	return (NULL);
}
