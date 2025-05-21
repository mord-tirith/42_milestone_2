
#include "fractol.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	int		calc;
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	calc = y * data->image.len + x * (data->image.bpp / 8);
	dst = data->image.addr + calc;
	*(unsigned int *)dst = color;
}

void	init_image(t_data *data)
{
	data->image.img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->image.addr = mlx_get_data_addr(data->image.img, &data->image.bpp, &data->image.len, &data->image.endian);
}


