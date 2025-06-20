
#include "pipex.h"
#include <stddef.h>

void	ft_error_handler(int m)
{
	if (m == BAD_ARGS)
		ft_perror("Please use: ./pipex.c infile cmd1 cmd2 outfile\n");
	else if (m == BAD_PIPE)
		ft_perror("Piping error\n");
	else if (m == BAD_FORK)
		ft_perror("Fork error\n");
	else if (m == BAD_MALL)
		ft_perror("Malloc error\n");
	exit(m);
}

void	ft_clean_split(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

char	**ft_bad_split(char **to_clean)
{
	ft_clean_split(to_clean);
	ft_error_handler(BAD_MALL);
	return (NULL);
}
