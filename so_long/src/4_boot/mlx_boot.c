
#include "so_long.h"

void	ft_boot_mlx(t_game *game)
{
	int	x;
	int	y;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		game->error_bitmask |= MLXLOAD_ER;
		return ;
	}
	x = game->map.x * TILE_SIZE;
	y = game->map.y * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, x, y, "So Long");
	if (!game->win)
		game->error_bitmask |= MLXLOAD_ER;
}
