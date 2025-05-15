#include "push_swap.h"

static void	paired_move(t_stack **a, t_stack **b, t_stack *cheap)
{
	if (cheap->above_median)
	{
		while (*a != cheap && *b != cheap->target)
			rr(a, b);
	}
	else
	{
		while (*a != cheap && *b != cheap->target)
			rrr(a, b);
	}
}

static void	force_move(t_stack **a, t_stack **b, t_stack *cheap)
{
	while (*a != cheap)
	{
		if (cheap->above_median)
			ra(a);
		else
			rra(a);
	}
	while (*b != cheap->target)
	{
		if (cheap->target->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	ft_move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*goal;
	
	goal = ft_find_cheapest(a);
	if (goal->above_median == goal->target->above_median)
		paired_move(a, b, goal);
	force_move(a, b, goal);
	pb(a, b);
}
