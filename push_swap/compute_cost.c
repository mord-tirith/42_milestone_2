#include "push_swap.h"

static size_t	calculate_target(t_stack *target)
{
	size_t	cost;

	if (target->above_median)
		cost = target->index;
	else
		cost = ft_st_last(&target)->index - target->index;
	return (cost);
}

static void	double_savings(t_stack *node)
{
	size_t	cost;
	size_t	target_cost;

	if (node->above_median)
		cost = node->index;
	else
		cost = ft_st_last(&node)->index - node->index;
	target_cost = calculate_target(node->target);
	if (target_cost > cost)
		node->cost = target_cost + 1;
	else
		node->cost = cost + 1;
}

static void	find_cost(t_stack *node)
{
	size_t	cost;

	if (node->above_median == node->target->above_median)
		return (double_savings(node));
	if (node->above_median)
		cost = node->index;
	else
		cost = ft_st_last(&node)->index - node->index;
	cost += calculate_target(node->target);
	node->cost = cost + 1;
}

static void	update_costs(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		find_cost(temp);
		temp = temp->next;
	}
}

t_stack	*ft_find_cheapest(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*cheapest;

	update_costs(stack);
	temp = *stack;
	cheapest = temp;
	while (temp)
	{
		if (temp->cost < cheapest->cost)
			cheapest = temp;
		temp = temp->next;
	}
	return (cheapest);
}
