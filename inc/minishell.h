#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

typedef	struct	s_inp
{
	char	*token;
	int	is_quoted;
}		t_inp;

typedef struct	s_fds
{
	int	in_fd;
	int	out_fd;
}		t_fds;

char	*get_var(char *var_name, t_list *envp);
char	**parse_path(char *str);
char	*get_path(char *str, t_list *envp);
t_inp	*get_arg(char **str, t_list *envp);
char	*eval(char *str, t_list *envp);
char	*eval_var(char *str, t_list *envp);

/* debug funciton */
void	print_line(t_list* l);
void	print_jobs(t_list* l);
/* ----------------- */

t_list	*parse_line(char *str, t_list *envp);
t_list	*make_jobs(t_list *l);
t_list	*make_list_from_vector(char **vec);

char	*get_prog_name(t_list *job);
char	**mvfl(t_list *l);
char	**mvfl_t(t_list *l);

int	run_cd(t_fds fd, t_list *job, t_list *env);
int	run_echo(t_fds fd, t_list *job, t_list *env);
int	run_pwd(t_fds fd, t_list *job, t_list *env);
int	run_export(t_fds fd, t_list *job, t_list *env);
int	run_unset(t_fds fd, t_list *job, t_list *env);
int	run_env(t_fds fd, t_list *job, t_list *env);
int	run_exit(t_fds fd, t_list *job, t_list *env);
int	exec_job(t_list *job, t_list *env, char *sh);
int	exec_line(t_list *jobs, t_list *env, char *sh);
void	print_err(int err, char *sh, char *p);
void	f(int);
void	f1(int);

int	is_spec_symb(const char *s);
int	dq_len(const char *str);
int	dq_len_n(const char *str, int n);
char	*dq_strncpy(char *dst, const char *str, int n);

#endif
