
#ifndef PARSE_LIB_H
# define PARSE_LIB_H

/* Includes: */
# include "so_long.h"
# include <stdlib.h>

/* Types: */

typedef struct s_validators
{
	int				flood;
	char			**arr;
	char			**coin_map;
	char			**exit_map;
	unsigned int	error_mask;
	unsigned int	player;
	unsigned int	exit;
	unsigned int	coins;
	int	x;
	int	y;
	int	p_x;
	int	p_y;
}	t_validators;

/* Macros: */

/* Functions: */
void	ft_uniques(t_validators *v);
void	ft_flood_map(t_validators *v);
void	ft_check_ones(t_validators *v);

#endif
