#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include "libft.h"
#include "get_next_line.h"

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

typedef	struct	s_env
{
	t_list	*envp;
	t_list	*vars;
}		t_env;
typedef	struct	s_job
{
	t_list	*job;
	char	kind;
}		t_job;

char	*get_var(char *var_name, t_list *envp);
char	**parse_path(char *str);
char	*get_path(char *str, t_list *envp);
t_inp	*get_arg(char **str, t_list *envp);
char	*eval(char *str, t_list *envp, int i);
char	*eval_var(char *str, t_list *envp);

/* debug funciton */
void	print_line(t_list* l);
void	print_jobs(t_list* l);
void	print_list(t_list *l);
/* ----------------- */

t_list	*parse_line(char *str, t_list *envp);
t_list	*make_jobs(t_list *l);
t_list	*make_list_from_vector(char **vec);

char	*get_prog_name(t_list *job);
char	**mvfl(t_list *l);
char	**mvfl_t(t_list *l);

int	run_cd(t_fds fd, t_list *job, t_env env);
int	run_echo(t_fds fd, t_list *job, t_env nv);
int	run_pwd(t_fds fd, t_list *job, t_env env);
int	run_export(t_fds fd, t_list *job, t_env env);
int	run_unset(t_fds fd, t_list *job, t_env env);
int	run_env(t_fds fd, t_list *job, t_env env);
int	run_exit(t_fds fd, t_list *job, t_env env);
int	exec_line(t_list *jobs, t_env env, char *sh);
void	print_err(int err, char *sh, char *p);
void	f(int);
void	f1(int);

int	is_spec_symb(const char *s);
int	dq_len(const char *str);
int	dq_len_n(const char *str, int n);
char	*dq_strncpy(char *dst, const char *str, int n);

t_list	*list_comb(t_env env);
t_list 	*init_vars(char **v);
void	update_return(t_list **l, int k);

int	is_piped(t_list *j);

int	exec_job(t_list *job, t_env env, char *sh, t_fds *fd);
int	execute(t_list *job, t_env env, char *sh, t_fds *fd);
int	exec_pipe(t_list *job, t_env env, char *sh, t_fds *fd);
void	del_inp(void *in);
void	del_jobs(t_list *j);
int		is_set_var(t_list *job);
int		set_var(t_list *job, t_env e);
int		is_var_name(char *var, char *var_name);
char	*get_full_var(t_list *l, char *var);
int		rm_var(t_list **l, char *var);
char	*get_token(t_list *job);
void	print_args(t_list *l);
t_list	*make_new_job(t_list *s, t_list *e);

#endif
