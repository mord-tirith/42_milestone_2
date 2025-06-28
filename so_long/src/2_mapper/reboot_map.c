
#include "map_lib.h"
#include <stdlib.h>

static void	clean_return(t_map *map)
{
	int	i;

	i = 0;
	while (map->arr[i])
	{
		free(map->arr[i]);
		i++;
	}
	free(map->arr);
}

static void	start_arr(t_map *map)
{
	int		i;
	char	**new_arr;

	new_arr = malloc(sizeof(char *) * (map->y + 1));
	if (!new_arr)
		return ;
	i = 0;
	while (i < map->y)
	{
		new_arr[i] = malloc(sizeof(char) * (map->x + 1));
		if (!new_arr[i])
			return (clean_return(map));
		new_arr[i][map->x] = '\0';
		i++;
	}
	new_arr[i] = NULL;
	map->arr = new_arr;
}

static char	prep_floor(t_map *map, int y, int x)
{
	static int	last_rand;
	int			faux_random;
	char		*floors;

	floors = "wxyz";
	faux_random = 0;
	if (x - 1 >= 0)
		faux_random += map->layout[y][x - 1];
	if (y - 1 >= 0)
		faux_random += map->layout[y - 1][x];
	if (x + 1 < map->x)
		faux_random += map->layout[y][x + 1];
	if (y + 1 < map->y)
		faux_random += map->layout[y + 1][x];
	faux_random %= 4;
	if (faux_random == last_rand)
		faux_random = (faux_random + 1) % 4;
	last_rand = faux_random;
	return (floors[faux_random]);
}

void	ft_detail_map(t_map *map)
{
	int	x;
	int	y;

	start_arr(map);
	if (!map->arr)
		return ;
	y = 0;
	while (map->layout[y])
	{
		x = 0;
		while (map->layout[y][x])
		{
			if (ft_is_wall(*map, y, x))
				map->arr[y][x] = ft_prep_wall(*map, y, x);
			else
				map->arr[y][x] = prep_floor(map, y, x); 
			x++;
		}
		y++;
	}
}
