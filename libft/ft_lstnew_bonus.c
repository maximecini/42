/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 06:26:20 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/17 03:18:04 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *elememt;

	elememt = (t_list *)malloc(sizeof(t_list));
	if (!elememt)
		return (NULL);

	elememt->content = content;
	elememt->next = NULL;
	return (elememt);
}
