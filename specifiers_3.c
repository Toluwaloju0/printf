#include "main.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * spec_P - to print the pointer address of a variable
 * @a: the variable
 * Return: the number of characters written
 */

int spec_P(void *a)

{
	char *to_print, fr_null = "(nil)";
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
