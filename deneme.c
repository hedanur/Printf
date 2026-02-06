
#include <stdio.h>
#include <stdarg.h>
#include "libft/libft.h"

int topla(int c, ...)
{
    va_list arg;
    va_start(arg,c);

    if (c == '+')
    {
        return (va_arg(arg,int) + va_arg(arg,int));
    }
    else if (c == '*')
    {
        return (va_arg(arg,int) * va_arg(arg,int));
    }
    else if (c == '/')
    {
        return (va_arg(arg,int) / va_arg(arg,int));
    }
    else if (c == '%')
    {
        return (va_arg(arg,int) % va_arg(arg,int));
    }

    return (0);
}
int main(int argc, char *argv[])
{
    (void)argc;
    printf("%d", topla(*argv[1], ft_atoi(argv[2]), ft_atoi(argv[3])));
}