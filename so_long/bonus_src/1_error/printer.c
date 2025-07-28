
#include "so_long_bonus.h"

static int	flood_error(int m)
{
	int	result;

	result = 0;
	if (m &= LOCKOIN_ER)
		result |= ft_perror(MAP__EXIT, "Unreacheable coin(s)\n");
	if (m &= LOCKEXI_ER)
		result |= ft_perror(MAP__EXIT, "No path to exit\n");
	return (result);
}

static int	mlx_error(int m)
{
	int	result;

	result = 0;
	if (m &= MLXLOAD_ER)
		result |= ft_perror(MEMO_EXIT, "MLX failed to load asset\n");
	return (result);

}

int	ft_print_error(int mask)
{
	static int	e;

	if (mask)
		e = ft_perror(0, "Error:\n");
	if (mask & MALLOCS_ER)
		e |= ft_perror(MEMO_EXIT, "Malloc failure\n");
	if ((mask & BERFILE_ER) || (mask & MAPFILE_ER))
		e |= ft_perror(FILE_EXIT, "Invalid file.\nUse your_mapfile.ber\n");
	if (mask & X_VALUE_ER)
		e |= ft_perror(MAP__EXIT, "Inconsistent map line length\n");
	if (mask & PLAYERS_ER)
		e |= ft_perror(MAP__EXIT, "More than one player\n");
	if (mask & EXITPLU_ER)
		e |= ft_perror(MAP__EXIT, "More than one exit\n");
	if (mask & OPENWAL_ER)
		e |= ft_perror(MAP__EXIT, "Map not enclosed by '1's\n");
	if (mask & NOCOINS_ER)
		e |= ft_perror(MAP__EXIT, "Map has no coins\n");
	if (mask & UNKNOWN_ER)
		e |= ft_perror(MAP__EXIT, "Unknown symbol detected on map\n");
	e |= flood_error(mask);
	e |= mlx_error(mask);
	return (e);
}
