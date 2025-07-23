/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 09:46:04 by thenriqu          #+#    #+#             */
/*   Updated: 2025/04/30 13:55:42 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_digicount(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		count++;
	while (n)
	{
		count++;
		n /= 16;
	}
	return (count);
}

void	ft_print_x(unsigned int n, char mode, t_stream *s)
{
	char	*hex;
	char	number[9];
	int		pos;

	if (mode == 'u')
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	pos = ft_hex_digicount(n);
	number[pos] = '\0';
	if (!n)
		number[0] = '0';
	while (n)
	{
		number[pos - 1] = hex[n % 16];
		n /= 16;
		pos--;
	}
	ft_print_s(number, s);
}

void	ft_print_p(void *ptr, t_stream *s)
{
	int				pos;
	char			*hex;
	char			pointer[17];
	unsigned long	n;

	if (!ptr)
	{
		ft_print_s("(nil)", s);
		return ;
	}
	hex = "0123456789abcdef";
	n = (unsigned long)ptr;
	pos = ft_hex_digicount(n);
	pointer[pos] = '\0';
	while (n)
	{
		pointer[pos - 1] = hex[n % 16];
		n /= 16;
		pos--;
	}
	ft_print_s("0x", s);
	ft_print_s(pointer, s);
}
