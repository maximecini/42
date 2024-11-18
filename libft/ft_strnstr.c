/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:23 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/13 22:12:00 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t size)
{
	size_t	l_to_find;
	size_t	i;
	char	*s1;

	l_to_find = ft_strlen(to_find);
	s1 = (char *)str;
	i = 0;
	if (to_find[0] == '\0')
		return (s1);
	if (size == 0 || s1[0] == '\0')
	{
		return (NULL);
	}
	while (i < size)
	{
		if (ft_strncmp(s1, (char *)to_find, l_to_find) == 0)
		{
			if (i + l_to_find > size)
				return (NULL);
			return (s1);
		}
		s1++;
		i++;
	}
	return (0);
}
