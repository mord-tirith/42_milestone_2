
#include "boot_lib.h"
#include "so_long.h"

static void	boot_map(t_assets *a, void *mlx, int *mask)
{
	int			i;
	char		path[20];

	i = 0;
	ft_bzero(path, 20);
	while (MAP_ASSETS[i])
	{
		ft_sprintf(path, 20, "../assets/map/%c.xpm", MAP_ASSETS[i]);
		a->a_map[i] = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
		if (!a->a_map[i])
		{
			*mask |= MLXLOAD_ER;
			ft_printf("Failed to load %s\n", path);
			return ;
		}
		i++;
	}
}

void	ft_boot_assets(t_game *game)
{
	boot_map(game->assets, game->mlx, &game->error_bitmask);
	//TODO: load player and sprites assets
}
