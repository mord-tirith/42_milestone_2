/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:16:21 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 15:19:10 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"
#include <stdlib.h>

static void	rotate(t_stack **s)
{
	t_stack	*temp;
	t_stack	*end;
	t_stack	*b_end;

	end = ft_st_last(*s);
	b_end = ft_st_second_last(*s);
	temp = *s;
	*s = end;
	(*s)->next = temp;
	b_end->next = NULL;
}

void	rra(t_stack **a)
{
	rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rrr\n");
}
