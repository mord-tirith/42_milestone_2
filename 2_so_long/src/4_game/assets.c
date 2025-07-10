
#include "so_long.h"

static int	boot_a_map(t_assets *a, void *mlx)
{
	int			i;
	static char	path[19];

	i = 0;
	while (MAP_ASSETS[i])
	{
		ft_sprintf(path, 19, "./assets/map/%c.xpm", MAP_ASSETS[i]);
		a->a_map[i] = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
		if (!a->a_map[i])
		{
			ft_printf("%couldn't load asset %s\n", path);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	boot_a_err(t_assets *a, void *mlx)
{
	char	*path;

	path = "./assets/a_err.xpm";
	a->a_err = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
	if (!a->a_err)
		return (0);
	return (1);
}

static int	boot_c_e(t_assets *a, void *mlx)
{
	char	*path;

	path = "./assets/others/C.xpm";
	a->a_coin = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
	path = "./assets/others/E.xpm";
	a->a_exit_c = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
	path = "./assets/others/W.xpm";
	a->a_exit_o = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
	if (!a->a_coin || !a->a_exit_c || !a->a_exit_o)
		return (0);
	return (1);
}

static int	boot_a_pla(t_assets *a, void *mlx)
{
	int			i;
	static char	path[22];

	i = 0;
	while (i < 4)
	{
		ft_sprintf(path, 22, "./assets/player/%d.xpm", i);
		a->a_pla[i] = mlx_xpm_file_to_image(mlx, path, &a->w, &a->h);
		if (!a->a_pla[i])
		{
			ft_printf("Couldn't load file %s\n", path);
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_boot_assets(t_game *game)
{
	if (!boot_a_map(game->assets, game->mlx) ||
	!boot_a_err(game->assets, game->mlx) || !boot_a_pla(game->assets, game->mlx) ||
	!boot_c_e(game->assets, game->mlx))
		game->error_bitmask |= MLXLOAD_ER;
}
