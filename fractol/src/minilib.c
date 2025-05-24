
#include "fractol.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ret;
	size_t			i;

	i = 0;
	ret = (unsigned char *)s;
	while (i < n)
		ret[i++] = '\0';
}
