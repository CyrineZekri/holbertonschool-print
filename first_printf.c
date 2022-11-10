#include "main.h"
/**
 *_printf -prints characters and strings.
 *@format:input var
 *Return:an integer.
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
			else if (*(format + i) == '%')
			{
				l = l + process_function(liste, format, i);
				i = i + 1;
			}
		}
	}
	va_end(liste);
	return (l);
}
