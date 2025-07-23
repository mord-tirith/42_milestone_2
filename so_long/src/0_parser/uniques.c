
#include "parse_lib.h"
#include "so_long.h"

static void	valid_e(t_validators *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->arr[y])
	{
		x = 0;
		while (v->arr[y][x])
		{
			if (v->arr[y][x] == 'E' && !v->exit)
				v->exit = 1;
			else if (v->arr[y][x] == 'E')
				v->error_mask |= EXITPLU_ER;
			x++;
		}
		y++;
	}
	if (!v->exit)
		v->error_mask |= NOEXITS_ER;
}

static void	valid_p(t_validators *v)
{
	int	x;
	int	y;

	y = 0;
	while (v->arr[y])
	{
		x = 0;
		while (v->arr[y][x])
		{
			if (v->arr[y][x] == 'P' && !v->player)
			{
				v->player = 1;
				v->p_x = x;
				v->p_y = y;
			}
			else if (v->arr[y][x] == 'P')
				v->error_mask |= PLAYERS_ER;
			x++;
		}
		y++;
	}
	if (!v->player)
		v->error_mask |= NOPLAYE_ER;
}

static void	valid_c(t_validators *v)
{
	int	y;
	int	x;

	y = 0;
	while (v->arr[y])
	{
		x = 0;
		while (v->arr[y][x])
		{
			if (v->arr[y][x] == 'C')
				v->coins++;
			x++;
		}
		y++;
	}
	if (!v->coins)
		v->error_mask |= NOCOINS_ER;
}

static int	valid_x(t_validators *v)
{
	int		i;

	i = 0;
	v->x = ft_strlen(v->arr[0]);
	while (v->arr[i])
	{
		if ((int)ft_strlen(v->arr[i]) != v->x)
		{
			v->error_mask |= X_VALUE_ER;
			return (0);
		}
		i++;
	}
	v->y = i;
	return (1);
}

void	ft_uniques(t_validators *v)
{
	if (!valid_x(v))
		return ;
	valid_p(v);
	valid_e(v);
	valid_c(v);
}
