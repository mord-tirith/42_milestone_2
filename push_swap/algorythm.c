#include "push_swap.h"

static t_stack	*find_target(t_stack *node, t_stack **stack)
{
	t_stack	*temp;
	t_stack	*target;

	temp = *stack;
	target->value = 0;
	while (temp->next)
	{
		if (temp->value > target->value && temp->value < node->value)
			target = temp;
		temp = temp->next;
	}
	return (target);
}

static void	make_target_top(t_stack *node, t_stack **b)
{
	while (node->target != *b)
	{
		if (node->target->above_median)
			rb(b);
		else
			rrb(b);
	}
}

void	ft_update_medians(t_stack **a, t_stack **b)
{
	size_t	total;
	t_stack	*temp;

	temp = *a;
	total = ft_st_last(a)->index + 1;
	while (temp)
	{
		temp->above_median = temp->index < (total / 2);
		temp = temp->next;
	}
	temp = *b;
	if (temp)
	{
		total = ft_st_last(b)->index + 1;
		while (temp)
		{
			temp->above_median = temp->index < (total / 2);
			temp = temp->next;
		}
	}
}

static void	update_a(t_stack **a, t_stack **b)
{
	size_t	i;
	size_t	total;
	t_stack	*temp;

	total = ft_st_last(a)->index;
	i = 0;
	temp = *a;
	while (i < total)
	{
		temp->target = find_target(temp, b);
		temp = temp->next;
		i++;
	}
}

