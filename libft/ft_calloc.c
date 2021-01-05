/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:59:02 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:47:13 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*ret;
	unsigned long	i;

	i = 0;
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	while (i < count * size)
	{
		ret[i] = '\0';
		i++;
	}
	return ((void*)ret);
}
