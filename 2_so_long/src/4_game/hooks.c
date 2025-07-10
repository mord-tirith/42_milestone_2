
#include "so_long.h"

static void	try_move(t_game *game, int y, int x, int dir)
{
	int		x2;
	int		y2;
	char	**map;

	x2 = game->player->x + x;
	y2 = game->player->y + y;
	map = game->map->layout;
	if (map[y2][x2] != '1' && map[y2][x2] != 'E')
	{
		game->player->y = y2;
		game->player->x = x2;
		game->player->dir = dir;
		game->player->pla_render = 1;
		game->map_render = 1;
		if (map[y2][x2] == 'C')
		{	
			game->map->layout[y2][x2] = '0';
			game->coins -= 1;
		}
		game->move_count += 1;
	}
	if (map[y2][x2] == 'E' && !game->coins)
		ft_win_game(game);
}

int	ft_key_handler(int key, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	if (key == KEY_ESC)
		ft_handle_exit(game);
	else if (key == KEY_W || key == KEY_UP)
		try_move(game, -1, 0, UP);
	else if (key == KEY_A || key == KEY_LEFT)
		try_move(game, 0, -1, LEFT);
	else if (key == KEY_S || key == KEY_DOWN)
		try_move(game, 1, 0, DOWN);
	else if (key == KEY_D || key == KEY_RIGHT)
		try_move(game, 0, 1, RIGHT);
	return (0);
}
