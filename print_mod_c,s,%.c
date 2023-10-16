#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
/**
*_printf - tp reproduce the printf function for c, s, %
* @format: the format to be followed
* @...: the variadic string
* Return: the number of characters printed
*/

int _printf(const char *format, ...)
{
	int b = 0, d = 0;
	char c, *str;
	va_list a;

	va_start(a, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				write(1, format, 1);
				format++;
				b++;
				continue;
			}
			else if (*format == 'c')
			{
				c = va_arg(a, int);
				write(1, &c, 1);
				format++;
				b++;
				continue;
			}
			else if (*format == 's')
			{
				str = va_arg(a, char *);
				{
					write(1, str, strlen(str));
					b++;
				}
				format++;
				continue;
			}
		}
		write(1, format, 1);
		format++;
		b++;
	}
	va_end(a);
	return (b + d);
}
