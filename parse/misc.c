#include "libft.h"
#include "minishell.h"

t_list	*make_list_from_vector(char **vec)
{
	t_list	*ret;

	ret = NULL;
	while (*vec)
	{
		ft_lstadd_back(&ret, ft_lstnew(*vec));
		vec++;
	}
	return ret;
}

char	*get_prog_name(t_list *job)
{
	char	*ret;

	ret = ((t_inp*)job->content)->token;
	return (ret);
}

char	**mvfl(t_list *l)
{
	int	i;
	char	**ret;
	int	n;

	i = 0;
	n = ft_lstsize(l);
	ret = ft_calloc(sizeof(char**), n + 1);
	while (l)
	{
		ret[i] = ft_strdup(l->content);
		i++;
		l = l->next;
	}
	return (ret);
}

char	**mvfl_t(t_list *l)
{
	int	i;
	char	**ret;
	int	n;

	i = 0;
	n = ft_lstsize(l);
	ret = ft_calloc(sizeof(char**), n + 1);
	while (l)
	{
		ret[i] = ft_strdup(((t_inp*)l->content)->token);
		i++;
		l = l->next;
	}
	return (ret);
}
