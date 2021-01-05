/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 13:39:19 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/05 13:42:48 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_ltoa2(long long s, int sign)
{
	long	j;
	char	temp[30];
	long	i;
	char	*ret;

	i = 0;
	while (s != 0)
	{
		temp[i] = s % 10 + '0';
		s = s / 10;
		i++;
	}
	i--;
	j = 0;
	ret = malloc(i + 2 + sign * -1);
	if (!ret)
		return (ret);
	if (sign == -1)
		ret[j++] = '-';
	while (i >= 0)
		ret[j++] = temp[i--];
	ret[j] = '\0';
	return (ret);
}

char		*ft_ltoa(long n)
{
	long long	s;
	int			sign;

	sign = 0;
	s = n;
	if (s < 0)
	{
		sign = -1;
		s = -s;
	}
	if (s == 0)
	{
		return (ft_strdup("0"));
	}
	return (ft_ltoa2(s, sign));
}
