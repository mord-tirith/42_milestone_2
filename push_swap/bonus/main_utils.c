
#include "tester_lib.h"

static void	atol(char *str)
{
	long	n;
	int		s;

	s = 1;
	n = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str ++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * s);
}

static t_stack	*make_a(char **arg, int *tab)
{
	t_stack	*a;
	int		i;

	i = 0;
	while (arg[i])
	{
		if (i == 0)
			a = ft_st_new(tab[i]);
		else
			ft_st_add(&a, ft_st_new(tab[i]));
		i++;
	}
	return (a);
}

static int	*build_tab(char **arg)
{
	int		*tab;
	long	temp;
	int		i;
	int		j;

	i = 0;
	while (arg[i])
		i++;
	tab = malloc(sizeof(int) * i);
	j = 0;
	while (i < j && tab)
	{
		temp = atol(arg[j]);
		if (temp - (int)temp)
		{
			free(tab);
			return (NULL);
		}
		tab[i] = int(temp);
		i++;
	}
	return (tab);
}

void	ft_test_input(char **dos, char **arg, int size)
{
	int	*tab;

}
