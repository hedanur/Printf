#include <stdarg.h>
#include <stdio.h>

int makine(int number, int n, ...)
{
    va_list arg;
    va_start(arg,n);
    int result;
    int sayi;

    if (n == '+' || n == '-')
    {
        result = 0;
    }
    else
    {
        result = 1;
    }
    while (number > 0)
    {
        sayi = va_arg(arg,int);
        if( n == '+')
        {
            result = sayi + result;
        }
        else if( n == '-')
            result = sayi - result;
        else if( n == '*')
             result = sayi * result;
        else if( n == '/')
            result = sayi / result;
        number--;
    }
    return (result);
}

int main()
{
    printf("%d",makine(3,'+', 1, 3, 4));
}