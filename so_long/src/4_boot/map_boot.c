
#include "so_long.h"

void	ft_boot_map(t_game *game)
{
	int		i;
	t_map	*map;

	map = &game->map;
	i = 0;
	while (map->layout[0][i])
		i++;
	map->x = i;
	i = 0;
	while (map->layout[i])
		i++;
	map->y = i;
	ft_detail_map(map);
}
