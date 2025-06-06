
#ifndef CLIENT_SIDE_H
# define CLIENT_SIDE_H

/*	Includes:  */

# include "../libft/inc/libftpp.h"
# include <signal.h>
# include <unistd.h>

/*	Types:	*/

typedef struct s_flags
{
	int	server_nodd;
	int	byte_count;
	int	print_mode;
}	t_flags;

/*	Functions:	*/

void	ft_send_signals(pid_t target, char byte);
void	ft_send_tty(char *pid);

#endif
