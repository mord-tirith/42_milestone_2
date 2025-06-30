
#include "parse_lib.h"
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

static int	map_height(char *file)
{
	int		map_size;
	int		fd;
	char	buffer;

	map_size = -1;
	fd = open(file, O_RDONLY);
	if (fd >= 0)
	{
		map_size = 0;
		while (read(fd, &buffer, 1) > 0)
		{
			if (buffer == '\n')
				map_size++;
		}
		close(fd);
	}
	return (map_size);
}

static char **snip_slash_ns(char **map)
{
	int	y;
	int	x;

	if (!map)
		return (NULL);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '\n')
				map[y][x] = '\0';
			x++;
		}
		y++;
	}
	return (map);
}

static char **load_map(char *file)
{
	int		fd;
	int		i;
	char	*temp;
	char	**map;

	i = map_height(file);
	map = NULL;
	if (i < 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd >= 0)
	{
		map = ft_calloc(i + 1, sizeof(char *));
		if (!map)
			return (NULL);
		i = 0;
		temp = get_next_line(fd);
		while (temp)
		{
			map[i] = temp;
			temp = get_next_line(fd);
			i++;
		}
	}
	return (snip_slash_ns(map));
}

static int	is_ber(char *file)
{
	size_t	size;

	size = ft_strlen(file);
	if (size >= 4)
	{
		if (!ft_strncmp(file + (size - 4), ".ber", 4))
			return (1);
	}
	return (0);
}

void	ft_file_check(t_game *game)
{
	int	fd;

	fd = open(game->assets.map_file, O_RDONLY);
	if (fd >= 0)
	{
		close(fd);
		if (!is_ber(game->assets.map_file))
			game->error_bitmask |= BERFILE_ER;
		game->map.layout = load_map(game->assets.map_file);
		if (game->map.layout)
			return ;
	}
	game->error_bitmask |= MAPFILE_ER;
}

