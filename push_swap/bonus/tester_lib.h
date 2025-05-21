
#ifndef TESTER_LIB_H
# define TESTER_LIB_H

# include "./gnl/get_next_line.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

int		ft_validate(char **args);
int		*ft_args_to_vals(char **args);
int		ft_st_sorted(t_stack *stack);
void	ft_follow_commands(int *commands, t_stack **a, t_stack **b);
void	ft_printf(char *str);
char	**ft_split(char *str);
t_stack	*ft_st_last(t_stack *s);
t_stack *ft_st_second_last(t_stack *s);
t_stack	*ft_st_new(int value);


void	ft_test_input(char **dos, char **arg, int size);

// Silent commands:
void	s_pa(t_stack **a, t_stack **b);
void	s_pb(t_stack **a, t_stack **b);
void	s_sa(t_stack **a);
void	s_sb(t_stack **b);
void	s_ss(t_stack **a, t_stack **b);
void	s_ra(t_stack **a);
void	s_rb(t_stack **b);
void	s_rr(t_stack **a, t_stack **b);
void	s_rra(t_stack **a);
void	s_rrb(t_stack **b);
void	s_rrr(t_stack **a, t_stack **b);




#endif
