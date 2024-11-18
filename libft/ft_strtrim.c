/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:05:15 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/14 23:22:44 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strnncpy(char *dest, const char *s1, size_t min, size_t max)
{
	size_t	i;

	i = 0;
	while (min < max)
	{
		dest[i] = s1[min];
		i++;
		min++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_char_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t min;
	size_t max;
	char *dest;

	max = ft_strlen(s1);
	min = 0;
	if (!set)
		return (0);
	while (s1[min] && ft_char_in_set(set, s1[min]))
		min++;
	while (max > 0 && ft_char_in_set(set, s1[max - 1]))
		max--;
	if (max < min)
		dest = ft_strdup("\0");
	else
	{
		dest = (char *)malloc((max - min + 1) * sizeof(char));
		if (!dest)
			return (NULL);
		dest = ft_strnncpy(dest, s1, min, max);
	}
	return (dest);
}