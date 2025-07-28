
#include "so_long.h"
#include <unistd.h>


void	run_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_handle_exit(game);
	width = game->map->x * TILE_SIZE;
	height = game->map->y * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, GAME_NAME);
	if (!game->win)
		ft_handle_exit(game);
	mlx_hook(game->win, 17, 0, ft_handle_exit, game);
	mlx_key_hook(game->win, ft_key_handler, game);
	ft_boot_assets(game);
	if (game->error_bitmask)
		ft_handle_exit(game);
	mlx_loop_hook(game->mlx, ft_draw_loop, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	int		invalid_run;
	t_game	game;

	if (ac != 2)
		return (ft_perror(1, "%s", "Use: ./so_long MAP_FILE.ber\n"));
	invalid_run = ft_valid_map(av[1]);
	if (invalid_run)
		return (ft_print_error(invalid_run));
	ft_boot_game(&game, av[1]);
	if (game.error_bitmask)
		return (ft_handle_exit(&game));
	run_game(&game);
}
