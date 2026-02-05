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
#include <stdlib.h>

int ft_decimal(int n)
{
	char *str;
	int i;
	
	str = ft_itoa(n);
	i = ft_str(str);
	free(str);
	return(i);
}