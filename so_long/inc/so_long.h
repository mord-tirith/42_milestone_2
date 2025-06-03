
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
t_map	*ft_create_map(char *map_path);
t_cycle	*ft_load_cycle(char model, int entity, t_dir dir, void *mlx);

//	Draw functions:
void	ft_draw_player(t_game *game);

//	Loop functions:
int	ft_game_loop(t_game *game);

//	Input functions:
int	ft_key_hook(int key, t_game *game);

//	Validation functions:
int	ft_valid_map(char *map_file);
int	ft_flood_fill(t_game *game);

//	Map utility functions:
int		ft_isfloor(char tile);
int		ft_iswall(char tile);
int		ft_ispecial(char tile);
void	ft_draw_map(t_game *game);
void	ft_remake_walls(t_map *map);
void	ft_remake_floor(t_map *map);
void	ft_load_map_assets(t_game *game);
#endif
