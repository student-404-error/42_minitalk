/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seong-ki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 21:39:17 by seong-ki          #+#    #+#             */
/*   Updated: 2024/05/30 19:04:43 by seong-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_print_chr(int c);
int		ft_print_str(char *str);
int		ft_print_nbr(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char c);
char	*convert_to_hexa(unsigned long nbr);
int		ft_print_ptr(uintptr_t nbr);
int		ft_print_pct(void);
#endif
