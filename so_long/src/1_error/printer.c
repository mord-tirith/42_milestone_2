
#include "error_lib.h"
#include "so_long.h"
#include <stdio.h>

static int	is_single_err(int mask)
{
	while (mask > 2)
	{
		mask /= 2;
		if (mask % 2)
			return (0);
	}
	return (1);
}

void	ft_resolve_error(int mask)
{
	if (!mask)
		return ;
	if (is_single_err(mask))
		ft_printf("Error:\n");
	else
		ft_printf("Errors:\n");
	if (mask & MALLOCS_ER)
		ft_printf("%s\n", "Malloc failure");
	if (mask & MAPFILE_ER)
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
}


