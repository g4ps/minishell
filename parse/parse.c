#include "libft.h"
#include "minishell.h"

/* puropse of those function is to parse an input line into the set of */
/* evaluated strings (justlike in bash */

char	*eval_var(char *str, char **envp)
{
	char	*ret;

	ret = get_var(str, envp);
	if (ret == NULL)
		return (ft_strdup(""));
	return (ret);
}


char	*eval(char *str, char **envp)
{
	char	*s;
	char	*prec;
	char	*var;
	char	*ret;
	char	*st;

	st = str;
	s = str;
	while (*str != '$' && *str != '\0')
		str++;
	if (*str == '\0')
		return str;
	prec = ft_calloc(sizeof(char), str - s + 2);
	ft_strlcpy(prec, s, str - s + 1);
	s = str;
	while (!ft_isspace(*str) && *str != '\0')
		str++;
	var = ft_calloc(sizeof(char), str - s + 2);
	ft_strlcpy(var, s + 1, str - s);
	var = eval_var(var, envp);
	ret = ft_strjoin(prec, var);
	free(prec);
	prec = ret;
	ret = ft_strjoin(ret, str);
	free(prec);
	free(st);
	return ret;
}

char	*get_quote(char **str)
{
	char	*s;
	char	*ret;

	(*str)++;
	s = *str;
	while (**str != '\'' && **str != '\0')
	{
		(*str)++;
	}
	ret = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret, s, *str - s + 1);
	(*str)++;
	return (ret);
}

char	*get_dquote(char **str)
{
	char	*s;
	char	*ret;
	
	(*str)++;
	s = *str;
	while (**str != '\"' && **str != '\0')
	{
		(*str)++;
	}
	ret = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret, s, *str - s + 1);
	(*str)++;
	return (ret);
}

char	*get_normal(char **str)
{
	char	*s;
	char	*ret;

	s = *str;
	while (!ft_isspace(**str))
		(*str)++;
	ret = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret, s, *str - s + 1);
	(*str)++;
	return (ret);
}

char	*get_arg(char **str, char **envp)
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
		return (eval(get_dquote(str), envp));
	else if (**str == '\0')
		return NULL;
	return (eval(get_normal(str), envp));
}

