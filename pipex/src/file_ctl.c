
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
