/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 22:09:32 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/14 10:50:14 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *dest;
	size_t l_s1;
	size_t l_s2;
	size_t l;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	l = l_s1 + l_s2;

	dest = ((char *)malloc((l + 1) * sizeof(char)));
	if (!dest)
		return (0);
	ft_strlcpy(dest, s1, l_s1 + 1);
	ft_strlcat(dest, s2, l + 1);
	return (dest);
}