/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:51:06 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:51:09 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*),
		void (*del)(void *))
{
	t_list	*ret;
	t_list	*t;

	ret = NULL;
	while (lst)
	{
		t = ft_lstnew(f(lst->content));
		if (t->content != lst->content && del != NULL)
			del(t->content);
		if (t == NULL)
			return (NULL);
		ft_lstadd_back(&ret, t);
		lst = lst->next;
	}
	return (ret);
}
