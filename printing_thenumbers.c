#include "main.h"
int printing_number(va_list liste)
{
    int n, c = 0 ,f = 0, x = 1, i = 0, k;

    n = va_arg(liste, int);
    if (n < 0)
    {
        _putchar('-');
        n = (-1) * n;
        f++;
    }
    k = n;
    while (k >= 10)
    {
        k = k / 10;
        c++;
    }
    while (i < c)
    {
        x = x * 10;
        i++;
    }
    while (n >= 10)
    {
        _putchar(n / x + '0');
        n = n % x;
        x = x / 10;
        f++;
    }
    if (n < 10)
    {
        _putchar(n + '0');
        f++;
    }
    return(f);
}