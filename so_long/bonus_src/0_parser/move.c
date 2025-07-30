#include "bonus_parse_lib.h"
#include <stdio.h>

static void	kill_enemies(t_point **list, char **map, int move)
{
	char		cell;
	t_point	*t;

	t = *list;
	while (t)
	{
		if (t->alive)
		{
			cell = map[t->y][t->x];
			if ((cell == '2' && move % 2) || (cell == '3' && !(move % 2)))
				t->alive = 0;
		}
		t = t->next;
	}
}

static void	reset(t_point **list)
{
	t_point	*t;

	t = *list;
	while (t)
	{
		t->x = t->og_x;
		t->y = t->og_y;
		t->dir = 0;
		t->alive = 1;
		t = t->next;
	}
}

static void move_enemy(t_point *t, char **map)
{
		int n_x;
    int n_y;
		int	moved;
    static int dx[4] = {0, -1, 0, 1};
    static int dy[4] = {1, 0, -1, 0};

		n_x = t->x + dx[t->dir];
		n_y = t->y + dy[t->dir];
		moved = 0;
		if (n_y >= 0 && map[n_y] && n_x >= 0 && map[n_y][n_x])
    {
			if (map[n_y][n_x] != '1' && map[n_y][n_x] != 'E')
			{
				t->y = n_y;
				t->x = n_x;
				moved = 1;
			}
    }
		if (!moved)
			t->dir = (t->dir + 1) % 4;
}

static void	step_enemies(t_point **list, char **map)
{
	t_point	*t;

	t = *list;
	while (t)
	{
		if (t->alive)
			move_enemy(t, map);
		t = t->next;
	}
}

void	ft_move_enemies(t_point **list, char **arr, int move)
{
	static int	old_move;
	
	if (old_move == move)
		return ;
	while (old_move < move)
	{
		step_enemies(list, arr);
		old_move++;
		kill_enemies(list, arr, old_move);
	}
	if (old_move > move)
	{
		reset(list);
		old_move = 0;
		ft_move_enemies(list, arr, move);
	}
}

