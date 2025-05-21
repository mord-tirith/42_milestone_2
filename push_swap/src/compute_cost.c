/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_cost.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:54:29 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 14:03:43 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>

static int	abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	ft_get_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp2;
	int		size1;
	int		size2;

	temp2 = *b;
	size1 = ft_st_len(*a);
	size2 = ft_st_len(*b);
	while (temp2)
	{
		temp2->cost_b = temp2->pos;
		if (temp2->pos > size2 / 2)
			temp2->cost_b = (size2 - temp2->pos) * -1;
		temp2->cost_a = temp2->target_pos;
		if (temp2->target_pos > size1 / 2)
			temp2->cost_a = (size1 - temp2->target_pos) * -1;
		temp2 = temp2->next;
	}
}

void	ft_move_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		goal;
	int		cost_a;
	int		cost_b;

	temp = *b;
	goal = INT_MAX;
	while (temp)
	{
		if (abs(temp->cost_a) + abs(temp->cost_b) < abs(goal))
		{
			goal = abs(temp->cost_a) + abs(temp->cost_b);
			cost_a = temp->cost_a;
			cost_b = temp->cost_b;
		}
		temp = temp->next;
	}
	ft_clever_mover(a, b, cost_a, cost_b);
}
