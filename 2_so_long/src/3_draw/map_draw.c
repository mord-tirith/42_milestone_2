
#include "draw_lib.h"
#include "so_long.h"

static void	add_exit(t_game *game)
{
	int		x;
	int		y;
	void	*asset;

	x = game->map->e_x * TILE_SIZE;
	y = game->map->e_y * TILE_SIZE;
	if (game->coins)
		asset = game->assets->a_exit_c;
	else
		asset = game->assets->a_exit_o;
	mlx_put_image_to_window(game->mlx, game->win, asset, x, y);
}

static void	add_coins_exit(t_game *game)
{
	int		x;
	int		y;
	char	**map;

	y = 1;
	map = game->map->layout;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win,
					game->assets->a_coin, x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
	add_exit(game);
}

static void	run_draw_map(t_game *game)
{
	int			y;
	int			x;
	t_map		*m;
	t_assets	*a;

	m = game->map;
	a = game->assets;
	y = 0;
	while (y < m->y)
	{
		x = 0;
		while (x < m->x)
		{
			if (m->arr[y][x] >= 0)
				mlx_put_image_to_window(game->mlx, game->win,
					a->a_map[m->arr[y][x]], x * TILE_SIZE, y * TILE_SIZE);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					a->a_err, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	add_coins_exit(game);
	game->map_render = 0;
}

void	ft_draw_map(t_game *game)
{
	if (game->map_render)
		run_draw_map(game);
}
