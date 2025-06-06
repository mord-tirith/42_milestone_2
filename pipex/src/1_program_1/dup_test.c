
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	if (ac != 3)
		return (0);
	int	t_fd = open(av[1], O_WRONLY | O_CREAT | O_APPEND);
	dup2(t_fd, STDOUT_FILENO);
	printf("%s\n", av[2]);
}

