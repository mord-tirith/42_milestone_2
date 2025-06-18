
#ifndef MAP_LIB_H
# define MAP_LIB_H

/* Types: */
typedef struct s_map_arr
{
	int		x;
	int		y;
	char	**arr;
}	t_map_arr;

/* Macros: */
# define WASD_BITMASK "BKNJMLGFPHOEICDA"
# define A_REFINEMASK "U######V###W#YX#"

/* Functions: */


// Internal Map Utils:
int		ft_is_wall(t_map_arr map, int y, int x);
char	ft_refine_wall(t_map_arr map, int y, int x, char c);

#endif
