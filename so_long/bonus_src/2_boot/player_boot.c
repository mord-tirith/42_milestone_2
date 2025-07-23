
#include "bonus_boot_lib.h"

void	ft_boot_player(t_game *game)
{
	t_player	*p;

	p = game->player;
	p->x = game->p_x * TILE_SIZE;
	p->y = game->p_y * TILE_SIZE;
	p->tile_x = game->p_x;
	p->tile_y = game->p_y;
	p->state = 0;
	p->curr = 0;
	p->dir = 2;
}
