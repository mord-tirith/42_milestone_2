/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:13:03 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 15:16:07 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester_lib.h"
#include <stdlib.h>

static void	rotate(t_stack **s)
{
	t_stack	*temp;
	t_stack	*end;

	temp = *s;
	*s = (*s)->next;
	end = ft_st_last(*s);
	temp->next = NULL;
	end->next = temp;
}

void	s_ra(t_stack **a)
{
	rotate(a);
}

void	s_rb(t_stack **b)
{
	rotate(b);
}

void	s_rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
