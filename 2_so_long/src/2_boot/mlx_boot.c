
#include "boot_lib.h"
#include "so_long.h"

void	ft_boot_mlx(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		game->error_bitmask |= MLXLOAD_ER;
		return ;
	}
	width = game->map->x * TILE_SIZE;
	height = game->map->y * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, GAME_NAME);
	if (!game->win)
		game->error_bitmask |= MLXLOAD_ER;
}
