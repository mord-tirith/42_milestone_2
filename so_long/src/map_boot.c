
#include "so_long.h"
#include "types.h"

static void	load_floor(void *target[4], void *mlx)
{
	int	t;

	target[0] = mlx_xpm_file_to_image(mlx, "./assets/map/floor0.xpm",&t, &t);
	target[1] = mlx_xpm_file_to_image(mlx, "./assets/map/floor1.xpm",&t, &t);
	target[2] = mlx_xpm_file_to_image(mlx, "./assets/map/floor2.xpm",&t, &t);
	target[3] = mlx_xpm_file_to_image(mlx, "./assets/map/floor3.xpm",&t, &t);
}

static void	load_walls(void *target[8], void *mlx)
{
	int	t;

	target[0] = mlx_xpm_file_to_image(mlx, "./assets/map/wall_A.xpm",&t, &t);
	target[1] = mlx_xpm_file_to_image(mlx, "./assets/map/wall_B.xpm",&t, &t);
	target[2] = mlx_xpm_file_to_image(mlx, "./assets/map/wall_C.xpm",&t, &t);
	target[3] = mlx_xpm_file_to_image(mlx, "./assets/map/wall_D.xpm",&t, &t);
	target[4] = mlx_xpm_file_to_image(mlx, "./assets/map/wall_E.xpm",&t, &t);
}

void	ft_load_map_assets(t_game *game)
{
	t_map	*map;

	if (!game)
		return ;
	map = &game->map;
	load_floor(map->map_floor, game->mlx);
	load_walls(map->map_walls, game->mlx);
}
