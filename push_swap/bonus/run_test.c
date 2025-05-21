#include "tester_lib.h"

static void	do_command_2(t_stack **a, t_stack **b, int c)
{
	if (c == 6)
		return (s_ra(a));
	if (c == 7)
		return (s_rb(b));
	if (c == 8)
		return (s_rr(a, b));
	if (c == 9)
		return (s_rra(a));
	if (c == 10)
		return (s_rrb(b));
	return (s_rrr(a, b));
}

static void	do_command_1(t_stack **a, t_stack **b, int c)
{
	if (c == 1)
		return (s_pa(a, b));
	if (c == 2)
		return (s_pb(a, b));
	if (c == 3)
		return (s_sa(a));
	if (c == 4)
		return (s_sb(b));
	if (c == 5)
		return (s_ss(a, b));
	return (do_command_2(a, b, c));
}

void	ft_follow_commands(int *commands, t_stack **a, t_stack **b)
{
	static int	i;

	while (++i < commands[0])
		do_command_1(a, b, commands[i]);
}
