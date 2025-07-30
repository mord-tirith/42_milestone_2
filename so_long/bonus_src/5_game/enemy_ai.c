

#include "so_long_bonus.h"

static int	illegal_move(t_game *game, int x, int y)
{
	char	cell;

	cell = game->map->layout[y][x];
	return (cell == '1' || cell == 'E');
}

static int	check_spike(t_game *game, int x, int y)
{
	int		result;
	char	cell;

	cell = game->map->layout[y][x];
	result = ((cell == '2' && game->move_count % 2) ||
		 (cell == '3' && !(game->move_count % 2)));
	if (result)
		return (2);
	else
		return (1);
}

void	ft_tick_enemies(t_game *game)
{
	int			i;
	int			n_x;
	int			n_y;
	t_entity	*m;

	i = -1;
	while (++i < game->mob_count)
	{
		m = game->mobs[i];
		if (m->state)
			continue;
		n_x = m->tile_x + ((m->dir == 3) - (m->dir == 1));
		n_y = m->tile_y + ((m->dir == 2) - (m->dir == 0));
		if (illegal_move(game, n_x, n_y))
			m->dir = (m->dir + 3) % 4;
		else
		{
			m->tile_x = n_x;
			m->tile_y = n_y;
			m->state = check_spike(game, n_x, n_y);
			m->curr = 0;
		}
	}
}
