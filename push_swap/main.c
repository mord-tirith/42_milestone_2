#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static void	deal_three(t_stack **a)
{
	int	i;
	int	j;
	int y;

	i = (*a)->value;
	j = (*a)->next->value;
	y = (*a)->next->next->value;
	if ((i < y && y < j) || (i > j && j > y))
	{
		sa(a);
		if (y < j)
			ra(a);
		else
			rra(a);
	}
	else if (j < i && i < y)
		sa(a);
	else if (y < i && i < j)
		rra(a);
	else if (j < y && y < i)
		ra(a);
}

static void	try_initialize(char **args)
{
	long	*tab;
	t_stack	*a;
	size_t	size;

	size = 0;
	while (args[size])
		size++;
	tab = ft_arg_to_tab(args);
	if (!tab)
		return ;
	a = NULL;
	ft_st_start_a(&a, tab, size);
	free(tab);
	if (size == 3)
	{
		deal_three(&a);
		ft_st_clean_stack(&a);
		return ;
	}
	ft_solver(&a);
}

static void	begin_push_swap(char **arg)
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
		return (free(tab));
	else if (i == 2)
		sa(NULL);
	else
		try_initialize(arg);
	if (tab)
		free(tab);
}

void	ft_st_clean_stack(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

int	main(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
		args = ft_split_mod(argv[1]);
	else
		args = argv + 1;
	if (!args || !ft_validate_input(args) || argc == 1)
		printf("ERROR\n");
	else
		begin_push_swap(args);
	if (argc == 2 && args)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
	}
	return (0);
}
