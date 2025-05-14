/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backwards_rabr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:13:46 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/14 18:19:53 by thenriqu         ###   ########.fr       */
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
	if (tail->prev)
		tail->prev->next = NULL;
	tail->prev = NULL;
	tail->next = head;
	head->prev = tail;
	*stack = tail;
}

void	rra(t_stack **a)
{
	write(1, "rra\n", 4);
	ft_rotate(a);
}

void	rrb(t_stack **b)
{
	write(1, "rrb\n", 4);
	ft_rotate(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	write(1, "rrr\n", 4);
	ft_rotate(a);
	ft_rotate(b);
}
