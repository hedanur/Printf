/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:45:02 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/13 16:45:02 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_decimal(long nb)
{
	int		number;
	char	result;
	int		len;

	len = 0;
	if (nb < 0)
	{
		number = write(1, "-", 1);
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
	number = write(1, &result, 1);
	if (number == -1)
		return (-1);
	return (len + 1);
}
