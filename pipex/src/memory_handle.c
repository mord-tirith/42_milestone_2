#include "pipex.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	fork_guardian(pid_t pid, char **av, char *bin)
{
	int	exit_code;

	waitpid(pid, &exit_code, 0);
	free(bin);
	ft_clean_split(av);
	exit(exit_code);
}

static void	run_exec(char *bin, char **av, char **ep)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		execve(bin, av, ep);
		ft_perror("pipex: execve failed\n");
		exit(1);
	}
	else
	{
		waitpid(pid, &status, 0);
		free(bin);
		ft_clean_split(av);
		exit(WEXITSTATUS(status));
	}
}

void	ft_exec_cmd(char *cmd, char **ep)
{
	char	**av;
	char	*bin;

	av = ft_split(cmd, ' ');
	if (!av)
		ft_error_handler(BAD_MALL);
	bin = ft_get_bin(av[0], ep);
	if (!bin)
	{
		ft_clean_split(av);
		ft_error_handler(BAD_MALL);
	}
	run_exec(bin, av, ep);
}
