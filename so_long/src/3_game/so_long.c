
#include "game_lib.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (1);
	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		ft_resolve_error(MALLOCS_ER);
	game->assets.map_file = av[1];
	ft_valid_map(game);
	if (game->error_bitmask)
		ft_resolve_error(game->error_bitmask);
	ft_boot_map(game);
	ft_boot_mlx(game);
	ft_boot_assets(game);
	if (game->error_bitmask)
		ft_resolve_error(game->error_bitmask);
	ft_draw_map(game);
	mlx_key_hook(game->win, ft_keys_hook, &game);
	mlx_hook(game->win, 17, 0, (void *)ft_exit_game, game);
	mlx_loop(game->mlx);
}
