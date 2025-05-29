#include "so_long.h"

static char	*finish_file(int i)
{
	static char	path[6];

	ft_bzero(path, 6);
	ft_strlcpy(path, "X.xpm", 6);
	path[0] = i + '0';
	return (path);
}

static char	*start_direction(t_dir dir)
{
	if (dir == DIR_UP)
		return ("up_00");
	else if (dir == DIR_RIGHT)
		return ("right_00");
	else if (dir == DIR_DOWN)
		return ("down_00");
	else
		return ("left_00");
}

static char	*complete_path(char model)
{
	if (model == 'i')
		return ("idle/192/idlex192_");
	else if (model == 'w')
			return ("walk/192/walkx192_");
	else
			return ("death/192/deathx192_");
}

char	*ft_give_frame(char model, t_dir dir, int frame, int entity)
{
	char	*frame_path;


	frame_path = ft_calloc(sizeof(char), 256);
	if (!frame_path)
		return (NULL);
	if ((model != 'i' && model != 'w' && model != 'd') ||
		frame < 0 || frame > 9)
	{
		ft_strlcat(frame_path, ERROR_ASSET, 256);
		return (frame_path);
	}
	if (entity == 0)
		ft_strlcat(frame_path, PLAYER, 256);
	else
		ft_strlcat(frame_path, ENEMY, 256);
	ft_strlcat(frame_path, complete_path(model), 256);
	ft_strlcat(frame_path, start_direction(dir), 256);
	ft_strlcat(frame_path, finish_file(frame), 256);
	return (frame_path);
}
