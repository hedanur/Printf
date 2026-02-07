/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:52:32 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/07 19:35:17 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_str(char *str)
{
    int i;
    int result;

    if(!str)
        str = "(null)";
    i = 0;
        while(str[i])
        {
            write(1,&str[i],1);
            if (result == -1)
                return (-1);
            i++;
        }
    return (i);
}