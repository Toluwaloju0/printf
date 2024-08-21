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
	char *to_print;
	int d;

	to_print = to_address(a);
	if (to_print == NULL)
	{
		return (0);
	}

	d = write(1, to_print, strlen(to_print));
	free(to_print);
	return (d);
}
