#include "libft.h"
#include "minishell.h"

int	is_piped(t_list *job)
{
	while (job)
	{
		if (ft_strcmp(((t_inp*)job->content)->token, "|") == 0)
			return 1;
		job = job->next;
	}
	return 0;
}
