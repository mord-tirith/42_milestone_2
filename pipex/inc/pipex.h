/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 08:51:31 by thenriqu          #+#    #+#             */
/*   Updated: 2025/06/20 08:53:11 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/*	Includes:	*/
# include "../libft/inc/libftpp.h"

/*	Macros:	*/
// Error handler macros:
# define BAD_ARGS 1
# define BAD_PIPE 2
# define BAD_FORK 3
# define BAD_MALL 4
# define BAD_OPEN 127
// Fd macros:
# define MODE_READ 1
# define MODE_WRIT 2
# define EXIST_ERROR -1
# define PERMS_ERROR -2

/*	Functions:	*/
int		ft_fd_opener(char *file, int io);
void	ft_error_handler(int m);
void	ft_clean_split(char **tab);
void	ft_exec_cmd(char *cmd, char **ep);
char	*ft_get_bin(char *cmd, char **ep);
char	**ft_quote_split(char *s);
char	**ft_bad_split(char **to_clean);
#endif
