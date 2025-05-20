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

#include "../../inc/push_swap.h"

static void	swap(t_stack *s)
{
	int	temp;

	if (!s || !s->next)
		return ;
	temp = s->value;
	s->value = s->next->value;
	s->next->value = temp;
	temp = s->index;
	s->index = s->next->index;
	s->next->index = temp;
}

void	sa(t_stack **a)
{
	swap(*a);
	ft_printf("sa\n");
}

void	sb(t_stack **b)
{
	swap(*b);
	ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b)
{
	swap(*a);
	swap(*b);
	ft_printf("ss\n");
}
