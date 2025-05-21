
#include "fractol.h"

static int	error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
	write(2, "\n", 1);
	return (1);
}

static int	error_handler(int type)
{
	if (!type)
		return (error_message("Error initializing mlx!"));
	if (type == 1)
		return (error_message("Error: window loading crashed"));
	return (error_message("UNKNWON ERROR"));
}

int	kill_window(void *window)
{
	(void)window;
	exit(0);
}

int	handle_input(int key, void *window)
{
	(void)window;
	if (key == 65307)
		exit(0);
	return (0);
}

int	handle_mouse(int dir, int x, int y, void *param)
{
	t_data	*data;
	double	val;
	double	lim;

	(void)x;
	(void)y;
	data = (t_data *)param;
	val = 0.001;
	lim = 0.5;
	if (dir == 5)
		val = -val;
	data->speed += val;
	if (data->speed > lim)
		data->speed = lim;
	if (data->speed < (-lim))
		data->speed = (-lim);
	return (0);
}

int	main()
{
	t_data	data;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (error_handler(0));
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "wheee");
	if (!data.win)
		return (error_handler(1));
	init_image(&data);

	data.angle = 0.0;
	data.speed = 0;
	data.center.x = 400;
	data.center.y = 300;
	data.len = 200;

	mlx_hook(data.win, 17, 0, kill_window, NULL);
	mlx_key_hook(data.win, handle_input, NULL);
	mlx_mouse_hook(data.win, handle_mouse, &data);
	mlx_loop_hook(data.mlx, update_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
