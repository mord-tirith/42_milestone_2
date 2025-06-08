
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
	while (ep[i] && !ft_strstr(ep[i], "PATH="))
		i++;
	path = ft_strjoin("/", cmd);
	if (!path)
		ft_error_handler(BAD_MALL);
	split = ft_split(ep[i], ':');
	if (!split)
		return (ft_bad_split(split));
	i = 0;
	while (split[i])
	{
		temp = ft_strjoin(split[i], path);
		if (!temp)
			return (ft_bad_split(split));
		free(split[i]);
		split[i] = temp;
		i++;
	}
	return (split);
}

char	*ft_get_bin(char *cmd, char **ep)
{
	char	*bin;
	char	**paths;
	size_t	i;

	paths = get_paths(cmd, ep);
	i = 0;
	while (paths[i] && access(paths[i], X_OK) != 0)
		i++;
	if (!paths[i])
		return (cmd);
	bin = ft_strdup(paths[i]);
	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
	return (bin);
}

int	ft_fd_opener(char *file, int io)
{
	int	fd;

	if (io == MODE_READ)
		fd = open(file, READ_FLAGS);
	else if (io == MODE_WRIT)
		fd = open(file, WRIT_FLAGS);
	else
		ft_error_handler(BAD_OPEN);
	if (fd < 0)
		ft_error_handler(BAD_OPEN);
	return (fd);
}
