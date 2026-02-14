/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/14 13:58:04 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/14 14:42:47 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_ptr(unsigned long int n)
{
	int	result;
	int	counter;

	counter = 0;
	if (n >= 16)
	{
		result = ft_ptr(n / 16);
		if (result == -1)
			return (-1);
		counter += result;
	}
	result = write(1, &"0123456789abcdef"[n % 16], 1);
	if (result == -1)
		return (-1);
	counter++;
	return (counter);
}
