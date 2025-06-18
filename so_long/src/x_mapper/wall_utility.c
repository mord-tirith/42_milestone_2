
#include "map_lib.h"

int	ft_is_wall(t_map_arr map, int y, int x)
{
	char	c;

	if (x < 0 || x >= map.x || y < 0 || y >= map.y)
		return (1);
	c = map.arr[y][x];
	return (c == '1' || (c >= 'A' && c <= 'S'));
}

int	wasd_bitmask(t_map_arr map, int y, int x)
{
	int	bit_mask;

	bit_mask = 0;
	bit_mask |= ft_is_wall(map, y - 1, x + 0) << 3;
	bit_mask |= ft_is_wall(map, y + 0, x - 1) << 2;
	bit_mask |= ft_is_wall(map, y + 1, x + 0) << 1;
	bit_mask |= ft_is_wall(map, y + 0, x + 1) << 0;
	return (bit_mask);
}

char	ft_first_wall(t_map_arr map, int y, int x)
{
	int		wasd_mask;
	char	r;

	wasd_mask = wasd_bitmask(map, y, x);
	r = WASD_BITMASK[wasd_mask];

	if (r == 'A' || r == 'C' || r == 'D' || r == 'E' || r == 'F')
		r = ft_refine_wall(map, y, x, r);
	return (r);
}

#include <stdlib.h>
#include <stdio.h>

int main()
{
	char *arr[] = {
		"11111",
		"11011",
		"10101",
		"11011",
		"11111",
		NULL
	};
	t_map_arr map;
	map.arr = arr;
	map.x = 5;
	map.y = 5;

	int y = 0;
	int x = 0;
	printf("Original map:\n");
	while (map.arr[y])
	{
		x = 0;
		while (map.arr[y][x])
		{
			printf("%c ", map.arr[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	y = 0;
	printf("\nChanged map:\n");
	char c = '0';
	while (map.arr[y])
	{
		x = 0;
		while (map.arr[y][x])
		{
			c = '0';
			if (map.arr[y][x] != c)
				c = ft_first_wall(map, y, x);
			printf("%c ", c);
			x++;
		}
		y++;
		printf("\n");
	}
}
