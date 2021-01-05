#include <stdio.h>
#include "libft.h"



int
main(int argc, char **argv)
{
  if (argc != 2)
    return 1;
  float b = ft_atof(argv[1]);
  printf("%g\n", b);
  return 0;
}
