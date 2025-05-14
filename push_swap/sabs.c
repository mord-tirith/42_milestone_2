/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sabs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:21:55 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/14 18:30:53 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

static void	swap_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = head->next;
	*stack = second;
	if (second->next)
		second->next->prev = head;
	head->next = second->next;
	head->prev = second;
	second->next = head;
	second->prev = NULL;
}

void	sa(t_stack **a)
{
	write(1, "sa\n", 3);
	swap_stack(a);
}

void	sb(t_stack **b)
{
	write(1, "sb\n", 3);
	swap_stack(b);
}

void	ss(t_stack **a, t_stack **b)
{
	write(1, "ss\n", 3);
	swap_stack(a);
	swap_stack(b);
}
