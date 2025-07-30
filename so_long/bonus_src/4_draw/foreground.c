
#include "bonus_draw_lib.h"
#include "so_long_bonus.h"

static void	move_being(t_entity *e)
{
	if (e->state == 0)
		return ;
	if (e->x < e->tile_x * TILE_SIZE)
		e->x += MOVE_SPEED;
	else if (e->x > e->tile_x * TILE_SIZE)
		e->x -= MOVE_SPEED;
	if (e->y < e->tile_y * TILE_SIZE)
		e->y += MOVE_SPEED;
	else if (e->y > e->tile_y * TILE_SIZE)
		e->y -= MOVE_SPEED;
	if (e->x == e->tile_x * TILE_SIZE &&
	 e->y == e->tile_y * TILE_SIZE && e->state != 2)
		e->state = 0;
}

static int	vars_to_i(t_entity *e)
{
	int			i;
	static int	offset[] = {0, 24, 56};
	static int	count[] = {6, 8, 10};

	i = offset[e->state];
	i += count[e->state] * e->dir;
	i += e->curr;
	if (e->state == 2)
	{
		if (e->curr < count[2])
			e->curr += 1;
	}
	else
	{
		e->curr += 1;
		if (e->curr == count[e->state])
			e->curr = 0;
	}
	return (i);
}

static void	blit_being(t_img *dst, t_img *src, int x_off, int y_off)
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

void	ft_draw_entities(t_game *game)
{
	int		i;
	int		j;
	t_img	*sprite;

	i = vars_to_i(game->player);
	sprite = &game->assets->a_pla[i];
	if (game->player->state)
		move_being(game->player);
	blit_being(game->frame, sprite, game->player->x, game->player->y);
	j = -1;
	while (++j < game->mob_count)
	{
		if (game->mobs[j]->state == 2 && game->mobs[j]->curr >= 9)
			continue ;
		i = vars_to_i(game->mobs[j]);
		sprite = &game->assets->a_mob[i];
		if (game->mobs[j]->state)
			move_being(game->mobs[j]);
		blit_being(game->frame, sprite, game->mobs[j]->x, game->mobs[j]->y);
	}
}
