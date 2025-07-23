
#include "so_long_bonus.h"

int ft_boot_map(t_assets *a, void *mlx)
{
	int			i;
	t_img		*t;
	static char	path[64];

	i = 0;
	while (MAP_ASSETS[i])
	{
		t = &a->a_map[i];
		ft_sprintf(path, sizeof(path), "../../assets/map/%c.xpm", MAP_ASSETS[i]);
		t->img = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
		if (!t->img)
			return (0);
		t->data = (unsigned int *)mlx_get_data_addr(t->img,
			&t->bpp, &t->line, &t->endian);
		i++;
	}
	return (1);
}
