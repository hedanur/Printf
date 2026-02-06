
#include <stdio.h>
#include <stdarg.h>

int topla(int c, ...)
{

    // int sum = 0;
    va_list arg;
    va_start(arg,c);

    if (c == '+')
    {
         return (va_arg(arg,int) + va_arg(arg,int));
    }
    else if (c == 'x')
    {
        return (va_arg(arg,int) * va_arg(arg,int));
    }
    else if (c == '/')
    {
        return (va_arg(arg,int) * va_arg(arg,int));
    }
    else if (c == '%')
    {
        return (va_arg(arg,int) * va_arg(arg,int));
    }

    return (0);
}
int main()
{
        printf("%d", topla('+',2,4));
}
