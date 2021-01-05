/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 12:53:47 by fthemis           #+#    #+#             */
/*   Updated: 2020/11/04 12:59:27 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	long	k;
	char	tmp[30];
	int		i;

	k = n;
	if (k < 0)
	{
		write(fd, "-", 1);
		k = -k;
	}
	i = 0;
	if (k == 0)
		write(fd, "0", 1);
	while (k != 0)
	{
		tmp[i] = k % 10 + '0';
		k = k / 10;
		i++;
	}
	while (i > 0)
	{
		write(fd, tmp + i - 1, 1);
		i--;
	}
}
