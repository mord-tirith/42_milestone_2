
#include "tester_lib.h"
#include <stdlib.h>

static int	command_to_int_2(char *str)
{
	if (!(str + 1) && *str == 'a')
		return (6);
	if (!(str + 1) && *str == 'b')
		return (7);
	if (!(str + 1))
		return (8);
	if (*(str + 2) == 'a')
		return (9);
	if (*(str + 2) == 'b')
		return (10);
	return (11);
}

static int	command_to_int_1(char *str)
{
	int	command;

	if (*str == 'p')
	{
		if (*(str + 1) == 'a')
			return (1);
		return (2);
	}
	if (*str == 's')
	{
		if (*(str + 1) == 'a')
			return (3);
		if (*(str + 1) == 'b')
			return (4);
		return (5);
	}
	return (command_to_int_2(str + 1));
}
int	*ft_args_to_vals(char **args)
{
	size_t	i;
	int		*tab;

	i = 0;
	while (args[i])
		i++;
	tab = malloc(sizeof(int) * (i + 1));
	if (!tab)
		return (NULL);
	tab[0] = i;
	i = 1;
	while (args[i])
	{
		tab[i] = command_to_int_1(args[i]);
		i++;
	}
	return (tab);
}
