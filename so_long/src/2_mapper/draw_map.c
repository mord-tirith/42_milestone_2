#include "map_lib.h"
#include "so_long.h"

static void	load_assets(t_game *data)
{
	int		i;
	int		w;
	int		h;
	char	*path;

	i = 0;
	path = ft_strdup("./assets/map/ .xpm");
	if (!path)
		return ;
	while (MAP_ASSETS[i])
	{
		path[13] = MAP_ASSETS[i];
		data->assets.a_map[(int)MAP_ASSETS[i]] = mlx_xpm_file_to_image(
			data->mlx, path, &w, &h);
		i++;
	}
	free(path);
}

void	ft_draw_map(t_game *game)
{
	int		x;
	int		y;
	char	tile;
	void	*img;

	y = 0;
	while (y < game->map.y)
	{
		x = 0;
		while (x < game->map.x)
		{
			tile = game->map.arr[y][x];
			img = game->assets.a_map[(int)tile];
			if (img)
				mlx_put_image_to_window(game->mlx, game->win, img,
				x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}

#include <stdlib.h>

int	main(void)
{
	t_game data;

	data.mlx = mlx_init();
	data.map.layout = (char *[]) {
		"1111111111111111111111111111111",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1000000000000000000000000000001",
		"1111111111111111111111111111111",
		NULL
	};

	int x = 0;
	int y = 0;
	while (data.map.layout[y])
		y++;
	while (data.map.layout[0][x])
		x++;

	data.map.x = x;
	data.map.y = y;

	data.win = mlx_new_window(data.mlx, x * TILE_SIZE, y * TILE_SIZE, "Map Sandbox");

	ft_detail_map(&data.map);
	load_assets(&data);
	ft_draw_map(&data);

	mlx_loop(data.mlx);
	return (0);
}
