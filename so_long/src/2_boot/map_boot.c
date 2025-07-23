
#include "boot_lib.h"
#include "so_long.h"
#include <fcntl.h>
#include <unistd.h>

static int	row_count(char *file)
{
	int		fd;
	int		rows;
	char	buffer;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	rows = 1;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
			rows++;
	}
	close(fd);
	return (rows);
}

static char	**copy_map(int fd, char **map, int size)
{
	int		i;
	char	*temp;

	temp = get_next_line(fd);
	i = 0;
	while (i < size && temp)
	{
		map[i] = ft_strtrim(temp, "\n");
		if (!map[i])
		{
			close(fd);
			return (ft_clean_arr(map));
		}
		free(temp);
		temp = get_next_line(fd);
		i++;
	}
	close(fd);
	return (map);
}

static char **load_map(char *file)
{
	int		fd;
	int		size;
	char	**map;

	size = row_count(file);
	if (size < 0)
		return (NULL);
	map = ft_calloc(size, sizeof(char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (ft_clean_arr(map));
	return (copy_map(fd, map, size));
}

static void	get_p_yx(t_game *game)
{
	int		i;
	char	*chr;
	char	**map;

	map = game->map->layout;
	i = 1;
	while (map[i])
	{
		chr = ft_strchr(map[i], 'P');
		if (chr)
		{
			game->p_y = i;
			game->p_x = chr - map[i];
			return ;
		}
		i++;
	}
}

void	ft_boot_map(t_game *game)
{
	int	i;

	game->map->layout = load_map(game->assets->map_file);
	if (!game->map->layout)
		game->error_bitmask |= MALLOCS_ER;
	game->map->x = ft_strlen(game->map->layout[0]);
	i = 0;
	while (game->map->layout[i])
		i++;
	game->map->y = i;
	ft_detail_map(game->map);
	if (!game->map->arr)
		game->error_bitmask |= MALLOCS_ER;
	get_p_yx(game);
}
