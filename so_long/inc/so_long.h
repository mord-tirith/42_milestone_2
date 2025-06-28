
#ifndef SO_LONG_H
# define SO_LONG_H

/* Global Includes: */
# include "../../.libft/inc/libftpp.h"
# include "../../minilibx-linux/mlx.h"

/* Types: */

typedef struct s_map
{
	int		x;
	int		y;
	char	**arr;
	char	**layout;
}	t_map;

typedef struct s_data
{
	void	*a_map[128];
}	t_assets;

typedef struct s_game
{
	int			error_bitmask;
	void		*mlx;
	void		*win;
	t_map		map;
	t_assets	assets;
}	t_game;

typedef enum e_flags
{	
	SUCCESSFUL = 0,
	MALLOCS_ER = 1 << 0,
	BERFILE_ER = 1 << 1,
	MAPFILE_ER = 1 << 2,
	X_VALUE_ER = 1 << 3,
	PLAYERS_ER = 1 << 4,
	EXITPLU_ER = 1 << 5,
	OPENWAL_ER = 1 << 6,
	NOCOINS_ER = 1 << 7,
	LOCKOIN_ER = 1 << 8,
	LOCKEXI_ER = 1 << 9
}	t_flags;

/* Macros: */
# define TILE_SIZE 48

/* Functions: */
void	ft_valid_map(t_game *game);
void	ft_detail_map(t_game *game);
void	ft_draw_map(t_game *game);
#endif
