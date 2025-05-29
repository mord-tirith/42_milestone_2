#include "so_long.h"
#include "types.h"

static void	move_player(t_game *game)
{
	if (game->player.dir == DIR_UP)
		game->player.position.y -= 1;
	else if (game->player.dir == DIR_LEFT)
		game->player.position.x -= 1;
	else if (game->player.dir == DIR_DOWN)
		game->player.position.y += 1;
	else if (game->player.dir == DIR_RIGHT)
		game->player.position.x += 1;
	game->player.state = IDLING;
}

int	ft_game_loop(t_game *game)
{
	t_being *p = &game->player;
	t_cycle *cycle;

	mlx_clear_window(game->mlx, game->win);
	if (p->state == IDLING)
		cycle = p->idle[p->dir];
	else if (p->state == MOVING)
	{
		cycle = p->walk[p->dir];
		move_player(game);
	}
	else
		cycle = p->dead[p->dir];

	cycle->delay_count++;
	if (cycle->delay_count >= cycle->frame_delay)
	{
		cycle->delay_count = 0;
		cycle->frame = (cycle->frame + 1) % cycle->frame_count;
	}

	ft_draw_player(game);
	return (0);
}
