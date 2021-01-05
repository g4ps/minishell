#include <stdio.h>
#include "libft.h"



int
main(int argc, char **argv)
{
	char*	str1 = "Hello";
	char*	str2 = "Hello";
	printf("%d->%d\n", strcmp(str1, str2), ft_strcmp(str1, str2));
}
