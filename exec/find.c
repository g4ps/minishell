#include "libft.h"
#include <dirent.h>
#include "minishell.h"

void	free_vec(char **vec)
{
	char **s;
	char **n;

	if (vec == NULL)
		return ;
	s = vec;
	while (*vec)
	{
		n = vec + 1;
		free(*vec);
		vec = n;
	}
	free(*vec);
	free(s);
}

char*	get_var(char *var_name, char **envp)
{
	int	len;
	char	*s;

	len = ft_strlen(var_name);
	while (*envp)
	{
		if (ft_strncmp(var_name, *envp, len) == 0)
		{
			s = *envp;
			while (*s != '=' && *s != '\0')
				s++;
			if (*s == '=')
				s++;
			return s;
		}
		envp++;
	}
	return NULL;
}

char**	parse_path(char *str)
{
	char **ret;
	char **t;

	ret = ft_split(str, ':');
	return (ret);
}

int	find_in_dir(char *dir, char *file)
{
	DIR* d;
	struct dirent *cont;

	if ((d = opendir(dir)) == NULL)
		return -1;
	while ((cont = readdir(d)) != NULL)
	{
		if (ft_strncmp(file, cont->d_name, 100) == 0)
		{
			closedir(d);
			return 1;
		}
	}
	closedir(d);
	return 0;
}

char *get_fn(char **dirs, char *str)
{
	char	*ret;
	char	*t;

	while (*dirs)
	{
		if (find_in_dir(*dirs, str) == 1)
		{
			t = ft_strjoin(*dirs, "/");
			ret = ft_strjoin(t, str);
			free(t);
			return ret;
		}
		dirs++;
	}
	return NULL;
}


char	*get_path(char *str, char **envp)
{
	char	*path;
	char	**dirs;
	char	*ret;

	if ((path = get_var("PATH", envp)) == NULL)
		return NULL;
	dirs = parse_path(path);
	ret = get_fn(dirs, str);
	free_vec(dirs);
	return ret;
}
