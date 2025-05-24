
#ifndef FDF_H
# define FDF_H

// Includes:
# include "../libft/inc/libftpp.h"
# include "../minilibx-linux/mlx.h"

// Marcros:
# ifndef WIDTH
#  define WIDTH 800
# endif

# ifndef HEIGHT
#  define HEIGHT 800
# endif

# define TO_RAD 0.017453292519943295

// Structures:
typedef struct s_point
{
	int	x;
	int	y;
	int	z;
} t_point;

typedef struct s_map
{
	int width;
	int	height;
	t_point **points;
} t_map;

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
	void	(*draw_func)(struct s_data *);
	t_map	*map;
	t_image	image;
}	t_data;

typedef struct s_bresenham
{
	int	delta_x;
	int	delta_y;
	int	dir_x;
	int	dir_y;
	int	err;
	int	x;
	int	y;
}	t_bresenham;

// Parse Functions:
int		ft_valid_map(char *file_name);
int		ft_get_height(char *arg);
t_map	*ft_fd_to_map(char *arg);

// Drawing Functions:
int		ft_update_frame(void *param);
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_buff_image(t_data *data);
void	draw_map(t_data *data);
t_point	ft_project_point(t_point p, int deg);


#endif
