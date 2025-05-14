#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Includes:
# include <stddef.h>

typedef struct s_stack
{
	int				value;
	int				cost;
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
void	ft_st_addback(t_stack **stack, t_stack *new);
void	ft_st_addfront(t_stack **stack, t_stack *new);
void	ft_print_stack(t_stack *head);
t_stack	*ft_st_new_node(int value);
t_stack	*ft_st_last(t_stack **stack);

// Push swap operations:

#endif
