/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teevee <teevee@students.21-school.ru>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 02:53:24 by teevee            #+#    #+#             */
/*   Updated: 2021/01/11 18:08:32 by fthemis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include "minishell.h"

char				*get_var(char *var_name, t_list *envp)
{
	int				len;
	char			*s;

	len = ft_strlen(var_name);
	while (envp)
	{
		if (is_var_name(envp->content, var_name))
		{
			s = envp->content;
			while (*s != '=' && *s != '\0')
				s++;
			if (*s == '=')
				s++;
			return (s);
		}
		envp = envp->next;
	}
	return (NULL);
}

char				**parse_path(char *str)
{
	char			**ret;

	ret = ft_split(str, ':');
	return (ret);
}

int					find_in_dir(char *dir, char *file)
{
	DIR				*d;
	struct dirent	*cont;

	if ((d = opendir(dir)) == NULL)
		return (-1);
	while ((cont = readdir(d)) != NULL)
	{
		if (ft_strncmp(file, cont->d_name, 100) == 0)
		{
			closedir(d);
			return (1);
		}
	}
	closedir(d);
	return (0);
}

char				*get_fn(char **dirs, char *str)
{
	char			*ret;
	char			*t;

	while (*dirs)
	{
		if (find_in_dir(*dirs, str) == 1)
		{
			t = ft_strjoin(*dirs, "/");
			ret = ft_strjoin(t, str);
			free(t);
			return (ret);
		}
		dirs++;
	}
	return (NULL);
}

char				*get_path(char *str, t_list *envp)
{
	char			*path;
	char			**dirs;
	char			*ret;

	if (ft_strchr(str, '/') != NULL)
		return (ft_strdup(str));
	if ((path = get_var("PATH", envp)) == NULL)
		return (NULL);
	dirs = parse_path(path);
	ret = get_fn(dirs, str);
	free_vec(dirs);
	return (ret);
}
