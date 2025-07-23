/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:17:35 by thenriqu          #+#    #+#             */
/*   Updated: 2025/04/28 13:27:13 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_stream	s;

	if (!format)
		return (-1);
	va_start(args, format);
	s.buffer = NULL;
	s.fd = 1;
	s.lim = SIZE_MAX;
	s.pos = 0;
	ft_printer(format, args, &s);
	return (s.pos);
}

int	ft_perror(int exit_code, const char *format, ...)
{
	va_list		args;
	t_stream	s;

	if (!format)
		return (-1);
	va_start(args, format);
	s.buffer = NULL;
	s.fd = 2;
	s.lim = SIZE_MAX;
	s.pos = 0;
	ft_printer(format, args, &s);
	return (exit_code);
}

int ft_pfile(int fd, const char *format, ...)
{
	va_list		args;
	t_stream	s;

	if (!format)
		return (-1);
	va_start(args, format);
	s.buffer = NULL;
	s.fd = fd;
	s.lim = SIZE_MAX;
	s.pos = 0;
	ft_printer(format, args, &s);
	return (s.pos);
}

int	ft_sprintf(char *buffer, size_t lim, const char *format, ...)
{
	va_list		args;
	t_stream	s;

	if (!format)
		return (-1);
	va_start(args, format);
	s.buffer = buffer;
	s.fd = -1;
	s.lim = lim;
	s.pos = 0;
	ft_printer(format, args, &s);
	if (s.pos < s.lim)
		s.buffer[s.pos] = '\0';
	else if (s.lim > 0)
		s.buffer[s.lim - 1] = '\0';
	return (s.pos);
}
