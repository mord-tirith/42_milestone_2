
#include "so_long_bonus.h"

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
	if ((collision == '2' && game->move_count % 2) ||
		(collision == '3' && game->move_count % 2 == 0))
		game->player->state = 2;
	if (game->player->state == 2 && game->player->curr == 9)
		ft_handle_exit(game);
	if (collision == 'C' && !game->player->state)
	{
		game->map->layout[y][x] = '0';
		game->coins -= 1;
	}
	if (collision == 'E' && !game->player->state && !game->coins)
		ft_handle_exit(game);
	return (0);
}

