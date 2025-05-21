/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:19:47 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 15:28:29 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_lib.h"

static void	swap(t_stack *s)
{
	int	temp;

	if (!s || !s->next)
		return ;
	temp = s->value;
	s->value = s->next->value;
	s->next->value = temp;
}

void	s_sa(t_stack **a)
{
	swap(*a);
}

void	s_sb(t_stack **b)
{
	swap(*b);
}

void	s_ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
}
