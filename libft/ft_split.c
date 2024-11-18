/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 13:50:38 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/16 20:51:51 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(char const *str, char ch)
{
	size_t	i;
	size_t	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != ch && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == ch)
			trigger = 0;
		str++;
	}
	return (i);
}

static void	ft_free_split(char **split, size_t count)
{
	size_t	i;

	i = -1;
	while (++i < count)
		free(split[i]);
	free(split);
}

static char	**ft_to_write(char const *src, char c, char **split, size_t l_word)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (src[++i])
	{
		if (src[i] != c)
			l_word++;
		else if (src[i] == c && l_word > 0)
		{
			split[j] = ft_substr(src, (i - l_word), l_word);
			if (!split[j++])
				return (ft_free_split(split, j), NULL);
			l_word = 0;
		}
	}
	if (l_word > 0)
	{
		split[j++] = ft_substr(src, (i - l_word), l_word);
		if (!split[j - 1])
			return (ft_free_split(split, j - 1), NULL);
	}
	return (split[j] = NULL, split);
}

char	**ft_split(char const *src, char c)
{
	char	**split;
	char	*cpy;

	split = (char **)malloc((ft_count_word(src, c) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = ft_to_write(src, c, split, 0);
	return (split);
}
