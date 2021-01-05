/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:45:57 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:46:45 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoil(char *str)
{
	long	ret;
	int		sign;

	sign = 1;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		str++;
		sign = -1;
	}
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + *str - '0';
		str++;
	}
	return (ret * sign);
}
