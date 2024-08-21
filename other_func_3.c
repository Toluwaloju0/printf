#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * to_address - To get the address of a variable
 * @var: - the variable
 * Return: a string containing the address
 */

char *to_address(void *var)
{
	char *fr_ret;
	unsigned long addr;

	if (var == NULL)
	{
		return (NULL);
	}

	addr = (unsigned long)var;

	fr_ret = itoa_fr_address(addr);
	if (fr_ret == NULL)
	{
		return (NULL);
	}
	return (fr_ret);
}


/**
 * itoa_fr_address - to convert an int to a string
 * @a: the string to be converted
 * Return: a buffer to storing the string
 */
char *itoa_fr_address(unsigned long a);
char *itoa_fr_address(unsigned long a)
{
	char j[512], *l;
	unsigned int rem;
	char rem_list[6] = {'A', 'B', 'C', 'D', 'E', 'F'};
	int d = 0, n;

	if (a == 0)
	{
		l = malloc(sizeof(char) * 2);
		l[0] = '0';
		l[1] = '\0';
		return (l);
	}
	while (a > 0)
	{
		rem = a % 16;
		if (rem > 9)
		{
			j[d] = rem_list[rem - 10];
		}
		else
		{
			j[d] = rem + '0';
		}
		a = a / 16;
		d++;
	}

	l = malloc(sizeof(char) * d);
	if (l == NULL)
	{
		return (NULL);
	}

	n = 2;
	l[0] = '0';
	l[1] = 'x';
	while (d > 0)
	{
		d--;
		l[n] = j[d];
		n++;
	}
	return (l);
}
