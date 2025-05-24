
#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>

static int	safe_demap(t_map *map, int *tab)
{
	int		i;

	i = 0;
	while (map->points && map->points[i])
	{
		free(map->points[i]);
		i++;
	}
	if (map->points)
		free(map->points);
	if (tab)
		free(tab);
	free(map);
	return (0);
}

static char	**gnl_split(int fd)
{
	char	*line;
	char	**split_line;

	split_line = NULL;
	line = get_next_line(fd);
	if (line)
		split_line = ft_split(line, ' ');
	if (line)
		free(line);
	return (split_line);
}

static int	*map_line_maker(int fd, int width)
{
	char	**line;
	int		*tab;
	int		i;

	i = 0;
	line = gnl_split(fd);
	if (!line)
		return (NULL);
	tab = malloc(sizeof(int) * width);
	if (!tab)
	{
		free(line);
		return (NULL);
	}
	while (line[i])
	{
		tab[i] = ft_atoi(line[i]);
		free(line[i]);
		i++;
	}
	free(line);
	return (tab);
}

static int	map_maker(t_map *map, int fd)
{
	int	*tab;
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		tab = map_line_maker(fd, map->width);
		if (!tab)
			return (safe_demap(map, NULL));
		map->points[y] = malloc(sizeof(t_point) * map->width);
		if (!map->points[y])
			return (safe_demap(map, tab));
		while (x < map->width)
		{
			map->points[y][x].x = x;
			map->points[y][x].y = y;
			map->points[y][x].z = tab[x];
			x++;
		}
		y++;
		free(tab);
	}
	return (1);
}

t_map	*ft_fd_to_map(char *arg)
{
	t_map	*map;
	int		fd;

	if (ft_valid_map(arg) == -1)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = ft_valid_map(arg);
	map->height = ft_get_height(arg);
	map->points = ft_calloc(map->height, sizeof(t_point *));
	if (!map->points)
	{
		safe_demap(map, NULL);
		return (NULL);
	}
	fd = open(arg, O_RDONLY);
	if (fd < 0 || !(map_maker(map, fd)))
	{
		safe_demap(map, NULL);
		close(fd);
		return (NULL);
	}
	close(fd);
	return (map);
}
