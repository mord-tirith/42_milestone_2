
#include "fractol.h"

int	ft_kill_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)data;
	exit(0);
	return (0);
}

int	ft_handle_mouse(int button, int x, int y, void *param)
{
	t_data	*data;
	double	mouse_r;
	double	mouse_i;

	data = (t_data *)param;
	mouse_r = ((double)x / WIDTH - 0.5) * 4.0 / data->zoom + data->x_off;
	mouse_i = ((double)y / HEIGHT - 0.5) * 4.0 / data->zoom + data->y_off;

	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom *= 0.9;
	else
		return (0);
	if (data->zoom < 1e-10)
		data->zoom = 1e-10;
	if (data->zoom > 1e10)
		data->zoom = 1e10;
	data->x_off = mouse_r - ((double)x / WIDTH - 0.5) * 4.0 / data->zoom;
	data->y_off = mouse_i - ((double)y / HEIGHT - 0.5) * 4.0 / data->zoom;
	return (0);
}

int	ft_handle_input(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	(void)data;
	if (key == 65307)
	{
		return (ft_kill_window(param));
	}
	return (0);
}
