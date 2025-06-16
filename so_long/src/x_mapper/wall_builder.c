/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_builder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:43:46 by thenriqu          #+#    #+#             */
/*   Updated: 2025/06/16 18:00:48 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

static int	is_wall(char **map, int x, int y, t_point s)
{
	char	temp;

	if (x < 0 || y < 0 || x >= s.x || y >= s.y)
		return (1);
	temp = map[y][x];
	return (temp == '1' || (temp >= 'A' && temp <= 'R'));
}

static int	corner_masks(char *arr)
{
	arr[22] = 'F';
	arr[23] = 'F';
	arr[54] = 'F';
	arr[55] = 'F';
	arr[11] = 'G';
	arr[15] = 'G';
	arr[139] = 'G';
	arr[143] = 'G';
	arr[112] = 'K';
	arr[116] = 'K';
	arr[240] = 'K';
	arr[244] = 'K';
	arr[200] = 'L';
	arr[201] = 'L';
	arr[232] = 'L';
	arr[233] = 'L';
	return (1);
}

static int	set_masks(char *arr)
{
	for (int i = 0; i < 256; i++)
		arr[i] = '1';
	arr[248] = 'A';
	arr[203] = 'B';
	arr[118] = 'C';
	arr[31]  = 'D';
	arr[0]   = 'E';
	arr[16]  = 'H';
	arr[24]  = 'I';
	arr[8]   = 'J';
	arr[26]  = 'M';
	arr[2]   = 'N';
	arr[66]  = 'O';
	arr[88]  = 'P';
	arr[64]  = 'Q';
	arr[255] = 'R';
	return (corner_masks(arr));
}

static int	give_wall(char **map, t_point size, int x, int y)
{
	int	bit_mask;

	bit_mask = 0;
	bit_mask |= is_wall(map, x - 1, y - 1, size) << 7;
	bit_mask |= is_wall(map, x + 0, y - 1, size) << 6;
	bit_mask |= is_wall(map, x + 1, y - 1, size) << 5;
	bit_mask |= is_wall(map, x + 1, y + 0, size) << 4;
	bit_mask |= is_wall(map, x - 1, y + 0, size) << 3;
	bit_mask |= is_wall(map, x + 1, y + 1, size) << 2;
	bit_mask |= is_wall(map, x + 0, y + 1, size) << 1;
	bit_mask |= is_wall(map, x - 1, y + 1, size) << 0;
	return (bit_mask);
}

void	ft_prepare_walls(char **map, t_point size)
{
	char	mask[256];
	int		y;
	int		x;
	/*
	if (set_masks(mask) != 0)
	{
		ft_perror("Map masking issue\n");
		exit (0);
	}
	*/
	set_masks(mask);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				map[y][x] = mask[give_wall(map, size, x, y)];
			x++;
		}
		y++;
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *sample_map[] = {
	"0000000",
	"0111110",
	"0100010",
	"0111110",
	"0000000",
	NULL
};

// Utility to print the map
void	print_map(char **map)
{
	for (int i = 0; map[i]; i++)
		printf("%s\n", map[i]);
}

// Utility to duplicate the sample map into writable memory
char **duplicate_map(char **map)
{
	int		rows = 0;
	char	**copy;

	while (map[rows])
		rows++;
	copy = malloc(sizeof(char *) * (rows + 1));
	if (!copy)
		return (NULL);
	for (int i = 0; i < rows; i++)
	{
		copy[i] = strdup(map[i]);
		if (!copy[i])
		{
			while (i-- > 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
	}
	copy[rows] = NULL;
	return (copy);
}

// Utility to free duplicated map
void	free_map(char **map)
{
	for (int i = 0; map[i]; i++)
		free(map[i]);
	free(map);
}

int	main(void)
{
	char	**map;
	t_point	size;

	map = duplicate_map(sample_map);
	if (!map)
		return (1);

	size.y = 0;
	while (map[size.y])
		size.y++;
	size.x = 0;
	while (map[0][size.x])
		size.x++;

	printf("Before:\n");
	print_map(map);

	ft_prepare_walls(map, size);

	printf("\nAfter:\n");
	print_map(map);

	free_map(map);
	return (0);
}

