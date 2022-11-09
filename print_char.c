#include "main.h"
/**
 * 
 * 
 * 
 * 
*/
void print_char(va_list p)
{
    char c;

    c = va_arg(p, int);
	_putchar(c);
}
