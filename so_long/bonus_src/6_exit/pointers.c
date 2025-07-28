
#include "bonus_exit_lib.h"
#include "so_long_bonus.h"

static void	free_mobs(t_entity **list, int mobs)
{
	int	i;

	i = 0;
	while (i < mobs)
	{
		if (list[i])
			free(list[i]);
		i++;
	}
	if (list)
		free(list);
}

static void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->layout[i])
	{
		if (map->layout[i])
			free(map->layout[i]);
		if (map->arr[i])
			free(map->arr[i]);
		i++;
	}
	if (map->layout)
		free(map->layout);
	if (map->arr)
		free(map->arr);
	if (map)
		free(map);
}

void	ft_free_pointers(t_game *g)
{
	free_map(g->map);
	free_mobs(g->mobs, g->mob_count);
	if (g->player)
		free(g->player);
	if (g->assets)
		free(g->assets);

}
