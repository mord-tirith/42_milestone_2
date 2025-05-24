
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 255

typedef struct s_mandel
{
	int		x;
	int		y;
	int		i;
	int		color;
	double	real;
	double	imag;
	double	old_r;
	double	old_i;
	double	new_r;
	double	new_i;
}	t_mandel;

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
	void	*mlx;
	void	*win;
	double	zoom;
	double	x_off;
	double	y_off;
	t_image	image;
	void (*draw_func)(struct s_data *);
}	t_data;

// Drawing Functions
int		ft_update_frame(void *param);
void	ft_buff_image(t_data *data);
void	ft_put_pixel(t_data *data, int x, int y, int color);

// MLX Helper Functions
int	ft_kill_window(void *param);
int	ft_handle_input(int key, void *param);
int	ft_handle_mouse(int button, int x, int y, void *param);

// Fractal Functions
void	ft_mandelbrot(t_data *data);

// Minilib Functions
void	ft_bzero(void *s, size_t n);

#endif
