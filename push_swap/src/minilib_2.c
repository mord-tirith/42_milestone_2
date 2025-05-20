/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 12:26:53 by thenriqu          #+#    #+#             */
/*   Updated: 2025/05/20 17:20:25 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count(char *s)
{
	size_t	i;
	int		c;

	i = 0;
	c = 0;
	while (s[i])
	{
		while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
			i++;
		if (s[i])
			c++;
		while (s[i] && !((s[i] >= 9 && s[i] <= 13) || s[i] == ' '))
			i++;
	}
	return (c);
}

static char	*make_word(char *s)
{
	size_t	i;
	char	*ns;

	i = 0;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (s[i] && ((s[i] < 9 || s[i] > 13) && s[i] != ' '))
		i++;
	ns = malloc(i + 1);
	if (!ns)
		return (NULL);
	i = 0;
	while (s[i] && ((s[i] < 9 || s[i] > 13) && s[i] != ' '))
	{
		ns[i] = s[i];
		i++;
	}
	ns[i] = 0;
	return (ns);
}

static char	**cleanup(char **tab, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char *str)
{
	int		c;
	int		i;
	char	**res;

	c = count(str);
	res = malloc(sizeof(char *) * (c + 1));
	if (!res)
		return (NULL);
	res[c] = NULL;
	i = 0;
	while (i < c)
	{
		res[i] = make_word(str);
		if (!res[i])
			return (cleanup(res, i));
		i++;
		while (!((*str >= 9 && *str <= 13) || *str == ' ') && *str)
			str++;
		while ((*str >= 9 && *str <= 13) || *str == ' ')
			str++;
	}
	return (res);
}
