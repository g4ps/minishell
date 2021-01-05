int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 - *str2 == 0 && *str1 != '\0')
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
