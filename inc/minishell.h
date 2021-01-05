#include <stdlib.h>


char *get_var(char *var_name, char **envp);
char **parse_path(char *str);
char *get_path(char *str, char **envp);
