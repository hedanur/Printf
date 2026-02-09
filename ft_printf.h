#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_char(char c);
int	ft_str(char *str);
int	ft_decimal(int n);
int	ft_unsigned(unsigned int nb);
int	ft_hex(unsigned long int n, char format);
int	ft_printf(const char *str, ...);

#endif