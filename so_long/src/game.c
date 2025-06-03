#include "macros.h"
#include "so_long.h"
#include "types.h"

static t_point	*locate_spawn(char **map_grid)
{
	int		x;
	int		y;
	t_point	*spawn_point;

	x = 0;
	y = 0;
	while (!ft_strchr(map_grid[y], 'P'))
		y++;
	while (map_grid[y][x] != 'P')
		x++;
	spawn_point = malloc(sizeof(t_point));
	if (!spawn_point)
		return (NULL);
	spawn_point->x = x;
	spawn_point->y = y;
	return (spawn_point);
}

static t_game	*boot_game(void *mlx, char *map)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx = mlx;
	game->map = *ft_create_map(map);
	ft_load_map_assets(game);
	game->win = mlx_new_window(mlx, game->map.width * 128, game->map.height * 128, "Blobbing");
	ft_remake_walls(&game->map);
	ft_remake_floor(&game->map);
	ft_draw_map(game);
	ft_boot_player(game, *locate_spawn(game->map.grid));
	return (game);
}

int	main(int ac, char **av)
{
	void	*mlx;
	t_game	*game;

	if (ac != 2 || !ft_valid_map(av[1]))
		return (1);

	mlx = mlx_init();
	game = boot_game(mlx, av[1]);

	if (!ft_flood_fill(game))
		exit(1);
	mlx_loop_hook(mlx, ft_game_loop, game);
	mlx_key_hook(game->win, ft_key_hook, game);
	mlx_loop(mlx);
	return (0);
}
