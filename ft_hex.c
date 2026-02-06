/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:59:53 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/05 19:52:17 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexadecimal(unsigned int n, int *i, char format)
{
    int result;
    if (n >= 16)
    {
        result = ft_hexadecimal(n / 16, i, format);
        if (result == -1)
            return (-1);
    }
    if (format ==  'x')
       result =  write(1,&"0123456789abcdef"[n % 16],1);
    else
       result = write(1,&"0123456789ABCDEF"[n % 16],1);
    if (result == -1)
        return (-1);
    (*i)++;
    return (*i); 
}