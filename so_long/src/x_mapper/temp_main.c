#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "map_lib.h"

// Utility: free map
void	free_map(char **map)
{
	int i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

// Utility: print map
void	print_map(char **map)
{
	for (int y = 0; map[y]; y++)
	{
		for (int x = 0; map[y][x]; x++)
		{
			switch (map[y][x])
			{
				case 'O': printf("║"); break;
				case 'L': printf("═"); break;
				case 'U': printf("╬"); break;
				//case 'H': printf("╔"); break;
				//case '2': printf("╗"); break;
				//case '3': printf("╚"); break;
				//case '4': printf("╝"); break;
				case 'T': printf("╠"); break;
				case 'S': printf("╣"); break;
				case 'Q': printf("╩"); break;
				case 'R': printf("╦"); break;
				case 'A': printf("■"); break;
				case 'B': printf("■"); break;
				default: putchar(map[y][x]); break;
			}
		}
		putchar('\n');
	}
}


int	main(void)
{
	char *original_map[] = {
		"1111111",
		"0111111",
		"0100010",
		"0111110",
		"0001000",
		NULL
	};

	printf("Original map:\n");
	print_map(original_map);

	char **map_copy = copy_map(original_map);
	if (!map_copy)
	{
		fprintf(stderr, "Failed to allocate map copy.\n");
		return (1);
	}
	int	x = 0;
	while (original_map[0][x])
		x++;
	int y = 0;
	while (original_map[y])
		y++;
	t_point map_size = {x, y};
	ft_tile_walls(map_copy, map_size);

	printf("\nTiled map:\n");
	print_map(map_copy);

	free_map(map_copy);
	return (0);
}
