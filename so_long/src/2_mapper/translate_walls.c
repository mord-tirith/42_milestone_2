
# include "map_lib.h"

int	ft_is_wall(t_map map, int y, int x)
{
	char	c;
	int		s_x;
	int		s_y;

	s_x = map.x;
	s_y = map.y;
	if (x < 0 || x >= s_x || y < 0 || y >= s_y)
		return (1);
	c = map.layout[y][x];
	return (c == '1');
}

static char	final_walls(int mask_dir, int mask_dig)
{
	if (mask_dir == 10)
		return ('Q');
	if (mask_dir == 11)
		return ("RSTU"[BITMASK_B[mask_dig] - '0']);
	if (mask_dir == 12)
		return ("VW"[BITMASK_C[mask_dig] - '0']);
	if (mask_dir == 13)
		return ("XYZ%"[BITMASK_D[mask_dig] - '0']);
	if (mask_dir == 14)
		return ("!@#$"[BITMASK_E[mask_dig] - '0']);
	if (mask_dir == 15)
		return (BITMASK_F[mask_dig]);
	return ('*');
}

static char	give_wall(int mask_dir, int mask_dig)
{
	if (mask_dir == 0)
		return ('A');
	if (mask_dir == 1)
		return ('B');
	if (mask_dir == 2)
		return ('C');
	if (mask_dir == 3)
		return ("DE"[BITMASK_3[mask_dig] - '0']);
	if (mask_dir == 4)
		return ('F');
	if (mask_dir == 5)
		return ('G');
	if (mask_dir == 6)
		return ("HI"[BITMASK_6[mask_dig] - '0']);
	if (mask_dir == 7)
		return ("JKLM"[BITMASK_7[mask_dig] - '0']);
	if (mask_dir == 8)
		return ('N');
	if (mask_dir == 9)
		return ("OP"[BITMASK_9[mask_dig] - '0']);
	return (final_walls(mask_dir, mask_dig));
}

char	ft_prep_wall(t_map map, int y, int x)
{
	int	wasd_mask;
	int	diag_mask;

	wasd_mask = 0;
	wasd_mask |= ft_is_wall(map, y - 1, x + 0) << 3;
	wasd_mask |= ft_is_wall(map, y + 0, x - 1) << 2;
	wasd_mask |= ft_is_wall(map, y + 1, x + 0) << 1;
	wasd_mask |= ft_is_wall(map, y + 0, x + 1) << 0;
	diag_mask = 0;
	diag_mask |= ft_is_wall(map, y - 1, x - 1) << 3;
	diag_mask |= ft_is_wall(map, y - 1, x + 1) << 2;
	diag_mask |= ft_is_wall(map, y + 1, x - 1) << 1;
	diag_mask |= ft_is_wall(map, y + 1, x + 1) << 0;
	return (give_wall(wasd_mask, diag_mask));
}
