#include "so_long.h"
#include "types.h"

void	ft_draw_player(t_game *game)
{
	t_cycle	*current_cycle;
	t_image	*img;

	if (game->player.state == IDLING)
		current_cycle = game->player.idle[game->player.dir];
	else if (game->player.state == MOVING)
		current_cycle = game->player.walk[game->player.dir];
	else
		current_cycle = game->player.dead[game->player.dir];
	img = current_cycle->sprites[current_cycle->frame]->img;
	mlx_put_image_to_window(game->mlx, game->win, img,
		game->player.position.x * 128 + game->player.offset.x,
		game->player.position.y * 128 + game->player.offset.y);
	if (current_cycle->frame == current_cycle->frame_count)
		current_cycle->frame = 0;
}
