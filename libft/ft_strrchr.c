/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:55:59 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:56:01 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *l;

	l = (char*)0;
	while (*s)
	{
		if (*s == (char)c)
			l = (char*)s;
		s++;
	}
	if (c != '\0')
		return (l);
	else
		return ((char*)s);
}
