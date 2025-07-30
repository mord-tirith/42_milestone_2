
#include "bonus_parse_lib.h"
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

static void	free_ll(t_point **t)
{
	t_point	*old_temp;
	t_point *new_temp;

	if (!t || !*t)
		return ;
	new_temp = *(t);
	while (new_temp)
	{
		old_temp = new_temp;
		new_temp = new_temp->next;
		free(old_temp);
	}
	free(t);
}

static int	deboot_validators(t_validators *v)
{
	if (v->arr)
		free2d(v->arr);
	if (v->coin_map)
		free2d(v->coin_map);
	if (v->exit_map)
		free2d(v->exit_map);
	if (v->enemies)
		free_ll(v->enemies);
	return (v->error_mask);
}

static t_validators	*boot_validators(char *file, t_validators *v)
{
	v->error_mask = 0;
	v->coins = 0;
	v->exit = 0;
	v->player = 0;
	v->x = 0;
	v->y = 0;
	v->flood = 0;
	v->enemies = NULL;
	v->arr = NULL;
	v->coin_map = NULL;
	v->exit_map = NULL;
	v->map_file = file;
	return (v);
}

int	ft_valid_map(char *map_file, int f)
{
	t_validators	v;

	boot_validators(map_file, &v);
	ft_file_check(&v);
	if (v.error_mask)
		return (v.error_mask);
	ft_uniques(&v);
	if (v.error_mask)
		return (deboot_validators(&v));
	ft_check_ones(&v);
	if (!f)
		ft_start_enemies(&v);
	ft_flood_map(&v);
	ft_valid_symbols(&v);
	deboot_validators(&v);
	return (v.error_mask);
}

