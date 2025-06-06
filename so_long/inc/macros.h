#ifndef MACROS_H
# define MACROS_H


/*	Path Macros:	*/
# define PLAYER "assets/player/"
# define ENEMY "assets/enemy/"
# define MAP "assets/map/"
# define ERROR_ASSET "assets/entity/null.xpm"

/*	System Specific Variables:	*/
# ifdef __linux__
#  define ESC_KEY	65307
#  define W_KEY		119
#  define A_KEY		97
#  define S_KEY		115
#  define D_KEY		100
#  define INSTANCE	1
# elif __APPLE__
#  define ESC_KEY	53
#  define W_KEY		13
#  define A_KEY		0
#  define S_KEY		1
#  define D_KEY		2
#  define INSTANCE	0
# endif

/*	Window Macros:	*/
# ifndef WIDTH
#  define WIDTH 800
# endif
# ifndef HEIGHT
#  define HEIGHT 600
# endif

#endif
