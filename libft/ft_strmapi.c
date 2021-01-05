/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:55:29 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:55:31 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	long	len;
	char	*ret;

	if (s == NULL || f == NULL)
		return (NULL);
	len = ft_strlen(s);
	ret = ft_calloc(len + 1, sizeof(char));
	if (ret == NULL)
		return (NULL);
	len--;
	while (len >= 0)
	{
		ret[len] = f(len, s[len]);
		len--;
	}
	return (ret);
}
