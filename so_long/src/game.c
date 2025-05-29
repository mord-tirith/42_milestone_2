#include "macros.h"
#include "so_long.h"
#include "types.h"

static t_game	*boot_game(void *mlx, void *win)
{
	t_game	*game;
	t_point	spawn;

	spawn.x = 1;
	spawn.y = 1;
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx;
	game->win = win;
	ft_boot_player(game, spawn);
	return (game);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	t_game	*game;

	mlx = mlx_init();
	win = mlx_new_window(mlx, WIDTH, HEIGHT, "Blobbing");
	game = boot_game(mlx, win);

	mlx_loop_hook(mlx, ft_game_loop, game);
	mlx_key_hook(win, ft_key_hook, game);
	mlx_loop(mlx);
	return (0);
}
