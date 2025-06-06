
#include "server_side.h"
#include <stddef.h>
#include <stdlib.h>

char	*ft_add_char(char *str, int c)
{
	char	*b_str;
	size_t	len;

	if (!str)
	{
		b_str = ft_calloc(sizeof(char), 2);
		if (!b_str)
			return (NULL);
		b_str[0] = (char)c;
		return (b_str);
	}
	len = ft_strlen(str);
	b_str = ft_calloc(sizeof(char), len + 2);
	if (!b_str)
		return (NULL);
	ft_memcpy(b_str, str, len);
	b_str[len] = (char)c;
	return (b_str);
}

void	ft_handle_signal(int c, int pid)
{
	static char	*message;
	char		*temp;

	if (c == 0)
	{
		ft_printf("Message from %d:\n%s\n", pid, message);
		free(message);
		message = NULL;
		return ;
	}
	temp = ft_add_char(message, c);
	free(message);
	message = NULL;
	if (!temp)
		return ;
	message = temp;
}
