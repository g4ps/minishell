/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:45:20 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:45:34 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = -1;
	while (*str == ' ' || *str == '\t' || *str == '\v'
			|| *str == '\f' || *str == '\n' || *str == '\r')
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = 0;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + *str - '0';
		if (0 > ret)
			return (sign);
		str++;
	}
	if (sign == 0)
		sign = 1;
	return (int)(ret * sign * -1);
}
