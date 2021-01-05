/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:52:15 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:59:14 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, unsigned long n)
{
	char			*d;
	char			*s;
	unsigned long	i;

	d = (char*)dst;
	s = (char*)src;
	if (d == NULL && s == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	else
	{
		while (i < n)
		{
			d[n - i - 1] = s[n - i - 1];
			i++;
		}
	}
	return (dst);
}
