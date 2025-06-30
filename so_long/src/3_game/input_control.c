
#include "so_long.h"

static void	move_player(t_game *game, int x, int y)
{
	char	target;

	target = game->map.layout[game->p_y + y][game->p_x + x];
	if (target == '1')
		return ;
	if (target == 'E')
	{
		if (game->coins == 0)
			return ; // <- TODO game won function here
		return ;
	}
	if (target == 'C')
	{
		game->coins -= 1;
		game->map.layout[game->p_y + y][game->p_x + x] = '0';
	}
	game->p_x += x;
	game->p_y += y;
	game->move_count += 1;
}

int	ft_keys_hook(int key, t_game *game)
{
	if (key == KEY_ESC)
		ft_exit_game(game);
	else if (key == KEY_W || key == KEY_UP)
		move_player(game, 0, -1);
	else if (key == KEY_A || key == KEY_LEFT)
		move_player(game, -1, 0);
	else if (key == KEY_S || key == KEY_DOWN)
		move_player(game, 0, 1);
	else if (key == KEY_D || key == KEY_RIGHT)
		move_player(game, 1, 0);
	return (0);
}


