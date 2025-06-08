/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thenriqu <thenriqu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 08:55:53 by thenriqu          #+#    #+#             */
/*   Updated: 2025/06/08 09:02:15 by thenriqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	size_t	i;

	if (!str2)
		return ((char *)str1);
	while (*str1)
	{
		i = 0;
		while (*str1 == str2[i])
		{
			i++;
			str1++;
		}
		if (!str2[i])
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
