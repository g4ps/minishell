/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:50:52 by teevee            #+#    #+#             */
/*   Updated: 2021/01/06 18:50:54 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "minishell.h"
#include "libft.h"

void	print_err(int err, char *sh, char *p)
{
	ft_putstr_fd(sh, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(p, 2);
	ft_putstr_fd(": ", 2);
	if (err == -1)
		ft_putstr_fd("couldn\'t process output redirection\n", 2);
	else if (err == -2)
		ft_putstr_fd("command not found\n", 2);
	else if (err == -3)
		ft_putstr_fd("can\'t fork:(\n", 2);
	else if (err == -4)
		perror("p");
}
