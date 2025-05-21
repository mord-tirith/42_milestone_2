
#include "tester_lib.h"
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

static int	count_commands(int fd)
{
	int		i;
	char	*trash;

	i = 0;
	trash = get_next_line(fd);
	while (trash)
	{
		i++;
		free(trash);
		trash = get_next_line(fd);
	}
	close(fd);
	return (i);
}

static char	**prep_commands(int fd, int size)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * size + 1);
	res[size] = NULL;
	res[i] = get_next_line(fd);
	while (res[i])
	{
		i++;
		res[i] = get_next_line(fd);
	}
	return (res);
}

static void	safe_free(char **arg)
{
	char	**temp;

	while (*arg)
	{
		temp = arg + 1;
		free(*arg);
		arg = temp;
	}
	if (*arg)
		free(*arg);
	free(arg);
}

int	main(int c, char **v)
{
	char 	**arg;
	char	**commands;
	int		count;

	if (c != 3)
		return (ft_printf("Error: please input 2 values:\n1 - values to sort\n2 - file with push_swap output.\n"), 1);
	arg = ft_split(v[1]);
	if (!arg || !ft_validate(arg))
		return (ft_printf("Error: invalid input or error processing values\n"), 1);
	count = run_commands(open(v[2], O_RDONLY));
	commands = prep_commands(open(v[2], O_RDONLY), count);
	ft_test_input(commands, arg, count);
	safe_free(commands);
	free(arg);
}
