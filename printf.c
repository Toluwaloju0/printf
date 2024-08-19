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

int _printf(const char *format, ...);
int _printf(const char *format, ...)
{
	int b = 0;
	va_list a;
/*	char none = '%';*/

	if (format == NULL)
	{
		exit(0);
	}
	va_start(a, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				b += write(1, format, 1);
				format++;
				continue;
			}
			else if (*format == 'c')
			{
				b += spec_C(va_arg(a, int));
				format++;
				continue;
			}
			else if (*format == 's')
			{
				b += spec_S(va_arg(a, char *));
				format++;
				continue;
			}
			else if (*format == 'd')
			{
				b += spec_D(va_arg(a, int));
				format++;
				continue;
			}
		}
		b += write(1, format, 1);
		format++;
	}
	return (b);
}
