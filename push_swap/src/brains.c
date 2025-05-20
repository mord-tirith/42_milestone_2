/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:13:41 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 14:18:32 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push_phase(t_stack **a, t_stack **b)
{
	int	size;
	int	pushed;
	int	i;

	size = ft_st_len(*a);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*a)->index <= size / 2)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a);
		i++;
	}
	while (size - pushed > 3)
	{
		pb(a, b);
		pushed++;
	}
}

static void	shift_phase(t_stack **a)
{
	int	lowest;
	int	size;

	size = ft_st_len(*a);
	lowest = ft_st_lowest(a);
	if (lowest > size / 2)
	{
		while (lowest < size)
		{
			rra(a);
			lowest++;
		}
	}
	else
	{
		while (lowest > 0)
		{
			ra(a);
			lowest--;
		}
	}
}

static int	st_highest(t_stack *s)
{
	int	i;

	i = s->index;
	while (s)
	{
		if (s->index > i)
			i = s->index;
		s = s->next;
	}
	return (i);
}

void	ft_deal_three(t_stack **a)
{
	int	end;

	if (ft_st_sorted(*a))
		return ;
	end = st_highest(*a);
	if ((*a)->index == end)
		ra(a);
	else if ((*a)->next->index == end)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	ft_st_sort(t_stack **a, t_stack **b)
{
	push_phase(a, b);
	ft_deal_three(a);
	while (*b)
	{
		ft_st_update_targets(a, b);
		ft_get_cost(a, b);
		ft_move_cheapest(a, b);
	}
	if (!ft_st_sorted(*a))
		shift_phase(a);
}
