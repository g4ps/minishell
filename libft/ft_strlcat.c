/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:47 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:54:47 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

unsigned long	ft_strlcat(char *dst, const char *src, unsigned long n)
{
	unsigned long r;
	unsigned long i;
	unsigned long j;

	i = 0;
	j = 0;
	r = ft_strlen(dst);
	if (r >= n)
		return (n + ft_strlen(src));
	while (i < n - 1 && dst[i] != '\0')
		i++;
	while (i < n - 1 && src[j] != '\0')
		dst[i++] = src[j++];
	if (i != n - 1 || i != n)
		dst[i] = '\0';
	return (ft_strlen(src) + r);
}
