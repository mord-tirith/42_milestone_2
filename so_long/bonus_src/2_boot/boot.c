
#include "bonus_boot_lib.h"

static void	find_exit(t_map *map)
{
	int		y;
	int		x;
	char	**arr;

	arr = map->layout;
	y = 1;
	while (arr[y])
	{
		x = 1;
		while (arr[y][x])
		{
			if (arr[y][x] == 'E')
			{
				map->e_x = x;
				map->e_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	count_coins(int *coins, char **map)
{
	int	y;
	int	x;

	y = 1;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				*coins += 1;
			x++;
		}
		y++;
	}
}

static void	boot_t_game(t_game *game)
{
	game->error_bitmask = 0;
	game->move_count = 0;
	game->map_render = 1;
	game->p_x = 0;
	game->p_y = 0;
	game->coins = 0;
	game->mlx = NULL;
	game->win = NULL;
	game->map = ft_calloc(1, sizeof(t_map));
	game->assets = ft_calloc(1, sizeof(t_assets));
	game->player = ft_calloc(1, sizeof(t_player));
	if (!game->map || !game->assets || !game->player)
		game->error_bitmask |= MALLOCS_ER;
}

void	ft_boot_game(t_game *game, char *file)
{
	boot_t_game(game);
	if (game->error_bitmask)
		return ;
	game->assets->map_file = file;
	ft_boot_map(game);
	if (game->error_bitmask)
		return ;
	count_coins(&game->coins, game->map->layout);
	find_exit(game->map);
	ft_boot_player(game);
}
