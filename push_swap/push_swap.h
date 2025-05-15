#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes:
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	int				above_median;
	size_t			cost;
	size_t			index;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// General math functions
long	ft_atol(char *s);
void	ft_putnum(int n);

// Argv mannipulation functions 
int		ft_validate_input(char **list);
int		ft_is_sorted(long *tab, size_t size);
char	**ft_split_mod(char *str);
long	*ft_arg_to_tab(char **arg);

// Stack operation functions
void	ft_st_clean_stack(t_stack **stack);
void	ft_st_addback(t_stack **stack, t_stack *new);
void	ft_st_print_stack(t_stack *head);
void	ft_st_start_a(t_stack **a, long *tab, size_t size);
t_stack	*ft_st_new_node(int value);
t_stack	*ft_st_last(t_stack **stack);

// Push swap operations:
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

// Solver helpers:
void	ft_cycle_refresh(t_stack **a, t_stack **b);
void	ft_move_cheapest(t_stack **a, t_stack **b);
t_stack	*ft_find_cheapest(t_stack **stack);


// Solver functions:
void	ft_deal_three(t_stack **a);
void	ft_solver(t_stack **a);
void	ft_smart_sort(t_stack **a);


#endif
