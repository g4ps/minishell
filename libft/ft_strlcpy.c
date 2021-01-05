/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:53 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 13:03:34 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned long	ft_strlcpy(char *dst, const char *src, unsigned long n)
{
	unsigned long	i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	if (n == 0)
		return (ft_strlen(src));
	while (i < n - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	if (i != 0 || ft_strlen(src) == 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
