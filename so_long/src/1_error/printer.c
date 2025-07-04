
#include "so_long.h"
#include <stdlib.h>


static void	print_mlx_errors(int mask)
{
	if (mask & MLXLOAD_ER)
		ft_printf("%s\n", "mlx failed to instantiate window");
}

static void	print_error(int mask)
{
	ft_printf("Error\n");
	if (mask & MALLOCS_ER)
		ft_printf("%s\n", "Malloc failure");
	if (mask & MAPFILE_ER)
		ft_printf("%s\n", "Map file not found");
	if (mask & BERFILE_ER)
		ft_printf("%s\n", "Invalid map file extension.\nUse .ber files please");
	if (mask & X_VALUE_ER)
		ft_printf("%s\n", "Map contains different x values");
	if (mask & PLAYERS_ER)
		ft_printf("%s\n", "More than 1 player symbol detected");
	if (mask & EXITPLU_ER)
		ft_printf("%s\n", "Multiple exits detected");
	if (mask & OPENWAL_ER)
		ft_printf("%s\n", "Map not enclosed by 1s");
	if (mask & NOCOINS_ER)
		ft_printf("%s\n", "No collectables on the map");
	if (mask & LOCKOIN_ER)
		ft_printf("%s\n", "Unreacheable coin detected");
	if (mask & LOCKEXI_ER)
		ft_printf("%s\n", "Unreacheable exit detected");
	print_mlx_errors(mask);
}

void	ft_resolve_error(int mask)
{
	if (mask)
		print_error(mask);
	exit(mask);
}
