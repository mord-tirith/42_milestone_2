
#include "fractol.h"

void	ft_buff_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(
			data->image.img, &data->image.bpp,
			&data->image.len, &data->image.endian
			);
}

void	ft_put_pixel(t_data *data, int x, int y, int color)
{
	int		offset;
	char	*aim;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	offset = y * data->image.len + x * (data->image.bpp / 8);
	aim = data->image.addr + offset;
	*(unsigned int)aim = color;
}

int	ft_update_frame(void *param)
{
	t_data *data;

	data = (t_data *)param;
	ft_bzero(data->image.addr, HEIGHT * data->image.len);
	if (data->draw_func)
		data->draw_func(data);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);
}


