/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:30:25 by thenriqu          #+#    #+#             */
/*   Updated: 2025/04/28 13:26:46 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>
#include <unistd.h>

void	ft_print_c(int c, t_stream *s)
{
	if (s->fd >= 0)
	{
		write(s->fd, &c, 1);
		s->pos += 1;
	}
	else
		s->buffer[s->pos++] = c;
}

void	ft_print_s(char *str, t_stream *s)
{
	if (!str)
		return (ft_print_s("(null)", s));
	while (*str)
	{
		ft_print_c(*str, s);
		str++;
	}
}
