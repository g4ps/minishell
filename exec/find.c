#include "libft.h"
#include <dirent.h>
#include "minishell.h"

void	free_vec(char **vec)
{
	char **n;
	while (*vec)
	{
		n = vec + 1;
		free(*vec);
		vec = n;
	}
	free(*vec);
}

char*	get_var(char *var_name, char **envp)
{
	int	len;

	len = ft_strlen(var_name);
	while (*envp)
	{
		if (ft_strncmp(var_name, *envp, len) == 0)
			return *envp;
		envp++;
	}
	return NULL;
}

char**	parse_path(char *str)
{
	char **ret;

	while (*str != '=' && str != '\0')
		str++;
	str++;
	ret = ft_split(str, ':');
	return ret;
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
			return 1;
	}
	free(cont);
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
	free_vec(dirs);
	ret = get_fn(dirs, str);
	return ret;
}
