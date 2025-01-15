/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:15:14 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/27 15:15:16 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef FT_NULL_STR
#  define FT_NULL_STR "(null)"
# endif

# ifndef FT_NULL_PTR
#  define FT_NULL_PTR "(nil)"
# endif

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	print_dec_to_hex(unsigned int n, char flag, int prefix, int count);
int	print_address(unsigned long address, int flag, int prefix, int count);
int	print_unsigned_int(unsigned int n, int count);
int	printf_ft_putchar(char c);
int	printf_ft_putstr(char *c);
int	printf_ft_putnbr(int n, int count);
#endif
