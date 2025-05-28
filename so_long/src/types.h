#ifndef TYPES_H
# define TYPES_H

/*	Enums:	*/
typedef enum e_state
{
	IDLING,
	MOVING,
	DYING
}	t_state;

typedef enum e_dir
{
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
}	t_dir;

/*	Structures:  */
typedef struct s_image
{
	int		width;
	int		height;
	void	*img;
}	t_image;

typedef struct s_cycle
{
	int			frame_count;
	int			frame_delay;
	int			delay_count;
	char		**frames;
	t_dir		dir;
	t_image	**sprites;
}	t_cycle;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_being
{
	int			frame;
	t_state	state;
	t_point	position;
	t_cycle	*idle;
	t_cycle	*move;
	t_cycle	*dead;
}	t_being;

typedef struct s_map
{
	int			width;
	int			height;
	char		**grid;
	t_image	bg;
	t_image	walls;
}	t_map;

typedef struct s_game
{
	int			tick;
	void		*mlx;
	void		*win;
	t_map		map;
	t_being	player;
	t_being	*enemies;
}	t_game;

#endif
