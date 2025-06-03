
#include "so_long.h"

static void	*get_image_for_tile(t_map *map, char tile)
{
	if (tile >= '0' && tile <= '3')
		return (map->map_floor[tile - '0']);
	else if (tile >= 'A' && tile <= 'E')
		return (map->map_walls[tile - 'A']);
	else
		return (map->map_floor[0]);
}

void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*tile;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			tile = get_image_for_tile(&game->map, game->map.grid[y][x]);
			if (tile)
				mlx_put_image_to_window(game->mlx, game->win, tile, x * 128, y * 128);
			x++;
		}
		y++;
	}
}
