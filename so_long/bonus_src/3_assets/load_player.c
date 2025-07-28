
#include "bonus_asset_lib.h"

static int	load_a(t_img *dst, void *mlx, char s, char d, int f)
{
	char		path[64];
	const char	*relative;

	ft_bzero(path, sizeof(path));
	relative = "./assets/anim/%c%c%d.xpm";
	ft_sprintf(path, sizeof(path), relative, s, d, f);
	dst->img = mlx_xpm_file_to_image(mlx, path, &dst->w, &dst->h);
	if (!dst->img)
		return (0);
	dst->data = (unsigned int *)mlx_get_data_addr(
		dst->img, &dst->bpp, &dst->line, &dst->endian);
	dst->ppl = dst->line / 4;
	return (1);
}

int	ft_boot_a_player(t_assets *a, void *mlx)
{
	int			f;
	int			d;
	static int	s;
	static int	i;

	while (s < 3)
	{
		d = 0;
		while (d < 4)
		{
			f = 0;
			while (f < (F_COUNT[s] - '0' + 1))
			{
				if (!load_a(&a->a_pla[i], mlx, S_NAMES[s], D_NAMES[d], f))
					return (0);
				i++;
				f++;
			}
			d++;
		}
		s++;
	}
	return (1);
}
