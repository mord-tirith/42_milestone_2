#include "server_side.h"

void	decode_signal(int signal)
{
	static unsigned char	current;
	static int				bit;

	current <<= 1;
	if (signal == 1)
		current |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", current);
		current = 0;
		bit = 0;
	}
}

void bit_putchar(char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		decode_signal(c >> i & 1);
		i--;
	}
}

int main()
{
	char *a = "This is so stupid but it works!";

	while (*a)
	{
		bit_putchar(*a);
		a++;
	}
	return (0);
}
