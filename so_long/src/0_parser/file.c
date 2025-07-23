
#include "parse_lib.h"
#include <fcntl.h>
#include <unistd.h>

static char	**bad_array(char **arr, int fd)
{
	int	i;

	if (fd >= 0)
		close(fd);
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

static int	map_row_size(char *file)
{
	int		fd;
	int		rows;
	char	buf;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	rows = 1;
	while (read(fd, &buf, 1) > 0)
	{
		if (buf == '\n')
			rows++;
	}
	close(fd);
	return (rows);
}

static char	**return_map(int fd, char **map, int size)
{
	int		i;
	char	*temp;

	temp = get_next_line(fd);
	i = 0;
	while (i < size && temp)
	{
		map[i] = ft_strtrim(temp, "\n");
		if (!map[i])
			return (bad_array(map, fd));
		if (temp)
			free(temp);
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

static char	**load_map(char *file)
{
	int		fd;
	int		n;
	char	**map;

	n = map_row_size(file);
	if (n <= 0)
		return (NULL);
	map = ft_calloc(n, sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (bad_array(map, fd));
	return (return_map(fd, map, n));
}

void	ft_file_check(t_validators *v)
{
	int	i;

	i = ft_strlen(v->map_file);
	if (i < 4)
		v->error_mask |= BERFILE_ER;
	else
	{
		if (ft_strncmp(v->map_file + (i - 4), ".ber", 4))
			v->error_mask |= BERFILE_ER;
	}
	if (!v->error_mask)
		v->arr = load_map(v->map_file);
	if (!v->arr)
		v->error_mask |= MAPFILE_ER;
}
