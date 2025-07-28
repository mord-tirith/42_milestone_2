#include "so_long.h"
#include <stdlib.h>

static void	finish_assets(t_assets *a, void *m)
{
	if (a->a_exit_c)
		mlx_destroy_image(m, a->a_exit_c);
	if (a->a_exit_o)
		mlx_destroy_image(m, a->a_exit_o);
	if (a)
		free(a);
}

void	ft_clean_assets(t_assets *assets, void *mlx)
{
	int	i;

	i = -1;
	while (++i < 52)
	{
		if (assets->a_map[i])
			mlx_destroy_image(mlx, assets->a_map[i]);
	}
	i = -1;
	while (++i < 4)
	{
		if (assets->a_pla[i])
			mlx_destroy_image(mlx, assets->a_pla[i]);
	}
	if (assets->a_err)
		mlx_destroy_image(mlx, assets->a_err);
	if (assets->a_coin)
		mlx_destroy_image(mlx, assets->a_coin);
	return (finish_assets(assets, mlx));
}

void	ft_clean_map(t_map *map)
{
	int	i;

	if (map->arr)
	{
		i = -1;
		while (++i < map->y)
			free(map->arr[i]);
		free(map->arr);
	}
	if (map->layout)
	{
		i = -1;
		while (map->layout[++i])
			free(map->layout[i]);
		free(map->layout);
	}
	free(map);
}

int	ft_handle_exit(t_game *game)
{
	int	code;

	code = ft_print_error(game->error_bitmask);
	if (game->map)
		ft_clean_map(game->map);
	if (game->assets)
		ft_clean_assets(game->assets, game->mlx);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx && LIN_FLAG)
		mlx_destroy_display(game->mlx);
	if (game->mlx)
		free(game->mlx);
	if (game->player)
		free(game->player);
	exit(code);
	return(0);
}

void	ft_win_game(t_game *game)
{
	ft_printf("Victory! Your move count:\n%d", game->move_count);
	ft_handle_exit(game);
}
