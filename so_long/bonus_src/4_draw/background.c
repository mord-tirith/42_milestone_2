
#include "bonus_draw_lib.h"
#include "so_long_bonus.h"

static int	symbol_to_i(char c)
{
	int	i;

	i = 0;
	while (MAP_ASSETS[i])
	{
		if (MAP_ASSETS[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static void	blit_bg(t_img *dst, t_img *src, int x_off, int y_off)
{
	int				x;
	int				y;
	unsigned int	*src_pixel;
	unsigned int	*dst_pixel;

	y = 0;
	while (y < src->h)
	{
		x = 0;
		while (x < src->w)
		{
			src_pixel = src->data + (y * src->ppl + x);
			dst_pixel = dst->data + ((y + y_off) * dst->ppl + (x + x_off));
			*dst_pixel = *src_pixel;
			x++;
		}
		y++;
	}
}

void	ft_prepare_frame(t_game *game)
{
	int	w;
	int	h;

	h = 0;
	w = 0;
	while (game->map->layout[h])
		h++;
	while (game->map->layout[0][w])
		w++;
	h *= TILE_SIZE;
	w *= TILE_SIZE;
	game->frame = ft_calloc(sizeof(t_img), 1);
	game->frame->img = mlx_new_image(game->mlx, w, h);
	if (!game->frame->img)
	{
		game->error_bitmask |= MLXLOAD_ER;
		return ;
	}
	game->frame->data = (unsigned int *)mlx_get_data_addr(game->frame->img, 
		&game->frame->bpp, &game->frame->line, &game->frame->endian);
	game->frame->h = h;
	game->frame->w = w;
	game->frame->ppl = game->frame->line / 4;
}

void	ft_draw_bg(t_game *game)
{
	int		y;
	int		x;
	int		i;
	t_img	*t;

	y = 0;
	while (game->map->layout[y])
	{
		x = 0;
		while (game->map->layout[y][x])
		{
			i = symbol_to_i(game->map->layout[y][x]);
			t = &game->assets->a_map[i];
			blit_bg(game->frame, t, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
}
