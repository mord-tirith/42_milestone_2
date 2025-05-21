
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_image;

typedef struct s_data
{
	int		len;
	void	*mlx;
	void	*win;
	double	angle;
	double	speed;
	t_point	center;
	t_image	image;
}	t_data;

// Minilib Functions:
void	ft_memset(void *p, int val, size_t len);

// Studying functions, TO DELETE
int		update_frame(t_data *data);
void	init_image(t_data *data);
void	draw_line(t_data *data, t_point p, int len, double a);
void	put_pixel(t_data *data, int x, int y, int color);


#endif
