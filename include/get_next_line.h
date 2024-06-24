/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:12:14 by seong-ki          #+#    #+#             */
/*   Updated: 2024/06/24 15:16:19 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);
size_t	gnl_strlen(char *s);
char	*gnl_strchr(char *s, int c);
size_t	gnl_strlcpy(char *dst, char *src, size_t dstsize);
char	*gnl_strdup(char *s1);
#endif
