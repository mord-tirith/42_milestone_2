
#include "boot_lib.h"
#include "so_long.h"
#include <stdlib.h>

static void	clone_arr(t_map *map)
{
	int	i;
	int	**new_arr;

	new_arr = ft_calloc(map->y, sizeof(int *));
	if (!new_arr)
		return ;
	i = 0;
	while (i < map->y)
	{
		new_arr[i] = ft_calloc(map->x, sizeof(int));
		if (!new_arr[i])
		{
			ft_clean_int_arr(new_arr, i);
			return ;
		}
		i++;
	}
	map->arr = new_arr;
}

static int	translate_symbol(char c)
{
	int	i;

	i = 0;
	while (MAP_ASSETS[i])
	{
		if (MAP_ASSETS[i] == c)
			return (i);
		i++;
	}
	return (ASSET_ERROR);
}

void	ft_detail_map(t_map *map)
{
	int		x;
	int		y;
	char	c;

	clone_arr(map);
	if (!map->arr)
		return ;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (ft_is_wall(*map, y, x))
				c = ft_prep_wall(*map, y, x);
			else
				c = 'z';
			map->arr[y][x] = translate_symbol(c);
			x++;
		}
		y++;
	}
}
