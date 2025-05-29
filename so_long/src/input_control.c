
#include "macros.h"
#include "so_long.h"
#include "types.h"



int	ft_key_hook(int key, t_game *game)
{
	if (key == ESC_KEY)
		exit(0);
	if (key == W_KEY)
	{
		game->player.dir = DIR_UP;
		game->player.state = MOVING;
	}
	else if (key == A_KEY)
	{
		game->player.dir = DIR_LEFT;
		game->player.state = MOVING;
	}
	else if (key == S_KEY)
	{	
		game->player.dir = DIR_DOWN;
		game->player.state = MOVING;
	}
	else if (key == D_KEY)
	{
		game->player.dir = DIR_RIGHT;
		game->player.state = MOVING;
	}
	else
		game->player.state = IDLING;
	return (0);
}
