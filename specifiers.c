#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
/**
* spec_C - to print the c character
* @c: the character to be printed
* Return: 1
*/
int spec_C(char c)
{
	write(1, &c, 1);
	return (1);
}
/**
* spec_S - to print the string character
* @str: the variadic string
* Return: string length of str
*/
int spec_S(char *str)
{
	int a;
	char *for_null = "(null)";

	if (str == NULL)
	{
		a = write(1, for_null, strlen(for_null));
		return (a);
	}
	a = write(1, str, strlen(str));
	return (a);
}


/**
* spec_D - to print an integer
* @a: the integer to be printed
* Return: the number of digits
*/

int spec_D(int a)
{
	char *b;
	int d = 0;

	b = itoa(a);
	if (b == NULL)
	{
		exit(100);
	}
	d = write(1, b, strlen(b));
	free(b);
	return (d);
}


/**
 * spec_B - tom print the binary of a number
 * @a: the number to be printed
 * Return: the number of characters printed
 */

int spec_B(unsigned int a)
{
	char *b;
	int d = 0;

	b = to_binary(a);
	if (b == NULL)
	{
		exit(100);
	}
	d = write(1, b, strlen(b));
	free(b);
	return (d);
}


/**
* spec_U - to print an integer
* @a: the integer to be printed
* Return: the number of digits
*/

int spec_U(unsigned int a)
{
	char *b;
	int d = 0;

	b = itoa_fr_unsigned(a);
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
* Return: the number of digits
*/

int spec_O(unsigned int a)
{
	char *b;
	int d = 0;

	b = itoa_fr_octal(a);
	if (b == NULL)
	{
		exit(100);
	}
	d = write(1, b, strlen(b));
	free(b);
	return (d);
}

/**
* spec_x - to print an integer
* @a: the integer to be printed
* Return: the number of digits
*/

int spec_x(unsigned int a)
{
	char *b;
	int d = 0;

	b = itoa_fr_hexasmall(a);
	if (b == NULL)
	{
		exit(100);
	}
	d = write(1, b, strlen(b));
	free(b);
	return (d);
}

/**
* spec_X - to print an integer
* @a: the integer to be printed
* Return: the number of digits
*/

int spec_X(unsigned int a)
{
	char *b;
	int d = 0;

	b = itoa_fr_hexabig(a);
	if (b == NULL)
	{
		exit(100);
	}
	d = write(1, b, strlen(b));
	free(b);
	return (d);
}
