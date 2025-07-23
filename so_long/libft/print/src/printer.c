/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:38:23 by thenriqu          #+#    #+#             */
/*   Updated: 2025/07/06 13:52:34 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parsel(char spec, va_list arg, t_stream *s)
{
	if (spec == '%')
		ft_print_c('%', s);
	if (spec == 'c')
		ft_print_c(va_arg(arg, int), s);
	if (spec == 's')
		ft_print_s(va_arg(arg, char *), s);
	if (spec == 'd' || spec == 'i')
		ft_print_di(va_arg(arg, int), s);
	if (spec == 'u')
		ft_print_u(va_arg(arg, unsigned int), s);
	if (spec == 'x')
		ft_print_x(va_arg(arg, unsigned int), 'l', s);
	if (spec == 'X')
		ft_print_x(va_arg(arg, unsigned int), 'u', s);
	if (spec == 'p')
		ft_print_p(va_arg(arg, void *), s);
}

int	ft_validate(char c)
{
	char	*valid_input;

	valid_input = "cspdiuxX%";
	while (*valid_input)
	{
		if (c == *valid_input)
			return (1);
		valid_input++;
	}
	return (0);
}

void	ft_printer(const char *format, va_list args, t_stream *s)
{
	while (*format && (s->pos < s->lim))
	{
		if (*format == '%' && ft_validate(*(format + 1)))
		{
			format++;
			ft_parsel(*format, args, s);
		}
		else
			ft_print_c(*format, s);
		format++;
	}
}
