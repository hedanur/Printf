/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:42:54 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/07 17:58:15 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int format(va_list arg,const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result += ft_char(va_arg(arg,int));
	else if (format == 's')
		result += ft_str(va_arg(arg,char *));
	else if (format == 'p')
	{
		ft_str("0x");
		result += ft_hex(va_arg(arg,unsigned long));
	}
	else if (format== 'd')
		result += ft_decimal(va_arg(arg, int));
	else if (format == 'i')
		result += ft_integer(va_arg(arg, int));
	else if (format == 'u')
		result += ft_unsigned(va_arg(arg, unsigned int));
	else if (format == 'x' || format == 'X')
		result += ft_hex(va_arg(arg, unsigned int));
	else if (format == '%')
		result += ft_putchar('%');
	else
		result += ft_putchar('%');
	return (result);
}


int	ft_printf(const char *str, ...)
{
    int i;
	int len;
	va_list arg;
	
	i = 0;
	len = 0;
	va_start(arg,str);
	while(str[i])
	{
		if (str[i] == '%')
		{
			len += ft_format(arg,str[i + 1]);
			i++;
		}
	else
	{
		len += ft_putchar(str[i]);
	}
	i++;
	}
	va_end(arg);
	return (len);
}