#ifndef MINISHELL_H
# define MINISHELL_H
#include <stdlib.h>


char	*get_var(char *var_name, char **envp);
char	**parse_path(char *str);
char	*get_path(char *str, char **envp);
char	*get_arg(char **str, char **envp);
char	*eval(char *str, char **envp);
char	*eval_var(char *str, char **envp);

#endif
