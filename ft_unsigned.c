/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 15:15:10 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/05 16:55:10 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsigned(unsigned int nb) 
{
	int number;
	char	result;
	int len;

	len = 0;
	if (nb > 9)
	{
		number = ft_unsigned(nb / 10);
		if (number == -1)
			return (-1);
		len += number;
	}
	result = (nb % 10) + '0';
	number = write(1,&result,1);
	if (number == -1)
		return (-1);
	len++;
	return(len);
}