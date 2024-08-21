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
	int b = 0, ar = 0;
	va_list a;
	char none = '%', sign, new;

	if (format == NULL || strcmp(format, "%") == 0)
	{
		exit(0);
	}
	va_start(a, format);
	while (format[ar] != '\0')
	{
		if (format[ar] == '%')
		{
			ar++;
			sign = '.';
			if (format[ar] == ' ' || format[ar] == '+' || format[ar] == '#')
			{
				new = format[ar + 1];
				if (new == 'd' || new == 'i')
				{
					sign = format[ar];
					ar++;
				}
				else if (new == 'x' || new == 'X' || new == 'o')
				{
					sign = format[ar];
					ar++;
				}
			}
			if (format[ar] == '%')
			{
				b += write(1, &format[ar], 1);
				ar++;
				continue;
			}
			else if (format[ar] == 'c')
			{
				b += spec_C(va_arg(a, int));
				ar++;
				continue;
			}
			else if (format[ar] == 's')
			{
				b += spec_S(va_arg(a, char *));
				ar++;
				continue;
			}
			else if (format[ar] == 'd' || format[ar] == 'i')
			{
				b += spec_D(va_arg(a, int), sign);
				ar++;
				continue;
			}
			else if (format[ar] == 'b')
			{
				b += spec_B(va_arg(a, unsigned int));
				ar++;
				continue;
			}
			else if (format[ar] == 'u')
			{
				b += spec_U(va_arg(a, unsigned int));
				ar++;
				continue;
			}
			else if (format[ar] == 'o')
			{
				b += spec_O(va_arg(a, unsigned int), sign);
				ar++;
				continue;
			}
			else if (format[ar] == 'x')
			{
				b += spec_x(va_arg(a, unsigned int), sign);
				ar++;
				continue;
			}
			else if (format[ar] == 'X')
			{
				b += spec_X(va_arg(a, unsigned int), sign);
				ar++;
				continue;
			}
			else if (format[ar] == 'S')
			{
				b += spec_SS(va_arg(a, char *));
				ar++;
				continue;
			}
			else if (format[ar] == 'p')
			{
				b += spec_P(va_arg(a, void *));
				ar++;
				continue;
			}
			else
			{
				b += write(1, &none, 1);
			}
		}
		b += write(1, &format[ar], 1);
		ar++;
	}
	return (b);
}
