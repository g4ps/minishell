/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:50:02 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:50:04 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*el;
	t_list	*nx;

	el = *lst;
	while (el)
	{
		nx = el->next;
		ft_lstdelone(el, del);
		el = nx;
	}
	*lst = NULL;
}
