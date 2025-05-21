
#include "fractol.h"
#include <math.h>



static void line(t_data *data, t_point p0, t_point p1)
{
    int dx = abs(p1.x - p0.x);
    int sx = p0.x < p1.x ? 1 : -1;
    int dy = -abs(p1.y - p0.y);
    int sy = p0.y < p1.y ? 1 : -1; 
    int err = dx + dy;
    int e2;

    while (1)
    {
		put_pixel(data, p0.x, p0.y, 0xFFFF00);
        if (p0.x == p1.x && p0.y == p1.y)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            p0.x += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            p0.y += sy;
        }
    }
}

int	update_frame(t_data *data)
{
	ft_memset(data->image.addr, 0, data->image.len * WIDTH);
	draw_line(data, data->center, data->len, data->angle);
	mlx_put_image_to_window(data->mlx, data->win, data->image.img, 0, 0);

	data->angle += data->speed;
	if (data->speed > 2 * M_PI)
		data->speed -= 2 * M_PI;
	return (0);
}

void	draw_line(t_data *data, t_point p, int len, double a)
{
	t_point	end;

	end.x = p.x + (int)(len * cos(a));
	end.y = p.y + (int)(len * sin(a));
	line(data, p, end);
}
