
#include "boot_lib.h"
#include "so_long.h"

static void	boot_t_game(t_game *game)
{
	game->error_bitmask = 0;
	game->move_count = 0;
	game->p_x = 0;
	game->p_y = 0;
	game->coins = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->map = ft_calloc(1, sizeof(t_map));
	game->assets = ft_calloc(1, sizeof(t_assets));
	if (!game->map || !game->assets)
		game->error_bitmask |= MALLOCS_ER;
}

void	ft_boot_game(t_game *game, char *file)
{
	boot_t_game(game);
	if (game->error_bitmask)
		return ;
	game->assets->map_file = file;
	ft_boot_map(game);
	if (game->error_bitmask)
		return ;
	/*
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		game->error_bitmask |= MLXLOAD_ER;
		return ;
	}
	ft_boot_mlx(game);
	if (game->error_bitmask)
		return ;
	ft_boot_assets(game);
	*/
}
