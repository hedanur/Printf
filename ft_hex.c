/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:48:36 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/13 16:48:36 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_hex(unsigned int n, char format)
{
	int	result;
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		result = ft_hex(n / 16, format);
		if (result == -1)
			return (-1);
		counter += result;
	}
	if (format == 'x')
		result = write(1, &"0123456789abcdef"[n % 16], 1);
	else
		result = write(1, &"0123456789ABCDEF"[n % 16], 1);
	if (result == -1)
		return (-1);
	counter++;
	return (counter);
}
