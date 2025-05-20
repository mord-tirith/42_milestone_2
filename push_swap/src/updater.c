/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   updater.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:30:31 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 13:54:24 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdint.h>

static void	update_pos(t_stack **s)
{
	t_stack	*temp;
	int		i;

	temp = *s;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
}

static int	find_target(t_stack **a, int i, int target_i, int target_pos)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->index > i && temp->index < target_i)
		{
			target_i = temp->index;
			target_pos = temp->pos;
		}
		temp = temp->next;
	}
	if (target_i != INT_MAX)
		return (target_pos);
	temp = *a;
	while (temp)
	{
		if (temp->index < target_i)
		{
			target_i = temp->index;
			target_pos = temp->pos;
		}
		temp = temp->next;
	}
	return (target_pos);
}

void	ft_st_update_targets(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		target_pos;

	temp = *b;
	update_pos(a);
	update_pos(b);
	target_pos = 0;
	while (temp)
	{
		target_pos = find_target(a, temp->index, INT_MAX, target_pos);
		temp->target_pos = target_pos;
		temp = temp->next;
		target_pos = 0;
	}
}

int	ft_st_lowest(t_stack **s)
{
	t_stack	*temp;
	int		i;
	int		pos;

	temp = *s;
	i = INT_MAX;
	update_pos(s);
	pos = temp->pos;
	while (temp)
	{
		if (temp->index < i)
		{
			i = temp->index;
			pos = temp->pos;
		}
		temp = temp->next;
	}
	return (pos);
}
