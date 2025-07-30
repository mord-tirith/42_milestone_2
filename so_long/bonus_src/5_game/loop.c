
#include "so_long_bonus.h"

static void	win_game(char c,t_game *game)
{
	int	moves;

	if (c == 'E' && game->player->state && !game->coins)
	{
		moves = game->move_count;
		ft_printf("Victory!\nYour move count: %d\n", moves);
		ft_handle_exit(game);
	}
}

static int	spike_death(t_game *game)
{
	char	cell;

	cell = game->map->layout[game->player->tile_y][game->player->tile_x];
	return ((cell == '2' && game->move_count % 2) ||
		 (cell == '3' && !(game->move_count % 2)));
}

static int	check_death(t_game *game)
{
	int			i;
	t_entity	*m;

	if (spike_death(game))
		return (1);
	i = -1;
	while (++i < game->mob_count)
	{
		m = game->mobs[i];
		if (m->state == 2)
			continue ;
		if (m->tile_x == game->player->tile_x && m->tile_y == game->player->tile_y)
			return (1);
	}
	return (0);
}

int	ft_game_loop(void *g)
{
	int		x;
	int		y;
	char	collision;
	t_game *game;

	game = (t_game *)g;
	ft_draw_loop(g);
	x = game->player->tile_x;
	y = game->player->tile_y;
	collision = game->map->layout[y][x];
	if (game->player->state != 2 && check_death(game))
	{
		game->player->state = 2;
		game->player->curr = 0;
	}
	if (game->player->state == 2 && game->player->curr >= 9)
		ft_handle_exit(game);
	if (collision == 'C' && !game->player->state)
	{
		game->map->layout[y][x] = '0';
		game->coins -= 1;
	}
	win_game(collision, game);
	return (0);
}

