/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecakir <hecakir@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 16:55:15 by hecakir           #+#    #+#             */
/*   Updated: 2026/02/13 16:55:15 by hecakir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_char(char c);
int	ft_str(char *str);
int	ft_decimal(long nb);
int	ft_unsigned(unsigned int nb);
int	ft_hex(unsigned int n, char format);
int	ft_printf(const char *str, ...);
int	ft_ptr(unsigned long int n);

#endif
