#include "so_long.h"
#include "types.h"
#include <stdlib.h>

static int	count_coins(char **map_arr)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (map_arr[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

static void	flood_coins(char **grid, t_map map, int y, int x, int *coins)
{
	if (x < 0 || y < 0 || x >= map.width || y >= map.height ||
		grid[y][x] == '1' || grid[y][x] == 'E' || grid[y][x] == 'X')
		return ;
	if (grid[y][x] == 'C')
		(*coins)--;
	grid[y][x] = 'X';
	flood_coins(grid, map, y - 1, x, coins);
	flood_coins(grid, map, y + 1, x, coins);
	flood_coins(grid, map, y, x - 1, coins);
	flood_coins(grid, map, y, x + 1, coins);
}

static int	flood_exit(char **grid, t_map map, int y, int x)
{
	int	i;

	if (x < 0 || y < 0 || x >= map.width || y >= map.height ||
		grid[y][x] == '1' || grid[y][x] == 'V')
		return (0);
	if (grid[y][x] == 'E')
		return (1);
	grid[y][x] = 'V';
	i = 0;
	i += flood_exit(grid, map, y - 1, x);
	i += flood_exit(grid, map, y + 1, x);
	i += flood_exit(grid, map, y, x - 1);
	i += flood_exit(grid, map, y, x + 1);
	return (i);
}

char	**make_grid(t_map map)
{
	int		i;
	char	**grid;

	grid = ft_calloc(map.height + 1, sizeof(char *));
	if (!grid)
		return (NULL);
	i = -1;
	while (map.grid[++i])
	{
		grid[i] = ft_strdup(map.grid[i]);
		if (!grid[i])
		{
			while (--i)
				free(grid[i]);
			free(grid);
			return (NULL);
		}
	}
	return (grid);
}

static int	safe_return(char **to_del, int i, int val)
{
	while (--i >= 0)
		free(to_del[i]);
	free(to_del);
	return (val);
}

int	ft_flood_fill(t_game *game)
{
	int		total_coins;
	char	**grid;
	t_point	start;

	start = game->player.position;
	grid = make_grid(game->map);
	if (!grid)
		return (0);
	total_coins = count_coins(grid);
	if (!total_coins)
		return (safe_return(grid, game->map.height, 0));
	flood_coins(grid, game->map, start.y, start.x, &total_coins);
	if (total_coins)
		return (safe_return(grid, game->map.height, 0));
	if (flood_exit(grid, game->map, start.y, start.x))
		return (safe_return(grid, game->map.height, 1));
	return (safe_return(grid, game->map.height, 0));
}
