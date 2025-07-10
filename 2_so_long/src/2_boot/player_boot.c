
#include "boot_lib.h"
#include "so_long.h"

void	ft_boot_player(t_game *game)
{
	t_player	*p;

	p = game->player;
	p->x = game->p_x;
	p->y = game->p_y;
	p->dir = 2;
	p->pla_render = 1;
}
