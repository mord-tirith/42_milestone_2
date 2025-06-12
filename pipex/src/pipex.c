
#include "pipex.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

static void	run_child(char **av, int *pipe, char **ep)
{
	int	fd;

	fd = ft_fd_opener(av[0], MODE_READ);
	dup2(fd, 0);
	dup2(pipe[1], 1);
	close(pipe[0]);
	ft_exec_cmd(av[1], ep);
}

static void	run_parent(char **av, int *pipe, char **ep)
{
	int	fd;

	fd = ft_fd_opener(av[3], MODE_WRIT);
	dup2(fd, 1);
	dup2(pipe[0], 0);
	close(pipe[1]);
	ft_exec_cmd(av[2], ep);
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fds[2];
	pid_t	pid;

	if (argc != 5)
		ft_error_handler(BAD_ARGS);
	if (pipe(pipe_fds) == -1)
		ft_error_handler(BAD_PIPE);
	pid = fork();
	if (pid == -1)
		ft_error_handler(BAD_FORK);
	if (pid == 0)
		run_child(argv + 1, pipe_fds, envp);
	else
	{
		run_parent(argv + 1, pipe_fds, envp);
		wait(NULL);
	}
}


