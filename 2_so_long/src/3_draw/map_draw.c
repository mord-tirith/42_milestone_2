
#include "draw_lib.h"
#include "so_long.h"
#include <stdlib.h>

static void	*give_image_ptr(t_game *game, char c)
{
	int		i;
	t_assets *a;

	if (!game || !game->assets)
		return (NULL);
	i = 0;
	a = game->assets;
	while (MAP_ASSETS[i])
	{
		if (c == MAP_ASSETS[i])
			return (a->a_map[i]);
		i++;
	}
	return (a->a_err);
}


void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;
	void	*img;
	t_map	*map;

	if (!game || !game->mlx || !game->win || !game->map)
		return ;
	map = game->map;
	y = 0;
	while (map->arr[y])
	{
		x = 0;
		while (map->arr[y][x])
		{
			img = give_image_ptr(game, map->arr[y][x]);
			ft_printf("(%d,%d) -> '%c'  ptr=%p\n", x, y, map->arr[y][x], img);
			if (!img)
				return ;
			mlx_put_image_to_window(game->mlx, game->win, img,
						   x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
