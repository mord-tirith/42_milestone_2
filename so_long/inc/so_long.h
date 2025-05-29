
#ifndef SO_LONG_H
# define SO_LONG_H

/*	Includes:	*/
//	Libs:
# include "../libft/inc/libftpp.h"

//	Sublibs:
# include "macros.h"
# include "types.h"

// System dependent libs:
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# elif __APPLE__
#  include "../minilibx-linux/mlx.h"
# endif

/*	Functions:	*/
//	Boot functions:
int		ft_boot_player(t_game *game, t_point spawn);
char	*ft_give_frame(char model, t_dir dir, int frame, int entity);
t_cycle	*ft_load_cycle(char model, int entity, t_dir dir, void *mlx);

//	Draw functions:
void	ft_draw_player(t_game *game);

//	Loop functions:
int	ft_game_loop(t_game *game);

// Input functions:
int	ft_key_hook(int key, t_game *game);
#endif
