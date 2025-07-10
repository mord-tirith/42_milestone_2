
#include "so_long_bonus.h"
#include <sys/time.h>

unsigned long	get_time_ms(void)
{
	struct timeval	tv;
	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}



t_anim	*boot_anim(int frames)
{
	t_anim	*a;

	a = ft_calloc(1, sizeof(t_anim));
	a->frames = ft_calloc(frames + 1, sizeof(void *));
	a->frame_count = frames;
	return (a);
}

void	load_animation(t_anim *a, void *mlx)
{
	int		i = 0;
	int		w = TILE_SIZE;
	int		h = TILE_SIZE;
	char	buf[38];

	while (i < a->frame_count)
	{
		ft_sprintf(buf, 38, "./assets/player_anim/idling_down%d.xpm", i);
		a->frames[i] = mlx_xpm_file_to_image(mlx, buf, &w, &h);
		i++;
	}
}

#define FRAME_DELAY_MS 100  // 100 milliseconds per frame

int loop_hook(t_game *game)
{
    unsigned long current_time = get_time_ms();

    if (current_time - game->last_frame_time >= FRAME_DELAY_MS)
    {
        game->last_frame_time = current_time;
        game->current_frame = (game->current_frame + 1) % game->anim->frame_count;
    }

    mlx_clear_window(game->mlx, game->win);
    mlx_put_image_to_window(game->mlx, game->win, game->anim->frames[game->current_frame], 0, 0);

    return (0);
}

int main(void)
{
    t_game  game;

    game.mlx = mlx_init();
    game.win = mlx_new_window(game.mlx, TILE_SIZE, TILE_SIZE, "Animation Test");

    game.anim = boot_anim(6);
    load_animation(game.anim, game.mlx);

    game.current_frame = 0;
    game.last_frame_time = get_time_ms();  // initialize timing

    mlx_loop_hook(game.mlx, loop_hook, &game);
    mlx_loop(game.mlx);

    return (0);
}

