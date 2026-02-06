#include <stdarg.h>
#include <stdio.h>

int makine(int n, ...)
{
    va_list arg;
    va_start(arg,n);
    if( n == '+')
            return (va_arg(arg,int) + va_arg(arg,int) + va_arg(arg,int));
    if( n == '-')
        return (va_arg(arg,int) - va_arg(arg,int));
    if( n == '/')
        return (va_arg(arg,int) / va_arg(arg,int));
    if( n == '*')
        return (va_arg(arg,int) * va_arg(arg,int));
    return (0);
}

int main()
{
    printf("%d",makine('+', 1, 3, 4));
}