#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * itoa - to convert an int to a string
 * @a: the string to be converted
 * Return: a buffer to storing the string
 */
char *itoa(int a);
char *itoa(int a)
{
	char j[512], *l;
	int d = 1, n;
	unsigned int for_convert;

	if (a < 0)
	{
		j[0] = '-';
		if (a == INT_MIN)
		{
			for_convert = (unsigned int)INT_MAX + 1;
		}
		else
		{
			for_convert = (unsigned int)a * -1;
		}
	}
	else if (a >  0)
	{
		j[0] = '+';
		for_convert = (unsigned int)a;
	}
	else
	{
		l = malloc(sizeof(char) * 2);
		l[0] = '0';
		l[1] = '\0';
		return (l);
	}
	while (for_convert > 0)
	{
		j[d] = (for_convert % 10) + '0';
		for_convert = for_convert / 10;
		d++;
	}
	if (j[0] == '-')
	{
		d++;
	}
	l = malloc(sizeof(char) * d);
	if (l == NULL)
	{
		return (NULL);
	}
	n = 0;
	if (j[0] == '-')
	{
		d -= 2;
		l[0] = '-';
		n = 1;
	}
	else
	{
		d--;
	}
	while (d > 0)
	{
		l[n] = j[d];
		n++;
		d--;
	}
	l[n] = '\0';
	return (l);
}


/**
 * to_binary - A program to convert a number to binary
 * @num: the number to convert
 * Return: A pointer to the converted number in binary
 */

char *to_binary(unsigned int num)

{
	char bin[512], *ret;
	unsigned int a = 0, b;

	if (num == 0)
	{
		ret = malloc(sizeof(char) * 2);
		ret[0] = '0';
		ret[1] = '\0';
		return (ret);
	}

	while (num > 0)
	{
		bin[a] = (num % 2) + '0';
		a++;
		num = num / 2;
	}

	ret = malloc(sizeof(char) * a);
	if (ret == NULL)
	{
		return (NULL);
	}

	b = 0;
	while (a > 0)
	{
		a--;
		ret[b] = bin[a];
		b++;
	}
	return (ret);
}
