#include "push_swap.h"

static void	update_index(t_stack **stack)
{
	t_stack	*temp;
	size_t	i;

	i = 0;
	if (!stack)
		return ;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

static void	update_medians(t_stack **stack)
{
	size_t	total;
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	total = ft_st_last(stack)->index + 1;
	while (temp)
	{
		temp->above_median = temp->index < (total / 2);
		temp = temp->next;
	}
}

static t_stack	*find_target(t_stack *node, t_stack **stack)
{
	t_stack	*temp;
	t_stack	*target;

	temp = *stack;
	target = NULL;
	while (temp)
	{
		if (temp->value > node->value 
			&& (!target || temp->value < target->value))
			target = temp;
		temp = temp->next;
	}
	if (!target)
	{
		temp = *stack;
		while (temp)
		{
			if (!target || temp->value < target->value)
				target = temp;
			temp = temp->next;
		}
	}
	return (target);
}

static void	update_targets(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from || !*from || !to || !*to)
		return ;
	temp = *from;
	while (temp)
	{
		temp->target = find_target(temp, to);
		temp = temp->next;
	}
}

void	ft_cycle_refresh(t_stack **a, t_stack **b)
{
	update_index(a);
	update_medians(a);
	update_targets(a, b);
	if (b)
	{
		update_index(b);
		update_medians(b);
		update_targets(b, a);
	}
}
