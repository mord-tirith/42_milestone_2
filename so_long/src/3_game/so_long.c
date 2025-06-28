
#include "so_long.h"

static void	is_ber(char *str, t_game *game)
{
	int	size;

	size = ft_strlen(str);
	if (size >= 4)
	{
		if (!ft_strncmp(str + (size - 4), ".ber", 4))
			return ;
	}
	game->error_bitmask |= MAPFILE_ER;
}



int	main(int ac, char **av)
{
	
}
