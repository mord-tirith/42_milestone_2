
#include "fractol.h"

/*
void	ft_mandelbrot(t_data *data)
{
	t_mandel	n;
	double		scale;

	scale = 4.0 / WIDTH;
	n.y = 0;
	while (n.y < HEIGHT)
	{
		n.x = 0;
		while (n.x < WIDTH)
		{
			n.real = (n.x * scale - 2.0) + data->x_off;
			n.imag = (n.y * scale - 2.0) + data->y_off;
			n.new_r = 0;
			n.new_i = 0;
			n.i = 0;
			while (n.new_r * n.new_r + n.new_i * n.new_i <= 4 && ++n.i < MAX_ITER)
			{
				n.old_i = n.new_i;
				n.old_r = n.new_r;
				n.new_r = n.old_r * n.old_r - n.old_i * n.old_i + n.real;
				n.new_i = 2 * n.old_r * n.old_i + n.imag;
			}
			n.color = n.i == MAX_ITER ? 0x000000 : (n.i << 24) | 0x0000FF;
			ft_put_pixel(data, n.x, n.y, n.color);
			n.x++;
		}
		n.y++;
	}
}
*/

void	ft_mandelbrot(t_data *data)
{
    t_mandel n;

    // Precompute zoomed scale
    double scale = (4.0 / WIDTH) / data->zoom;

    n.y = 0;
    while (n.y < HEIGHT)
    {
        n.x = 0;
        while (n.x < WIDTH)
        {
            // Center and map to complex plane
            double cx = n.x - WIDTH  / 2.0;
            double cy = n.y - HEIGHT / 2.0;
            n.real = cx * scale + data->x_off;
            n.imag = cy * scale + data->y_off;

            // Mandelbrot iteration
            n.new_r = 0;
            n.new_i = 0;
            n.i = 0;
            while (n.new_r * n.new_r + n.new_i * n.new_i <= 4
                   && ++n.i < MAX_ITER)
            {
                n.old_r = n.new_r;
                n.old_i = n.new_i;
                n.new_r = n.old_r * n.old_r - n.old_i * n.old_i + n.real;
                n.new_i = 2 * n.old_r * n.old_i + n.imag;
            }

            // Color (alpha-blue)
            n.color = n.i == MAX_ITER
                ? 0x000000
                : (n.i << 24) | 0x0000FF;

            ft_put_pixel(data, n.x, n.y, n.color);
            n.x++;
        }
        n.y++;
    }
}


