/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:08:27 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 15:12:01 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_st_add(t_stack **stack, t_stack *to_add)
{
	t_stack	*end;

	if (!to_add)
		return ;
	if (!*stack)
	{
		*stack = to_add;
		return ;
	}
	end = ft_st_last(*stack);
	end->next = to_add;
}

int	ft_st_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
