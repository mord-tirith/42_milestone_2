#include "so_long.h"
#include "types.h"
#include <fcntl.h>

static char	**give_rows(int fd, int *row_count, int *col_count)
{
	int		size;
	char	*current_row;
	char	**whole_map;

	current_row = get_next_line(fd);
	*col_count = ft_strlen(current_row);
	size = 0;
	while (current_row)
	{
		size++;
		free(current_row);
		current_row = get_next_line(fd);
	}
	*row_count = size;
	whole_map = ft_calloc(sizeof(char *), size + 1);
	if (!whole_map)
		return (NULL);
	return (whole_map);
}

static t_map	*finish_map(char *path, t_map *map)
{
	int		i;
	int		fd;
	char	*new_row;

	fd = open(path, O_RDONLY);
	i = 0;
	while (i < map->height)
	{
		new_row = get_next_line(fd);
		if (new_row && new_row[ft_strlen(new_row) - 1] == '\n')
			new_row[ft_strlen(new_row) - 1] = '\0';
		map->grid[i] = new_row;
		i++;
	}
	close(fd);
	return (map);
}

t_map	*ft_create_map(char *map_path)
{
	int		fd;
	int		rows;
	int		cols;
	t_map	*new_map;

	fd = open(map_path, O_RDONLY);
	new_map = malloc(sizeof(t_map));
	if (!new_map)
		return (NULL);
	new_map->grid = give_rows(fd, &rows, &cols);
	if (!new_map->grid)
	{
		free(new_map);
		return (NULL);
	}
	new_map->height = rows;
	new_map->width = cols;
	close(fd);
	return (finish_map(map_path, new_map));
}
