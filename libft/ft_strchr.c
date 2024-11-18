/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:58:03 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/13 22:17:41 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int n)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)n)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)n == 0)
		return ((char *)s);
	return (0);
}
