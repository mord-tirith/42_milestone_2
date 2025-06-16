#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int ac, char **av)
{
	if (ac != 2)
		return (0);
	pid_t	pid = atoi(av[1]);
	kill(pid, SIGUSR1);
}
