#include "minishell.h"
#include "libft.h"
/* debug function */

void	print_line(t_list *l)
{
	int	i;

	i = 1;
	while (l)
	{
		printf("%d: %s\n", i, l->content);
		i++;
		l = l->next;
	}
}

t_list*	parse_line(char *str, char **envp)
{
	t_list	*ret;
	char	*s;

	ret = NULL;
	while ((s = get_arg(&str, envp)) != NULL)
	{
		ft_lstadd_back(&ret, ft_lstnew(s));
	}
	return ret;
}
