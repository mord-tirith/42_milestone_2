#include "bonus_parse_lib.h"
#include "so_long_bonus.h"

static int	add_enemy(int x, int y, t_point **t)
{
	t_point	*new;
	t_point *temp;

	new = ft_calloc(sizeof(t_point), 1);
	if (!new)
		return (0);
	new->x = x;
	new->y = y;
	new->og_x = x;
	new->og_y = y;
	new->alive = 1;
	if (!*t)
		*t = new;
	else
	{
		temp = *t;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

static int	known_enemies(int x, int y, t_validators *v)
{
	t_point	*t;

	if (!v->enemies)
		return (add_enemy(x, y, v->enemies));
	t = *(v->enemies);
	while (t)
	{
		if (t->y == y && t->x == x)
			return (1);
		t = t->next;
	}
	return (add_enemy(x, y, v->enemies));
}

int	ft_enemy_collision(int y, int x, int move, t_validators *v)
{
	int					o_x;
	int					o_y;
	static int	dx[4] = {0, -1, 0, 1};
	static int	dy[4] = {1, 0, -1, 0};
	t_point	*t;

	ft_move_enemies(v->enemies, v->arr, move);
	t = *(v->enemies);
	while (t)
	{
		o_x = t->x + (dx[t->dir] * -1);
		o_y = t->y + (dy[t->dir] * -1);
		if ((t->x == x && t->y == y) ||
			(o_x == x && o_y == y))
		{
			v->error_mask |= MOBHITS_ER;
			return (1);
		}
		t = t->next;
	}
	return (0);
}

int	ft_start_enemies(t_validators *v)
{
	int					y;
	int					x;

	y = 0;
	v->enemies = ft_calloc(sizeof(t_point *), 1);
	if (!v->enemies)
		return (0);
	while (v->arr[y])
	{
		x = 0;
		while (v->arr[y][x])
		{
			if (v->arr[y][x] == 'M')
			{
				if (!known_enemies(x, y, v))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
