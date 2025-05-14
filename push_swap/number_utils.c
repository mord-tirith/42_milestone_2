#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

static void	pnbr(long n)
{
	if (n > 10)
		pnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void	ft_putnum(int n)
{
	long	temp;

	temp = (long)n * ((n > 0) - (n < 0));
	if (n < 0)
		write(1, "-", 1);
	pnbr(temp);
}

long	ft_atol(char *s)
{
	int		sign;
	long	total;

	total = 0;
	sign = 1;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		total = (total * 10) + (*s - '0');
		s++;
	}
	return (total * sign);
}

long	*ft_arg_to_tab(char **arg)
{
	int		i;
	int		j;
	long	*tab;

	i = 0;
	while (arg[i])
		i++;
	tab = malloc(sizeof(long) * i);
	if (!tab)
		return (NULL);
	j = 0;
	while (j < i)
	{
		tab[j] = ft_atol(arg[j]);
		j++;
	}
	return (tab);
}
