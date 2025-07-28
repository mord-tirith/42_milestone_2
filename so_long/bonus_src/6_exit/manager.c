
#include "bonus_exit_lib.h"
#include "so_long_bonus.h"

static void	delete_game(t_game *g)
{
	if (g->win)
		mlx_destroy_window(g->mlx, g->win);
	if (g->mlx && LIN_FLAG)
		mlx_destroy_display(g->mlx);
	if (g->mlx)
		free(g->mlx);
}

int	ft_handle_exit(t_game *game)
{
	int	exit_code;

	exit_code = ft_print_error(game->error_bitmask);
	if (game->assets)
		ft_free_assets(game->assets, game->mlx, game->frame);
	ft_free_pointers(game);
	delete_game(game);
	exit(exit_code);
	return (0);
}
