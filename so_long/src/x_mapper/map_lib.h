
#ifndef MAP_LIB_H
# define MAP_LIB_H

# include "sl_types.h"

/* Types: */
typedef struct s_map_arr
{
	int		x;
	int		y;
	char	**arr;
}	t_map_arr;


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

# define MAP_ASSETS "!%@$aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPQRSTUvVwWxXyYzZ#"

/* Functions: */


// Internal Map Utils:
int		ft_is_wall(t_map map, int y, int x);
char	ft_prep_wall(t_map map, int y, int x);
void	ft_detail_map(t_map *map);

#endif
