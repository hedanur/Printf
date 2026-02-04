/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:52:32 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/04 13:28:26 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_str(char *str)
{
    int i;

    if(!str)
        str = ("null");//?
    i = 0;
        while(str[i])
        {
            write(1,&str[i],1);
            i++;
        }
    return (i);
} 
#include <stddef.h>
#include <stdio.h>

int main()
{
    printf("%s","hedanur");
}