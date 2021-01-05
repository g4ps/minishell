/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:54:19 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:54:20 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char			*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (char*)s;
		s++;
	}
	if (c != '\0')
		return (char*)0;
	else
		return ((char*)s);
}
