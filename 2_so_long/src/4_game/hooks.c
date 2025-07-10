
#include "so_long.h"
#include <stdlib.h>

void	ft_clean_map(t_map *map)
{
	int	i;

	if (map->arr)
	{
		i = -1;
		while (map->arr[++i])
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
	if (game->map)
		ft_clean_map(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx && LIN_FLAG)
		mlx_destroy_display(game->mlx);
	if (game->assets)
		free(game->assets);
	if (game->mlx)
		free(game->mlx);
	exit(0);
	return(0);
}

int	ft_key_handler(int key, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	if (key == KEY_ESC)
		ft_handle_exit(game);
	return (0);
}
