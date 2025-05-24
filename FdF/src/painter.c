
#include "fdf.h"
#include <math.h>

static void	boot_line(t_point start, t_point end, t_bresenham *line)
{
	int	t1;
	int	t2;

	line->delta_x = end.x - start.x;
	line->delta_y = end.y - start.y;
	line->err = line->delta_x - line->delta_y;
	t1 = start.x;
	t2 = end.x;
	line->dir_x = 1 * ((t1 <= t2) - (t1 > t2));
	t1 = start.y;
	t2 = end.y;
	line->dir_y = 1 * ((t1 <= t2) - (t1 > t2));
	line->x = start.x;
	line->y = start.y;
}

void	ft_draw_line(t_data *data, t_point a, t_point b, int color)
{
	t_bresenham	line;
	int			error;

	boot_line(a, b, &line);
	while (1)
	{
		ft_put_pixel(data, line.x, line.y, color);
		if (line.x == b.x && line.y == b.y)
			break ;
		error = 2 * line.err;
		if (error > (-line.delta_y))
		{
			line.err -= line.delta_y;
			line.x += line.dir_x;
		}
		if (error < line.delta_x)
		{
			line.err += line.delta_x;
			line.y += line.dir_y;
		}
	}
}

static int	get_color(int z)
{
	// simple gradient: low (blue) → high (white)
	int base = 0x0000FF;
	int shade = (z * 255) /  (/* choose a max Z, e.g. */  100);
	if (shade > 255) shade = 255;
	return (base | (shade << 16) /* red channel */);
}

void	draw_map(t_data *data)
{
	int      x, y;
	t_point  p0, p1, r0, r1;
	int      color;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			// original grid point
			p0 = data->map->points[y][x];
			// project to screen coords
			r0 = ft_project_point(p0, 45 /* degrees, for example */);
			// pick a color based on height
			color = get_color(p0.z);

			// horizontal neighbor
			if (x + 1 < data->map->width)
			{
				p1 = data->map->points[y][x + 1];
				r1 = ft_project_point(p1, 45);
				ft_draw_line(data, r0, r1, color);
			}

			// vertical neighbor
			if (y + 1 < data->map->height)
			{
				p1 = data->map->points[y + 1][x];
				r1 = ft_project_point(p1, 45);
				ft_draw_line(data, r0, r1, color);
			}

			x++;
		}
		y++;
	}
}

