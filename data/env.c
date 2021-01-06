#include "libft.h"
#include "minishell.h"

t_list	*list_comb(t_env env)
{
	t_list	*ret;
	t_env	t;

	ret = NULL;
	t = env;
	while (t.envp)
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_strdup(t.envp->content)));
		t.envp = t.envp->next;
	}
	while (t.vars)
	{
		ft_lstadd_back(&ret, ft_lstnew(ft_strdup(t.vars->content)));
		t.vars = t.vars->next;
	}
	return ret;
}

t_list	*init_vars(char **argv)
{
	t_list	*ret;

	ret = NULL;
	ft_lstadd_back(&ret, ft_lstnew(ft_strjoin("0=", argv[0])));
	ft_lstadd_back(&ret, ft_lstnew(ft_strdup("?=0")));
	return (ret);
}

void	print_list(t_list *l)
{
	while (l)
	{
		ft_putstr_fd(l->content, 1);
		ft_putstr_fd("\n", 1);
		l = l->next;
	}
}
