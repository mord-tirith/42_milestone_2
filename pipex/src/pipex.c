
#include "pipex.h"
#include <sys/types.h>
#include <unistd.h>


static void	exec_cmd(char *cmd, char *ep)
{
	
}

static void	run_parent(char **av, int *pipe, char **ep)
{
	
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe[2];
	pid_t	pid;

	if (argc != 5)
		ft_error_handler(BAD_ARGS);
	if (pipe(pipe) == -1)
		ft_error_handler(BAD_PIPE);
	pid = fork();
	if (pid == -1)
		ft_error_handler(BAD_FORK);
	if (pid == 0)
		run_child(argv, pipe, envp);
	else
		run_parent(argv, pipe, envp);
}
