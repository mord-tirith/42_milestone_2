
#ifndef SO_LONG_H
# define SO_LONG_H

//	Includes:
# include "../libft/inc/libftpp.h"
# include "../minilibx-linux/mlx.h"

//	Macros:
# define WIDTH 800
# define HEIGHT 600

//	Animation Macros:
# define IDLE_FRAMES 6
# define MOVE_SPEED 1000
//	Data types:
typedef struct s_image
{
	void	*image;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		frame;
	int		frame_count;
	int		player_x;
	int		player_y;
	t_image	idle[IDLE_FRAMES];
}	t_data;

#endif
