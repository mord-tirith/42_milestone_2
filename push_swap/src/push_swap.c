/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:24:24 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 12:38:03 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdlib.h>

static void	sort(t_stack **a, t_stack **b, int size)
{
	int	sorted;

	sorted = ft_st_sorted(*a);
	if ((size == 2) && !sorted)
		sa(a);
	else if (size == 3)
		ft_deal_three(a);
	else if (!sorted)
		ft_st_sort(a, b);
}

void	ft_free_arg(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
		i++;
	j = 0;
	while (j < i)
	{
		free(args[j]);
		j++;
	}
	free(args);
}

static char	**safe_split(char *arg)
{
	char	**split_args;

	split_args = ft_split(arg);
	if (!split_args)
		return (NULL);
	return (split_args);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**arg;
	int		size;

	if (argc < 2)
		return (0);
	if (argc == 2)
		arg = safe_split(argv[1]);
	else
		arg = argv + 1;
	if (!arg || !arg[0] || !ft_validate(arg))
		ft_error_handler(NULL, NULL, arg, argc);
	a = ft_kickoff_a(arg, argc);
	b = NULL;
	size = ft_st_len(a);
	ft_index_stack(a, size + 1);
	sort(&a, &b, size);
	if (argc == 2)
		ft_free_arg(arg);
	ft_st_cleanup(&a);
	ft_st_cleanup(&b);
	return (0);
}
