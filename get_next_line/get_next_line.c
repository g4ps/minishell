/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:43:32 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/09 17:20:53 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line)
{
	static char	*buf = NULL;
	static int	eof = 0;
	int			n;

	while ((n = make_line(line, &buf, eof)) == 0)
	{
		eof = expand_buf(fd, &buf);
		if (eof < 0)
			return (-1);
	}
	if (n < 0)
	{
		free(buf);
		*line = NULL;
		return (-1);
	}
	if (eof == 1)
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	return (1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned long	i;
	unsigned long	l;
	char			*ret;

	if (s == NULL)
		return (NULL);
	l = 0;
	while (s[l] != '\0')
		l++;
	i = 0;
	if (l - start > len)
		l = len;
	if (start >= l)
		return (ft_calloc(1, 1));
	ret = malloc(sizeof(char) * l + 1);
	if (ret == NULL)
		return (NULL);
	while (i < len && s[i + start] != '\0')
	{
		ret[i] = s[i + start];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

int		make_line(char **line, char **buf, int eof)
{
	char	*k;
	char	*t;

	k = *buf;
	if (k == NULL)
	{
		*line = NULL;
		return (0);
	}
	while (*k != '\n' && *k != '\0')
		k++;
	t = k;
	skip_symb(&t, '\0');
	if (!eof && *k != '\n')
		return (0);
	*line = ft_substr(*buf, 0, k - *buf);
	t = ft_substr(k, 1, t - k - 1);
	if (*line == NULL || t == NULL)
	{
		double_whammy(t, *line);
		return (-1);
	}
	free(*buf);
	*buf = t;
	return (1);
}

int		expand_buf(int fd, char **l)
{
	char	*buf;
	char	*t;
	int		n;

	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (buf == NULL)
		return (-1);
	n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
		n = -1;
	else
	{
		if (*l)
			t = ft_strjoin(*l, buf);
		else
			t = ft_strdup(buf);
		free(*l);
		*l = t;
		if (n == 0)
			n = 1;
		else
			n = 0;
	}
	free(buf);
	return (n);
}
