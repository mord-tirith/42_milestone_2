
#include "boot_lib.h"
#include "so_long.h"

static void	boot_map(t_assets *a, void *mlx, int *mask)
{
	int			i;
	char		path[23];

	i = 0;
	ft_bzero(path, 23);
	while (MAP_ASSETS[i])
	{
		ft_sprintf(path, 23, "./assets/map/%c.xpm", MAP_ASSETS[i]);
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

static void	boot_error(t_assets *a, void *mlx, int *mask)
{
	int		i;
	t_img	img;

	img.img = mlx_new_image(mlx, TILE_SIZE, TILE_SIZE);
	if (!img.img)
	{
		*mask |= MLXLOAD_ER;
		return ;
	}
	img.data = (int *)mlx_get_data_addr(mlx, &img.bpp, &img.line, &img.endian);
	if (!img.data)
	{
		*mask |= MLXLOAD_ER;
		return ;
	}
	i = 0;
	while (i < TILE_SIZE * TILE_SIZE)
		img.data[i++] = 0xFF00FF;
	a->a_err = img.img;
}

void	ft_boot_assets(t_game *game)
{
	boot_map(game->assets, game->mlx, &game->error_bitmask);
	if (game->error_bitmask)
		return ;
	boot_error(game->assets, game->mlx, &game->error_bitmask);
	if (game->error_bitmask)
		return ;
	//TODO: load player and sprites assets
}
