/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 05:37:40 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/17 14:33:42 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void ft_putstr_fd(char *s, int fd)
{
	unsigned int i;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i],fd);
		i++;
	}
	
}