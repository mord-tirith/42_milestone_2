
#include "so_long.h"
#include <stdlib.h>

static void	free_map_assets(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (MAP_ASSETS[i])
	{
		j = (int)MAP_ASSETS[i];
		if (game->assets.a_map[j])
			mlx_destroy_image(game->mlx, game->assets.a_map[j]);
		i++;
	}
}

/*
static void	free_sprite_assets(t_game *game)
{
	return ; // TODO: clean up player, coin and exit assets
}
*/

static void	free_2d_array(char **arr, int y)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (i < y)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_exit_game(t_game *game)
{
	int	mask;

	mask = game->error_bitmask;
	free_2d_array(game->map.arr, game->map.y);
	free_2d_array(game->map.layout, game->map.y);
	free_map_assets(game);
	//free_sprite_assets(game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (LIN_FLAG && game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_printf("Total moves: %d", game->move_count);
	free(game);
	if (mask)
		ft_resolve_error(mask);
	exit(0);
}
