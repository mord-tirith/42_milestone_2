#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_begin_push_swap(char **arg)
{
	long	*tab;
	size_t	i;

	i = 0;
	while (arg[i])
		i++;
	tab = ft_arg_to_tab(arg);
	if (!tab)
		printf("ERROR\n");
	else if (ft_is_sorted(tab, i))
		printf("Input already sorted\n");
	else
		printf("Valid input detected\n");
	if (tab)
		free(tab);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 1)
		return (printf("Insuficient Arguments\n"), 0);
	else if (argc == 2)
		args = ft_split_mod(argv[1]);
	else
		args = argv + 1;
	if (!args || !ft_validate_input(args))
		printf("ERROR\n");
	else
		ft_begin_push_swap(args);
	if (argc == 2 && args)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
	}
	return (0);
}
