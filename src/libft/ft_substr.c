/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:52:47 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/23 14:58:38 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (malloc(1));
	if (len > s_len - start)
		len = s_len - start;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*str;
	char	*s;

	str = "0123456789";
	s = ft_substr("", 0, 0);
	printf("%s\n", s);
	free(s);
}*/
