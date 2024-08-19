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
	char *for_null;

	if (str == NULL || strlen(str) == 0)
	{
		for_null = "null";
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
	d = write(1, b, strlen(b));
	return (d);
}
