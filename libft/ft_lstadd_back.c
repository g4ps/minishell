/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:48:55 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:48:57 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	new->next = NULL;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		ft_lstlast(*lst)->next = new;
	}
}
