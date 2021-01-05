#include <stdlib.h>
#include "libft.h"
#include "minishell.h"

int	run_builtin(t_list *job, char **envp)
{
	if (ft_strcmp(job->content, "echo") == 0)
		return (run_echo (job->next));
	else if (ft_strcmp(job->content, "cd") == 0)
		return (run_cd(job->next, envp));
	else if (ft_strcmp(job->content, "pwd") == 0)
		return (run_pwd(job->next), envp);
	else if (ft_strcmp(job->content, "export") == 0)
		return (run_export(job->next, envp));
	else if (ft_strcmp(job->content, "unset") == 0)
		return (run_unset(job->next, envp));
	else if (ft_strcmp(job->content, "env") == 0)
		return (run_env(job->next, envp));
	else if (ft_strcmp(job->content, "exit") == 0)
		return (run_env(job->next, envp));
}

int	exec_job(t_list *job, char **envp)
{
	if (is_builtin(job->content))
		return (run_builtin(job), char **envp);
}
