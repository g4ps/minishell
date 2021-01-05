/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:28 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:54:30 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned long	i;
	char			*ret;

	i = 0;
	while (s1[i] != '\0')
		i++;
	i++;
	ret = ft_calloc(i, sizeof(char));
	if (ret == NULL)
		return (ret);
	i = 0;
	while ((ret[i] = s1[i]) != '\0')
		i++;
	ret[i] = '\0';
	return (ret);
}
