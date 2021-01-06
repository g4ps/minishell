#include "libft.h"
#include "minishell.h"

/* puropse of those function is to parse an input line into the set of */
/* evaluated strings (justlike in bash */

/*to norm: header, 9 func, 31 line in *eval*/

static int		dss(char *str1, char *str2)
{
	int			len;

	len = ft_strlen(str2);
	if (ft_strncmp(str1, str2, len) == 0)
		return (1);
	return (0);
}

int				is_sh_symb(char *str)
{
	if (dss(str, ">>"))
		return (2);
	if (dss(str, ";") || dss(str, "\'") || dss(str, "\"")
			|| dss(str, "<") || dss(str, ">") ||
			dss(str, "|"))
		return (1);
	return (0);
}

char			*eval_var(char *str, t_list *envp)
{
	char		*ret;

	ret = get_var(str, envp);
	if (ret == NULL)
		return (ft_strdup(""));
	return (ret);
}

char			*eval(char *str, t_list *envp)
{
	char		*s;
	char		*prec;
	char		*var;
	char		*ret;
	char		*st;

	st = str;
	s = str;
	while (*str != '$' && *str != '\0')
	{
		if (is_spec_symb(str))
			str++;
		str++;
	}
	if (*str == '\0')
		return (s);
	prec = ft_calloc(sizeof(char), dq_len_n(s, str - s) + 1);
	dq_strncpy(prec, s, str - s);
	s = str;
	while (!ft_isspace(*str) && *str != '\0')
		str++;
	var = ft_calloc(sizeof(char), dq_len_n(s, str - s) + 2);
	dq_strncpy(var, s + 1, str - s - 1);
	var = eval_var(var, envp);
	ret = ft_strjoin(prec, var);
	free(prec);
	prec = ret;
	ret = ft_strjoin(ret, str);
	free(prec);
	free(st);
	return (ret);
}

t_inp			*eval_token(t_inp *tok, t_list *envp)
{
	tok->token = eval(tok->token, envp);
	return (tok);
}

t_inp			*get_quote(char **str)
{
	char		*s;
	t_inp		*ret;

	(*str)++;
	s = *str;
	ret = ft_calloc(sizeof(t_inp), 1);
	ret->is_quoted = 1;
	while (**str != '\'' && **str != '\0')
	{
		(*str)++;
	}
	ret->token = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret->token, s, *str - s + 1);
	(*str)++;
	return (ret);
}

t_inp			*get_dquote(char **str)
{
	char		*s;
	t_inp		*ret;

	(*str)++;
	s = *str;
	while (**str != '\"' && **str != '\0')
	{
		if (**str == '\\' && *(*str + 1) == '\"')
			(*str) += 2;
		else
			(*str)++;
	}
	ret = ft_calloc(sizeof(t_inp), 1);
	ret->is_quoted = 1;
	ret->token = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret->token, s, *str - s + 1);
	(*str)++;
	return (ret);
}

t_inp			*get_normal(char **str)
{
	char		*s;
	int			n;
	t_inp		*ret;

	s = *str;
	if ((n = is_sh_symb(*str)))
		(*str) += n;
	else
	{
		while (!ft_isspace(**str) && **str != '\0' && !is_sh_symb(*str))
			(*str)++;
	}
	ret = ft_calloc(sizeof(t_inp), 1);
	ret->token = ft_calloc(sizeof(char), *str - s + 1);
	ft_strlcpy(ret->token, s, *str - s + 1);
	return (ret);
}

t_inp			*get_arg(char **str, t_list *envp)
{
	char		*s;

	while (ft_isspace(**str))
	{
		(*str)++;
	}
	if (**str == '\'')
		return (get_quote(str));
	else if (**str == '\"')
		return (eval_token(get_dquote(str), envp));
	else if (**str == '\0')
		return (NULL);
	return (eval_token(get_normal(str), envp));
}
