
#include "so_long.h"
#include <X11/keysym.h>

int	safe_close (t_data *data)
{
	int	i;

	i = 0;
	while (i < IDLE_FRAMES)
	{
		if (data->idle[i].image)
			mlx_destroy_image(data->mlx, data->idle[i].image);
		i++;
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	#ifdef __linux__
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	#endif
	return (0);
}

void	move_player(t_data *data, int dx, int dy)
{
	data->player_x += dx*64;
	data->player_y += dy*64;
}

int	handle_key(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		safe_close(data);
		exit(0);
	}
	else if (key == XK_Left || key == 'a')
		move_player(data, -1, 0);
	else if (key == XK_Right || key == 'd')
		move_player(data, 1, 0);
	else if (key == XK_Up || key == 'w')
		move_player(data, 0, -1);
	else if (key == XK_Down || key == 's')
		move_player(data, 0, 1);
	
	return (0);
}

int	animate_loop(t_data *data)
{
	static int	delay;

	if (++delay >= MOVE_SPEED)
	{
		delay = 0;
		data->frame = (data->frame + 1) % IDLE_FRAMES;
	}

	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->idle[data->frame].image, data->player_x, data->player_y);
	return (0);
}

int	main(void)
{
	t_data	data = {0};
	int		img_height;
	int		img_width;
	int		i;
	char	*path[IDLE_FRAMES] = {
		"assets/player/idle/front00.xpm",
		"assets/player/idle/front01.xpm",
		"assets/player/idle/front02.xpm",
		"assets/player/idle/front03.xpm",
		"assets/player/idle/front04.xpm",
		"assets/player/idle/front05.xpm"
	};

	i = 0;
	data.frame = 0;
	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, 800, 600, "Idle Test");
	if (!data.win)
		return (safe_close(&data));
	
	while (i < 6)
	{
		data.idle[i].image = mlx_xpm_file_to_image(data.mlx, path[i], &img_height, &img_width);
		if (!data.idle[i].image)
			return (safe_close(&data));
		i++;
	}
	data.player_x = 50;
	data.player_y = 50;
	mlx_hook(data.win, 17, 0, safe_close, &data);
	mlx_key_hook(data.win, handle_key, &data);
	mlx_loop_hook(data.mlx, animate_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
