/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 18:59:53 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/07 19:15:44 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hex(unsigned long int n, char format)
{
    int result;
    int counter;

    counter = 0;
    if (n >= 16)
    {
        result = ft_hex(n / 16,format);
        if (result == -1)
            return (-1);
        counter += result;
    }
    if (format == 'x' || format == 'p')
       result =  write(1,&"0123456789abcdef"[n % 16],1);
    else
       result = write(1,&"0123456789ABCDEF"[n % 16],1);
    if (result == -1)
        return (-1);
    counter++;
    return (counter); 
}
