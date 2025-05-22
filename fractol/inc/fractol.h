
#ifndef FRACTOL_H
# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 800
# define HEIGHT 800

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
	t_image	image;
}	t_data;

#endif
