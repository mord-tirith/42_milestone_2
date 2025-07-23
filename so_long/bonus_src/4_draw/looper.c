
#include "bonus_draw_lib.h"
#include <stdio.h>
#include <sys/time.h>

static long	get_time_us(void)
{
	struct timeval v;
	
	gettimeofday(&v, NULL);
	return ((v.tv_sec * 1000000) + v.tv_usec);
}


int	ft_draw_loop(void *g)
{
	long		time;
	t_game		*game;
	static int	frames[3] = {83333, 62500, 50000};
	static long	last_time;

	
	game = (t_game *)g;
	time = get_time_us();
	if (time - last_time < frames[game->player->state])
		return (0);
	ft_draw_bg(game);
	ft_player_draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	last_time = time;
	return (0);
}
