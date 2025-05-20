/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:42:07 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 14:45:31 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <unistd.h>
#include <limits.h>

void	ft_printf(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

void	ft_print_num(int value)
{
	if (value == INT_MIN)
		return (ft_printf("-2147483648"));
	if (value < 0)
	{
		ft_printf("-");
		value = -value;
	}
	if (value >= 10)
		ft_print_num(value / 10);
	write(1, &"0123456789"[value % 10], 1);
}

long	ft_atol(char *str)
{
	long	n;
	int		s;

	n = 0;
	s = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = (n * 10) + (*str - '0');
		str++;
	}
	return (n * s);
}
