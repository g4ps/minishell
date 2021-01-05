/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_funcs3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:04:29 by fthemis           #+#    #+#             */
/*   Updated: 2020/10/30 17:05:17 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_itoa2(long s, long sign)
{
	long	j;
	char	temp[20];
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

char		*ft_itoa(int n)
{
	long	s;
	int		sign;

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
	return (ft_itoa2(s, sign));
}
