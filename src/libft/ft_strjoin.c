/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:06:26 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/25 05:08:57 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	size_t	i;
	size_t	len;

	len = ft_strlen(s1);
	result = malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (result == NULL)
		return (result);
	i = 0;
	while (i < len)
	{
		result[i] = s1[i];
		i++;
	}
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	free(s1);
	return (result);
}
/*
int	main(int argc, const char *argv[])
{
	char	s1[] = "lorem ipsum";
	char	s2[] = "dolor sit amet";
	char	*strjoin;
	
	strjoin = ft_strjoin(s1, s2);
	printf("%s\n", strjoin);
	return (0);
}
*/
