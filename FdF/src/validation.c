
#include "fdf.h"
#include <stdlib.h>
#include <fcntl.h>

static int	valid_input(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n' && !line[i + 1])
			break ;
		if (line[i] == '+' || line[i] == '-')
		{
			if (line[i + 1] < '0' || line[i + 1] > '9')
				return (0);
			if (i && line[i - 1] != ' ')
				return (0);
		}
		else if ((line[i] < '0' || line[i] > '9') && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	count_nums(char *line)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!valid_input(line))
		return (-1);
	while (line[i])
	{
		while (line[i] == ' ')
			i++;
		if (line[i])
			count++;
		while (line[i] && line[i] != ' ')
			i++;
	}
	if (!count)
		return (-1);
	return (count);
}

int	ft_valid_map(char *file_name)
{
	char	*temp;
	int		width;
	int		fd;

	width = 0;
	fd = open(file_name, O_RDONLY);
	temp = get_next_line(fd);
	if (!temp)
	{
		close(fd);
		return (-1);
	}
	width = count_nums(temp);
	while (temp)
	{
		if (count_nums(temp) != width)
			width = -1;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	return (width);
}

int ft_get_height(char *arg)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(arg, O_RDONLY);
	height = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			height++;
	}
	close(fd);
	return (height);
}
