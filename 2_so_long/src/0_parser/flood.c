
#include "parse_lib.h"
#include <stdlib.h>

static void	coin_flood(int y, int x, t_validators *v)
{
	if (x < 0 || y < 0 || x >= v->x || y >= v->y || v->coin_map[y][x] == '1' ||
	v->coin_map[y][x] == 'F' || v->coin_map[y][x] == 'E')
		return ;
	if (v->coin_map[y][x] == 'C')
		v->coins -= 1;
	v->coin_map[y][x] = 'F';
	coin_flood(y - 1, x, v);
	coin_flood(y, x - 1, v);
	coin_flood(y + 1, x, v);
	coin_flood(y, x + 1, v);
}

static int	exit_flood(int y, int x, t_validators *v)
{

	if (x < 0 || y < 0 || x >= v->x || y >= v->y
		|| v->exit_map[y][x] == '1' || v->exit_map[y][x] == 'F')
		return (0);
	if (v->exit_map[y][x] == 'E')
		return (1);
	v->exit_map[y][x] = 'F';
	return (exit_flood(y - 1, x, v) ||
	exit_flood(y, x + 1, v) ||
	exit_flood(y + 1, x, v) ||
	exit_flood(y, x - 1, v));
}

static char	**clean_arr(t_validators *v)
{
	int	i;

	if (v->coin_map)
	{
		i = -1;
		while (v->coin_map[++i])
			free(v->coin_map[i]);
		free(v->coin_map);
		v->coin_map = NULL;
	}
	if (v->exit_map)
	{
		i = -1;
		while (v->exit_map[++i])
			free(v->exit_map[i]);
		free(v->exit_map);
		v->exit_map = NULL;
	}
	v->error_mask |= MALLOCS_ER;
	return (NULL);
}

static char	**clone_arr(t_validators *v)
{
	int		i;
	char	**new_arr;

	new_arr = ft_calloc(v->y + 1, sizeof(char *));
	if (!new_arr)
		return (clean_arr(v));
	i = 0;
	while (v->arr[i])
	{
		new_arr[i] = ft_strdup(v->arr[i]);
		if (!new_arr[i])
			return (clean_arr(v));
		i++;
	}
	return (new_arr);
}

void	ft_flood_map(t_validators *v)
{
	v->coin_map = clone_arr(v);
	v->exit_map = clone_arr(v);
	if (!v->coin_map || !v->exit_map)
	{
		clean_arr(v);
		return ;
	}
	if (v->coin_map)
		coin_flood(v->p_y, v->p_x, v);
	if (v->exit_map)
		v->exit = exit_flood(v->p_y, v->p_x, v);
	if (v->coins)
		v->error_mask |= LOCKOIN_ER;
	if (!v->exit)
		v->error_mask |= LOCKEXI_ER;
}
