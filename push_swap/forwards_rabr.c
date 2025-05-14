/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forwards_rabr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 11:38:48 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/14 18:17:19 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	ft_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	tail = ft_st_last(stack);
	*stack = head->next;
	(*stack)->prev = NULL;
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

void	ra(t_stack **a)
{
	write(1, "ra\n", 3);
	ft_rotate(a);
}

void	rb(t_stack **b)
{
	write(1, "rb\n", 3);
	ft_rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	write(1, "rr\n", 3);
	ft_rotate(a);
	ft_rotate(b);
}
