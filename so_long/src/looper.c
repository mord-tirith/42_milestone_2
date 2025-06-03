#include "so_long.h"
#include "types.h"

static float ease(float raw)
{
	float slow_end;

	slow_end = 1 - raw;
	return (1 - slow_end * slow_end * slow_end);
}

static void	animate_move(t_being *player, t_cycle *cycle)
{
	int		delta_x;
	int		delta_y;
	float	progress;

	cycle = player->walk[player->dir];
	player->animation_c++;
	progress = ease((float)player->animation_c / player->animation_t);
	delta_x = player->position.x - player->origin.x;
	delta_y = player->position.y - player->origin.y;
	player->offset.x = (int)((1.0f - progress) * (-delta_x) * 128);
	player->offset.y = (int)((1.0f - progress) * (-delta_y) * 128);
	if (player->animation_c >= player->animation_t)
	{
		player->offset.x = 0;
		player->offset.y = 0;
		player->state = IDLING;
		//player->idle[player->dir]->frame_count = 0;
	}
}

int	ft_game_loop(t_game *game)
{
	t_being *p = &game->player;
	t_cycle *cycle;

	mlx_clear_window(game->mlx, game->win);
	if (p->state == MOVING)
	{
		cycle = p->walk[p->dir];
		animate_move(p, cycle);
	}
	else
		cycle = p->idle[p->dir];
	cycle->delay_count++;
	if (cycle->delay_count >= cycle->frame_delay)
	{
		cycle->delay_count = 0;
		cycle->frame = (cycle->frame + 1) % cycle->frame_count;
	}
	ft_draw_map(game);
	ft_draw_player(game);
	return (0);
}
