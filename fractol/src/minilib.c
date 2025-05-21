
#include "fractol.h"

void	ft_memset(void *p, int val, size_t size)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = p;
	while (i < size)
	{
		s[i] = (unsigned char)val;
		i++;
	}
}

