#include "main.h"
/**
 *
 *
 */
int process_function(va_list list, const char* format, int i)
{
    int f = 0;

    if (format[i + 1] == 'c')
    {
        print_char(list);
        f++;
    }
    else if (format[i + 1] == '\0')
    {
        f--;
    }
    else if (format[i + 1] == '%')
    {
        _putchar('%');
        f++;
    }
    else if (*(format + i + 1) == 's')
    {
        f = f + print_string(list);
    }
    return (f);
}
