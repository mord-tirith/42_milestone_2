
#ifndef SO_LONG_H
# define SO_LONG_H

/* Global Includes: */
# include "../../libft/inc/libftpp.h"
# include "../minilibx-linux/mlx.h"

/* Types: */

typedef struct s_map
{
	int		x;
	int		y;
	char	**arr;
	char	**layout;
}	t_map;

typedef struct s_assets
{
	int		h;
	int		w;
	char	*map_file;
	void	*a_map[52];
}	t_assets;

typedef struct s_game
{
	int			error_bitmask;
	int			move_count;
	int			p_x;
	int			p_y;
	int			coins;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_assets	*assets;
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
	NOPLAYE_ER = 1 << 8,
	NOEXITS_ER = 1 << 9,
	LOCKOIN_ER = 1 << 10,
	LOCKEXI_ER = 1 << 11,
	WRONGAC_ER = 1 << 12,
	MLXLOAD_ER = 1 << 13
}	t_flags;

/* System Dependant Macros: */
# ifdef __linux__
#  define KEY_ESC	65307
#  define KEY_W		119
#  define KEY_A		97
#  define KEY_S		115
#  define KEY_D		100
#  define KEY_UP	65362
#  define KEY_LEFT	65361
#  define KEY_DOWN	65364
#  define KEY_RIGHT	65363
#  define LIN_FLAG	1

# elif __APPLE__
#  define KEY_ESC	53
#  define KEY_W		13
#  define KEY_A		0
#  define KEY_S		1
#  define KEY_D		2
#  define KEY_UP	126 
#  define KEY_LEFT	123 
#  define KEY_DOWN	125
#  define KEY_RIGHT	124 
#  define LIN_FLAG	0
# endif

/* Macros: */
# define GAME_NAME "so_long"
# define TILE_SIZE 48
# define MAP_ASSETS "!%@$aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPQRSTUvVwWxXyYzZ#"

/* Functions: */
int	ft_valid_map(char *map_file);

// Boot functions:
void	ft_detail_map(t_map *map);

// Exit functions:
void	ft_exit_game(t_game *game);

// Error management:
void	ft_resolve_error(int mask);

// Draw functions:
void	ft_draw_map(t_game *game);
#endif
