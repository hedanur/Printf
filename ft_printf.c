/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:49:52 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/13 16:49:52 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	pointer(va_list arg)
{
	unsigned long	ptr;
	int				check;
	int				result;

	result = 0;
	ptr = (unsigned long)va_arg(arg, void *);
	if (ptr == 0)
		return (ft_str("(nil)"));
	check = ft_str("0x");
	if (check == -1)
		return (-1);
	result += check;
	check = ft_ptr(ptr);
	if (check == -1)
		return (-1);
	result += check;
	return (result);
}

static	int	ft_format(va_list arg, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_char(va_arg(arg, int));
	else if (format == 's')
		result += ft_str(va_arg(arg, char *));
	else if (format == 'p')
		result += pointer(arg);
	else if (format == 'd' || format == 'i')
		result += ft_decimal(va_arg(arg, int));
	else if (format == 'u')
		result += ft_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		result += ft_hex(va_arg(arg, unsigned int), format);
	else if (format == '%')
		result += ft_char('%');
	else if (format == '\0')
		return (-1);
	else if (format != '\0')
		result += ft_char('%') + ft_char(format);
	if (result == -1)
		return (-1);
	return (result);
}

static int	helper(const char *format, va_list arg)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			check = ft_format(arg, format[i + 1]);
			if (check == -1)
				return (-1);
			check += check;
			i++;
		}
		else
		{
			check = ft_char(format[i]);
			if (check == -1)
				return (-1);
			check += check;
		}
		i++;
	}
	return (check);
}

int	ft_printf(const char *format, ...)
{
	int		check;
	va_list	arg;

	check = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	check = helper(format, arg);
	if (check == -1)
		return (-1);
	va_end(arg);
	return (check);
}
