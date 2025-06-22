#include <stdio.h> // for perror
#include "map_lib.h"

void	load_assets(t_data *data)
{
	int		i;
	int		w;
	int		h;
	char	path[256];

	i = 0;
	while (MAP_ASSETS[i])
	{
		snprintf(path, sizeof(path), "assets/%c.xpm", MAP_ASSETS[i]);
		data->assets.a_map[(int)MAP_ASSETS[i]] = mlx_xpm_file_to_image(
			data->mlx, path, &w, &h);
		if (!data->assets.a_map[(int)MAP_ASSETS[i]])
		{
			fprintf(stderr, "Failed to load image: %s\n", path);
		}
		i++;
	}
}

void	render_map(t_data *data)
{
	int	x;
	int	y;
	int	tile_size = 32; // or whatever size your tiles are

	for (y = 0; y < data->map.size.y; y++)
	{
		for (x = 0; x < data->map.size.x; x++)
		{
			char symbol = data->map.arr[y][x];
			void *img = data->assets.a_map[(int)symbol];
			if (img)
				mlx_put_image_to_window(data->mlx, data->win, img,
					x * tile_size, y * tile_size);
		}
	}
}

#include "sl_types.h"
#include "map_lib.h"
#include <stdlib.h>

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.map.layout = (char *[]) {
		"1111111111111111111111111111111111111111111111111",
		"1000000000000000000000000000000000000000000000001",
		"1000000000100100111100100001000001110000000000001",
		"1000000000100100100000100001000011111000000000001",
		"1000000000111100110000100001000111111100000000001",
		"1000000000100100100000100001000011111000000000001",
		"1000000000100100111100111001110001110000000000001",
		"1000000000000000000000000000000000000000000000001",
		"1000000000001000011100001000000100001110000000001",
		"1000001000001000111110001111100100001111000000001",
		"1000001001001001111111001000000100001111100000001",
		"1000001001001000111110001000000100001111000000001",
		"1000001111111000011100001000000111001110000000001",
		"1000000000000000000000000000000000000000000000001",
		"1111111111111111111111111111111111111111111111111",
		NULL
	};
	int x = 0;
	int y = 0;
	while (data.map.layout[y])
		y++;
	while (data.map.layout[0][x])
		x++;

	data.map.size.x = x;
	data.map.size.y = y;

	data.win = mlx_new_window(data.mlx, x * 32, y * 32, "Map Sandbox");

	ft_detail_map(&data.map);
	y = 0;
	while (data.map.arr[y])
	{
		printf("%s\n", data.map.arr[y]);
		y++;
	}
	load_assets(&data);
	render_map(&data);

	mlx_loop(data.mlx);
	return (0);
}

