#include "main.h"
/**
 *
 *
 */
int process_function(va_list list, const char* format, int i, int l)
{
    if (format[i + 1] == 'c')
    {
        print_char(list);
        l++;
    }
    else if (format[i + 1] == '\0')
    {
        l--;
    }
    else if (format[i + 1] == '%')
    {
        _putchar('%');
        l++;
    }
    else if (*(format + i + 1) == 's')
    {
        l = l + print_string(list);
    }
    return (l);
}
