
#include "boot_lib.h"

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

int main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (0);
	boot_t_game(&game);
	game.assets->map_file = av[1];
	ft_boot_map(&game);
	ft_boot_mlx(&game);
	ft_boot_assets(&game);

	ft_clean_game(&game);
	return (0);
}
