#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
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

	if (a < 0)
	{
		j[0] = '-';
		a *= -1;
		printf("---------------------\n%d\n-----------------\n", a);
	}
	else if (a >  0)
	{
		j[0] = '+';
	}
	else
	{
		return ("0");
	}
	while (a > 0)
	{
		j[d] = (a % 10) + '0';
		a = a / 10;
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
