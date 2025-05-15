#include "push_swap.h"
#include <unistd.h>

static void	ft_st_push(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!from || !*from)
		return ;
	temp = *from;
	*from = temp->next;
	if (*from)
		(*from)->prev = NULL;
	temp->next = *to;
	if (*to)
		(*to)->prev = temp;
	temp->prev = NULL;
	*to = temp;
}

void	pa(t_stack **a, t_stack **b)
{
	write(1, "pa\n", 3);
	ft_st_push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	write(1, "pb\n", 3);
	ft_st_push(a, b);
}
