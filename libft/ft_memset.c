/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:53:00 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:58:17 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *b, int c, unsigned long len)
{
	char			*str;
	char			k;
	unsigned long	i;

	str = b;
	k = (char)c;
	i = 0;
	while (i < len)
	{
		str[i] = k;
		i++;
	}
	return (b);
}
