
#include "fractol.h"

static void	hooks(t_data *data)
{
	mlx_loop_hook(data->mlx, ft_update_frame, data);
	mlx_key_hook(data->win, ft_handle_input, data);
	mlx_mouse_hook(data->win, ft_handle_mouse, data);
	mlx_hook(data->win, 17, 0, ft_kill_window, data);
}

int main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	if (data.mlx)
		data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract.ol");
	if (!data.mlx)
		return (1);
	data.zoom = 1.0;
	data.x_off = 0.0;
	data.y_off = 0.0;
	data.draw_func = ft_mandelbrot;
	ft_buff_image(&data);
	hooks(&data);
	mlx_loop(data.mlx);
}
