#include "libft.h"
#include "minishell.h"

int		is_spec_symb(const char *s)
{
	char	k;

	if (*s == '\\')
	{
		k = *(s + 1);
		if (k == '`' || k == '\\' ||
				k == '$' || k == '\"')
			return (1);
		s++;
	}
	return (0);
}

int		dq_len(const char *str)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	while (str[i])
	{
		if (is_spec_symb(str + i))
			i++;
		i++;
		ret++;
	}
	return (ret);
}

int		dq_len_n(const char *str, int n)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (str[i] && i < n)
	{
		if (is_spec_symb(str + i))
			i++;
		i++;
		ret++;
	}
	return (ret);
}

char	*dq_strncpy(char *dst, const char *str, int n)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && i < n)
	{
		if (is_spec_symb(str + i))
		{
			i++;
			dst[j] = str[i];
		}
		else
		{
			dst[j] = str[i];
		}
		j++;
		i++;
	}
	return (dst);
}
