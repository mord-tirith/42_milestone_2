
#include "so_long.h"
#include "parse_lib.h"
#include <stddef.h>
#include <stdlib.h>

static void	free2d(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static void	deboot_validators(t_validators *v)
{
	if (v->arr)
		v->arr = NULL;
	if (v->coin_map)
		free2d(v->coin_map);
	if (v->exit_map)
		free2d(v->exit_map);
	free(v);
}

static t_validators	*boot_validators(t_game *game)
{
	t_validators	*v;

	v = malloc(sizeof(t_validators));
	if (!v)
		return (NULL);
	v->error_mask = 0;
	v->coins = 0;
	v->exit = 0;
	v->player = 0;
	v->x = 0;
	v->y = 0;
	v->flood = 0;
	v->arr = game->map.layout;
	return (v);
}

void	ft_valid_map(t_game *game)
{
	t_validators	*v;

	ft_file_check(game);
	if (game->error_bitmask)
		return ;
	v = boot_validators(game);
	if (v)
	{
	ft_uniques(v);
	ft_check_ones(v);
	ft_flood_map(v);
	game->map.y = v->y;
	game->error_bitmask |= v->error_mask;
	}
	else
		game->error_bitmask |= MALLOCS_ER;
	deboot_validators(v);
}
