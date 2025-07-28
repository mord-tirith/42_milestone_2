
#include "bonus_draw_lib.h"

static void	update_enemy(t_game *g, t_entity *e)
{
	(void)g;
	(void)e;
}

void	ft_tick_enemies(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->mob_count)
		update_enemy(game, game->mobs[i]);
}
