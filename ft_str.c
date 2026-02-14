/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:56:56 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/13 16:56:56 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str(char *str)
{
	int	i;
	int	result;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
	{
		result = write(1, &str[i], 1);
		if (result == -1)
			return (-1);
		i++;
	}
	return (i);
}
