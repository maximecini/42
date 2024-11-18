/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcini-ha <rcini-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:26:36 by rcini-ha          #+#    #+#             */
/*   Updated: 2024/11/16 14:39:04 by rcini-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void ft_lstadd_back(t_list **lst, t_list *new)
{ 	
	
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	t_list *temp;
	temp = *lst;
	temp = ft_lstlast(temp);
	temp->next = new ;
}