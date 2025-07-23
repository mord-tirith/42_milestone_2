
#include "bonus_boot_lib.h"
#include <stdlib.h>

void	ft_clean_int_arr(int **arr, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(arr[j]);
		j++;
	}
	free(arr);
}

char	**ft_clean_arr(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static void	deload_assets(t_assets *assets, void *mlx)
{
	int	i;

	if (!assets || !mlx)
		return ;
	i = -1;
	while (MAP_ASSETS[++i])
		mlx_destroy_image(mlx, assets->a_map[i].img);
	i = -1;
	while (i++ < 96)
		mlx_destroy_image(mlx, assets->a_pla[i].img);
}

void	ft_clean_game(t_game *game)
{
	if (game->map)
	{
		if (game->map->arr)
			ft_clean_int_arr(game->map->arr, game->map->y);
		if (game->map->layout)
			ft_clean_arr(game->map->layout);
		free(game->map);
	}
	if (game->assets)
	{
		deload_assets(game->assets, game->mlx);
		free(game->assets);
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}
