#include "so_long.h"
#include "types.h"

static int	boot_cycles(void *mlx, t_being *p)
{
	p->idle[0] = ft_load_cycle('i', 0, DIR_UP, mlx);
	p->idle[1] = ft_load_cycle('i', 0, DIR_LEFT, mlx);
	p->idle[2] = ft_load_cycle('i', 0, DIR_DOWN, mlx);
	p->idle[3] = ft_load_cycle('i', 0, DIR_RIGHT, mlx);
	if (!p->idle[0] || !p->idle[1] || !p->idle[2] || !p->idle[3])
		return (0);
	p->walk[0] = ft_load_cycle('w', 0, DIR_UP, mlx);
	p->walk[1] = ft_load_cycle('w', 0, DIR_LEFT, mlx);
	p->walk[2] = ft_load_cycle('w', 0, DIR_DOWN, mlx);
	p->walk[3] = ft_load_cycle('w', 0, DIR_RIGHT, mlx);
	if (!p->walk[0] || !p->walk[1] || !p->walk[2] || !p->walk[3])
		return (0);
	p->dead[0] = ft_load_cycle('d', 0, DIR_UP, mlx);
	p->dead[1] = ft_load_cycle('d', 0, DIR_LEFT, mlx);
	p->dead[2] = ft_load_cycle('d', 0, DIR_DOWN, mlx);
	p->dead[3] = ft_load_cycle('d', 0, DIR_RIGHT, mlx);
	if (!p->dead[0] || !p->dead[1] || !p->dead[2] || !p->dead[3])
		return (0);
	return (1);
}

int	ft_boot_player(t_game *game, t_point spawn)
{
	int		x;
	t_being	*p;

	p = &game->player;
	p->state = IDLING;
	p->position = spawn;
	p->frame = 0;
	p->dir = DIR_DOWN;
	x = boot_cycles(game->mlx, p);
	if (!x)
		return (0);
	return (1);
}
