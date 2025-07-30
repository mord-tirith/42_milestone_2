
#include "so_long_bonus.h"

void	run_game(t_game *game)
{
	int	width;
	int	height;

	game->mlx = mlx_init();
	if (!game->mlx)
		ft_handle_exit(game);
	ft_boot_assets(game);
	ft_prepare_frame(game);
	width = game->map->x * TILE_SIZE;
	height = game->map->y * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, width, height, GAME_NAME);
	if (!game->win || game->error_bitmask)
	{
		game->error_bitmask |= MLXLOAD_ER;
		ft_handle_exit(game);
	}
	mlx_hook(game->win, 17, 0, ft_handle_exit, game);
	mlx_key_hook(game->win, ft_key_handler, game);
	mlx_loop_hook(game->mlx, ft_game_loop, game);
	mlx_loop(game->mlx);
}

static int	valid_input(int ac, char **av, int *f)
{
	*f = 0;
	if (ac != 2 && ac != 3)
		return (ft_perror(0, "Use: ./so_long_bonus MAP_FILE.ber\n"));
	if (ac == 3)
	{
		if (ft_strncmp(av[1], "-f", 3) && ft_strncmp(av[2], "-f", 3))
			return (ft_perror(0, "Use: ./so_long_bonus -f MAP_FILE.ber\n"));
		*f = 1;
		if (!ft_strncmp(av[1], "-f", 3))
			return (2);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		file;
	int		forced;
	int		invalid_run;
	t_game	game;

	file = valid_input(ac, av, &forced);
	if (!file)
		return (0);
	invalid_run = ft_valid_map(av[file], forced);
	if (invalid_run)
		return (ft_print_error(invalid_run));
	ft_boot_game(&game, av[file]);
	if (game.error_bitmask)
		return (ft_handle_exit(&game));
	run_game(&game);
}
