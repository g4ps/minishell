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
