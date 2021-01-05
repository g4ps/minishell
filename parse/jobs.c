#include "minishell.h"
#include "libft.h"
/* debug function */

void	print_line(t_list *l)
{
	int	i;

	i = 1;
	while (l)
	{
		printf("%d: %s\n", i, ((t_inp*)l->content)->token);
		i++;
		l = l->next;
	}
}

void	print_jobs(t_list *l)
{
	while (l)
	{
		print_line(l->content);
		printf("\n");
		l = l->next;
	}
}

/* ---------------- */

t_list*	parse_line(char *str, char **envp)
{
	t_list	*ret;
	t_inp	*s;

	ret = NULL;
	while ((s = get_arg(&str, envp)) != NULL)
	{
		ft_lstadd_back(&ret, ft_lstnew(s));
	}
	return ret;
}

t_list*	make_jobs(t_list *line)
{
	t_list	*ret;
	t_list	*s;
	t_list	*prev;

	ret = NULL;
	prev = NULL;
	s = line;
	while (line)
	{
		if (ft_strncmp(line->content, ";", 3) == 0)
		{
			prev->next = NULL;
			ft_lstadd_back(&ret, ft_lstnew(s));
			s = line->next;
		}
		prev = line;
		line = line->next;
	}
	ft_lstadd_back(&ret, ft_lstnew(s));
	return ret;
}
