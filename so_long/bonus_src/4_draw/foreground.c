
#include "bonus_draw_lib.h"
#include "so_long_bonus.h"

static void	move_player(t_entity *p)
{
	if (p->state == 0)
		return ;
	if (p->x < p->tile_x * TILE_SIZE)
		p->x += MOVE_SPEED;
	else if (p->x > p->tile_x * TILE_SIZE)
		p->x -= MOVE_SPEED;
	if (p->y < p->tile_y * TILE_SIZE)
		p->y += MOVE_SPEED;
	else if (p->y > p->tile_y * TILE_SIZE)
		p->y -= MOVE_SPEED;
	if (p->x == p->tile_x * TILE_SIZE &&
	 p->y == p->tile_y * TILE_SIZE)
		p->state = 0;
}

static int	vars_to_i(t_entity *p)
{
	int			i;
	static int	offset[] = {0, 24, 56};
	static int	count[] = {6, 8, 10};

	i = offset[p->state];
	i += count[p->state] * p->dir;
	i += p->curr;
	p->curr += 1;
	if (p->curr == count[p->state])
		p->curr = 0;
	return (i);
}

static void	blit_player(t_img *dst, t_img *src, int x_off, int y_off)
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

void	ft_player_draw(t_game *game)
{
	int		i;
	t_img	*sprite;

	i = vars_to_i(game->player);
	sprite = &game->assets->a_pla[i];
	if (game->player->state)
		move_player(game->player);
	blit_player(game->frame, sprite, game->player->x, game->player->y);
}
