
#ifndef BOOT_LIB_H
# define BOOT_LIB_H

# include "so_long.h"

int		ft_is_wall(t_map map, int y, int x);
char	ft_prep_wall(t_map map, int y, int x);
char	**ft_clean_arr(char **arr);
void	ft_clean_game(t_game *game);
void	ft_boot_map(t_game *game);
void	ft_boot_assets(t_game *game);
void	ft_boot_mlx(t_game *game);
void	ft_detail_map(t_map *map);


/* Macros: */
# define WASD_BITMASK "0123456789abcdef"
# define BITMASK_3 "0101010101010101"
# define BITMASK_6 "0011001100110011"
# define BITMASK_7 "3102310231023102"
# define BITMASK_9 "0000111100001111"
# define BITMASK_B "3131020231310202"
# define BITMASK_C "0000000011111111"
# define BITMASK_D "3333111100002222"
# define BITMASK_E "3311331100220022"
# define BITMASK_F "abcdefghijklmnop"

#endif
