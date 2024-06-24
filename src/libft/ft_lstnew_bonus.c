/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:48:52 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/19 14:26:41 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->idx = 0;
	new_node->lis = 1;
	new_node->move[0] = 0;
	new_node->move[1] = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
// Description
// idx = 순서대로 hashing
// lis = 증가수열에 들어있는가
// move[0] a를 회전시키는 횟수, ra는 양수 rra는 음수
// move[1] b를 회전시키는 횟수, rb는 양수 rrb는 음수
