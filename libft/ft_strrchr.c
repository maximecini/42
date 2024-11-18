/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:57:20 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/17 15:34:23 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	int	l;
	int	i;

	l = 0;
	l = ft_strlen(string);
	i = 0;
	while (l + 1)
	{
		if (string[l] == (unsigned char)searchedChar)
			return ((char *)&string[l]);
		l--;
	}
	return (0);
}
