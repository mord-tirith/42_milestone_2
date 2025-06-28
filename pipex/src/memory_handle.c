/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:53:53 by thenriqu          #+#    #+#             */
/*   Updated: 2025/06/20 08:53:57 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

static void	run_exec(char *bin, char **av, char **ep)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (execve(bin, av, ep) == -1)
		{
			ft_perror("pipex: command not found:");
			ft_perror(" %s\n", bin);
		}
		exit(127);
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

	if (ft_strchr(cmd, '"') || ft_strchr(cmd, 39))
		av = ft_quote_split(cmd);
	else
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
