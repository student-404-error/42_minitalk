/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:47:28 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/21 18:57:55 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s_pt1;
	unsigned char	*s_pt2;

	s_pt1 = (unsigned char *) s1;
	s_pt2 = (unsigned char *) s2;
	if (!n)
		return (0);
	while (--n)
	{
		if (*s_pt1 != *s_pt2)
			break ;
		s_pt1++;
		s_pt2++;
	}
	return (*s_pt1 - *s_pt2);
}
