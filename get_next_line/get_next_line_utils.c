/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:48:17 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/08 09:04:58 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void			double_whammy(void *p1, void *p2)
{
	free(p1);
	free(p2);
}

void			skip_symb(char **str, char t)
{
	while (**str == t)
		(*str)++;
}
