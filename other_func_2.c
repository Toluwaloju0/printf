#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * itoa_fr_unsigned_int - to convert an int to a string
 * @a: the string to be converted
 * Return: a buffer to storing the string
 */

char *itoa_fr_unsigned_int(unsigned int a)
{
	char j[512], *l;
	int d = 0, n;

	if (a == 0)
	{
		l = malloc(sizeof(char) * 2);
		l[0] = '0';
		l[1] = '\0';
		return (l);
	}
	l = malloc(sizeof(char) * 2);
	while (a > 0)
	{
		j[d] = (a % 10) + '0';
		a = a / 10;
		d++;
	}
	l = malloc(sizeof(char) * d);
	if (l == NULL)
	{
		return (NULL);
	}

	n = 0;
	while (d > 0)
	{
		d--;
		l[n] = j[d];
		n++;
	}
	return (l);
}

/**
 * itoa_fr_octal - to convert an int to a string
 * @a: the string to be converted
 * Return: a buffer to storing the string
 */

char *itoa_fr_octal(unsigned int a)
{
	char j[512], *l;
	int d = 0, n;

	if (a == 0)
	{
		l = malloc(sizeof(char) * 2);
		l[0] = '0';
		l[1] = '\0';
		return (l);
	}
	l = malloc(sizeof(char) * 2);
	while (a > 0)
	{
		j[d] = (a % 8) + '0';
		a = a / 8;
		d++;
	}
	l = malloc(sizeof(char) * d);
	if (l == NULL)
	{
		return (NULL);
	}

	n = 0;
	while (d > 0)
	{
		d--;
		l[n] = j[d];
		n++;
	}
	return (l);
}


/**
 * itoa_fr_hexasmall - to convert an int to a string
 * @a: the string to be converted
 * Return: a buffer to storing the string
 */

char *itoa_fr_hexasmall(unsigned int a);
char *itoa_fr_hexasmall(unsigned int a)

{
	char j[512], *l;
	unsigned int rem;
	char rem_list[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	int d = 0, n;

	if (a == 0)
	{
		l = malloc(sizeof(char) * 2);
		l[0] = '0';
		l[1] = '\0';
		return (l);
	}
	l = malloc(sizeof(char) * 2);
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

	n = 0;
	while (d > 0)
	{
		d--;
		l[n] = j[d];
		n++;
	}
	return (l);
}


/**
 * itoa_fr_hexabig - to convert an int to a string
 * @a: the string to be converted
 * Return: a buffer to storing the string
 */

char *itoa_fr_hexabig(unsigned int a);
char *itoa_fr_hexabig(unsigned int a)
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
	l = malloc(sizeof(char) * 2);
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

	n = 0;
	while (d > 0)
	{
		d--;
		l[n] = j[d];
		n++;
	}
	return (l);
}
