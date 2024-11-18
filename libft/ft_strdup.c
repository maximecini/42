/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:03:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/13 22:19:12 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*s;
	int		l;
	int		i;

	l = ft_strlen(src);
	s = (char *)malloc((l + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (i < l)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
