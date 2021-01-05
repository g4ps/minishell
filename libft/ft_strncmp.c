/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:55:38 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:55:39 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - s2[i]);
		if (s1[i] == '\0' || s2[i] == '\0')
			return ((unsigned char)s1[i] - s2[i]);
		i++;
	}
	return (0);
}
