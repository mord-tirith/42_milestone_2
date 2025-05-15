#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

t_stack	*ft_st_new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->cost = 0;
	new->above_median = 0;
	new->index = 0;
	new->target = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_stack	*ft_st_last(t_stack **stack)
{
	t_stack	*temp;

	if (!stack || !*stack)
		return (NULL);
	temp = *stack;
	if (!temp->next)
		return (temp);
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

void	ft_st_print_stack(t_stack *head)
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

void    ft_st_start_a(t_stack **a, long *tab, size_t size)
{
        size_t  i;
        t_stack *node;

        i = 0;
        while (i < size)
        {
                node = ft_st_new_node(tab[i]);
                node->index = i;
                ft_st_addback(a, node);
                i++;
        }
}
