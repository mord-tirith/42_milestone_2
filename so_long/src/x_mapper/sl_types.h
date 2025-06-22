

#ifndef SL_TYPES_H
# define SL_TYPES_H

# include "../../minilibx-linux/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_map
{
	char	**layout;
	char	**arr;
	t_point	size;
}	t_map;

typedef struct s_assets
{
	void	*a_map[128];
}	t_assets;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_assets	assets;
}	t_data;

#endif


