
#include "draw_lib.h"

void	ft_draw_player(t_game *game)
{
	int			x;
	int			y;
	t_player	*p;

	p = game->player;
	if (!p->pla_render)
		return ;
	x = p->x * TILE_SIZE;
	y = p->y * TILE_SIZE;
	mlx_put_image_to_window(game->mlx, game->win,
			game->assets->a_pla[p->dir], x, y);
	p->pla_render = 0;
	game->map_render = 0;
}

