#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
*_printf - to reproduce the printf function for c, s, %
* @format: the format to be followed
* @...: the variadic string
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int b = 0;
	va_list a;

	va_start(a, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, format,1);
				format++;
				b++;
				continue;
			}
			else if (*format == 'c')
			{
				spec_C(va_arg(a, int));
				format++;
				b++;
				continue;
			}
			else if (*format == 's')
			{
				spec_S(va_arg(a, char *));
				format++;
				continue;
			}
		}
		write(1, format, 1);
		format++;
		b++;
	}
	return (b);
}
