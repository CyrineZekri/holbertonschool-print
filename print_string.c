#include "main.h"
/**
 *_printf -prints characters and strings.
 *@format:input var
 *Return:an int.
 */
int _printf(const char *format, ...)
{
    va_list liste;
    int i, n, l = 0;

    va_start(liste, format);
    if (format == NULL)
    {
        return (-1);
    }
    else
    {
        n = strlen(format);
        for (i = 0; i < n; i++)
        {
            if (*(format + i) != '%')
            {
                _putchar(*(format + i));
                l++;
            }
            else
            {
                if (format[i + 1] == 'c')
                {
                    print_char(liste);
                    l++;
                    i = i + 1;
                }
                else if (format[i + 1] == '\0')
                {

                    l--;
                    i = i + 1;
                }

                else if (format[i + 1] == '%')
                {
                    _putchar('%');
                    l++;
                    i = i + 1;
                }
                else if (*(format + i + 1) == 's')
                {
                    l = l + print_string(liste);
                    i = i + 1;
                }
            }
        }
    }
    va_end(liste);
    return (l);
}