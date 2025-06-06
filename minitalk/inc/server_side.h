
#ifndef SERVER_SIDE_H
# define SERVER_SIDE_H

/*	Includes:	*/

# include "../libft/inc/libftpp.h"
# include <unistd.h>
# include <signal.h>

/*	Functions:	*/

void	ft_handle_signal(int c, int pid);
char	*ft_add_char(char *str, int c);

#endif
