#include "so_long.h"
#include <fcntl.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

static int	locate_uniques(char *row, int *p, int *e)
{
	char	*new_p;
	char	*new_e;

	new_p = ft_strchr(row, 'P');
	new_e = ft_strchr(row, 'E');
	if (new_p && *p)
		return (0);
	if (new_e && *e)
		return (0);
	if (new_p)
		*p = 1;
	if (new_e)
		*e = 1;
	return (1);
}

static int	valid_dimensions(int fd)
{
	char	*row;
	size_t	size;

	row = get_next_line(fd);
	if (!row)
		return (0);
	size = ft_strlen(row);
	while (row)
	{
		if (ft_strlen(row) != size || row[0] != '1' || 
			(row[size - 1] == '\n' && row[size - 2] != '1') || 
			(row[size - 1] != '\n' && row[size - 1] != '1'))
		{
			free(row);
			return (0);
		}
		free(row);
		row = get_next_line(fd);
	}
	return (1);
}

static int	is_legal(int fd)
{
	int		found_player;
	int		found_exit;
	char	*current_row;

	found_player = 0;
	found_exit = 0;
	current_row = get_next_line(fd);
	while (current_row)
	{
		if (!locate_uniques(current_row, &found_player, &found_exit))
		{
			free(current_row);
			return (0);
		}
		free(current_row);
		current_row = get_next_line(fd);
	}
	if (!found_player || !found_exit)
		return (0);
	return (1);
}

static int	closing_time(int fd, int state)
{
	close(fd);
	return (state);
}

int	ft_valid_map(char *map_file)
{
	int		fd;

	fd = open(map_file, O_RDONLY);
	if (!valid_dimensions(fd))
		return (closing_time(fd, 0));
	close(fd);
	fd = open(map_file, O_RDONLY);
	return (closing_time(fd, is_legal(fd)));
}
