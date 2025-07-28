
#ifndef BONUS_ASSET_LIB_H
# define BONUS_ASSET_LIB_H

/* Includes: */
# include "so_long_bonus.h"

/* Macros: */

# define F_COUNT "579"
# define D_NAMES "uldr"
# define S_NAMES "iwd"


int	ft_boot_a_others(t_assets *a, void *mlx);
int	ft_boot_a_map(t_assets *a, void *mlx);
int	ft_boot_a_player(t_assets *a, void *mlx);
int	ft_boot_a_mobs(t_assets *a, void *mlx);

#endif
