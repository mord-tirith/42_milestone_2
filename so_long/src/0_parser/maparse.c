
#include "so_long.h"
#include "parse_lib.h"
#include <stdlib.h>

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

	v = boot_validators(game);

	if (!v)
	{
	ft_uniques(v);
	ft_check_ones(v);
	ft_flood_map(v);
	game->error_bitmask |= v->error_mask;
	}
	else
		game->error_bitmask |= MALLOCS_ER;
}
