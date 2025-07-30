
#include "parse_lib.h"

static int	translate_valids(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'C' || c == 'E');
}

static int	check_symbols(char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!translate_valids(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_valid_symbols(t_validators *v)
{
	if (!check_symbols(v->arr))
		v->error_mask |= UNKNOWN_ER;
}
