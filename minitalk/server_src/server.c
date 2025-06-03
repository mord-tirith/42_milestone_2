
#include "server_side.h"
#include <bits/types/siginfo_t.h>
#include <signal.h>
#include <sys/types.h>

static void	signal_to_char(int sig, siginfo_t *info, void *c)
{
	static int		bit_index;
	static char		bit_value;
	static pid_t	client_pid;

	(void)c;
	if (client_pid != info->si_pid)
		client_pid = info->si_pid;
	bit_value |= (sig == SIGUSR2) << (7 - bit_index);
	bit_index++;
	if (bit_index == 8)
	{
		write(1, &bit_value, 1);
		bit_index = 0;
		bit_value = 0;
		kill(client_pid, SIGUSR1);
	}
}

int main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = signal_to_char;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (42)
		pause();
}
