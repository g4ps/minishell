#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

typedef	struct	s_inp
{
	char	*token;
	int	is_quoted;
}		t_inp;

char	*get_var(char *var_name, char **envp);
char	**parse_path(char *str);
char	*get_path(char *str, char **envp);
t_inp	*get_arg(char **str, char **envp);
char	*eval(char *str, char **envp);
char	*eval_var(char *str, char **envp);

/* debug funciton */
void	print_line(t_list* l);
void	print_jobs(t_list* l);
/* ----------------- */

t_list	*parse_line(char *str, char **envp);
t_list	*make_jobs(t_list *l);

#endif
