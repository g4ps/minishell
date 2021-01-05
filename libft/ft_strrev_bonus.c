/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 12:36:40 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/05 13:15:08 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *s)
{
	char			t;
	unsigned long	len;
	unsigned long	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	while (i <= len / 2)
	{
		t = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = t;
		i++;
	}
	return (s);
}
