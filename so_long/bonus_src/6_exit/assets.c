
#include "bonus_exit_lib.h"

void	asset_destroy(t_img *list, void *mlx, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (list[i].img)
			mlx_destroy_image(mlx, list[i].img);
		i++;
	}
}

void	ft_free_assets(t_assets *a, void *mlx, t_img *frame)
{
	asset_destroy(a->a_map, mlx, 52);
	asset_destroy(a->a_pla, mlx, 96);
	asset_destroy(a->a_spi, mlx, 3);
	asset_destroy(a->a_key, mlx, 3);
	asset_destroy(a->a_exi, mlx, 2);
	asset_destroy(a->a_mob, mlx, 96);
	if (frame->img)
		mlx_destroy_image(mlx, frame->img);
	free(frame);
}
