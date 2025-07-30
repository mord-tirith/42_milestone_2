
#include "bonus_draw_lib.h"
#include "so_long_bonus.h"

static int mid_symbols(char c)
{
	if (c == '2' || c == '3' || c == 'C' || c == 'E')
		return (c);
	return (0);
}

static t_img *mid_asset(t_game *game, char c)
{
	if ((c == '2' || c == '3') && game->player->state == 1)
		return (&game->assets->a_spi[1]);
	if (c == '2' && game->move_count % 2)
		return (&game->assets->a_spi[2]);
	else if (c == '2')
		return (&game->assets->a_spi[0]);
	if (c == '3' && game->move_count % 2)
		return (&game->assets->a_spi[0]);
	if (c == '3')
		return (&game->assets->a_spi[2]);
	if (c == 'C')
		return (&game->assets->a_key[game->assets->key_i]);
	if (c == 'E')
	{
		if (game->coins)
			return (&game->assets->a_exi[0]);
		return (&game->assets->a_exi[1]);
	}
	return (NULL);
}

static void	blit_mg(t_img *dst, t_img *src, int x_off, int y_off)
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
			if (*src_pixel != 0xFF000000)
				*dst_pixel = *src_pixel;
			x++;
		}
		y++;
	}
}

void	ft_draw_mg(t_game *game)
{
	int	y;
	int	x;
	int	s;

	y = 0;
	while (game->map->layout[y])
	{
		x = 0;
		while (game->map->layout[y][x])
		{
			s = mid_symbols(game->map->layout[y][x]);
			if (s)
			{
				blit_mg(game->frame, mid_asset(game, s),
					x * TILE_SIZE, y * TILE_SIZE);
			}
			x++;
		}
		y++;
	}
}
