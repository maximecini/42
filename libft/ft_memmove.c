/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:03:07 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/13 22:11:39 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*cpy_dest;
	const char		*cpy_src;
	size_t			i;

	if (n <= 0 || (!dest && !src))
		return (dest);
	cpy_dest = dest;
	cpy_src = src;
	i = 0;
	if (dest < src)
	{
		ft_memcpy(cpy_dest, cpy_src, n);
	}
	else
	{
		i = n;
		while (i--)
		{
			cpy_dest[i] = cpy_src[i];
		}
	}
	return (dest);
}
