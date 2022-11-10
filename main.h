#ifndef MAIN
#define MAIN
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int _printf(const char *format, ...);
int _putchar(char c);
int process_function(va_list list, const char *format, int i, int f);
void print_char(va_list p);
int print_string(va_list p);
#endif
