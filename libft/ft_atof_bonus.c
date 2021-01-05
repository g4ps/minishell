#include "libft.h"

float	ft_atof(char *buf)
{
	double	ret;
	int	dot;
	double	div;
	int	sign;

	ret = 0;
	sign = 1;
	dot = 0;
	div = 1;
	if (*buf == '+' || *buf == '-')
	{
		if (*buf == '-')
			sign = -1;
		buf++;
	}
	while (ft_isdigit(*buf) || *buf == '.')
	{
		if (dot)
			div *= 10;
		if (*buf != '.')
			ret = ret * 10 + (*buf - '0');
		else
		{
			if (dot)
				return 0;
			dot = 1;
		}
		buf++;
	}
	return sign * ret / div;
}
