#include "minishell.h"
#include "libft.h"

/* debug function */

void	print_line(t_list *l)
{
	int		i;
	t_inp	*t;

	i = 1;
	while (l)
	{
		t = l->content;
		printf("%d: %-30s", i, t->token);
		if (t->is_quoted)
			printf("quoted\n");
		else
			printf("not quoted\n");
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

void	print_args(t_list *l)
{

	while (l)
	{
		printf("%s\n", l->content);
		l = l->next;
	}
}

/* ---------------- */

t_list	*make_new_job(t_list *line, t_list *end)
{
	t_list	*ret;
	t_inp	*i;

	ret = NULL;
	while (line != end)
	{
		i = ft_calloc(sizeof(t_inp), 1);
		if (i == NULL)
			return NULL;
		i->token = ft_strdup(((t_inp*)line->content)->token);
		i->is_quoted = ((t_inp*)line->content)->is_quoted;
		ft_lstadd_back(&ret, ft_lstnew(i));
		line = line->next;
	}
	return (ret);
}

t_list	*parse_line(char *str, t_list *envp)
{
	t_list	*ret;
	t_inp	*s;

	ret = NULL;
	while ((s = get_arg(&str, envp)) != NULL)
	{
		ft_lstadd_back(&ret, ft_lstnew(s));
	}
	return (ret);
}

t_list	*make_jobs(t_list *line)
{
	t_list	*ret;
	t_list	*s;
	t_list	*prev;
	char	*tk;

	ret = NULL;
	prev = NULL;
	s = line;
	while (line)
	{
		tk = ((t_inp *)line->content)->token;
		if (ft_strcmp(tk, ";") == 0)
		{
			if (prev && s != line)
			{
				ft_lstadd_back(&ret, ft_lstnew(make_new_job(s, prev->next)));
			}
			s = line->next;
		}
		prev = line;
		line = line->next;
	}
	if (ft_strcmp(tk, ";") != 0 && prev)
		ft_lstadd_back(&ret, ft_lstnew(make_new_job(s, prev->next)));
	return (ret);
}
