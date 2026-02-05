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
#include <stdlib.h>

static int	ft_len(long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static  char	*ft_uitoa(unsigned int n)
{
	char	*str;
	int		len;
	unsigned long	nb;

	nb = (long)n;
	len = ft_len(nb);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[len - 1] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}
int ft_unsigned(unsigned int n) // unsigned ve int değer aralığı bak
{
    int i;
    char *str;
    
    str = ft_uitoa(n);
    i = ft_str(str);
    free(str);
    return (i);
}