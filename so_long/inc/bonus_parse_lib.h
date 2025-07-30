
#ifndef BONUS_PARSE_LIB_H
# define BONUS_PARSE_LIB_H

/* Includes: */
# include <stdlib.h>
# include "so_long_bonus.h"

/* Types: */

typedef struct s_point
{
	int							x;
	int							y;
	int							dir;
	int							og_x;
	int							og_y;
	int							alive;
	struct s_point	*next;
}	t_point;

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
	t_point		**enemies;
	unsigned int	error_mask;
	unsigned int	player;
	unsigned int	exit;
	unsigned int	coins;
}	t_validators;

/* Macros: */

/* Functions: */
int		ft_start_enemies(t_validators *v);
int		ft_enemy_collision(int y, int x, int move, t_validators *v);
void	ft_move_enemies(t_point **list, char **arr, int move);
void	ft_uniques(t_validators *v);
void	ft_flood_map(t_validators *v);
void	ft_check_ones(t_validators *v);
void	ft_file_check(t_validators *v);
void	ft_valid_symbols(t_validators *v);

#endif
