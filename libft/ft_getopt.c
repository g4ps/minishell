#include "libft.h"

static int	parse_arg(char a, char *p)
{
	while (*p)
	{
		if (*p == a)
			return (a);
		p++;
	}
	return (256);
}

int	get_opt(int argc, char **argv, char *param)
{
	static int	i = 0;
	static int	pos = 0;
	char		*k;
	int		ret;

	if (i == 0)
		i++;
	while (i != argc)
	{
		k = argv[i];
		if (k[0] == '-' && k[pos + 1] != '\0')
		{
			ret = parse_arg(k + 1 + pos, param);
			pos++;
			return ret;
		}
		pos = 0;
		i++;
	}
	i = 0;
	return (-1);
}
