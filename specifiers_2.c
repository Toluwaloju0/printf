#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
* spec_U - to print an integer
* @a: the integer to be printed
* Return: the number of digits
*/

int spec_U(unsigned int a)
{
	char *b;
	int d = 0;

	b = itoa_fr_unsigned_int(a);
	if (b == NULL)
	{
		exit(100);
	}
	d = write(1, b, strlen(b));
	free(b);
	return (d);
}

/**
* spec_O - to print an integer
* @a: the integer to be printed
* @sign: the sign before the specifier
* Return: the number of digits
*/

int spec_O(unsigned int a, char sign)
{
	char *b, zero = '0';
	int d = 0;

	if (sign == '#')
	{
		d += write(1, &zero, 1);
	}
	b = itoa_fr_octal(a);
	if (b == NULL)
	{
		exit(100);
	}
	d += write(1, b, strlen(b));
	free(b);
	return (d);
}

/**
* spec_x - to print an integer
* @a: the integer to be printed
* @sign: the sign before the specifier
* Return: the number of digits
*/

int spec_x(unsigned int a, char sign)
{
	char *b, *zero = "0x";
	int d = 0;

	b = itoa_fr_hexasmall(a);
	if (b == NULL)
	{
		exit(100);
	}
	if (sign == '#')
	{
		d += write(1, zero, 2);
	}
	d += write(1, b, strlen(b));
	free(b);
	return (d);
}

/**
* spec_X - to print an integer
* @a: the integer to be printed
* @sign: the sign before the specifier
* Return: the number of digits
*/

int spec_X(unsigned int a, char sign)
{
	char *b, *zero = "0X";
	int d = 0;

	b = itoa_fr_hexabig(a);
	if (b == NULL)
	{
		exit(100);
	}
	if (sign == '#')
	{
		d += write(1, zero, 2);
	}
	d += write(1, b, strlen(b));
	free(b);
	return (d);
}

/**
 * spec_SS - to print strings replacing some values with ascii
 * @str: the string to be printed
 * Return: the number of strings printed
 */

int spec_SS(char *str)

{
	int a = 0;
	char *for_null = "(null)", *in_ascii = "\\x", con = '0';

	if (str == NULL)
	{
		a = write(1, for_null, strlen(for_null));
		return (a);
	}

	while (*str != '\0')
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			a += write(1, in_ascii, strlen(in_ascii));

			for_null = itoa_fr_hexabig(*str);

			if (*str >= 127)
			{
				con = '1';
			}
			else
			{
				con = '0';
			}
			a += write(1, &con, 1);
			a += write(1, for_null, strlen(for_null));

			free(for_null);
			str++;
			continue;
		}
		a += write(1, str, 1);
		str++;
	}
	return (a);
}
