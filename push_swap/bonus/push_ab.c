/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:31:31 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 15:34:31 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_lib.h"

static void	push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	temp = (*from)->next;
	(*from)->next = *to;
	*to = *from;
	*from = temp;
}

void	s_pa(t_stack **a, t_stack **b)
{
	push(b, a);
}

void	s_pb(t_stack **a, t_stack **b)
{
	push(a, b);
}
