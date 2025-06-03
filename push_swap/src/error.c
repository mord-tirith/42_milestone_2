/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:37:39 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 14:38:15 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

void	ft_st_cleanup(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

void	ft_error_handler(t_stack **a, t_stack **b, char **arg, int c)
{
	if (a && *a)
		ft_st_cleanup(a);
	if (b && *b)
		ft_st_cleanup(b);
	if (c == 2)
		ft_free_arg(arg);
	ft_printf("Error\n");
	exit(1);
}
