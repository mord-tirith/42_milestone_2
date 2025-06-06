
#include "client_side.h"
#include <stdio.h>
#include <unistd.h>


char	*ft_send_tty()
{
	
}


int main()
{
	char *tty = ttyname(STDIN_FILENO);
	printf(tty);
}
