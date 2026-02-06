/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 13:42:54 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/06 13:56:03 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int counter(char *str)
{
    	int i;

	i = 0;
	while (str[i] == '%')
	{
		if (str[i + 1] == 'c')
			return ();
		else if (str[i + 1] == 's')
			return ();
		else if (str[i + 1] == 'p')
		    return ();
		else if (str[i + 1] == 'd')
			return ();
		else if (str[i + 1] == 'i')
            return ();
		else if (str[i + 1] == 'u')
			return ();
		else if (str[i + 1] == 'x' || str[i + 1] == 'X')
            return ();
		else if (str[i + 1] == '%%')
			return ();
        else
            //eklenecek; 
        i++;
	}
}

int	ft_printf(const char *, ...)
{
	va_list format;

}