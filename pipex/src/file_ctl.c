
#include "pipex.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

static char	**get_paths(char *cmd, char **ep)
{
	char	*path;
	char	*temp;
	char	**split;
	size_t	i;

	i = 0;
	while (ep[i] && !ft_strnstr(ep[i], "PATH=", 5))
		i++;
	split = ft_split(&ep[i][5], ':');
	if (!split)
		return (ft_bad_split(split));
	i = -1;
	while (split[++i])
	{
		path = ft_strjoin("/", cmd);
		if (!path)
			return (ft_bad_split(split));
		temp = ft_strjoin(split[i], path);
		if (!temp)
			return (ft_bad_split(split));
		free(split[i]);
		split[i] = temp;
		free(path);
	}
	return (split);
}

char	*ft_get_bin(char *cmd, char **ep)
{
	char	*bin;
	char	**paths;
	size_t	i;

	if (!ep || !ep[0])
	{
		bin = ft_strjoin("/bin/", cmd);
		return (bin);
	}
	paths = get_paths(cmd, ep);
	i = 0;
	while (paths[i] && access(paths[i], X_OK) != 0)
		i++;
	if (!paths[i])
	{
		ft_clean_split(paths);
		return (ft_strdup(cmd));
	}
	bin = ft_strdup(paths[i]);
	ft_clean_split(paths);
	return (bin);
}


static void	file_error(char *file, int type)
{
	if (type == EXIST_ERROR)
		ft_perror("pipex: no such file or directory:");
	else if (type == PERMS_ERROR)
		ft_perror("pipex: permission denied:");
	ft_perror(" %s\n", file);
	ft_error_handler(BAD_OPEN);
}

int	ft_fd_opener(char *file, int io)
{
	int		fd;

	fd = -1;
	if (io == MODE_READ)
	{
		if (access(file, F_OK) != 0)
			file_error(file, EXIST_ERROR);
		if (access(file, R_OK) != 0)
			file_error(file, PERMS_ERROR);
		fd = open(file, READ_FLAGS);
	}
	else if (io == MODE_WRIT)
	{
		if (access(file, F_OK) == 0)
		{
			if (access(file, W_OK) != 0)
				file_error(file, PERMS_ERROR);
		}
		fd = open(file, WRIT_FLAGS);
	}
	return (fd);
}
