/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 11:37:22 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/05 16:51:14 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_decimal(int n)
{
	long	nb;
	int number;
	char	result;
	int len;

	len = 0;
	nb = (long)n;
	if (nb < 0)
	{
		number = write(1,"-", 1);
		if (number == -1)
			return (-1);
		len++;
		nb = -nb;
	}
	if (nb > 9)
	{
		number = ft_decimal(nb / 10);
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