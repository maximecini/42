/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:44:52 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/17 14:59:59 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void *allocated_array;
	size_t i;
	size_t p;
	
	allocated_array = 0;
	if (size && nmemb > 2147483647/size)
		return (allocated_array);
	p = nmemb * size;
	if (p >= 0)
	{
		allocated_array = malloc(p);
		if (allocated_array == 0)
			return (allocated_array);
		i = 0;
		while (i < (nmemb * size))
		{
			((unsigned char *)allocated_array)[i] = 0;
			i++;
		}
	}

	return (allocated_array);
}