/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:04:04 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 14:11:19 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rev_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca < 0 && *cb < 0)
	{
		(*ca)++;
		(*cb)++;
		rrr(a, b);
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *ca, int *cb)
{
	while (*ca > 0 && *cb > 0)
	{
		(*ca)--;
		(*cb)--;
		rr(a, b);
	}
}

static void	iter_ra(t_stack **a, int *ca)
{
	while (*ca)
	{
		if (*ca > 0)
		{
			ra(a);
			(*ca)--;
		}
		else
		{
			rra(a);
			(*ca)++;
		}
	}
}

static void	iter_rb(t_stack **b, int *cb)
{
	while (*cb)
	{
		if (*cb > 0)
		{
			rb(b);
			(*cb)--;
		}
		else
		{
			rrb(b);
			(*cb)++;
		}
	}
}

void	ft_clever_mover(t_stack **a, t_stack **b, int ca, int cb)
{
	if (ca < 0 && cb < 0)
		rev_both(a, b, &ca, &cb);
	else if (ca > 0 && cb > 0)
		rotate_both(a, b, &ca, &cb);
	iter_ra(a, &ca);
	iter_rb(b, &cb);
	pa(a, b);
}
