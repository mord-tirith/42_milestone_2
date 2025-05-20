/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:40:32 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 13:13:12 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <limits.h>
#include <stdlib.h>

t_stack	*ft_kickoff_a(char **v)
{
	t_stack	*a;
	long	n;
	int		i;
	int		c;

	c = 0;
	while (v[c])
		c++;
	a = NULL;
	n = 0;
	i = 0;
	while (i < c)
	{
		n = ft_atol(v[i]);
		if (n > INT_MAX || n < INT_MIN)
			ft_error_handler(&a, NULL);
		if (i == 0)
			a = ft_st_new((int)n);
		else
			ft_st_add(&a, ft_st_new((int)n));
		i++;
	}
	return (a);
}

void	ft_index_stack(t_stack *stack, int size)
{
	t_stack	*temp;
	t_stack	*end;
	int		val;

	while (--size > 0)
	{
		temp = stack;
		val = INT_MIN;
		end = NULL;
		while (temp)
		{
			if (temp->value == INT_MIN && !temp->index)
				temp->index = 1;
			if (temp->value > val && !temp->index)
			{
				val = temp->value;
				end = temp;
				temp = stack;
			}
			else
				temp = temp->next;
		}
		if (end)
			end->index = size;
	}
}
