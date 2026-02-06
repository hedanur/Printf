#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

int	ft_char(char c);
int	ft_str(char *str);
int	ft_decimal(int n);
int	ft_unsigned(unsigned int n);
int	ft_integer(int n);
int	ft_hexadecimal(unsigned int n, int *i, char format);

#endif