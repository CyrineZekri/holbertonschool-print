#include "main.h"
/**
 * 
 * b njr
 * 
 * 
*/
int print_string(va_list p)
{
    char *s;
    int ls ,j, i = 0;

    s = va_arg(p, char*);
    ls = strlen(s);
	for (j = 1; j <=ls ; j++)
	{
		_putchar(*s);
		s++;
        i++;
	}
    return(i);
}
