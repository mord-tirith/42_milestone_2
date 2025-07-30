
#include "bonus_draw_lib.h"
#include <stdio.h>
#include <sys/time.h>

static long	get_time_us(void)
{
	struct timeval v;
	
	gettimeofday(&v, NULL);
	return ((v.tv_sec * 1000000) + v.tv_usec);
}

static void	key_loop(t_game *g)
{
	long		time;
	static int	i;
	static int	frames[4] = {1, 0, 1, 2};
	static long	last_time;

	time = get_time_us();
	if (time - last_time < 500000)
		return ;
	g->assets->key_i = frames[i];
	i++;
	i %= 4;
	last_time = time;
}

static void	print_moves(t_game *g)
{
	static int	x;
	static int	y;
	static char	str[32];

	x = (g->frame->w / 2) - 40;
	y = 15;
	ft_sprintf(str, sizeof(str), "Your moves: %d", g->move_count);
	mlx_string_put(g->mlx, g->win, x, y, 0xA0FFA0, str);
}

void	ft_draw_loop(void *g)
{
	long		time;
	t_game		*game;
	static int	frames[3] = {83333, 62500, 50000};
	static long	last_time;

	
	game = (t_game *)g;
	time = get_time_us();
	if (time - last_time < frames[game->player->state])
		return ;
	ft_draw_bg(game);
	key_loop(game);
	ft_draw_mg(game);
	ft_draw_entities(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame->img, 0, 0);
	print_moves(game);
	last_time = time;
}
