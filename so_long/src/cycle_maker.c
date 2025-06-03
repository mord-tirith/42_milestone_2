#include "so_long.h"
#include "types.h"
#include <stdlib.h>

static int	count_frames(char model)
{
	if (model == 'w')
		return (8);
	else if (model == 'i')
		return (6);
	else if (model == 'd')
		return (10);
	ft_printf("ERROR: invalid model %c passed for sprite sheet\n", model);
	return (0);
}

static t_image	*make_frame(void *mlx, t_dir dir, int ent, char mod, int i)
{
	char	*path;
	t_image	*new_sprite;

	path = ft_give_frame(mod, dir, i, ent);
	if (!path)
		return (NULL);
	new_sprite = malloc(sizeof(t_image));
	if (!new_sprite)
	{
		free(path);
		return (NULL);
	}
	new_sprite->img = mlx_xpm_file_to_image(
	mlx, path, &new_sprite->width, &new_sprite->height);
	free(path);
	if (!new_sprite->img)
	{
		free(new_sprite);
		return (NULL);
	}
	return (new_sprite);
}

static void	destroy_images(void *mlx, t_image **sheet, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sheet[i]->img)
			mlx_destroy_image(mlx, sheet[i]->img);
		free(sheet[i]);
		i++;
	}
	free(sheet);
}

static int	make_sprites(t_cycle *cycle, void *mlx, int ent, char mod)
{
	int	i;

	cycle->sprites = malloc(sizeof(t_image *) * cycle->frame_count);
	if (!cycle->sprites)
		return (0);
	i = 0;
	while (i < cycle->frame_count)
	{
		cycle->sprites[i] = make_frame(mlx, cycle->dir, ent, mod, i);
		if (!cycle->sprites[i])
		{
			destroy_images(mlx, cycle->sprites, i);
			return (0);
		}
		i++;
	}
	return (1);
}

t_cycle	*ft_load_cycle(char model, int entity, t_dir dir, void *mlx)
{
	t_cycle	*new_cycle;
	int		i;

	i = count_frames(model);
	new_cycle = malloc(sizeof(t_cycle));
	if (!i || !new_cycle)
		return (NULL);
	new_cycle->frame_count = i;
	if (model == 'i')
		new_cycle->frame_delay = 60;
	else
		new_cycle->frame_delay = 0;
	new_cycle->delay_count = 0;
	new_cycle->frame = 0;
	new_cycle->dir = dir;
	if (!make_sprites(new_cycle, mlx, entity, model))
	{
		free(new_cycle);
		return (NULL);
	}
	new_cycle->frame = 0;
	return (new_cycle);
}
