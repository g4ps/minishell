/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_x_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 14:42:43 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/05 14:43:50 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	hex_dig(int n, int cas)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else if (n >= 10 && n <= 15)
	{
		n -= 10;
		if (cas == 1)
			return (n + 'A');
		else
			return (n + 'a');
	}
	return ('\0');
}

char		*ft_ltoa_x(unsigned long arg, int cas)
{
	char	tmp[30];
	int		i;
	char	*ret;

	i = 0;
	ft_memset(tmp, 0, 20);
	if (arg == 0)
		return (ft_strdup("0"));
	while (arg != 0)
	{
		tmp[i] = hex_dig(arg % 16, cas);
		arg = arg / 16;
		i++;
	}
	ret = ft_calloc(ft_strlen(tmp) + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	ft_strrev(tmp);
	ft_memcpy(ret, tmp, ft_strlen(tmp) + 1);
	return (ret);
}
