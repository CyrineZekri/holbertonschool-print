#include "main.h"
/**
 * 
 * 
*/
int printing_numbers(va_list liste)
{
    int f = 0, pr, i, n;
    char *its;

    its = malloc (33 * sizeof(char));
    pr = va_arg(liste, int);
    1
    n = strlen(its);
    for (i = 0; i < n; i++)
    {
        _putchar(its[i]);
        f++;
    }
    return(f);
}