/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:19:17 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 12:23:13 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

// Mini lib utils:
long	ft_atol(char *str);
void	ft_printf(char *str);
void	ft_print_num(int value);
char	**ft_split(char *str);

// Stack utils:
int		ft_st_len(t_stack *stack);
int		ft_st_sorted(t_stack *stack);
int		ft_st_lowest(t_stack **s);
void	ft_index_stack(t_stack *stack, int size);
void	ft_st_cleanup(t_stack **stack);
void	ft_st_add(t_stack **stack, t_stack *to_add);
void	ft_st_update_targets(t_stack **a, t_stack **b);
void	ft_st_print(t_stack **stack);
t_stack	*ft_st_new(int val);
t_stack	*ft_st_last(t_stack *s);
t_stack	*ft_st_second_last(t_stack *s);

// Pre-sort utils:
int		ft_validate(char **args);
void	ft_error_handler(t_stack **a, t_stack **b, char **arg, int c);
void	ft_free_arg(char **args);
t_stack	*ft_kickoff_a(char **v, int argc);

// Algorithm:
void	ft_deal_three(t_stack **a);
void	ft_st_sort(t_stack **a, t_stack **b);

//Algorithm Utils:
void	ft_clever_mover(t_stack **a, t_stack **b, int ca, int cb);
void	ft_get_cost(t_stack **a, t_stack **b);
void	ft_move_cheapest(t_stack **a, t_stack **b);

// Push Swap Commands:
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif
