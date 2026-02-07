/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:42:54 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/07 16:50:49 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>


int	ft_printf(const char *str, ...)
{
    int i;
	int	result;
	va_list arg;
	va_start(arg,str);
	
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == 'c' && str[i])
				result = ft_char(va_arg(arg,int)) + result; 
			else if (str[i + 1] == 's')
				result = ft_str(va_arg(arg,char *)) + result;
			else if (str[i + 1] == 'p')
				result = ;
			else if (str[i + 1] == 'd')
				result = ft_decimal(va_arg(arg, int)) + result;
			else if (str[i + 1] == 'i')
				result = ft_integer(va_arg(arg, int));
			else if (str[i + 1] == 'u')
				result = ft_unsigned(va_arg(arg, unsigned int)) + result
			else if (str[i + 1] == 'x' || str[i + 1] == 'X')
				result = ft_hex(va_arg(arg, unsigned int)) + result;
			else if (str[i + 1] == '%')
				result = ft_putchar('%');
			else
				 
			i++;
		}
	}
}