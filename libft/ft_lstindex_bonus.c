/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:05:56 by teevee            #+#    #+#             */
/*   Updated: 2021/01/06 19:05:57 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_lstindex(t_list *l, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		if (l == NULL)
			return (NULL);
		i++;
		l = l->next;
	}
	return (l->content);
}
