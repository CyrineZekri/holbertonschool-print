#include "main.h"
int printing_number(va_list liste)
{
    int n, c, x;
    n = va_arg(liste, int);
    if (n < 0)
    {
        _putchar('-');
        n = (-1) * n;
    }
    while (n >= 10)
    {
        n = n / 10;
        c++;
    }
    x = 10 ^ c;
    while (n >= 10)
    {
        _putchar(n % x + '0');
        n = n / x;
        x = x / 10;
    }
}