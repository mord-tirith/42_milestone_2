
#include "draw_lib.h"

int	ft_draw_loop(void *g)
{
	t_game	*game;

	game = (t_game *)g;
	if (game->map_render)
		ft_draw_map(game);
	if (game->player->pla_render)
		ft_draw_player(game);
	return (0);
}
