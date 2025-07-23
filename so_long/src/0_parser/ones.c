
#include "parse_lib.h"
#include "so_long.h"

static int	top_and_bottom(t_validators *v)
{
	int	i;
	int	y;

	i = 0;
	y = v->y - 1;
	while (v->arr[0][i])
	{
		if (v->arr[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (v->arr[y][i])
	{
		if (v->arr[y][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	sides(t_validators *v)
{
	int	i;
	int	y_lim;
	int	x_lim;

	y_lim = v->y - 1;
	x_lim = v->x - 1;
	i = 1;
	while (i < y_lim)
	{
		if (v->arr[i][0] != '1' || v->arr[i][x_lim] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_ones(t_validators *v)
{
	if (!top_and_bottom(v) || !sides(v))
		v->error_mask |= OPENWAL_ER;
}
