
#include "macros.h"
#include "so_long.h"


static void	handle_move(int key, t_being *p)
{
	if (key == W_KEY)
	{
		p->dir = DIR_UP;
		p->position.y -= 1;
	}
	else if (key == A_KEY)
	{
		p->dir = DIR_LEFT;
		p->position.x -= 1;
	}
	else if (key == S_KEY)
	{
		p->dir = DIR_DOWN;
		p->position.y += 1;
	}
	else
	{
		p->dir = DIR_RIGHT;
		p->position.x += 1;
	}
}

int	ft_key_hook(int key, t_game *game)
{
	if (key == ESC_KEY)
		exit(0);
	if (game->player.state == MOVING)
		return (0);
	if (key == W_KEY || key == A_KEY ||
		key == S_KEY || key == D_KEY)
	{
		game->player.origin = game->player.position;
		handle_move(key, &game->player);
		game->player.animation_c = 0;
		game->player.animation_t = 1200;
		game->player.state = MOVING;
		game->player.walk[game->player.dir]->frame = 0;
		game->player.walk[game->player.dir]->delay_count = 0;
	}
	return (0);
}
