
#include "bonus_asset_lib.h"

static int	load_spikes(t_assets *a, void *mlx)
{
	int			i;
	t_img		*t;
	static char	path[64];

	i = 0;
	while (i < 3)
	{
		t = &a->a_spi[i];
		ft_sprintf(path, sizeof(path), "./assets/gen/s%d.xpm", i);
		t->img = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
		if (!t->img)
			return (0);
		t->data = (unsigned int *)mlx_get_data_addr(t->img,
			&t->bpp, &t->line, &t->endian);
		t->ppl = t->line / 4;
		i++;
	}
	return (1);
}

static int	load_keys(t_assets *a, void *mlx)
{
	int			i;
	t_img		*t;
	static char	path[64];

	i = 0;
	while (i < 3)
	{
		t = &a->a_key[i];
		ft_sprintf(path, sizeof(path), "./assets/gen/k%d.xpm", i);
		t->img = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
		if (!t->img)
			return (0);
		t->data = (unsigned int *)mlx_get_data_addr(t->img,
			 &t->bpp, &t->line, &t->endian);
		t->ppl = t->line / 4;
		i++;
	}
	return (1);
}

static int	load_exit(t_assets *a, void *mlx)
{
	int			i;
	t_img		*t;
	static char	path[64];

	i = 0;
	while (i < 2)
	{
		t = &a->a_exi[i];
		ft_sprintf(path, sizeof(path), "./assets/gen/e%d.xpm", i);
		t->img = mlx_xpm_file_to_image(mlx, path, &t->w, &t->h);
		if (!t->img)
			return (0);
		t->data = (unsigned int *)mlx_get_data_addr(t->img,
			 &t->bpp, &t->line, &t->endian);
		t->ppl = t->line / 4;
		i++;
	}
	return (1);
}

int	ft_boot_a_others(t_assets *a, void *mlx)
{
	if (!load_spikes(a, mlx) || !load_keys(a, mlx) || !load_exit(a, mlx))
		return (0);
	return (1);
}
