
#include "so_long_bonus.h"

static int legal_move(t_game *game, int dir)
{
	int	x;
	int	y;

	x = game->player->tile_x;
	y = game->player->tile_y;
	if (dir == UP)
		y--;
	else if (dir == LEFT)
		x--;
	else if (dir == DOWN)
		y++;
	else if (dir == RIGHT)
		x++;
	game->player->dir = dir;
	if (game->map->layout[y][x] == 'E' && game->coins)
		return (0);
	return (game->map->arr[y][x] == 49);
}

void	ft_control_player(int key, t_game *game)
{
	int			temp_x;
	int			temp_y;
	t_player	*p;

	p = game->player;
	temp_x = p->tile_x;
	temp_y = p->tile_y;
	if (p->state)
		return ;
	if ((key == KEY_W || key == KEY_UP) && legal_move(game, UP))
		p->tile_y -= 1;
	else if ((key == KEY_S || key == KEY_DOWN) && legal_move(game, DOWN))
		p->tile_y += 1;
	else if ((key == KEY_A || key == KEY_LEFT) && legal_move(game, LEFT))
		p->tile_x -= 1;
	else if ((key == KEY_D || key == KEY_RIGHT) && legal_move(game, RIGHT))
		p->tile_x += 1;
	if (temp_y != p->tile_y || temp_x != p->tile_x)
	{	
		p->state = 1;
		p->curr = 0;
		game->move_count++;
	}
}

int	ft_key_handler(int key, void *g)
{
	t_game	*game;

	game = (t_game *)g;
	if (key == KEY_W || key == KEY_UP || key == KEY_A || key == KEY_LEFT ||
	 key == KEY_S || key == KEY_DOWN || key == KEY_D || key == KEY_RIGHT)
		ft_control_player(key, game);
	else if (key == KEY_ESC)
			ft_handle_exit(game);
	return (0);
}


