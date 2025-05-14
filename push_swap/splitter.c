#include "push_swap.h"
#include <stdlib.h>

static int	count_numbers(char *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s)
			count++;
		while (*s && *s != ' ')
			s++;
		if (*s)
			s++;
	}
	return (count);
}

static char	*make_number(char *s)
{
	int		i;
	char	*n;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	n = malloc(i + 1);
	if (!n)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != ' ')
	{
		n[i] = s[i];
		i++;
	}
	n[i] = '\0';
	return (n);
}

static char	**clean_clean(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (arr[i])
			free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

static char	**clean_cut(char *s, char **arr, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		while (*s == ' ')
			s++;
		arr[i] = make_number(s);
		if (!arr[i])
			return (clean_clean(arr, j));
		i++;
		while (*s && *s != ' ')
			s++;
		if (*s)
			s++;
	}
	return (arr);
}

char	**ft_split_mod(char *s)
{
	char	**arr;
	int		size;
	int		i;

	i = 0;
	size = count_numbers(s);
	arr = malloc(sizeof(char *) * (size + 1));
	if (!arr)
		return (NULL);
	while (i <= size)
	{
		arr[i] = NULL;
		i++;
	}
	return (clean_cut(s, arr, size));
}
