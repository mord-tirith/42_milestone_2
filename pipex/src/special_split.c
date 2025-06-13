#include "pipex.h"
#include <stddef.h>

static size_t	count_words(char *s)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		if (*s)
			count++;
		while (*s && *s != ' ' && *s != '\t')
		{
			if (*s == '"' || *s == 39)
			{
				s++;
				while (*s && *s != '"' && *s != 39)
					s++;
			}
			s++;
		}
	}
	return (count);
}

static char	*make_piece(char *s)
{
	char	quote;
	char	*piece;
	size_t	i;

	quote = 0;
	i = 0;
	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '"' || *s == 39)
		quote = *s;
	while (s[i] && s[i] != ' ' && s[i] != '\t')
	{
		if (quote)
		{
			while (s[i] && s[i] != quote)
				i++;
		}
		i++;
	}
	piece = ft_calloc(i + 1, sizeof(char));
	if (!piece)
		return (NULL);
	ft_strlcpy(piece, s, i + 1);
	return (piece);
}

static char	*jump_quotes(char *s)
{
	char	quote;

	while (*s == ' ' || *s == '\t')
		s++;
	if (*s == '"' || *s == 39)
	{
		quote = *s;
		while (*s && *s != quote)
			s++;
	}
	return (s);
}

static char	**cleanup(char **split)
{
	size_t	i;
	char	*temp;

	i = 0;
	while (split[i])
	{
		if (split[i][0] == '"')
		{
			temp = split[i];
			split[i] = ft_strtrim(split[i], "\"");
			free(temp);
		}
		else if (split[i][0] == 39)
		{
			temp = split[i];
			split[i] = ft_strtrim(split[i], "'");
			free(temp);
		}
		i++;
	}
	return (split);
}

char	**ft_quote_split(char *s)
{
	char	**split;
	size_t	size;
	size_t	i;

	if (!s)
		return (NULL);
	size = count_words(s);
	split = ft_calloc(size + 1, sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == ' ' || *s == '\t')
			s++;
		split[i] = make_piece(s);
		if (!split[i])
			return (ft_bad_split(split));
		s += ft_strlen(split[i]);
		i++;
		s = jump_quotes(s);
	}
	return (cleanup(split));
}
