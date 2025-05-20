/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:38:22 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 12:39:55 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

int	ft_st_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_stack	*ft_st_last(t_stack *s)
{
	while (s && s->next)
		s = s->next;
	return (s);
}

t_stack	*ft_st_second_last(t_stack *s)
{
	while (s && s->next && s->next->next)
		s = s->next;
	return (s);
}

t_stack	*ft_st_new(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->pos = -1;
	new->target_pos = -1;
	new->cost_a = -1;
	new->cost_b = -1;
	new->next = NULL;
	return (new);
}

void	ft_st_print(t_stack **stack)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		if (i)
			ft_printf(" ");
		ft_print_num(temp->value);
		temp = temp->next;
		if (!i)
			i = 1;
	}
}
