/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:56:41 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/15 11:54:27 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_lenght_s(long long n)
{
	long long	i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str_number;
	long long	l;
	long long	number;

	number = (long long)n;
	if ((n < 0))
		number = -number;
	if (number == 0)
		return (ft_strdup("0"));
	l = ft_lenght_s(n);
	str_number = (char *)malloc((l + 1) * sizeof(char));
	if (!str_number)
		return (NULL);
	str_number[l--] = '\0';
	while (l >= 0)
	{
		str_number[l--] = (number % 10) + '0';
		number /= 10;
	}
	if (n < 0)
		str_number[0] = '-';
	return (str_number);
}
