/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 10:55:26 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/13 11:14:37 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*ft_st_new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->prev = NULL;
	new->value = value;
	new->next = NULL;
	return (new);
}

t_stack	*ft_st_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	ft_st_addback(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	temp = ft_st_last(stack);
	temp->next = new;
	new->prev = temp;
}

void	ft_st_addfront(t_stack **stack, t_stack *new)
{
	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	new->next = *stack;
	(*stack)->prev = new;
	*stack = new;
}

void	ft_print_stack(t_stack *head)
{
	write(1, "Stack:", 6);
	while (head)
	{
		ft_putnum(head->value);
		write(1, " ", 1);
		head = head->next;
	}
	write(1, "\n", 1);
}
