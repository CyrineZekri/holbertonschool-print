#include "main.h"
/**
 *_printf -prints characters and strings.
 *@format:input var
 *Return:int.
 */
int _printf(const char *format, ...)
{
	va_list liste;
	int l = 0, i, n;

	va_start(liste, format);
	n = strlen(format);
	for (i = 0; i < n; i++)
	{
		if ((format) = '\0')
		{
			_putchar('\0');
		}
		else if (*(format + i) != '%')
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
			else if (*(format + i + 1) == 's')
			{
				l = l + print_string(liste);
				i = i + 1;
			}
			else 
			{
				_putchar('%');
				l++;
			}
		}
	}
	va_end(liste);
	return (l);
}
