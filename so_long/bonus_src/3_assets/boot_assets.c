
# include "bonus_asset_lib.h"

void	ft_boot_assets(t_game *game)
{
	if (!ft_boot_a_player(game->assets, game->mlx) ||
	 !ft_boot_a_map(game->assets, game->mlx) ||
	!ft_boot_a_others(game->assets, game->mlx) ||
	!ft_boot_a_mobs(game->assets, game->mlx))
		game->error_bitmask |= MLXLOAD_ER;
}
