/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:52:37 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:52:38 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, unsigned long n)
{
	char			*str;
	char			ch;
	unsigned long	i;

	str = (char*)s;
	ch = (char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == ch)
			return ((void*)str + i);
		i++;
	}
	return (NULL);
}
