#include "push_swap.h"

void	ft_smart_sort(t_stack **a)
{
	t_stack **b;
	size_t	i;

	b = NULL;
	i = ft_st_last(a)->index + 1;
	pb(a, b);
	pb(a, b);
	ft_cycle_refresh(a, b);
	while (i > 3)
	{
		ft_move_cheapest(a, b);
		ft_cycle_refresh(a, b);
		i = ft_st_last(a)->index + 1;
	}
	ft_deal_three(a);
	while (*b)
	{
		ft_move_cheapest(b, a);
		ft_cycle_refresh(b, a);
	}
}
