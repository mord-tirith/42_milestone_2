
#ifndef PARSE_LIB_H
# define PARSE_LIB_H

/* Includes: */
# include <stdlib.h>
# include "so_long.h"

/* Types: */

typedef struct s_validators
{
	int				flood;
	int				x;
	int				y;
	int				p_x;
	int				p_y;
	char			*map_file;
	char			**arr;
	char			**coin_map;
	char			**exit_map;
	unsigned int	error_mask;
	unsigned int	player;
	unsigned int	exit;
	unsigned int	coins;
}	t_validators;

/* Macros: */

/* Functions: */
void	ft_uniques(t_validators *v);
void	ft_flood_map(t_validators *v);
void	ft_check_ones(t_validators *v);
void	ft_file_check(t_validators *v);

#endif
