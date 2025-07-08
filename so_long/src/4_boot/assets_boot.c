
#include "so_long.h"

/*
static void	boot_a_player(t_game *game)
{
	return ;
}
*/

static void	boot_a_map(t_game *game)
{
	int		i;
	int		hw;
	char	*path;

	i = 0;
	path = ft_strdup("./assets/map/ .xpm");
	if (!path)
		return ;
	while (MAP_ASSETS[i])
	{
		path[13] = MAP_ASSETS[i];
		game->assets.a_map[(int)MAP_ASSETS[i]] = mlx_xpm_file_to_image(
			game->mlx, path, &hw, &hw);
		i++;
	}
	free(path);
}

#include <stdlib.h>

void	ft_boot_assets(t_game *game)
{
	int	i = 0;

	while (i < 128)
	{
		game->assets.a_map[i] = NULL;
		i++;
	}
	boot_a_map(game);
}
