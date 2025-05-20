/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:14:01 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 13:30:03 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_number(char *arg)
{
	while ((*arg >= 9 && *arg <= 13) || *arg == ' ')
		arg++;
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg >= '0' && *arg <= '9')
		arg++;
	if (*arg)
		return (0);
	return (1);
}

static int	is_zero(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	while (*arg == '0')
		arg++;
	if (*arg)
		return (0);
	return (1);
}

static int	nb_cmp(char *s1, char *s2)
{
	if (*s1 == '+')
	{
		if (*s2 != '+')
			s1++;
	}
	else
	{
		if (*s2 == '+')
			s2++;
	}
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

static int	has_duplicate(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[j])
		{
			if (nb_cmp(args[i], args[j]) == 0 && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_validate(char **args)
{
	int	i;
	int	zero_count;

	if (has_duplicate(args))
		return (0);
	zero_count = 0;
	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
			return (0);
		zero_count += is_zero(args[i]);
		if (zero_count > 1)
			return (0);
		i++;
	}
	return (1);
}
