/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:47:20 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/21 12:05:50 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*list_ptr;

	if (!lst)
		return (NULL);
	list_ptr = lst;
	while (list_ptr->next)
		list_ptr = list_ptr->next;
	return (list_ptr);
}
