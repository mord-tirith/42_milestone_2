
#include "so_long.h"

void	ft_remake_walls(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == '1')
			{
				if (x == 0)
					map->grid[y][x] = 'B';
				else if (x == map->width - 1)
					map->grid[y][x] = 'C';
				else if (y == 0)
					map->grid[y][x] = 'A';
				else if (y == map->height - 1)
					map->grid[y][x] = 'D';
				else
					map->grid[y][x] = 'E';
			}
		}
		y++;
	}
}

void	ft_remake_floor(t_map *map)
{
	int		x;
	int		y;
	char	to_add;

	y = 0;
	to_add = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == '0')
			{
				to_add += map->grid[y][x - 1];
				to_add += map->grid[y][x + 1];
				to_add += map->grid[y - 1][x];
				to_add += map->grid[y + 1][x];
				map->grid[y][x] = '0' + (to_add % 4);
			}
			x++;
		}
		y++;
	}
}

int	ft_isfloor(char tile)
{
	if (tile >= '0' && tile <= '3')
		return (1);
	return (0);
}

int	ft_iswall(char tile)
{
	if (tile >= 'A' && tile <= 'J')
		return (1);
	return (0);
}

int	ft_ispecial(char tile)
{
	if (tile == 'p' || tile == 'c' || tile == 'e')
		return (1);
	return (0);
}
