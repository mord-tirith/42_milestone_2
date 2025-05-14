#include "push_swap.h"
#include <stdlib.h>
#include <stddef.h>

static int	are_numbers(char **list)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (list[i])
	{
		j = 0;
		while (list[i][j])
		{
			if ((list[i][j] == '+' || list[i][j] == '-') && !j)
				j++;
			if (!(list[i][j] >= '0' && list[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	are_unique_underflow(long *tab, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((tab[i] == tab[j] && i != j) || tab[i] != (int)tab[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_validate_input(char **list)
{
	long	*tab;
	size_t	size;

	size = 0;
	if (!are_numbers(list))
		return (0);
	tab = ft_arg_to_tab(list);
	if (!tab)
		return (0);
	while (list[size])
		size++;
	if (!are_unique_underflow(tab, size))
	{
		free(tab);
		return (0);
	}
	free(tab);
	return (1);
}

int	ft_is_sorted(long *tab, size_t size)
{
	size_t	i;

	if (!tab || !size)
		return (1);
	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			return (0);
		i++;
	}
	return (1);
}
