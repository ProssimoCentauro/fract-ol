/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtodaro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:15:21 by rtodaro           #+#    #+#             */
/*   Updated: 2024/12/27 15:19:14 by rtodaro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	get_char(const char *s)
{
	s++;
	while ((*s == '-') || (*s == '0') || (*s == '.') || ((*s >= '0')
			&& (*s <= '9')) || (*s == '#') || (*s == ' ') || (*s == '+'))
		s++;
	return (*s);
}

static int	func_select(const char *s, va_list args)
{
	int	count;

	count = 0;
	if (*s == '%' && get_char(&*s) == 'c')
		count += printf_ft_putchar(va_arg(args, int));
	else if (*s == '%' && get_char(&*s) == 's')
		count += printf_ft_putstr(va_arg(args, char *));
	else if (*s == '%' && ((get_char(&*s) == 'x') || (get_char(&*s) == 'X')))
		count += print_dec_to_hex(va_arg(args, unsigned int), get_char(&*s), 0,
				0);
	else if (*s == '%' && ((get_char(&*s) == 'd') || (get_char(&*s) == 'i')))
		count += printf_ft_putnbr(va_arg(args, int), 0);
	else if (*s == '%' && get_char(&*s) == 'p')
		count += print_address(va_arg(args, unsigned long), 0, 1, 0);
	else if (*s == '%' && get_char(&*s) == 'u')
		count += print_unsigned_int(va_arg(args, unsigned int), 0);
	else if (*s == '%' && get_char(&*s) == '%')
		count += printf_ft_putchar('%');
	else
		count += printf_ft_putchar(*s);
	return (count);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			count += func_select(s, args);
			s = s + 2;
		}
		else
		{
			count += printf_ft_putchar(*s);
			s++;
		}
	}
	va_end(args);
	return (count);
}
