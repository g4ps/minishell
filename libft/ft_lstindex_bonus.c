#include "libft.h"
#include <stdlib.h>

void	*ft_lstindex(t_list *l, int ind)
{
	int	i;

	i = 0;
	while (i < ind)
	{
		if (l == NULL)
			return (NULL);
		i++;
		l = l->next;
	}
	return (l->content);
}
