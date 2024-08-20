#include <stdio.h>
#include <limits.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int len, len2 = 0;

	len = _printf("%X\n", 123);
	len2 = printf("%X\n", 123);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n%d\n%d\n", len, len2);
		fflush(stdout);
		return (1);
	}
	return (0);
}
