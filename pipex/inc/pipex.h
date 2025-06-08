
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
# define BAD_OPEN 5
// Fd macros:
# define MODE_READ 1
# define MODE_WRIT 2
# define READ_FLAGS O_RDONLY, 0777
# define WRIT_FLAGS O_WRONLY | O_CREAT | O_TRUNC, 0777

/*	Functions:	*/
void	ft_error_handler(int m);
char	*ft_get_bin(char *cmd, char **ep);
char	**ft_bad_split(char **tab);
#endif
