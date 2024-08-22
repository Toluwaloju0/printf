#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/**
 * spec_P - to print the pointer address of a variable
 * @a: the variable
 * Return: the number of characters written
 */

int spec_P(void *a)

{
	char *to_print, *fr_null = "(nil)";
	int d;

	to_print = to_address(a);
	if (to_print == NULL)
	{
		d = write(1, fr_null, strlen(fr_null));
		return (d);
	}

	d = write(1, to_print, strlen(to_print));
	free(to_print);
	return (d);
}


/**
 * spec_R - to print a string in reverse
 * @a: the string to print
 * Return: the number of characters printed
 */

int spec_R(char *a)

{
	char *none = "(null)";
	int d = 0, tras;

	if (a == NULL)
	{
		d = write(1, none, strlen(none));
		return (d);
	}

	tras = strlen(a);
	while (tras > 0)
	{
		tras--;
		d += write(1, &a[tras], 1);
	}
	return (d);
}
