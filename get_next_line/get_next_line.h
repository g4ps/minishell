/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fthemis <fthemis@student.21-school>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 14:00:40 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/08 09:04:15 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFFER_SIZE 32

int				make_line(char **line, char **buf, int eof);
int				expand_buf(int fd, char **buf);
char			*ft_strjoin(char const *s1, char const *s2);
unsigned long	ft_strlen(const char *s1);
char			*ft_strdup(const char *s);
void			*ft_calloc(unsigned long n1, unsigned long n2);
int				get_next_line(int fd, char **s);
void			double_whammy(void *p1, void *p2);
void			skip_symb(char **str, char t);

#endif
