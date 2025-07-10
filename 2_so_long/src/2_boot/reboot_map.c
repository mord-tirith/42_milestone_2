
#include "boot_lib.h"

static void	clone_arr(t_map *map)
{
	int		i;
	char	**new_arr;

	new_arr = ft_calloc(map->y + 1, sizeof(char *));
	if (!new_arr)
		return ;
	i = 0;
	while (i < map->y)
	{
		new_arr[i] = ft_calloc(map->x + 1, sizeof(char));
		if (!new_arr[i])
		{
			ft_clean_arr(new_arr);
			return ;
		}
		i++;
	}
	map->arr = new_arr;
}

static char	prep_floor(t_map map, int y, int x)
{
	int			faux_random;
	static int	last_rand;

	faux_random = 0;
	if (x - 1 >= 0)
		faux_random += map.layout[y][x - 1];
	if (y - 1 >= 0)
		faux_random += map.layout[y - 1][x];
	if (x + 1 < map.x)
		faux_random += map.layout[y][x + 1];
	if (y + 1 < map.y)
		faux_random += map.layout[y + 1][x];
	faux_random %= 4;
	if (faux_random == last_rand)
		faux_random = (faux_random + 1) % 4;
	last_rand = faux_random;
	return ("wxyz"[faux_random]);
}

void	ft_detail_map(t_map *map)
{
	int	x;
	int	y;

	clone_arr(map);
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
				map->arr[y][x] = prep_floor(*map, y, x);
			x++;
		}
		y++;
	}
}
