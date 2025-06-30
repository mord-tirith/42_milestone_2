#include "so_long.h"

void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;
	void	*img;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			tile = game->map.arr[y][x];
			img = game->assets.a_map[(int)tile];
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

