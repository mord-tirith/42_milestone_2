/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 08:05:49 by thenriqu          #+#    #+#             */
/*   Updated: 2025/04/30 13:55:31 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* Includes: */
# include <stdarg.h>
# include <stddef.h>

/* Types: */
typedef struct s_stream
{
	int		fd;
	char	*buffer;
	size_t	pos;
	size_t	lim;
}	t_stream;

/* Functions: */
// Main
int		ft_printf(const char *format, ...);
int		ft_perror(int exit_code, const char *format, ...);
int		ft_pfile(int fd, const char *format, ...);
int		ft_sprintf(char *buffer, size_t lim, const char *format, ...);

// Helpers
int		ft_validate(char c);
void	ft_printer(const char *format, va_list args, t_stream *s);
void	ft_parsel(char spec, va_list arg, t_stream *s);
void	ft_print_c(int c, t_stream *s);
void	ft_print_s(char *str, t_stream *s);
void	ft_print_di(int n, t_stream *s);
void	ft_print_u(unsigned int n, t_stream *s);
void	ft_print_x(unsigned int n, char mode, t_stream *s);
void	ft_print_p(void *ptr, t_stream *s);

#endif
