
#include "client_side.h"
#include <bits/types/sigset_t.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>

static t_flags	flags;

void	ft_receive_nodd(int sig, siginfo_t *info, void *c)
{
	t_flags	*f;

	(void)sig;
	(void)info;
	(void)c;

	flags.server_nodd = 1;
	flags.byte_count++;
	if (flags.print_mode == 'v')
		ft_printf("Server received 1 byte\n");
}

void	ft_send_signals(pid_t target, char byte)
{
	int	bit;
	int	new_byte;

	bit = 7;
	while (bit >= 0)
	{
		new_byte = (byte >> bit) & 1;
		if (new_byte)
			kill(target, SIGUSR2);
		else
			kill(target, SIGUSR1);
		bit--;
		usleep(100);
	}
	while(!flags.server_nodd)
		pause();
	flags.server_nodd = 0;
}

static int	error_messages(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

static void	set_signal_masks()
{
	struct sigaction	sa;
	sigset_t			sig1_block;

	sigemptyset(&sig1_block);
	sigaddset(&sig1_block, SIGUSR1);
	sigprocmask(SIG_BLOCK, &sig1_block, NULL);

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = ft_receive_nodd;
	sigaction(SIGUSR1, &sa, NULL);
	sigprocmask(SIG_UNBLOCK, &sig1_block, NULL);
}

static void	secondary(char *s_pid, char *msg)
{
	pid_t	pid;

	pid = ft_atoi(s_pid);
	while (*msg)
	{
		ft_send_signals(pid, *msg);
		msg++;
	}
	ft_send_signals(pid, '\0');
	if (flags.print_mode == 'v' || flags.print_mode == 't')
		ft_printf("Total bytes received by server: %d\n", flags.byte_count);
}

int main(int argc, char **argv)
{
	char				*message;

	flags.print_mode = getopt(argc, argv, "vst");
	if (flags.print_mode == -1)
		flags.print_mode = 't';
	else if (flags.print_mode != 'v' && flags.print_mode != 's' && flags.print_mode != 't')
		return (error_messages("Non valid flag, use -v -s or -t\n"));
	if (optind + 2 > argc)
		return (error_messages("Usage: ./client [-vst] <PID> <message>\n"));
	flags.byte_count = 0;
	flags.server_nodd = 0;
	message = argv[optind + 1];
	set_signal_masks();
	secondary(argv[optind], message);
	return (0);
}
