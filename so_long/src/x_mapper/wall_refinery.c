
#include "map_lib.h"

static int	diagonal_bitmask(t_map_arr map, int y, int x)
{
	int	bit_mask;

	bit_mask = 0;
	bit_mask |= ft_is_wall(map, y - 1, x - 1) << 3;
	bit_mask |= ft_is_wall(map, y - 1, x + 1) << 2;
	bit_mask |= ft_is_wall(map, y + 1, x - 1) << 1;
	bit_mask |= ft_is_wall(map, y + 1, x + 1) << 0;
	return (bit_mask);
}

char	ft_refine_wall(t_map_arr map, int y, int x, char c)
{
	int		diag_mask;
	char	temp;

	diag_mask = diagonal_bitmask(map, y, x);
	if (c == 'A')
		temp = A_REFINEMASK[diag_mask];
	else if (c == 'C')
		temp = "QQQQ############"[diag_mask];
	else if (c == 'D')
		temp = "SS##SS##########"[diag_mask];
	else if (c == 'E')
		temp = "T#T#####T#T#####"[diag_mask];
	else
		temp = "R###R###R###R###"[diag_mask];
	if (temp == '#')
		return (c);
	return (temp);
}
