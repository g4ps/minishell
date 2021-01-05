#include "libft.h"
#include "minishell.h"

char	*get_arg(char **str)
{
	char	*ret;
	char	*s;

	while (ft_isspace(**str))
	{
		(*str)++;
	}
	if (**str == '\'')
		return (get_quote(str));
	else if (**str == '\"')
		return (get_dquote(str));
}
