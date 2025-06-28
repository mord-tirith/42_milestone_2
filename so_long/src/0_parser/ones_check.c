
#include "so_long.h"
#include "parse_lib.h"

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

	i = 1;
	while (i < v->y)
	{
		if (v->arr[i][0] != '1' || v->arr[i][v->x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	ft_check_ones(t_validators *v)
{
	int	passed;

	passed = 1;
	if (!top_and_bottom(v) || !sides(v))
		passed = 0;
	if (!passed)
		v->error_mask |= OPENWAL_ER;
}
