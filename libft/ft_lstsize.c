/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:51:49 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:51:50 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	ret;

	ret = 0;
	while (lst)
	{
		lst = lst->next;
		ret++;
	}
	return (ret);
}
