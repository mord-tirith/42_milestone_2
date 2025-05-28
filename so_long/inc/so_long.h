
#ifndef SO_LONG_H
# define SO_LONG_H

/*	Includes:	*/
//	Libs:
# include "../libft/inc/libftpp.h"

//	Sublibs:
# include "macros.h"
# include "types.h"

// System dependent libs:
# ifdef __linux__
#  include "../minilibx-linux/mlx.h"
# elif __APPLE__
#  include "../minilibx-linux/mlx.h"
# endif

/*	Functions:	*/
//	Boot functions:
char	*ft_give_frame(char model, t_dir dir, int frame, int entity);

#endif
