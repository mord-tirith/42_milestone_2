
#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* Global Includes: */
# include "../libft/inc/libftpp.h"
# include "../minilibx-linux/mlx.h"

/* Types: */

typedef enum e_num_macros
{
	UP = 0,
	LEFT = 1,
	DOWN = 2,
	RIGHT = 3,
	IDLE = 0,
	WALK = 1,
	DEATH = 2
}	t_num_macros;

typedef struct s_map
{
	int		x;
	int		y;
	int		e_x;
	int		e_y;
	int		**arr;
	char	**layout;
}	t_map;

typedef struct s_img
{
	int				w;
	int				h;
	int				bpp;
	int				line;
	int				ppl;
	int				endian;
	void			*img;
	unsigned int	*data;
}	t_img;

typedef struct s_assets
{
	int		h;
	int		w;
	char	*map_file;
	t_img	a_coin;
	t_img	a_exit[2];
	t_img	a_map[52];
	t_img	a_pla[96];
}	t_assets;

typedef struct s_player
{
	int	x;
	int	y;
	int	tile_x;
	int	tile_y;
	int	curr;
	int	dir;
	int	state;
}	t_player;

typedef struct s_game
{
	int			error_bitmask;
	int			move_count;
	int			p_x;
	int			p_y;
	int			coins;
	int			map_render;
	void		*mlx;
	void		*win;
	t_map		*map;
	t_img		*frame;
	t_assets	*assets;
	t_player	*player;
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
# define TILE_SIZE 64
# define MOVE_SPEED 8
# define MAP_ASSETS "!%@$aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPQRSTUvVwWxXyYzZ#"
# define ASSET_ERROR -1
# define DEATH_F (char *[]){ "du", "dl", "dd", "dr"}
# define IDLE_F (char *[]){ "iu", "il", "id", "ir"}
# define WALK_F (char *[]){ "wu", "wl", "wd", "wr"}
/* Functions: */
int	ft_valid_map(char *map_file);

// Boot functions:
void	ft_prepare_frame(t_game *game);
void	ft_boot_game(t_game *game, char *file);
void	ft_boot_assets(t_game *game);

// Exit functions:
void	ft_clean_assets(t_assets *assets, void *mlx);
void	ft_exit_game(t_game *game);

// Error management:
void	ft_resolve_error(int mask);

// Draw functions:
int		ft_draw_loop(void *g);

// Loop functions:
int		ft_on_expose(void *g);
int		ft_on_destroy(void *g);

// Game functions:
int		ft_control(int key, void *g);
int		ft_key_handler(int key, void *g);
int		ft_handle_exit(t_game *game);
void	ft_clean_map(t_map *map);
void	ft_win_game(t_game *game);
#endif
