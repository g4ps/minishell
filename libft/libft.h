/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 16:22:58 by fthemis           #+#    #+#             */
/*   Updated: 2021/01/06 19:12:41 by teevee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

void				*ft_memset(void *b, int c, unsigned long n);
void				*ft_bzero(void *b, unsigned long n);
void				*ft_memcpy(void *dst, const void *src, unsigned long n);
void				*ft_memccpy(void *dst,
					const void *src, int c, unsigned long n);
void				*ft_memmove(void *dst, void *src, unsigned long n);
void				*ft_memchr(const void *s, int c, unsigned long n);
int					ft_memcmp(const void *s1, const void *s2, unsigned long n);

unsigned long		ft_strlen(const char *s);
unsigned long		ft_strlcpy(char *d, const char *s, unsigned long n);
unsigned long		ft_strlcat(char *d, const char *s, unsigned long n);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *h, const char *nd, unsigned long n);
int					ft_strncmp(const char *s1, const char *s2, unsigned long n);

int					ft_atoi(const char *str);

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(unsigned long l1, unsigned long l2);
char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s,
					unsigned int start, unsigned long len);
char				*ft_strjoin(char const *s1, const char *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst,
					void *(*f)(void *), void (*del)(void *));

long				ft_atoil(char *str);
int					ft_isspace(int c);
char				*ft_strrev(char *s);
char				*ft_itoa_x(unsigned int arg, int cas);
char				*ft_ltoa(long x);
char				*ft_ltoa_x(unsigned long arg, int cas);
float				ft_atof(char *buf);
void				*ft_lstindex(t_list *l, int i);
int					ft_strcmp(char *str1, char *str2);

#endif
