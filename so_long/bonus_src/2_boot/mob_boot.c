

#include "so_long_bonus.h"

static void	boot_mob(t_game *g, int y, int x, int i)
{
	g->mobs[i] = ft_calloc(sizeof(t_entity), 1);
	if (!g->mobs[i])
		return ;
	g->mobs[i]->x = x * TILE_SIZE;
	g->mobs[i]->y = y * TILE_SIZE;
	g->mobs[i]->tile_x = x;
	g->mobs[i]->tile_y = y;
	g->mobs[i]->state = 0;
	g->mobs[i]->curr = 0;
	g->mobs[i]->dir = 2;
}

static int	no_enemies(t_game *g)
{
	g->mobs = NULL;
	return (1);
}

int	ft_boot_mobs(t_game *game)
{
	int			x;
	static int	y;
	static int	i;

	if (!game->mob_count)
		return (no_enemies(game));
	game->mobs = ft_calloc(sizeof(t_entity *), game->mob_count);
	while (game->map->layout[y])
	{
		x = 0;
		while (game->map->layout[y][x])
		{
			if (game->map->layout[y][x] == 'M')
			{
				boot_mob(game, y, x, i);
				if (!game->mobs[i])
					return (0);
				i++;
			}
			x++;
		}
		y++;
	}
	return (1);
}
